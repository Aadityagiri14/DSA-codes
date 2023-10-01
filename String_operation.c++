#include<iostream>
using namespace std;
char STR[20],PAT[20],REP[20],RES[20];
int i=0,m=0,j=0,k,flag=0,c=0;

void match(){
    while(STR[c]!='\0') {
        if (STR[m]==PAT[i]) {
            i++;
            m++;
            if(PAT[i]=='\0') {
                for(k=0;REP[k]!='\0';k++,j++){
                    RES[j]=REP[k];
                }
                i=0;
                flag=1;
                c=m;
            }
        }
		else{
            RES[j]=STR[c];
            c++;
            j++;
            m=c;
            i=0;
        }
    }
    RES[j]='\0';
    if (flag == 0) {
        cout<<"Pattern not found in the main string."<<endl;
    } else {
        cout<<"Result: "<<RES<<endl;
    }
}
int main(){
	char len;
	int i=0;
	cout<<"Enter your main String:";
	cin>>STR;
	cout<<"Enter the pattern string:";
	cin>>PAT;
	cout<<"Enter the replace string:";
	cin>>REP;
	match();
	return 0;
}