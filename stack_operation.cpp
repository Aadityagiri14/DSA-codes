/*Design, Develop and implement a menu driven program in C for following operations on stack of integer Array implementation of stack with maximum size Max.
a. Push a element on to a stack 
b. Pop an element from a stack.
c. Demonstrate how stack can used to check palindrome
d. Demonstrate overflow and underflow situation on stack
e. display of stack 
f. exit*/
#include<iostream>
using namespace std;
int MAX=10, top=0, ele, STACK[10];
void display(){
	if(top==0){
		cout<<"\n The stack is empty!";
	}else{
		cout<<"\n Stack: \t";
		for(int i=top;i>0;i--){
			cout<<STACK[i]<<"\t";
		}
	}
}void Push(){
	if(top==MAX)	
		cout<<"Overflow!!";
	else{
		top++;
		cout<<"Enter the element you want to PUSH:";
		cin>>ele;
		STACK[top]=ele;
		display();
	}
}	
void POP(){
	if(top==0)
		cout<<"Underflow!!";
	else{
		cout<<"The element removed is:"<<STACK[top];
		top--;
		display();
	}
}
void pal_check(){
	int count=0;
	for(int i=1; i<=top;i++){
		if(STACK[i]==STACK[top-(i-1)]){
			count++;
		}
	}
	if(count==top)
		cout<<"The stack is a palindrome";
	else
		cout<<"The stack is not a palindrome";
}
int main(){
	char choice;
	menu:
		cout<<"\n ___________________________________________________________";
		cout<<"\n a. Push a element on to a stack.";
		cout<<"\n b. Pop an element from a stack.";
		cout<<"\n c. Demonstrate how stack can used to check palindrome.";
		cout<<"\n d. display of stack.";
		cout<<"\n e. exit";
		cout<<"\n Enter your choice (a,b,c,d,e):";
		cin>>choice;
		switch(choice){
			case 'a':
				Push();
				goto menu;
			case 'b':
				POP();
				goto menu;
			case 'c':
				pal_check();
				goto menu;
			case 'd':
				display();
				goto menu;
			case 'e':
				cout<<"Succesfully exited from the program.";
				break;
		}
		return 0;
}

