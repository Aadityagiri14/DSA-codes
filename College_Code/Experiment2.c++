#include<iostream>
using namespace std;
void swap(int &a, int&b){
    int temp=a;
    a=b;
    b=temp;
}
int part(int arr[],int low, int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low; j<=high-1;j++){
        if (arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quicksort(int arr[], int low, int high){
    if(low<high){
        int pivot= part(arr, low,high);
        quicksort(arr,low,pivot-1);
        quicksort(arr,pivot+1,high);
    }
}
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements in the array:";
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    // int arr[]={5,7,8,1,3,6,4,2};
    //int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Unsorted array:\n";
    for(int i=0; i<n;i++){
        cout<<arr[i]<<"\t";
    }
    quicksort(arr,0,n - 1);
    cout<<"\nSorted array:\n";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}