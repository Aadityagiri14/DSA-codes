/*Design, Develop and implement a program in C for converting an infix expression to postfix expression.
Program should support for both parenthesized and free parenthesized expression with the operators:
+,-,*,/,%,^ and alphanumeric operands*/
#include<iostream>
char Stack[20], infix[20], postfix[20], ch;
int k=0,j=0;
using namespace std;
int pre(char ch){
	switch(ch){
		case '(':
			return 6;
            break;
        case ')':
			return 6;
            break;
		case '*':
            return 3;
            break;
		case '/':
            return 3;
            break;
		case '^':
            return 5;
            break;
        case '%':
            return 4;
            break;
        case '-':
            return 2;
            break;
        case '+':
            return 2;
            break;
	}
}
void PUSH(char ch){
    Stack[k++]=ch;
}
char POP(){
    return (Stack[k]);
    k--;
}
int main(){
	cout<<"Enter the String:";
    cin>>infix;
    PUSH('#');
    ch=infix[k++];
    while(ch!='\0'){
        if(ch=='('){
            PUSH('(');
        }
        else if(isalnum(ch)){
            postfix[j++]=ch;
        }
        else if(ch==')'){
            while(ch!='('){
                postfix[j++]=POP();
            }
            POP();
        }
        else if(pre(Stack[k]>=pre(ch))){
            postfix[j++]=POP();
        }
        else{
    	cout<<"Not performed";
		}
        }
    while(Stack[k]!='#'){
        postfix[j++]=POP();
    }
    cout<<"Postfix Notation: "<< postfix;
}