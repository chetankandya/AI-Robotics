#!/usr/bin/env python3

import rospy
import visualization_msgs.msg
import geometry_msgs.msg
import std_msgs.msg
import lrs_kdb_msgs.srv
import json

class visualise_semantic_objects:
    def __init__(self):
        self.display_marker_pub = rospy.Publisher('semantic_sensor_visualisation', visualization_msgs.msg.MarkerArray, queue_size=10, latch=True)
        self.query_service = rospy.ServiceProxy('kDBServerNodelet/sparql_query', lrs_kdb_msgs.srv.QueryDatabase)

        self.marker = visualization_msgs.msg.Marker()
        self.marker.id     = 1242 # identifier the marker, should be unique
        self.marker.header.frame_id = "odom"
        self.marker.type   = visualization_msgs.msg.Marker.CUBE_LIST
        self.marker.action = 0
        self.marker.scale.x = 0.5
        self.marker.scale.y = 0.5
        self.marker.scale.z = 0.5
        self.marker.pose.orientation.w = 1.0
        self.marker.color.a = 1.0

        self.query = f"""
            PREFIX gis: <http://www.ida.liu.se/~TDDE05/gis>
            PREFIX properties: <http://www.ida.liu.se/~TDDE05/properties>
            SELECT ?obj_id ?class ?x ?y  WHERE {{ ?obj_id a ?class ;
            properties:location [ gis:x ?x; gis:y ?y ] . }}
        """
        response = self.query_service(['semanticobject'], 'json', self.query, "", "kDBServerNodelet/sparql_query")

        if response.success:
            print("*** Response from query ***")
            data = json.loads(response.result)
            print("len of result", len(data["results"]["bindings"]))
            for row in data["results"]["bindings"]:
                #print(json.dumps(row, indent=4, sort_keys=True))
                x = row["x"]["value"]
                y = row["y"]["value"]
                if row["class"]["value"] == 'human':
                    self.marker.points.append(geometry_msgs.msg.Point(int(float(x)), int(float(y)), 0))
                    self.marker.colors.append(std_msgs.msg.ColorRGBA(0.5, 1.0, 0.5, 1.0))    
                else:
                    self.marker.points.append(geometry_msgs.msg.Point(int(float(x)), int(float(y)), 0))
                    self.marker.colors.append(std_msgs.msg.ColorRGBA(1.0, 0.5, 0.5, 1.0))

                self.display_marker_pub.publish(visualization_msgs.msg.MarkerArray([self.marker]))
        else:
            print("response failed")
            print(response)

if __name__ == '__main__':
    rospy.init_node('visualise_semantic_objects', anonymous=False)

    v = visualise_semantic_objects()
    rospy.spin()

""" EVERY ROW LOOKS LIKE
{
    "class": {
        "type": "uri",
        "value": "table"
    },
    "obj_id": {
        "type": "uri",
        "value": "id11"
    },
    "x": {
        "datatype": "http://www.w3.org/2001/XMLSchema#decimal",
        "type": "literal",
        "value": "2.8417491249780196"
    },
    "y": {
        "datatype": "http://www.w3.org/2001/XMLSchema#decimal",
        "type": "literal",
        "value": "-0.829765613671177"
    }
}
"""

# Query to only find humans

# self.query = f"""
#             PREFIX gis: <http://www.ida.liu.se/~TDDE05/gis>
#             PREFIX properties: <http://www.ida.liu.se/~TDDE05/properties>
#             SELECT ?obj_id ?x ?y  WHERE {{ ?obj_id a <human> ;
#             properties:location [ gis:x ?x; gis:y ?y ] . }}
#         """