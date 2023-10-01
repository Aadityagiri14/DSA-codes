/*Design, Develop and implement a menu deriven program in C/C++ for the following array operations.
a. Creating an array of N elemtn
b. Display of Array elements with suitable headings
c.Inserting an element(ELEM) at given valid position (POS)
d.Deleting an element at given valid position
e.Exit*/
#include<iostream>
using namespace std;
int size, A[100];
void create(){
	int i;
	cout<<"Enter the size of your array:";
	cin>>size;
	cout<<"Enter the elements in the array:\n";
	for(i=0;i<size;i++){
		cin>>A[i];
	}
}
void display(){
	int i;
	cout<< "Array: \t";
	for(i=0;i<size;i++){
		cout<<A[i]<<"\t";
	}
}
void insert(){
	int pos,ele,i;
	cout<<"Enter the element to be inserted:";
	cin>>ele;
	cout<<"Enter the position:";
	cin>>pos;
	for(i=(size-1);i>=pos;i--){
		A[i+1]=A[i];
	}
	A[pos]=ele;
	display();
}
void deletes(){
	int pos,i;
	cout<<"Enter the position of the element to be deleted:";
	cin>>pos;
	for(i=pos;i<size;i++){
		A[i]=A[i+1];
	}
	display();
}
int main(){
	Menu:
		char choice;
		cout<<"\n --------------------------------------------------- ";
		cout<<"\n*** Options:***\n";
		cout<<"A.  Creating an array of N element.\n";
		cout<<"B.  Displaying of array elements with suitable headings.\n";
		cout<<"C.  Inserting an element at given valid position POS.\n";
		cout<<"D.  Deleting an element at given valid position.\n";
		cout<<"E.  Exit \n";
		cout<<"--------------------------------------------------- \n Enter your choice (A,B,C,D,E):";
		cin>>choice;
		switch(choice){
			case 'A':
				create();
				goto Menu;
				break;
			case 'B':
				display();
				goto Menu;
				break;
			case 'C':
				insert();
				goto Menu;
				break;
			case 'D':
				deletes();
				goto Menu;
				break;
			case 'E':
				cout<<"----Program Ended----";
				break;
		}
	
}

