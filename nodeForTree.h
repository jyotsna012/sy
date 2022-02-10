#include <cstring>
#pragma once

using namespace std;
class nodeForTree{
 public:
  nodeForTree();
  void setLeft(nodeForTree*);
  void setRight(nodeForTree*);
  nodeForTree* getLeft();
  nodeForTree* getRight();
  char* getVal();
  void setVal(char);

 private:
  nodeForTree* left;
  nodeForTree* right;
  char* val;
};
