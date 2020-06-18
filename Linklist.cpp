#include <stdio.h>
#include <iostream>
#include <array>
using namespace std;

struct node{
    int data;
    struct node *next;
}*first=NULL;

void create(int A[],int n){
    int i;
    struct node *t,*last;
    first=new node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=new node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }
}

void display(struct node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";

}
int  count(struct node *p){
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}

void search(struct node *s,int key){
    struct node *prev=NULL;
    while(s){
        if(s!=NULL){
            if(s->data==key)
                {cout<<"It is  found"<<endl;
                prev->next=s->next;
                s->next=first;
                first=s;
                
                display(first);
                break;
                }

                
       
        else
        {   
            prev=s;
            s=s->next;
            
        }
        
    }
}
}

void reverse(struct node *q){
    struct node *r=NULL;
    struct node *temp=NULL;
    struct node *end=NULL;
    end=q;
    r=q->next;
    
    
    while(r!=NULL){
        temp=r->next;
        r->next=q;
        q=r;
        r=temp;
    }
    end->next=NULL;
    display(q);
    
}

void rreverse(struct node *q,struct node *p){
    if (p!=NULL){
         rreverse(p,p->next);
         p->next=q;
     }
     else{
         first=q;
     }

    
}
int main(){

int A[]={3,5,7,10,15};
create(A,5);
//display(first);

// search(first,15);
//reverse(first);
// rreverse(NULL,first);
// display(first);
return 0;
}



