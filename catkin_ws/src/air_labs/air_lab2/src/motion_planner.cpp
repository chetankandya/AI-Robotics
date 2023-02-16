#include "air_lab2/motion_planner_interface.h"
#include <ros/service.h>
#include <ros/node_handle.h>
#include <nav_msgs/GetPlan.h>
class MotionPlanner{
public:
    MotionPlanner(const ros::NodeHandle& _nodeHandle)
    : m_nodeHandle(_nodeHandle), m_motion_planner_interface(nullptr)
    {
        m_planRequest = m_nodeHandle.advertiseService("plan_path",
                                                    &MotionPlanner::pathService,
                                                    this);
        m_motion_planner_interface = new MotionPlannerInterface();
        
    }
    bool pathService(nav_msgs::GetPlanRequest& _req,
                    nav_msgs::GetPlanResponse& _resp)
                    {
                        double start_x = _req.start.pose.position.x;
                        double start_y = _req.start.pose.position.y;
                        double dest_x = _req.goal.pose.position.x;
                        double dest_y = _req.goal.pose.position.y;
                        std::string frame_id;

                        std::vector<std::pair<double, double>> points = m_motion_planner_interface->planPath<nav_msgs::GetMap>(start_x, start_y, dest_x, dest_y, &frame_id);

                        nav_msgs::Path path{};

                        // can be more than 2 points
                        float a=0;
                        float b=0;

                        for (int i = 0; i < points.size(); ++i)
                        {
                            geometry_msgs::PoseStamped tmp_p;

                            // Set current position
                            tmp_p.pose.position.x = points[i].first;
                            tmp_p.pose.position.y = points[i].second;

                            if (i == 0)
                            {
                                a = points[i+1].second - points[i].second;
                                b = points[i+1].first - points[i].first;
                                
                            }
                            else if (i == points.size() - 1 )
                            {
                                a = points[i].second - points[i-1].second;
                                b = points[i].first - points[i-1].first;
                            }
                            else
                            {
                                a = points[i+1].second - points[i-1].second;
                                b = points[i+1].first - points[i-1].first;
                            }

                            tf::Quaternion orientation;
                            auto yaw_angle = std::atan2(a, b);

                            orientation.setRPY(0, 0, yaw_angle);

                            tmp_p.pose.orientation.x = orientation.getX();
                            tmp_p.pose.orientation.y = orientation.getY();
                            tmp_p.pose.orientation.z = orientation.getZ();
                            tmp_p.pose.orientation.w = orientation.getW();

                            path.poses.push_back(tmp_p);
                        }

                        _resp.plan = path;
                        _resp.plan.header.frame_id = frame_id;


                        return true;
                    }
private:
    ros::ServiceServer m_planRequest;
    MotionPlannerInterface* m_motion_planner_interface;
    ros::NodeHandle m_nodeHandle;
};

// In your motion_planner node, you should create a service call plan_path of type
// nav_msgs/GetPlan and then call the function planPath of motion_planner. You
// then need to convert the list of points returned to that function into a list of geometry_msgs/PoseStamped

int main(int argc, char** argv)
{
    // ... = motion_planner_interface->planPath<nav_msgs::GetMap>(...);
    ros::init(argc, argv, "motion_planner");
    ros::NodeHandle n;

    MotionPlanner ptd(n);

    ros::spin();

    return 0;
}