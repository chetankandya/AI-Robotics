#!/usr/bin/env python3

import sensor_msgs.msg
import std_msgs.msg
import rospy
import TstML
import rospkg
import TstML.Executor
import air_lab4.srv
from abstract_node_executor import EchoExecutor
from drive_to_executor import DriveToExecutor
from explore_executor import ExploreExecutor
from record_executor import RecordExecutor
from record_semantic_executor import RecordSemanticExecutor
from fixed_window import fixed_window
from q_explore import q_learn
from std_srvs.srv import Empty

class tst_executor:
    def __init__(self):
        self.tst_registry = TstML.TSTNodeModelsRegistry()
        self.tst_registry.loadDirectory(rospkg.RosPack().get_path("air_tst") + "/configs")

        # Create a registry with node executors
        self.tst_executor_registry = TstML.Executor.NodeExecutorRegistry()

        # Setup the executors for sequence and concurrent
        self.tst_executor_registry.registerNodeExecutor(
            self.tst_registry.model("seq"),
            TstML.Executor.DefaultNodeExecutor.Sequence
            )
        self.tst_executor_registry.registerNodeExecutor(
            self.tst_registry.model("conc"),
            TstML.Executor.DefaultNodeExecutor.Concurrent
            )

        # Associate the EchoExecutor to the "echo" model
        self.tst_executor_registry.registerNodeExecutor(self.tst_registry.model("echo"), EchoExecutor)
        #self.tst_executor_registry.registerNodeExecutor(self.tst_registry.model("fixed_window"), fixed_window)
        self.tst_executor_registry.registerNodeExecutor(self.tst_registry.model("drive-to"), DriveToExecutor)
        self.tst_executor_registry.registerNodeExecutor(self.tst_registry.model("explore"), ExploreExecutor)
        self.tst_executor_registry.registerNodeExecutor(self.tst_registry.model("record"), RecordExecutor)
        self.tst_executor_registry.registerNodeExecutor(self.tst_registry.model("record-semantic"), RecordSemanticExecutor)

        self.service = rospy.Service('execute_tst', air_lab4.srv.ExecuteTst, self.execute_tst)
        self.service_abort = rospy.Service('abort', Empty, self.abort)
        self.service_stop = rospy.Service('stop', Empty, self.stop)
        self.service_pause = rospy.Service('pause', Empty, self.pause)
        self.service_resume = rospy.Service('resume', Empty, self.resume)

    def execute_tst(self, req):
        tst_node = TstML.TSTNode.load(req.tst_file, self.tst_registry)

        # Create an executor using the executors defined
        # in tst_executor_registry
        tst_executor = TstML.Executor.Executor(tst_node,
                        self.tst_executor_registry)

        tst_executor.start()

        # Block until the execution has finished
        status = tst_executor.waitForFinished()

        # Display results
        if status.type() == TstML.Executor.ExecutionStatus.Type.Finished:
            print("Execution successful")
            return air_lab4.srv.ExecuteTstResponse(True,"No error" )
        else:
            print(status)
            return air_lab4.srv.ExecuteTstResponse(False, "Something went wrong...")

    def abort(self, req):
        self.tst_executor.abort()
        
    def stop(self, req):
        self.tst_executor.stop()

    def pause(self, req):
        self.tst_executor.pause()

    def resume(self, req):
        self.tst_executor.resume()


if __name__ == '__main__':
    print("Starting tst executor!")
    rospy.init_node('tst_executor', anonymous=False)

    ec = tst_executor()

    rospy.spin()