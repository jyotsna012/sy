//the node for the expression tree
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

//gets the left node
nodeForTree* nodeForTree::getLeft(){
  return left;
}

//gets right node
nodeForTree* nodeForTree::getRight(){
  return right;
}

//gets value stored in node
char nodeForTree::getVal(){
  return val;
}

//sets the left
void nodeForTree::setLeft(nodeForTree* newLeft){
  left = newLeft;
}

//sets the right
void nodeForTree::setRight(nodeForTree* newRight){
  right = newRight;
}

//sets the value
void nodeForTree::setVal(char newVal){
  val = newVal;
}

//gets the next node
nodeForTree* nodeForTree::getNext(){
  return next;
}

//sets the next node
void nodeForTree::setNext(nodeForTree* nextNew){
  next = nextNew;
}





