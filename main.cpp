#include <iostream>
#include <cstring>

using namespace std;

struct Node{
  Node* next = NULL;
  char dataVal;
};

void infixToPostfix(char equation[80]);
void push(Node* &head, Node* toPush);
Node* pop(Node* &head);
Node* peek(Node* head);
void printStack(Node* head);
int countStack(Node* head);
int checkImp(char toCheck);


Node* remove(Node* &head);
void add(Node* &head, Node* &tail, Node* toAdd);
void printQueue(Node* head);
void popAdd(int newImp, int stackImp, Node* &sHead, Node* &qHead, Node* &qTail);


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
  cout << "******Stack Start*******"<< endl;
  while(head != NULL){
    cout << head -> dataVal << endl;
    head = head -> next;
  }
  cout << "******Stack End*******"<< endl;
}

int countStack(Node* head){  
  int count = 0;
  while(head != NULL){
  count = count +1;
  head = head -> next;
  }
  return count;
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
  cout << "******Queue Start*******"<< endl;
  while(head != NULL){
    cout << head -> dataVal << endl;
    head = head -> next;
  }
  cout << "*******Queue End******"<< endl;
}

int checkImp(char toCheck){
  int importance;
      if(toCheck == '+'){
        importance = 1;
      }
      else if(toCheck == '-'){
        importance = 1;
      }
      else if(toCheck == '/'){
        importance = 2;
      }
      else if(toCheck == '^'){
        importance = 3;
      }
      else if(toCheck == '*'){
        importance = 2;
      }
      else if(toCheck == '('){
        importance = 4;
      }
      else if(toCheck == ')'){
        importance = 5;
      }
  return importance;
}

void infixToPostfix(char equation[80]){
  Node* qHead = NULL;
  Node* qTail = NULL;
  Node* sHead = NULL;
  for(int i = 0; i < strlen(equation); i++){
    if(isdigit(equation[i])){
      Node* addIt = new Node;
      char val = equation[i];
      addIt -> dataVal = val;
      add(qHead, qTail, addIt);
      printQueue(qHead);
    }
    else{
      int stackCount = countStack(sHead);
      char op = equation[i];
      
      if(stackCount == 0){
        Node* n = new Node;
        n -> dataVal = op;
        push(sHead, n);
        printStack(sHead);
      }else{
        int newImp = checkImp(op); 
        int stackImp = checkImp(sHead -> dataVal);
        if(newImp > stackImp){
          Node* n = new Node;
          n -> dataVal = op;
          push(sHead, n);
          printStack(sHead);
        } else if(newImp <= stackImp){
            cout << "hi, i entered the euqal to less than loop" << endl;
            popAdd(newImp, stackImp, sHead, qHead, qTail);
            cout << "done popadding" << endl;
            Node* n = new Node;
            n -> dataVal = op;
            push(sHead, n);
            printStack(sHead);
        }
      }
    }
  }
}


void popAdd(int newImp, int stackImp, Node* &sHead, Node* &qHead, Node* &qTail){
  if(newImp <= stackImp){
            cout << "hi, i'm pop adding" << endl;
            Node* removed = pop(sHead);
            add(qHead, qTail, removed);
            printStack(sHead);
            printQueue(qHead);
            stackImp = checkImp(sHead -> dataVal);
            cout << "New Imp: " << newImp << endl;
            cout << "Check Imp: " << checkImp << endl;
            popAdd(newImp, stackImp, sHead, qHead, qTail);
  }
  else{
    return;
  }
}

