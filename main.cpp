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
void printInfix(nodeForTree* head);
void printPost(nodeForTree* head);
void printPre(nodeForTree* head);

int main(){
  char input[80];
  cout << "please enter you math equation, make sure that there are no spaces" << endl;
  cin >> input;
  cin.get();
  cout << "HERE IS THE EXPRESSION IN POSTFIX: " << infixToPostfix(input) << endl;
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
  nodeForTree* head = NULL; 
  for(int i = 0; i < strlen(queueChar); i++){
    if(isdigit(queueChar[i])){
      nodeForTree* addIt = new nodeForTree();
      char val = queueChar[i];
      addIt -> setVal(val);
      treepush(head, addIt);
    }else if(queueChar[i] == '+' || queueChar[i] == '-' || queueChar[i] == '*' || queueChar[i] == '/' || queueChar[i] == '^'){
      nodeForTree* top = new nodeForTree();
       nodeForTree* right = treepop(head);
       nodeForTree* left = treepop(head);
       top -> setRight(right);
       top -> setLeft(left);
       char val = queueChar[i];
       top -> setVal(val);
       treepush(head, top);
    }
  }  
  cout << "WOULD YOU LIKE TO OUTPUT AS PREFIX, POSTFIX, OR INFIX. TYPE 1 FOR PRE, 2 FOR POST AND 3 FOR IN " << endl;
  int input2;
  cin >> input2;
  if(input2 == 1){
    cout << "PREFIX: ";
    printPre(head);
  }
  if(input2 == 2){
    cout << "POSTFIX: ";
    printPost(head);
  }
  if(input2 == 3){
     cout << "INFIX: ";
    printInfix(head);
  }
}

void printInfix(nodeForTree* head){
  if(head == NULL){
    return;
  }
  printInfix(head-> getLeft());
  cout << head -> getVal();
  printInfix(head-> getRight());
  
}
void printPost(nodeForTree* head){
  if(head == NULL){
    return;
  }
  printPost(head -> getLeft());
  printPost(head-> getRight());
  cout << head -> getVal();  
}

void printPre(nodeForTree* head){
  if(head == NULL){
    return;
  }
  cout << head -> getVal();
  printPre(head-> getLeft());
  printPre(head-> getRight());

}
