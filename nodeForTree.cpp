#include "nodeForTree.h"
#include <iostream>
#include <cstring>

using namespace std;

nodeForTree::nodeForTree(){
  val = NULL;
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


char nodeForTree::getVal(){
  return val;
}

void nodeForTree::setLeft(nodeForTree* newLeft){
  left = newLeft;
}

void nodeForTree::setRight(nodeForTree* newRight){
  right = newRight;
}

void nodeForTree::setVal(char newVal){
  val = newVal;
}

nodeForTree* nodeForTree::getNext(){
  return next;
}

void nodeForTree::setNext(nodeForTree* nextNew){
  next = nextNew;
}





