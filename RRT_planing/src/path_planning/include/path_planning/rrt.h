#ifndef rrt_h
#define rrt_h

#include <vector>
using namespace std;

namespace rrt {
class RRT {

public:
  RRT();
  RRT(double input_PosX, double input_PosY);//构造函数

  struct rrtNode {//节点结构体
    int nodeID;
    double posX;
    double posY;
    int parentID;
    vector<int> children;
  };

  vector<rrtNode> getTree() const;
  void setTree(vector<rrtNode> input_rrtTree);
  int getTreeSize() const;

  void addNewNode(rrtNode node);
  rrtNode removeNode(int nodeID);
  rrtNode getNode(int nodeID);

  double getPosX(int nodeID);
  double getPosY(int nodeID);
  void setPosX(int nodeID, double input_PosX);
  void setPosY(int nodeID, double input_PosY);

  rrtNode getParent(int nodeID);
  void setParentID(int nodeID, int parentID);

  void addChildID(int nodeID, int childID);
  vector<int> getChildren(int nodeID);
  int getChildrenSize(int nodeID);

  int getNearestNodeID(double X, double Y);
  vector<int> getRootToEndPath(int endNodeID);

private:
  vector<rrtNode> rrtTree;
  double getEuclideanDistance(double sourceX, double sourceY,
                              double destinationX, double destinationY);
};
};

#endif
