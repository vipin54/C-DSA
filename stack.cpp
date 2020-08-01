#include<bits/stdc++.h>
using namespace std;

int isBalanced(char *expre){
    stack <char> s;
    for(int i=0;expre[i]!='\0';i++){
        if(expre[i]=='(') s.push(expre[i]);
        
        else if(expre[i]==')')
                {
                    if(s.empty())
                    return 0;
                    s.pop();
                }

    }
    if(s.empty()) return 1;
    else return 0;
    
}
int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')'){
        return 0;
    }
    return 1;
}

int pre(char x){
    if(x=='+'|| x=='-')
        return 1;
    else if (x=='*'|| x=='/') return 2;
    else return 0;
}
char* infixtopostfix(char *expre){
    stack <char> infix;
    int i=0,j=0;
    char *postfix=new char[infix.size()+1];

    while(expre[i]!='\0'){
        if(isOperand(expre[i]))
            postfix[j++]=expre[i++];
        else{
            if(!infix.empty()){
            if(pre(expre[i]>pre(infix.top())))
            infix.push(expre[i++]);
            else
            {
                postfix[j++]=infix.top();
                infix.pop();
            }
            
            }
            else infix.push(expre[i++]);
        }
    }
    while(!infix.empty()) {
        postfix[j++]=infix.top();
        infix.pop();
}
postfix[j]='\0'; 
return postfix;
}

int outPrecedence(char x){
    if (x == '+' || x == '-'){
        return 1;
    } else if (x == '*' || x == '/'){
        return 3;
    } else if (x == '^'){
        return 6;
    } else if (x == '('){
        return 7;
    } else if (x == ')'){
        return 0;
    }
    return -1;
}

int inPrecedence(char x){
    if (x == '+' || x == '-'){
        return 2;
    } else if (x == '*' || x == '/'){
        return 4;
    } else if (x == '^'){
        return 5;
    } else if (x == '('){
        return 0;
    }
    return -1;
}

char *convert(char* infix){
    stack <char> stk;
    char* postfix=new char[strlen(infix)+1];
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(stk.empty()|| outPrecedence(infix[i])> inPrecedence(stk.top())){
                stk.push(infix[i++]);
            }else if(outPrecedence(infix[i]) == inPrecedence(stk.top())){
                    stk.pop();
            }
            else{
                postfix[j++]=stk.top();
                stk.pop();
            }
        }
    }
    while(!stk.empty() && stk.top()!=')'){
        postfix[j++] = stk.top();
        stk.pop();
    }
    postfix[j]='\0';
    return postfix;
}

int main(){

    char expre[]="((a+b)*c)-d^e^f";
    // cout<<isBalanced(expre)<<" ** ";
    //cout<<infixtopostfix(expre);
    cout<<convert(expre)<<endl;
    
    }

