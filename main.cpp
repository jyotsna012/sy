#include <iostream>
#include <cstring>

using namespace std;

struct Node{
  Node* next = NULL;
  int dataVal;
};

void infixToPostfix(char equation[80]);
void push(Node* &head, Node* toPush);
Node* pop(Node* &head);
Node* peek(Node* head);

Node* remove(Node* &head);
void add(Node* &tail, Node* toAdd);
void printStack(Node* head);


int main(){

  Node* tail = NULL;
  Node* head = NULL;
  Node* one = new Node;
  Node* two = new Node;
  Node* three = new Node;
  Node* four = new Node;
  
  one -> dataVal = 1;
  two -> dataVal = 2;
  three -> dataVal = 3;
  four -> dataVal = 4;
  
  add(tail, one);
  add(tail, two);
  
 // cout << tail -> dataVal << endl;
  
 /* push(head, one);
  push(head, two);
  push(head, three);
  push(head, four);
  peek(head); */
  
  /*char input[80];
  cout << "please enter you math equation, make sure that there are no spaces" << endl;
  cin >> input;
  cin.get();
  infixToPostfix(input);*/
}

void push(Node* &head, Node* toPush){
  if(head == NULL){
    head = toPush;
    head -> next = NULL;
  }
  else{
    Node* temp = head;
    toPush -> next = temp;
    head = toPush;
  }
}

void printStack(Node* head){  
  while(head != NULL){
    cout << head -> dataVal << endl;
    head = head -> next;
  }
}

Node* pop(Node* &head){
  Node* temp = head;
  head = head -> next;
  temp -> next = NULL;
  cout << "this is value of popped: " << temp -> dataVal << endl;
  return temp;
}

Node* peek(Node* head){
  cout << "this is value of peeked: " << head -> dataVal << endl;
  return head;
}

void add(Node* &tail, Node* toAdd){
  if(tail == NULL){
    toAdd = tail;
  }
  Node* temp = tail;
  temp -> next = toAdd;
  toAdd = tail;
}


