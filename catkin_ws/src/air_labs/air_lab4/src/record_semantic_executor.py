#!/usr/bin/env python3

import std_msgs.msg
import time
import rospy
import TstML
import tf
import geometry_msgs.msg 
import nav_msgs.msg
import math
import subprocess
import air_simple_sim_msgs.msg
import lrs_kdb_msgs.srv
import json

class RecordSemanticExecutor(TstML.Executor.AbstractNodeExecutor):
    def __init__(self, node, context):
        super(TstML.Executor.AbstractNodeExecutor, self).__init__(node, context)

        self.executor_name = "[RecordSemanticExecutor]"
        self.graph_name = self.node().getParameter(TstML.TSTNode.ParameterType.Specific, "graphname")
        self.topic = self.node().getParameter(TstML.TSTNode.ParameterType.Specific, "topic")
        self.query      = ""
        self.content    = ""

        self.tf_listener = tf.TransformListener()
        time.sleep(2.0)
        # self.robot_frame = rospy.get_param('~robot_frame')
        self.robot_frame = "base_footprint"
        time.sleep(2.0)
        self.semantic_sensor_sub = rospy.Subscriber(self.topic, air_simple_sim_msgs.msg.SemanticObservation, self.semantic_sensor_callback)

        """
        Structure for request to query
        string[] graphnames
        string format
        string query
        string bindings
        string service
        """
        self.query_service = rospy.ServiceProxy('kDBServerNodelet/sparql_query', lrs_kdb_msgs.srv.QueryDatabase)

        """
        string graphname
        string format
        string content
        --- 
        string errMsg
        bool success
        """
        self.insert_triplets_service = rospy.ServiceProxy('kDBServerNodelet/insert_triples', lrs_kdb_msgs.srv.InsertTriples)

        time.sleep(2.0)


    def semantic_sensor_callback(self, msg):
        print(f"{self.executor_name} ****Semantic sensor sent something!****\n")

        self.robot_frame = msg.point.header.frame_id
        x = msg.point.point.x
        y = msg.point.point.y
        klass = msg.klass
        uuid = msg.uuid

        try:
            (trans,_) = self.tf_listener.lookupTransform('odom', self.robot_frame, rospy.Time(0))
            x, y, _ = trans
            print("[POINT] ({}, {})".format(x, y))
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            rospy.logerr("Failed to get transformation from 'odom' to 'base_footprint'!")
            return

        # print("====================")
        # print("Found x and y (directly): ({:}, {:})".format(x, y))
        # print("TF: ({:})".format(trans))
        # print("====================")

        #print(f"\tuuid: {uuid}\n\tx: {x}\n\ty: {y}\n\tklass: {klass}\n\ttopic: {self.topic}\n\tgraphname: {self.graph_name}\n")

        # 1. check if already in db
        try:
            """
            Query to see if current
            object with an id and class
            already exists in db
            """
            self.query = f"""
                PREFIX gis: <http://www.ida.liu.se/~TDDE05/gis>
                PREFIX properties: <http://www.ida.liu.se/~TDDE05/properties>
                SELECT ?x ?y WHERE {{ <{uuid}> a <{klass}> ;
                properties:location [ gis:x ?x; gis:y ?y ] . }}
            """

            response = self.query_service([self.graph_name], 'json', self.query, "", "kDBServerNodelet/sparql_query")
            
            print(f"{self.executor_name} ***got response from query!***")
            if response.success:
                data = json.loads(response.result)
                if len(data["results"]["bindings"]) == 0:
                    # object is not in db
                    # so insert triple
                    self.content = f"""
                        @prefix gis: <http://www.ida.liu.se/~TDDE05/gis>
                        @prefix properties: <http://www.ida.liu.se/~TDDE05/properties>
                        <{uuid}> a <{klass}>;
                            properties:location [ gis:x {x}; gis:y {y} ] .
                    """
                    response = self.insert_triplets_service(self.graph_name, 'ttl', self.content)
                    if response.success:
                        print(f"{self.executor_name} Inserted triple into db successfully")
                    else:
                        print(f"{self.executor_name} ERROR while trying insert triple")
                        print(response.errMsg)
                else:
                    print(f"{self.executor_name} Object <{uuid}> a <{klass}> already in db, not inserting ")

        except rospy.ServiceException as e:
            print("Service call failed: %s" %e)

    # def terminate_process_and_children(self, p):
    #     import psutil
    #     import signal
    #     process = psutil.Process(p.pid)
    #     for sub_process in process.children(recursive=True):
    #         sub_process.send_signal(signal.SIGINT)
    #     p.wait()
    
    def start(self):
        print(f"{self.executor_name} Started")

        #self.p = subprocess.Popen(["rosbag", "record", "-O"] + [self.filename] + [self.topics])

        return TstML.Executor.ExecutionStatus.Started()

    def pause(self):
        self.paused = True
        return TstML.Executor.ExecutionStatus.Paused()

    def resume(self):
        self.paused = False
        return TstML.Executor.ExecutionStatus.Running()

    def stop(self):
        # self.timer.shutdown()
        #self.terminate_process_and_children(self.p)
        
        return TstML.Executor.ExecutionStatus.Finished()

    def abort(self):
        # self.timer.shutdown()
        return TstML.Executor.ExecutionStatus.Aborted()


