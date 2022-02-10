#include <iostream>
#include <cstring>
#include <cstdlib>

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
int countQueue(Node* head);
int checkImp(char toCheck);
Node* remove(Node* &head);
void add(Node* &head, Node* &tail, Node* toAdd);
void printQueue(Node* head);
void popAdd(int newImp, int stackImp, Node* &sHead, Node* &qHead, Node* &qTail);
void toTree(Node* head);

int main(){
  char input[80];
  cout << "please enter you math equation, make sure that there are no spaces" << endl;
  cin >> input;
  cin.get();
  infixToPostfix(input);
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
        importance = -1;
      }
      else if(toCheck == ')'){
        importance = 4;
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
      printStack(sHead);
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
        printQueue(qHead);
      }else{
        int newImp = checkImp(op); 
        int stackImp = checkImp(sHead -> dataVal);
        cout<<"newImp: " << newImp << endl;
        cout << "stackImp: " << stackImp << endl;
        
        if(newImp == 4){
           cout << "i am in 4 area " << endl;
          while(stackImp != -1){
            cout << "came into while " << endl;
            Node* removed = pop(sHead);
            add(qHead, qTail, removed);
            stackImp = checkImp(sHead -> dataVal);
          }
           cout << "came out while " << endl;
            Node* removed = pop(sHead);
            printStack(sHead);
            printQueue(qHead);
        }
 
         else if(newImp > stackImp){
           if(newImp != 4){
          Node* n = new Node;
          n -> dataVal = op;
          push(sHead, n);
          printStack(sHead);
          printQueue(qHead);
          }
        } else if(newImp <= stackImp && newImp != 4){
             if(newImp == -1){
             Node* n = new Node;
             n -> dataVal = op;
             push(sHead, n);
            printStack(sHead);
            printQueue(qHead);
            }else{
            popAdd(newImp, stackImp, sHead, qHead, qTail);
            Node* n = new Node;
            n -> dataVal = op;
            push(sHead, n);
            printStack(sHead);
            printQueue(qHead);
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
  printStack(sHead);
  printQueue(qHead);
  char* toReturn = new char[countQueue(qHead)];
  for(int z = 0; z<3; z++){
    strcpy(toReturn, "jji");
    cout << "hi" << endl;
  }
  cout << "toR: " << toReturn << endl;
}


void popAdd(int newImp, int stackImp, Node* &sHead, Node* &qHead, Node* &qTail){
  if(newImp <= stackImp){
            cout << "hi, i'm pop adding" << endl;
            Node* removed = pop(sHead);
            add(qHead, qTail, removed);
            if(sHead == NULL){
              stackImp = 0;
            }else{
              stackImp = checkImp(sHead -> dataVal);
            }
            cout << "New Imp: " << newImp << endl;
            cout << "Check Imp: " << stackImp << endl;
            popAdd(newImp, stackImp, sHead, qHead, qTail);
  }
  else{
    return;
  }
}

void toTree(Node* head){
  
}
