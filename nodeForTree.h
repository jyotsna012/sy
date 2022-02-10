#include <cstring>
#pragma once

using namespace std;
class nodeForTree{
 public:
  nodeForTree(char*);
  void setLeft(nodeForTree*);
  void setRight(nodeForTree*);
  nodeForTree* getLeft();
  nodeForTree* getRight();
  char* getVal();
 private:
  nodeForTree* left;
  nodeForTree* right;
  char* val;
};
