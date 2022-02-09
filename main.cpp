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
void printStack(Node* head);

Node* remove(Node* &head);
void add(Node* &head, Node* &tail, Node* toAdd);
void printQueue(Node* head);



int main(){

  char input[80];
  cout << "please enter you math equation, make sure that there are no spaces" << endl;
  cin >> input;
  cin.get();
  infixToPostfix(input);
  
 /* Node* tail = NULL;
  Node* head = NULL;
  Node* one = new Node;
  Node* two = new Node;
  Node* three = new Node;
  Node* four = new Node;
  
  one -> dataVal = 1;
  two -> dataVal = 2;
  three -> dataVal = 3;
  four -> dataVal = 4;
  
  add(head, tail, one);
  printQueue(head);
  add(head, tail, two);
  printQueue(head);
  add(head, tail, three);
  printQueue(head);
  remove(head);
  printQueue(head);

  push(head, one);
  push(head, two);
  push(head, three);
  push(head, four);
  peek(head); */
 
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

void add(Node* &head, Node* &tail, Node* toAdd){
  if(head == NULL){
    head = toAdd;
    tail = toAdd;
  }
  else{
  Node* temp = tail;
  tail = toAdd;
  temp->next = tail;
  tail->next = NULL;
  }

}

Node* remove(Node* &head){
  Node* temp = head;
  head = temp -> next;
  temp -> next = NULL;
  cout << "this is value of the returned : " << temp -> dataVal << endl;
  return temp;
}

void printQueue(Node* head){
  while(head != NULL){
    cout << head -> dataVal << endl;
    head = head -> next;
  }
}

void infixToPostfix(char equation[80]){
  Node* qHead = NULL;
  printQueue(qHead);
  Node* qTail = NULL;
  Node* sHead = NULL;
  for(int i = 0; i < 1; i++){
    if(isdigit(equation[i])){
      cout << equation[i] << endl;
      Node* addIt = new Node;
      addIt -> dataVal = (int)equation[i];
      add(qHead, qTail, addIt);
      //printQueue(qHead);
    }
  }
}



