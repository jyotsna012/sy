#include "nodeForTree.h"
#include <iostream>
#include <cstring>

using namespace std;

nodeForTree::nodeForTree(char* newVal){
  val = newVal;
  left = NULL;
  right = NULL;
}

nodeForTree* nodeForTree::getLeft(){
  return left;
}

nodeForTree* nodeForTree::getRight(){
  return right;
}


char* nodeForTree::getVal(){
  return val;
}

void nodeForTree::setLeft(nodeForTree* newLeft){
  left = newLeft;
}

void nodeForTree::setRight(nodeForTree* newRight){
  right = newRight;
}





