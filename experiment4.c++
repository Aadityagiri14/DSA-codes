#include<iostream>
using namespace std;
char Stack[20], infix[20], postfix[20], ch;
int k = 0, j = 0;
int pre(char ch) {
    switch(ch){
        case '(':
        case ')':
            return 6;
        case '*':
        case '/':
        case '%':
            return 3;
        case '^':
            return 5;
        case '-':
        case '+':
            return 2;
    }
    return 0;
}
void PUSH(char ch) {
    Stack[++k]=ch;
}
char POP() {
    return Stack[k--];
}
int main() {
    cout<<"Enter the String:";
    cin>> infix;

    PUSH('#');
    for (int i=0; infix[i]!='\0'; i++) {
        ch=infix[i];
        if(ch=='(') {
            PUSH('(');
        }
		else if(isalnum(ch)){
            postfix[j++] = ch;
        }
		else if(ch==')'){
            while(Stack[k]!='(') {
                postfix[j++]=POP();
            }
            POP();
        }
		else {
            while(pre(Stack[k])>=pre(ch)){
                postfix[j++]=POP();
            }
            PUSH(ch);
        }
    }
    while (Stack[k]!='#') {
        postfix[j++] = POP();
    }
    postfix[j]='\0';
    cout<<"Postfix Notation: "<< postfix;
    return 0;
}