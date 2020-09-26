#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* next;
};

Node* head=NULL;

// appending the node ; 
void append(int data){
  Node* NewNode = new Node();
  Node* temp = head;
  NewNode->data = data;
  NewNode->next = NULL;
  if(head==NULL){
    head = NewNode;
    return;
  }
  while(temp->next!=NULL){
    temp = temp->next;
  }
  temp->next = NewNode;

}
// pushing the node ;
void push(int data){
  Node* NewNode = new Node();
  NewNode->next = head;
  NewNode->data = data;
  head = NewNode;

}


//define globally(wrong) , so that if anything wrong then display show error; 
int wrong=0; 


// insert after the link list ;
void InsertAfter(int p , int data){
  Node* NewNode = new Node();
  Node* temp = head;
  NewNode->data = data;
  if(p<1){
    NewNode->next = head;
    head = NewNode;
    return;
  }
  for(int i=2; i<=p; ++i){
    temp = temp->next;
  }
  if(temp==NULL){
    wrong++;
    return;
  }
  NewNode->next = temp->next;
  temp->next =  NewNode;

}

// deleting the node;
void DeleteNode(int p){
  Node* temp = head;
  if(p==1){
    head = temp->next;
  }
  for(int i=2; i<p; ++i){
    temp = temp->next;
  }
  temp->next = temp->next->next;
}

// printing the node;
void display(){
  Node* temp = head;
  if(wrong==0){

    while(temp!=NULL){
      cout<<temp->data<<"->";
      temp= temp->next;
    }
    cout<<"Null"<<endl;
  }
  else
    cout<<"something wrong"<<endl;
}


// finding the legth of linklist ;
void count(){
  Node* temp = head;
  int count=0;
  while(temp!=NULL){
    temp = temp->next;
    count++;
  }
  cout<<count<<endl;
}


// reverse the linklist iterative method;

void reverseLinkList(){
  
  Node *PrevNode , *CurrentNode, *NextNode;
  PrevNode = NULL;
  CurrentNode = NextNode = head;
  while(NextNode!=NULL){
    NextNode = NextNode->next;
    CurrentNode->next = PrevNode;
    PrevNode = CurrentNode;
    CurrentNode = NextNode; 
  }
  head = PrevNode;
}


int main(){
  for(int i = 1; i<=10; ++i){
    append(i);
  }
  // InsertAfter(6,8);
  // DeleteNode(1);
  display();
  reverseLinkList();
  display();
  // count();
}