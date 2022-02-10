#include <cstring>
#pragma once

using namespace std;
class nodeForTree{
 public:
  nodeForTree();
  void setLeft(nodeForTree*);
  void setRight(nodeForTree*);
  void setNext(nodeForTree*);
  nodeForTree* getLeft();
  nodeForTree* getNext();
  nodeForTree* getRight();
  char* getVal();
  void setVal(char);

 private:
  nodeForTree* left;
  nodeForTree* right;
  nodeForTree* next;
  char* val;
};
