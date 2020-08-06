#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node *lchild;
    Node *rchild;
    int data;
};

class Tree{
    private:
    Node *root;
    public:
    Tree();
    ~Tree();
    void CreateTree();
    void Preorder(Node *p);
    void Preorder() {Preorder(root);}
    void Postorder(Node *p);
    void Postorder() { Postorder(root); }
    void Inorder(Node *p);
    void Inorder() { Inorder(root); }
    void Levelorder(Node *p);
    void Levelorder() { Levelorder(root); }
    int height(Node *p);
    int height() { return height(root); }
};

Tree::Tree() {
    root = nullptr;
}
 
Tree::~Tree() {
    // TODO
}

void Tree::CreateTree(){
    Node *p,*t;
    int x;
    queue <Node *> q;
    root=new Node;
    cout<<"enter the root value"<<endl;
    cin>>x;
    
    root->data=x;
    root->lchild=root->rchild=nullptr;
    q.emplace(root);
    
    while(!q.empty()){
        p=q.front();
        q.pop();

        cout<<"enter the left child data of "<<p->data<<" :";
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=nullptr;
            p->lchild=t;
            q.emplace(t);
        }

        cout<<"enter the right child data of "<<p->data<<" :";
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=nullptr;
            p->rchild=t;
            q.emplace(t);
        }
    }
}

void Tree:: Preorder(Node *p){
    if(p){
        cout<<p->data<<", "<<flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree:: Inorder(Node *p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<", "<<flush;
        Inorder(p->rchild);
    }
}

void Tree:: Postorder(Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<", "<<flush;
    }
}

void Tree::Levelorder(Node *p){
    queue <Node *> que;
    Node *r=p;
    Node *temp;
    cout<<r->data<<", "<<flush;
    que.emplace(r);
    while (!que.empty()){
        temp=que.front();
        que.pop();
        if(temp->lchild){
            cout<<temp->lchild->data<<", "<<flush;
            que.emplace(temp->lchild);
        }
        if(temp->rchild){
           cout<<temp->rchild->data<<", "<<flush; 
           que.emplace(temp->rchild);
        }
    }   
}

int Tree::height(Node *p){
int l = 0;
    int r = 0;
    if (p == nullptr){
        return 0;
    }
 
    l = height(p->lchild);
    r = height(p->rchild);
 
    if (l > r){
        return l + 1;
    } else {
        return r + 1;
    }
}

int main(){
    Tree bt;
    bt.CreateTree();
    cout<<endl;

    cout << "Preorder: " << flush;
    bt.Preorder();
    cout << endl;

    cout << "Inorder: " << flush;
    bt.Inorder();
    cout << endl;
 
    cout << "Postorder: " << flush;
    bt.Postorder();
    cout << endl;
 
    cout << "Levelorder: " << flush;
    bt.Levelorder();
    cout << endl;
 
    cout << "Height: " << bt.height() << endl;
    return 0;
}



