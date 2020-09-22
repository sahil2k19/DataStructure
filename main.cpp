#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* next;
};

Node* head=NULL;

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

void push(int data){
  Node* NewNode = new Node();
  NewNode->next = head;
  NewNode->data = data;
  head = NewNode;

}



void display(){
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp= temp->next;
  }
  cout<<"Null"<<endl;
}


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
    cout<<"Galat hai";
  }
  NewNode->next = temp->next;
  temp->next =  NewNode;

}



int main(){
  for(int i = 1; i<=6; ++i){
    append(i);
  }
  InsertAfter(7,8);
  display();
}