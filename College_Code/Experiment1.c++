#include <iostream>
using namespace std;
int bSearch(int arr[], int n, int x) {
    int f=0, l=n-1;
    while(f<=l) {
        int m=f+(l-f) / 2;
        if (arr[m]==x) {
            return m;
        } else if (arr[m] < x) {
            f=m+1;
        } else {
            l=m-1;
        }
    }return -1;
}
int main() {
    // Write C++ code here
    int temp, b, A[8]={5,7,8,1,3,6,4,2};
    for(int i=0;i<8;i++){
        for(int j=0;j<8-i-1;j++){
            if(A[j]>A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
    cout<<"The sorted arry is: \n";
    for(int i=0;i<8;i++){
        cout<<A[i]<<"\t";
    }
    cout<<"\n\nEnter the element to be found:";
    cin>>b;
    int index=bSearch(A, 8, b);
    if(index==-1){
        cout<<"Element not found!!!";
    }
    else{
        cout<<"The element was found at index:"<<index;
    }
    return 0;
}