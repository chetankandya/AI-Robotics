import std_msgs.msg
import time
import rospy
import TstML
import geometry_msgs.msg 
import nav_msgs.msg
import math
import subprocess

class RecordExecutor(TstML.Executor.AbstractNodeExecutor):
    def __init__(self, node, context):
        super(TstML.Executor.AbstractNodeExecutor, self).__init__(node, context)

        time.sleep(2.0)

        self.executorName = "[RecordExecutor]"
        self.filename = None
        self.topics = None

    def terminate_process_and_children(self, p):
        import psutil
        import signal
        process = psutil.Process(p.pid)
        for sub_process in process.children(recursive=True):
            sub_process.send_signal(signal.SIGINT)
        p.wait()

    def start(self):
        print("{}".format(self.executorName))
        self.filename = self.node().getParameter(TstML.TSTNode.ParameterType.Specific, "filename")
        self.topics = self.node().getParameter(TstML.TSTNode.ParameterType.Specific, "topics")

        self.p = subprocess.Popen(["rosbag", "record", "-O"] + [self.filename] + [self.topics])

        return TstML.Executor.ExecutionStatus.Started()

    def pause(self):
        self.paused = True
        return TstML.Executor.ExecutionStatus.Paused()

    def resume(self):
        self.paused = False
        return TstML.Executor.ExecutionStatus.Running()

    def stop(self):
        # self.timer.shutdown()
        self.terminate_process_and_children(self.p)
        
        return TstML.Executor.ExecutionStatus.Finished()

    def abort(self):
        # self.timer.shutdown()
        return TstML.Executor.ExecutionStatus.Aborted()