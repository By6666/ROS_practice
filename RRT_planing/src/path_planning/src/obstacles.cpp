#include <path_planning/obstacles.h>
#include <geometry_msgs/Point.h>

void initializeMarkers(visualization_msgs::Marker &boundary,
    visualization_msgs::Marker &obstacle)
{
    //init headers
	boundary.header.frame_id    = obstacle.header.frame_id    = "path_planner";
	boundary.header.stamp       = obstacle.header.stamp       = ros::Time::now();
	boundary.ns                 = obstacle.ns                 = "path_planner";
	boundary.action             = obstacle.action             = visualization_msgs::Marker::ADD;
	boundary.pose.orientation.w = obstacle.pose.orientation.w = 1.0;

    //setting id for each marker
    boundary.id    = 110;
	obstacle.id   = 111;

	//defining types
	boundary.type  = visualization_msgs::Marker::LINE_STRIP;//线条（点的连线）
	obstacle.type = visualization_msgs::Marker::LINE_LIST;//线条序列

	//setting scale
	boundary.scale.x = 1;
	obstacle.scale.x = 1;

    //assigning colors
	boundary.color.r =  1.0f;
	boundary.color.g =  0.0f;
	boundary.color.b =  0.0f;

	obstacle.color.r = 0.0f;
	obstacle.color.g = 0.0f;
	obstacle.color.b = 0.0f;

	boundary.color.a = obstacle.color.a = 1.0f;
}


vector<geometry_msgs::Point> initializeBoundary()
{
    vector<geometry_msgs::Point> bondArray;

    geometry_msgs::Point point;

    //first point
    point.x = 0;
    point.y = 0;
    point.z = 0;

    bondArray.push_back(point);

    //second point
    point.x = 0;
    point.y = 100;
    point.z = 0;

    bondArray.push_back(point);

    //third point
    point.x = 100;
    point.y = 100;
    point.z = 0;

    bondArray.push_back(point);

    //fourth point
    point.x = 100;
    point.y = 0;
    point.z = 0;
    bondArray.push_back(point);

    //first point again to complete the box
    point.x = 0;
    point.y = 0;
    point.z = 0;
    bondArray.push_back(point);

    return bondArray;
}

vector<geometry_msgs::Point> initializeObstacles()
{
    vector< vector<geometry_msgs::Point> > obstArray;

    vector<geometry_msgs::Point> obstaclesMarker;

    obstacles obst;

    obstArray = obst.getObstacleArray();

    for(int i=0; i<obstArray.size(); i++)
    {
        for(int j=0; j<obstArray[i].size()-1; j++)
        {
            obstaclesMarker.push_back(obstArray[i][j]);
            obstaclesMarker.push_back(obstArray[i][j+1]);
        }
    }
    return obstaclesMarker;
}

vector< vector<geometry_msgs::Point> > obstacles::getObstacleArray()
{
    vector<geometry_msgs::Point> obstaclePoint;
    geometry_msgs::Point point;

    //first point
    point.x = 50;
    point.y = 50;
    point.z = 0;

    obstaclePoint.push_back(point);

    //second point
    point.x = 50;
    point.y = 60;
    point.z = 0;

    obstaclePoint.push_back(point);

    //third point
    point.x = 70;
    point.y = 60;
    point.z = 0;

    obstaclePoint.push_back(point);

    //fourth point
    point.x = 70;
    point.y = 50;
    point.z = 0;
    obstaclePoint.push_back(point);

    //first point again to complete the box
    point.x = 50;
    point.y = 50;
    point.z = 0;
    obstaclePoint.push_back(point);

    obstacleArray.push_back(obstaclePoint);

//********************************
    obstaclePoint.clear();
    //first point
    point.x = 10;
    point.y = 10;
    point.z = 0;

    obstaclePoint.push_back(point);

    //second point
    point.x = 20;
    point.y = 20;
    point.z = 0;

    obstaclePoint.push_back(point);

    //third point
    point.x = 30;
    point.y = 15;
    point.z = 0;

    obstaclePoint.push_back(point);

    //fourth point
    point.x = 40;
    point.y = 30;
    point.z = 0;
    obstaclePoint.push_back(point);

    //first point again to complete the box
    point.x = 40;
    point.y = 10;
    point.z = 0;
    obstaclePoint.push_back(point);

   //first point again to complete the box
    point.x = 10;
    point.y = 10;
    point.z = 0;
    obstaclePoint.push_back(point);

    obstacleArray.push_back(obstaclePoint);
    
    return obstacleArray;

}

