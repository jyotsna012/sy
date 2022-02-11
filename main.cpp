#include <iostream>
#include <cstring>
#include <cstdlib>
#include "nodeForTree.h"


using namespace std;

//struct that is used in stack and queue and has a data value and a neext pointer
struct Node{
  Node* next = NULL;
  char dataVal;
};

//a bunch of function prototypes
char getCharAt(int a, Node* head);
char* shuntingYard(char equation[80]);
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

//main function will ask the user to input their expression, 
//and will input the result after the ShuntingYard algorithm into the toTree function to create an expression tree
int main(){
  char input[80];
  cout << "please enter you math equation, make sure that there are no spaces" << endl;
  cin >> input;
  cin.get();
  toTree(shuntingYard(input));
}

//new head is equal to what is inputted and the old head is connected to new head
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

//goes through stack and prints each datavalue
void printStack(Node* head){  
  cout << "******Stack Start*******"<< endl;
  while(head != NULL){
    cout << head -> dataVal << endl;
    head = head -> next;
  }
  cout << "******Stack End*******"<< endl;
}

//itterartes through stack and increases the counter by one each time
int countStack(Node* head){  
  int count = 0;
  while(head != NULL){
  count = count +1;
  head = head -> next;
  }
  return count;
}

//itterartes through stack and increases the counter by one each time (counts the stack for the binary tree)
int countTreeStack(nodeForTree* head){
  int count = 0;
  while(head != NULL){
  count = count +1;
  head = head -> getNext();
  }
  return count;

}

//itterartes through queye and increases the counter by one each time to find length
int countQueue(Node* head){  
  int count = 0;
  while(head != NULL){
  count = count +1;
  head = head -> next;
  }
  return count;
}

//returns the current head and makes the one after the new head
Node* pop(Node* &head){
  Node* temp = head;
  head = head -> next;
  temp -> next = NULL;
  return temp;
}

//returns head
Node* peek(Node* head){
  return head;
}

//adds to queue by making the input the new tail and pointing the old tail to the new one 
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

//removes the head from a queue and returns it. makes new head equal to the next node
Node* remove(Node* &head){
  Node* temp = head;
  head = temp -> next;
  temp -> next = NULL;
  return temp;
}

//iterates through queue to print out each datavalue
void printQueue(Node* head){
  cout << "******Queue Start*******"<< endl;
  while(head != NULL){
    cout << head -> dataVal << endl;
    head = head -> next;
  }
  cout << "*******Queue End******"<< endl;
}

//takes a char as the input and returns an importance int based on the importance ranking in the Shunting Yard Algorithm
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

//goes through Shunting yard algorithim
char* shuntingYard(char equation[80]){
  //creates the head and tail pointers for the queue and the stack
  Node* qHead = NULL;
  Node* qTail = NULL;
  Node* sHead = NULL;
  //loos through the given char array
  for(int i = 0; i < strlen(equation); i++){
    //if the char at the given point is a digit, it is added to the stack
    if(isdigit(equation[i])){
      Node* addIt = new Node;
      char val = equation[i];
      addIt -> dataVal = val;
      add(qHead, qTail, addIt);
    }
    else{
      int stackCount = countStack(sHead); //length of stack
      char op = equation[i]; 
      //if count equals 0, means the node being added to stack is the first
      if(stackCount == 0){
        Node* n = new Node;
        n -> dataVal = op;
        push(sHead, n);
      }else{
        //importance of char to be added and the top char of the stack
        int newImp = checkImp(op); 
        int stackImp = checkImp(sHead -> dataVal);
        
        //newchar is a closing parenthesis so nodes from stack are popped until matching opening in found 
        if(newImp == 4){
          while(stackImp != -1){
            Node* removed = pop(sHead);
            add(qHead, qTail, removed);
            stackImp = checkImp(sHead -> dataVal);
          }
            Node* removed = pop(sHead);
        }
         //if new char has a higher importance and is not a closing parenthesis, it is added to the top of stack
         else if(newImp > stackImp){
           if(newImp != 4){
          Node* n = new Node;
          n -> dataVal = op;
          push(sHead, n);
          }
           //if new char has lower importance....
        } else if(newImp <= stackImp && newImp != 4){
           //if its a opening bracket, it is placed on the stack
             if(newImp == -1){
             Node* n = new Node;
             n -> dataVal = op;
             push(sHead, n);
            }else{
               //else nodes are popped until the stack char has a imp lower value than new char. all popped noded added to queue
            popAdd(newImp, stackImp, sHead, qHead, qTail);
            Node* n = new Node;
            n -> dataVal = op;
            push(sHead, n);
            }
        }
      }
    }
  }
  //everything in stack is popped into the queue
  int stackCount = countStack(sHead);
  for(int a = 0; a < stackCount; a++){
    Node* popped = pop(sHead);
    add(qHead, qTail, popped);
  }
  //turns the queue into a char array and returns it
  char* toReturn = new char[countQueue(qHead)];
  for(int z = 0; z<countQueue(qHead); z++){
    char temp = getCharAt(z, qHead);
    strcat(toReturn, (char*)&temp);
  }
  return toReturn;
}

