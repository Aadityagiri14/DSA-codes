#include<iostream>
using namespace std;
int main(){
	struct student{
		int age;
		char name[30], section[10], group[2];
	}st[10];
	int i;
	for(i=0;i<10;i++){
		cout<<"Enter Name:";
		cin>>st[i].name;
		cout<<"Enter Age:";
		cin>>st[i].age;
		cout<<"Enter Section:";
		cin>>st[i].section;
		cout<<"Enter Group:";
		cin>>st[i].group;
	}
	for(i=0;i<10;i++){
		cout<<"\n Name : \t"<<st[i].name;
		cout<<"\n Age: \t"<<st[i].age;
		cout<<"\n Section: \t"<<st[i].section;
		cout<<"\n Group: \t"<<st[i].group;
	}
}
