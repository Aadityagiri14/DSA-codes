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
	if(op == '+'){
		re=a+b;
		cout<<"The result of a+b is: "<<re;
	}
	else if(op== '-'){
		re=a-b;
		cout<<"The result of a-b is:" << re;
	}
	else if (op== '*'){
		re=a*b;
		cout<<"The result of a*b is: "<<re;
	}
	else if(op== '/'){
		re=a/b;
		cout<<"The result of a/b is:"<<re;
	}
	else{
		cout<<"Error!!!";
	}
}
