#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <string>
#include <sstream>
#include <vector>
#include <chessboard.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_shapes");
  ros::NodeHandle n;
  ros::Rate r(100);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;

  int k = 0;
  bool color = false;

  for (int i = 0; i < 14; i++)
  {
    color = !color;
    for (int j = 0; j < 14; j++)
    {

      visualization_msgs::Marker marker;
      marker.header.frame_id = "/basic_shapes";
      marker.header.stamp = ros::Time::now();

      std::stringstream s;
      s << k;
      std::string ss;
      s >> ss;
      marker.ns = ss;
      marker.id = k;

      marker.type = visualization_msgs::Marker::CUBE;
      marker.action = visualization_msgs::Marker::ADD;

      marker.pose.position.x = double(i);
      marker.pose.position.y = double(j);
      marker.pose.position.z = 0;

      marker.pose.orientation.x = 0.0;
      marker.pose.orientation.y = 0.0;
      marker.pose.orientation.z = 0.0;
      marker.pose.orientation.w = 1.0;

      marker.scale.x = 1.0;
      marker.scale.y = 1.0;
      marker.scale.z = 0.3;

      if (color)
      {
        marker.color.r = 0.0f;
        marker.color.g = 0.0f;
        marker.color.b = 0.0f;
        marker.color.a = 1.0;
        color = !color;
      }
      else
      {
        marker.color.r = 255.0f;
        marker.color.g = 255.0f;
        marker.color.b = 255.0f;
        marker.color.a = 1.0;
        color = !color;
      }

      marker.lifetime = ros::Duration();

      while (marker_pub.getNumSubscribers() < 1)
      {
        if (!ros::ok())
        {
          return 0;
        }
        ROS_WARN_ONCE("Please create a subscriber to the marker");
        sleep(1);
      }
      marker_pub.publish(marker);
      r.sleep();
      k++;
    }
  }

  status_ptr first_status{new (status)};
  first_status->black_or_white = true;
  first_status->chessboard[4][3] = black;

  while (1)
  {
    
  }

  shape = visualization_msgs::Marker::CYLINDER;

  while (1)
  {

    // status_ptr head{new (status)};
    // head->generation = -1;
    // int x, y;
    // cin >> x >> y;
    // first_status->chessboard[x][y] = white;

    // for (int i = 0; i < row_num; i++)
    // {
    //   for (int j = 0; j < col_num; j++)
    //   {
    //     cout << first_status->chessboard[i][j] << ' ';
    //   }
    //   cout << endl;
    // }

    // cout << endl;
    // // int fx = Minimax(first_status, head);
    // int fx = alpha_belta(first_status, head);

    // cout << "..........................................................." << endl;
    // for (int i = 0; i < row_num; i++)
    // {
    //   for (int j = 0; j < col_num; j++)
    //   {
    //     if (i == first_status->x && j == first_status->y)
    //     {
    //       first_status->chessboard[i][j] = 1;
    //     }
    //     cout << first_status->chessboard[i][j] << ' ';
    //   }
    //   cout << endl;
    // }

    // cout << first_status->fx << endl;
    // first_status->black_or_white = true;
    // first_status->generation = 0;
    // first_status->x = 0;
    // first_status->y = 0;
    // first_status->fx = -1000;

    visualization_msgs::Marker marker;
    marker.header.frame_id = "/basic_shapes";
    marker.header.stamp = ros::Time::now();

    std::stringstream s;
    s << k;
    std::string ss;
    s >> ss;
    marker.ns = ss;
    marker.id = k;

    marker.type = visualization_msgs::Marker::CYLINDER;
    marker.action = visualization_msgs::Marker::ADD;

    int x, y;
    std::cin >> x >> y;

    marker.pose.position.x = double(x - 0.5);
    marker.pose.position.y = double(y - 0.5);
    marker.pose.position.z = 0.2;

    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    marker.scale.x = 1.0;
    marker.scale.y = 1.0;
    marker.scale.z = 0.4;

    if (color)
    {
      marker.color.r = 0.0f;
      marker.color.g = 0.0f;
      marker.color.b = 0.0f;
      marker.color.a = 1.0;
      color = !color;
    }
    else
    {
      marker.color.r = 255.0f;
      marker.color.g = 255.0f;
      marker.color.b = 255.0f;
      marker.color.a = 1.0;
      color = !color;
    }

    marker.lifetime = ros::Duration();

    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }
    marker_pub.publish(marker);
    r.sleep();
    k++;
  }
}
