#include <iostream>
#include <cstring>
#include <cstdlib>
#include "nodeForTree.h"


using namespace std;

struct Node{
  Node* next = NULL;
  char dataVal;
};

char getCharAt(int a, Node* head);
char* infixToPostfix(char equation[80]);
void push(Node* &head, Node* toPush);
Node* pop(Node* &head);
Node* peek(Node* head);
void printStack(Node* head);
int countStack(Node* head);
int countTreeStack(nodeForTree* head);
int countQueue(Node* head);
int checkImp(char toCheck);
Node* remove(Node* &head);
void add(Node* &head, Node* &tail, Node* toAdd);
void printQueue(Node* head);
void popAdd(int newImp, int stackImp, Node* &sHead, Node* &qHead, Node* &qTail);
void toTree(char* queueChar);
nodeForTree* treepop(nodeForTree* &head);
void treepush(nodeForTree* &head, nodeForTree* toPush);

int main(){
  char input[80];
  cout << "please enter you math equation, make sure that there are no spaces" << endl;
  cin >> input;
  cin.get();
  cout << "FINAL QUEUE: " << infixToPostfix(input) << endl;
  toTree(infixToPostfix(input));
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

int countTreeStack(nodeForTree* head){
  int count = 0;
  while(head != NULL){
  count = count +1;
  head = head -> getNext();
  }
  return count;

}

int countQueue(Node* head){  
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
  return temp;
}

Node* peek(Node* head){
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
        importance = -1;
      }
      else if(toCheck == ')'){
        importance = 4;
      }
  return importance;
}

char* infixToPostfix(char equation[80]){
  Node* qHead = NULL;
  Node* qTail = NULL;
  Node* sHead = NULL;
  for(int i = 0; i < strlen(equation); i++){
    if(isdigit(equation[i])){
      Node* addIt = new Node;
      char val = equation[i];
      addIt -> dataVal = val;
      add(qHead, qTail, addIt);
    }
    else{
      int stackCount = countStack(sHead);
      char op = equation[i];
      
      if(stackCount == 0){
        Node* n = new Node;
        n -> dataVal = op;
        push(sHead, n);
      }else{
        int newImp = checkImp(op); 
        int stackImp = checkImp(sHead -> dataVal);
        
        if(newImp == 4){
          while(stackImp != -1){
            Node* removed = pop(sHead);
            add(qHead, qTail, removed);
            stackImp = checkImp(sHead -> dataVal);
          }
            Node* removed = pop(sHead);
        }
 
         else if(newImp > stackImp){
           if(newImp != 4){
          Node* n = new Node;
          n -> dataVal = op;
          push(sHead, n);
          }
        } else if(newImp <= stackImp && newImp != 4){
             if(newImp == -1){
             Node* n = new Node;
             n -> dataVal = op;
             push(sHead, n);
            }else{
            popAdd(newImp, stackImp, sHead, qHead, qTail);
            Node* n = new Node;
            n -> dataVal = op;
            push(sHead, n);
            }
        }
      }
    }
  }
  
  int stackCount = countStack(sHead);
  for(int a = 0; a < stackCount; a++){
    Node* popped = pop(sHead);
    add(qHead, qTail, popped);
  }
  char* toReturn = new char[countQueue(qHead)];
  for(int z = 0; z<countQueue(qHead); z++){
    char temp = getCharAt(z, qHead);
    strcat(toReturn, (char*)&temp);
  }
  return toReturn;
}

char getCharAt(int a, Node* head){
  
  for(int i = 0; i < a; i++){
    head = head -> next;
  }

  return head -> dataVal;
}

void popAdd(int newImp, int stackImp, Node* &sHead, Node* &qHead, Node* &qTail){
  if(newImp <= stackImp){
            Node* removed = pop(sHead);
            add(qHead, qTail, removed);
            if(sHead == NULL){
              stackImp = 0;
            }else{
              stackImp = checkImp(sHead -> dataVal);
            }
            popAdd(newImp, stackImp, sHead, qHead, qTail);
  }
  else{
    return;
  }
}

nodeForTree* treepop(nodeForTree* &head){
  nodeForTree* temp = head;
  head = head -> getNext();
  temp -> setNext(NULL);
  return temp;
}

void treepush(nodeForTree* &head, nodeForTree* toPush){
    if(head == NULL){
    head = toPush;
    head -> setNext(NULL);
  }
  else{
    nodeForTree* temp = head;
    toPush -> setNext(temp);
    head = toPush;
  }
}

void toTree(char* queueChar){
  cout << "hi 1: " << endl;
  nodeForTree* head = new nodeForTree();        
  cout << "hi 2: " << endl;
  cout << "len: " << strlen(queueChar) << endl;
  for(int i = 0; i < strlen(queueChar); i++){
    cout << "val: " << queueChar[i] << endl;
      cout << "hi 3: " << endl;
    if(isdigit(queueChar[i])){
        cout << "hi 4: " << endl;
      nodeForTree* addIt = new nodeForTree();
        cout << "hi 5: " << endl;
      char val = queueChar[i];
        cout << "hi 6: " << endl;
      addIt -> setVal(val);
        cout << "hi 7: " << endl;
      nodeForTree* left = NULL;
        cout << "hi 8: " << endl;
      nodeForTree* right = NULL;
        cout << "hi 9: " << endl;
      head -> setRight(right);
       cout << "hi 10: " << endl;
      head -> setLeft(left);
        cout << "hi 11: " << endl;
      treepush(head, addIt);
        cout << "hi 12: " << endl;
    }else if(queueChar[i] == '+'){
        cout << "its a plus: " << endl;
      nodeForTree* top = new nodeForTree();        
        cout << "hi 14: " << endl;
       nodeForTree* left = treepop(head);
        cout << "hi 15: " << endl;
       nodeForTree* right = treepop(head);
        cout << "hi 16: " << endl;
       top -> setRight(right);
        cout << "hi 17: " << endl;
       top -> setLeft(left);
        cout << "hi 18: " << endl;
       char val = queueChar[i];
        cout << "hi 19: " << endl;
       top -> setVal(val);
        cout << "hi 20: " << endl;
       treepush(head, top);
    }
      cout << "hi 21: " << endl;
  }
  
    cout << "hi 22: " << endl;
  cout << countTreeStack(head) << endl;
  
}
