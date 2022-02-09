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
  
  head -> dataVal = 1;
  two -> dataVal = 2;
  
  head -> next = two;
  head = two;
  
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
  if(head!=NULL){
    cout << head->dataVal << endl;
    printStack(head->next);
  }
}


