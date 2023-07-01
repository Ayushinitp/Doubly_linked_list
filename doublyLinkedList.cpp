#include <iostream>
#include <stdio.h>
using namespace std;
struct node{
    node *prev;
    int data;
    node *next;
};
class dll{
private:
node *start;
public: 
dll();
void insert_at_beg(int);
void insert_at_last(int);
void insert_at_position(int, int);
void show();
int count();
void del_at_beg();
void del_at_last();
void del_at_position(int);
};

dll::dll(){
    start=NULL;
}

void dll::insert_at_beg(int data){
    node *n=new node;
     n->data=data;
     n->prev=NULL;
     if(start==NULL){
        start=n;
        n->next=NULL;
     }
     else
    {
        n->next=start;
        start->prev=n;
        start=n;
    }
}

void dll::insert_at_last(int data){
    node *n=new node;
    n->data=data;
    n->next=NULL;
    if(start==NULL){
         start=n;
        n->next=NULL;
    }
    else
    {
        node *temp;
        temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        n->prev=temp;
        temp->next=n;
    }
}

void dll::insert_at_position(int data, int position){
     node *temp;
        temp=start;
        node *n=new node;
        n->data=data;
        int i=1;
        while(i<position-1){
            temp=temp->next;
            i++;
        }
        n->prev=temp;
        n->next=temp->next;
        temp->next->prev=n;
        temp->next=n;
}

void dll::show(){
    node *temp;
    temp=start;
    cout<<"Elements in linked list are "<<endl;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}

int dll::count(){
    int count=1;
    node *temp;
    temp=start;
    while(temp->next!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void dll::del_at_beg(){
    if(start==NULL){
        cout<<"deletion is not possible";
    }
    else
    {
        node *temp;
        temp=start;
        start=temp->next;
        temp->next->prev=NULL;
        delete temp;
    }
}

void dll::del_at_last(){
    if(start==NULL){
        cout<<"Deletion is not possible"<<endl;

    }
    if(start->next==NULL){
        delete start;
        start=NULL;
        cout<<"List is empty after this deletion"<<endl;
    }
    else
    {
        node *temp;
        temp=start;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
}

void dll::del_at_position(int position){
    int i=1;
    node *temp, *temp1;
    temp=start;
    
    while(i<position-1){
        temp=temp->next;
        temp1=temp->next;
        i++;
    }
    temp->next=temp1->next;
    temp1->next->prev=temp;
    delete temp1;
}
int main(){
    dll obj1;
    obj1.insert_at_beg(50);
    obj1.insert_at_beg(40);
    obj1.insert_at_last(60);
    obj1.insert_at_last(70);
    obj1.insert_at_last(80);
   
  
    obj1.show();
    return 0;
}