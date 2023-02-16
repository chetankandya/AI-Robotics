#!/usr/bin/env python3

from textwrap import indent
import rospy
import visualization_msgs.msg
import geometry_msgs.msg
import std_msgs.msg
import lrs_kdb_msgs.srv
import json
import os

class generate_tst:
    def __init__(self):
        self.query_service = rospy.ServiceProxy('kDBServerNodelet/sparql_query', lrs_kdb_msgs.srv.QueryDatabase)
        
        self.query = f"""
            PREFIX gis: <http://www.ida.liu.se/~TDDE05/gis>
            PREFIX properties: <http://www.ida.liu.se/~TDDE05/properties>
            SELECT ?obj_id ?x ?y  WHERE {{ ?obj_id a <human> ;
            properties:location [ gis:x ?x; gis:y ?y ] . }}
        """
        self.super_object = {
                    "children" : [],
                    "common_params": {},
                    "name": "seq",
                    "params": {}
                }

        self.tst_objects = []

        response = self.query_service(['semanticobject'], 'json', self.query, "", "kDBServerNodelet/sparql_query")
        if response.success:
            print("Running")
            data = json.loads(response.result)
            print("*******resp from data********")
            print(data["results"]["bindings"])
            print("******************************")
            for row in data["results"]["bindings"]:
                x = row["x"]["value"]
                y = row["y"]["value"]

                self.object = {
                    "children" : [],
                    "common_params" : {},
                    "name" : "",
                    "params" : {}
                }
                self.object["name"] = "drive-to"
                inner_point = {
                    "p": {
                        "rostype" : "Point",
                        "x": int(float(x)),
                        "y": int(float(y)),
                        "z": 0
                    }
                }
                self.object['params'].update(inner_point)
                self.object['params']['use-motion-planner'] = False
                self.super_object["children"].append(self.object)
        # print(json.dumps(self.super_object, indent=4))
        with open(os.getcwd() + "/air_lab4/custom_tsts/custom_tst.json", "w") as file:
            json.dump(self.super_object, file, indent=4)

if __name__ == '__main__':
    rospy.init_node('generate_tst', anonymous=False)

    v = generate_tst()
    rospy.spin()