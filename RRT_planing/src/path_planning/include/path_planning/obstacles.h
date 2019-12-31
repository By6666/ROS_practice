#ifndef OBSTACLES_H
#define OBSTACLES_H
#include <geometry_msgs/Point.h>
#include <visualization_msgs/Marker.h>
#include <vector>
#include <iostream>

using namespace std;

class obstacles
{
    public:
        /** Default constructor */
        obstacles() {}
        /** Default destructor */
        virtual ~obstacles() {}

        vector<vector<geometry_msgs::Point> > getObstacleArray();

    private:
        vector< vector<geometry_msgs::Point> > obstacleArray;
};

void initializeMarkers(visualization_msgs::Marker &boundary,
    visualization_msgs::Marker &obstacle);

vector<geometry_msgs::Point> initializeBoundary();

vector<geometry_msgs::Point> initializeObstacles();

#endif // OBSTACLES_H
