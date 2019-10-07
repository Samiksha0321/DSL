//============================================================================
// Name        : Proj7.cpp
// Author      : 21153
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class stackexp{
    int top;
    char stk[10];
public:
    stackexp(){
     top=-1;
    }
    void push(char);
    char pop();
    int isfull();
    int isempty();
};

void stackexp::push(char x){
    top=top+1;
    stk[top]=x;
}

char stackexp::pop(){
    char s;
    s=stk[top];
    top=top-1;
    return s;
}

int stackexp::isfull(){
    if(top==10)
        return 1;
    else
        return 0;
}

int stackexp::isempty(){
    if(top==-1)
        return 1;
    else
        return 0;
}

int main(){
    stackexp s1;
    char exp[20],ch;
    int i=0;
    cout <<"\nEnter the expression :  ";
    cin >> exp;
    if((exp[0]==')')||(exp[0]==']')||(exp[0]=='}')){
        cout<<"\n Invalid Expression.....\n";
        return 0;
    }
    else{
        while(exp[i]!='\0'){
            ch=exp[i];
            switch(ch){
            	case'(':s1.push(ch);
            			break;
            	case'[':s1.push(ch);
            			break;
            	case'{':s1.push(ch);
            			break;
            	case')':s1.pop();
            			break;
            	case']':s1.pop();
            			break;
            	case'}':s1.pop();
            			break;
            }
            i=i+1;
        }
    }
    if(s1.isempty()){
        cout<<"\nExpression is well parenthesized.\n";
    }
    else{
        cout<<"\nExpression isn't well parenthesized.\n";
    }
    return 0;
}
