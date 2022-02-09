#include <cstring>
#pragma once

using namespace std;
class nodeForTree{
 public:
  nodeForTree(char*);
  void setLeft(nodeForTree*);
  void setRight(nodeForTree*);
  void setNext(nodeForTree*);
  nodeForTree* getLeft();
  nodeForTree* getRight();
  nodeForTree* getNext();
  char* getVal();
 private:
  nodeForTree* left;
  nodeForTree* right;
  nodeForTree* next;
  char* val;
};
