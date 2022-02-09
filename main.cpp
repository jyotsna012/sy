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

  Node* head = new Node;
  Node* two = new Node;
  Node* three = new Node;
  Node* four = new Node;

  head -> dataVal = 1;
  head -> next = NULL;
  
  two -> dataVal = 2;
  two -> next = head;
  
  head = two;
  
  three -> dataVal = 3;
  two -> next = head;
  
  head = three;
  
  four -> dataVal = 4;
  two -> next = head;
  
  head = four;
  
  
  printStack(head);
  
  
  
  /*char input[80];
  cout << "please enter you math equation, make sure that there are no spaces" << endl;
  cin >> input;
  cin.get();
  infixToPostfix(input);*/
}

void push(Node* &head, Node* toPush){

  if(head == NULL){
    head = toPush;
  }
  else{
  
    head -> next = toPush;
    toPush = head;
  
  }

}

void printStack(Node* head){
   cout << "in the loopq" << endl;  
  
  if(head!=NULL){
    cout << "in the loop2" << endl;
    cout << head->dataVal << endl;
    printStack(head->next);
  }
}

Node* pop(Node* &head){

}