//function to get the char at a specific node
char getCharAt(int a, Node* head){
  
  for(int i = 0; i < a; i++){
    head = head -> next;
  }

  return head -> dataVal;
}

//this function pops the top of the stack and adds it into the queue untill newIMP is less than or equal to stack imp
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

//function to pop from a stack of tree nodes
nodeForTree* treepop(nodeForTree* &head){
  nodeForTree* temp = head;
  head = head -> getNext();
  temp -> setNext(NULL);
  return temp;
}

//function to push to a stack of tree nodes
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

//function to turn result from Shunting Yard into the bianary expression tree
void toTree(char* queueChar){
  //inititiates a null head for the binary tree
  nodeForTree* head = NULL; 
  //goes through the inputted char array one by one
  for(int i = 0; i < strlen(queueChar); i++){
    //if the char is a digit then it is added to the stack
    if(isdigit(queueChar[i])){
      nodeForTree* addIt = new nodeForTree();
      char val = queueChar[i];
      addIt -> setVal(val);
      treepush(head, addIt);
      //everytime its a operator, a new node is formed with the left and right being the previous two nodes in the stack
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
  //once tree is complete, asks user how to output the expression and calls function based on response
  cout << "WOULD YOU LIKE TO OUTPUT AS PREFIX, POSTFIX, OR INFIX. TYPE 1 FOR PRE, 2 FOR POST AND 3 FOR IN " << endl;
  int input2;
  cin >> input2;
  if(input2 == 1){
    cout << "PREFIX: ";
    printPre(head);
    cout<<"\n";
  }
  if(input2 == 2){
    cout << "POSTFIX: ";
    printPost(head);
    cout<<"\n";
  }
  if(input2 == 3){
     cout << "INFIX: ";
    printInfix(head);
    cout<<"\n";
  }
}

//follows the left node right pattern untill all nodes are viisted and printed
void printInfix(nodeForTree* head){

    if(head->getLeft()!=NULL && head->getRight()!= NULL){
      cout<<"(";
    }
    if(head->getLeft()!=NULL){
      printInfix(head->getLeft());
    }
    cout<<head->getVal();
    if(head->getRight()!=NULL){
      printInfix(head->getRight());
    }
    if(!(head->getLeft()==NULL && head->getRight()==NULL)){
      cout<<")";
    }
}

//follows the left right node pattern until all nodes are printed
void printPost(nodeForTree* head){
  if(head == NULL){
    return;
  }
  printPost(head -> getLeft());
  printPost(head-> getRight());
  cout << head -> getVal();  
}

//follows the node left right pattern until all nodes are printed
void printPre(nodeForTree* head){
  if(head == NULL){
    return;
  }
  cout << head -> getVal();
  printPre(head-> getLeft());
  printPre(head-> getRight());

}
