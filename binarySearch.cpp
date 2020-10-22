#include <iostream>
using namespace std;
void binarySearch(int*a,int first,int last,int value){
    int k = (first+last)/2;
    if(value == a[k]){
        cout<<"vi tri can tim la: "<<k+1;
        exit(0);
    }
    if(first==k&&value!=a[k]){
        cout<<"k tim thay";
        exit(0);
    }
    if(value<a[k]){
        binarySearch(a,first,k,value);
    }
    else{
        binarySearch(a,k+1,last,value);
    }

}
int main(){
    int a[] = {1,5,6,7,9,10,15,18,20,23,25,36,50,59};
    int n= sizeof(a)/sizeof(a[0]);
    int value;
    cin>>value;
    binarySearch(a,0,n-1,value);
    
}