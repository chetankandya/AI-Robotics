#include "air_lab2/occ.h"

#include <ros/node_handle.h>
#include <ros/service.h>
#include <ros/subscriber.h>
#include <atomic>

#include <sensor_msgs/LaserScan.h>

class LStoOCC {
public:
    LStoOCC(const ros::NodeHandle& _nodeHandle)
        : m_nodeHandle(_nodeHandle), m_occ(nullptr),
        m_cell_size(0.1), m_robot_size(1.0)
    {
            
        m_s = m_nodeHandle.subscribe("scan", 
                                    1, &LStoOCC::laserScanCallback, 
                                    this);
            
        m_mapRequest = m_nodeHandle.advertiseService("map_request",
                    &LStoOCC::mapService, this);


        ros::NodeHandle private_nodehandle("~");

        private_nodehandle.getParam("grid_cell_size", m_cell_size);
        private_nodehandle.getParam("robot_size", m_robot_size);

        m_occ = new OCC(m_cell_size, 2*m_robot_size);
        
    }


    void laserScanCallback(const sensor_msgs::LaserScanPtr& _message)
    {
        tf::StampedTransform transform;
        try {
            // Define a 1s timeout
            ros::Duration timeout(1.0);
            // First, lets wait a bit to make synchronize our TF tree and
            // make sure we have received the transform
            m_tfListener.waitForTransform(
                "odom",
                _message->header.frame_id, 
                _message->header.stamp,
                timeout);
            // Then lets get the transformation
            m_tfListener.lookupTransform(
                "odom",
                _message->header.frame_id, 
                _message->header.stamp,
                transform);
        } catch(tf::TransformException& ex)
        {
            ROS_ERROR_STREAM( "Failed to get the transformation: "
            << ex.what() << ", quitting callback");
            return;
        }
        
        m_occ->ensureInitialise(transform);

        int index = 0;

        for (float i = _message->angle_min; i <= _message->angle_max; i += _message->angle_increment)
        {

            tf::Vector3 origin = transform * tf::Vector3(0, 0, 0);

            tf::Vector3 dir = tf::Vector3(transform * 
                                tf::Vector3(std::cos(i), std::sin(i), 0) - 
                                origin).normalize();

            if (std::isnan(_message->ranges[index])){
                m_occ->rayTrace(
                    m_robot_size,
                    origin,
                    dir,
                    _message->range_max,
                    false
                );
            } else {
                m_occ->rayTrace(
                    m_robot_size,
                    origin,
                    dir,
                    _message->ranges[index],
                    true
                );
            }
            ++index;
        }
    }
 
    bool mapService(nav_msgs::GetMapRequest& _req,
                    nav_msgs::GetMapResponse& _resp)
    {
        return m_occ->requestMap(_resp);
    }
    
 private:
    ros::NodeHandle m_nodeHandle;
    OCC* m_occ;
    double m_cell_size, m_robot_size;
    ros::ServiceServer m_mapRequest;
    tf::TransformListener m_tfListener;
    ros::Subscriber m_s;
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "ls_to_occ");
    ros::NodeHandle n;

    LStoOCC ptd(n);

    ros::spin();
    return 0;
}