"""
-- retrieved with command "rosservice list" in terminal

/husky0/kDBServerNodelet/erase_database
/husky0/kDBServerNodelet/get_loggers
/husky0/kDBServerNodelet/insert_triples
/husky0/kDBServerNodelet/sparql_query
/husky0/kDBServerNodelet/sparql_query2
/husky0/kDBServerNodelet/sql_query
/husky0/kDBServerNodelet/start_topic_recording
/husky0/kDBServerNodelet/stop_topic_recording
/husky0/kdb_nodelets/list
/husky0/kdb_nodelets/load_nodelet
/husky0/kdb_nodelets/set_logger_level
/husky0/kdb_nodelets/unload_nodelet
"""

""" HOW A MSG LOOKS LIKE
    point: 
    header: 
        seq: 0
        stamp: 
        secs: 1645794806
        nsecs: 916115283
        frame_id: "husky0/semantic_sensor"
    point: 
        x: 0.3539651280276413
        y: -2.010594731656836
        z: 0.0
    klass: "table"
    uuid: "16"
"""

"""
{'x': {'type': 'uri', 'value': 'http://www.ida.liu.se/~TDDE051'}, 'y': {'type': 'uri', 'value': 'http://www.w3.org/1999/02/22-rdf-syntax-ns#type'}, 'z': {'ty
pe': 'uri', 'value': 'http://www.ida.liu.se/~TDDE05/classesHuman'}}
{'x': {'type': 'bnode', 'value': '0'}, 'y': {'type': 'uri', 'value': 'http://www.ida.liu.se/~TDDE05/gisx'}, 'z': {'datatype': 'http://www.w3.org/2001/XMLSche
ma#integer', 'type': 'literal', 'value': '10'}}
{'x': {'type': 'bnode', 'value': '0'}, 'y': {'type': 'uri', 'value': 'http://www.ida.liu.se/~TDDE05/gisy'}, 'z': {'datatype': 'http://www.w3.org/2001/XMLSche
ma#integer', 'type': 'literal', 'value': '10'}}
{'x': {'type': 'uri', 'value': 'http://www.ida.liu.se/~TDDE051'}, 'y': {'type': 'uri', 'value': 'http://www.ida.liu.se/~TDDE05/propertieslocation'}, 'z': {'t
ype': 'bnode', 'value': '0'}}
{'x': {'type': 'uri', 'value': 'http://www.ida.liu.se/~TDDE052'}, 'y': {'type': 'uri', 'value': 'http://www.w3.org/1999/02/22-rdf-syntax-ns#type'}, 'z': {'ty
pe': 'uri', 'value': 'http://www.ida.liu.se/~TDDE05/classesHuman'}}
{'x': {'type': 'bnode', 'value': '1'}, 'y': {'type': 'uri', 'value': 'http://www.ida.liu.se/~TDDE05/gisx'}, 'z': {'datatype': 'http://www.w3.org/2001/XMLSche
ma#integer', 'type': 'literal', 'value': '10'}}
{'x': {'type': 'bnode', 'value': '1'}, 'y': {'type': 'uri', 'value': 'http://www.ida.liu.se/~TDDE05/gisy'}, 'z': {'datatype': 'http://www.w3.org/2001/XMLSche
ma#integer', 'type': 'literal', 'value': '12'}}
{'x': {'type': 'uri', 'value': 'http://www.ida.liu.se/~TDDE052'}, 'y': {'type': 'uri', 'value': 'http://www.ida.liu.se/~TDDE05/propertieslocation'}, 'z': {'t
ype': 'bnode', 'value': '1'}}
{'x': {'type': 'bnode', 'value': '2'}, 'y': {'type': 'uri', 'value': 'http://www.ida.liu.se/~TDDE05/gisx'}, 'z': {'datatype': 'http://www.w3.org/2001/XMLSche
ma#integer', 'type': 'literal', 'value': '10'}}
{'x': {'type': 'bnode', 'value': '2'}, 'y': {'type': 'uri', 'value': 'http://www.ida.liu.se/~TDDE05/gisy'}, 'z': {'datatype': 'http://www.w3.org/2001/XMLSche
ma#integer', 'type': 'literal', 'value': '10'}}
{'x': {'type': 'uri', 'value': 'http://www.ida.liu.se/~TDDE051'}, 'y': {'type': 'uri', 'value': 'http://www.ida.liu.se/~TDDE05/propertieslocation'}, 'z': {'t
ype': 'bnode', 'value': '2'}}
{'x': {'type': 'bnode', 'value': '3'}, 'y': {'type': 'uri', 'value': 'http://www.ida.liu.se/~TDDE05/gisx'}, 'z': {'datatype': 'http://www.w3.org/2001/XMLSche
ma#integer', 'type': 'literal', 'value': '10'}}
{'x': {'type': 'bnode', 'value': '3'}, 'y': {'type': 'uri', 'value': 'http://www.ida.liu.se/~TDDE05/gisy'}, 'z': {'datatype': 'http://www.w3.org/2001/XMLSche
ma#integer', 'type': 'literal', 'value': '12'}}
{'x': {'type': 'uri', 'value': 'http://www.ida.liu.se/~TDDE052'}, 'y': {'type': 'uri', 'value': 'http://www.ida.liu.se/~TDDE05/propertieslocation'}, 'z': {'t
ype': 'bnode', 'value': '3'}}
"""

"""
example of 1 row
{
    'x': {'type': 'uri', 'value': 'http://www.ida.liu.se/~TDDE051'}, 
    'y': {'type': 'uri', 'value': 'http://www.w3.org/1999/02/22-rdf-syntax-ns#type'}, 
    'z': {'type': 'uri', 'value': 'http://www.ida.liu.se/~TDDE05/classesHuman'}
}
"""