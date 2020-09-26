#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node *next, *prev;
};

Node* head = NULL; 

// adding node to list;
void append(int data)
{

  Node* Newnode = new Node();
  Node* temp = head;

  Newnode->data = data; 
  Newnode->next = NULL;

  if(head== NULL)
  {
    head = Newnode;
    Newnode->prev = NULL;
    return;
  }
  while(temp->next!=NULL)
  {
    temp = temp->next;
  }
  Newnode->prev = temp;
  temp->next = Newnode;
  // temp = Newnode;

}

// display list;
void display(){
  Node* temp = head;
  if(head==NULL)
    cout<<"NO head Found";
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
  }
}


int main(){
  for(int i=1; i<12; ++i){
    append(i);
  }
  display();
}












