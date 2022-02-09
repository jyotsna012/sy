#include "nodeForTree.h"
#include <iostream>
#include <cstring>

using namespace std;

nodeForTree::nodeForTree(char* newVal){
  val = newVal;
  left = NULL;
  right = NULL;
  next = NULL;
}

nodeForTree* nodeForTree::getLeft(){
  return left;
}

nodeForTree* nodeForTree::getRight(){
  return right;
}

nodeForTree* nodeForTree::getNext(){
  return next;
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

void nodeForTree::setNext(nodeForTree* newNext){
  next = newNext;
}




