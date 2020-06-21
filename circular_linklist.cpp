#include <stdio.h>
#include <iostream>
#include <array>
using namespace std;

struct node
{
    public:
     int data;
     node *next;
}*head=NULL;

void create(int A[],int n){
    int i;
    struct node *t,*last;
    head=new node;
    head->data=A[0];
    head->next=head;
    last=head;
    for(i=1;i<n;i++){
        t=new node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    } 
}

void display(struct node *h){
    do{
        cout<<h->data<<" ";
        h=h->next;
    }while(head!=h);
    cout<<"\n";
}

int main(){
    int A[]={1,2,3,4,5};
    create(A,5);
    display(head);
}