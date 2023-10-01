#include<iostream>
using namespace std;
int main(){
	int a,b,re;
	char op;
	cout<<"***BASIC CALCULATOR*** \n";
	cout<<"Enter the first integer:";
	cin>>a;
	cout<<"Enter the second integer:";
	cin>>b;
	cout<<"Enter the operator (+,-,/,*):";
	cin>>op;
	switch(op){
		case '+':
			cout<<a+b;
			break;
		case '-':
			cout<<a-b;
			break;
		case '*':
			cout<<a*b;
			break;
		case '/':
			cout<<a/b;
			break;
	}
}
