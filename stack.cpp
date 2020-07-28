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
int main(){

    char *expre="(a*b)+)b+a)";
    cout<<isBalanced(expre)<<" ** ";

    }
