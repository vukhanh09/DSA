#include <iostream>
#include <ctime>
#include <algorithm>
#include<vector>
#define max 10000000

using namespace std;

void merge(int *a,int first,int p,int last){
    int n1=p-first+1;
    int n2=last-p;
    int *L = new int[n1];
    int *R =new int[n2];

    for(int i=0;i<n1;i++){
        L[i] = a[first+i];
    }
    for(int i=0;i<n2;i++){
        R[i] = a[p+1+i];
    }
    int i=0,j=0;
    int k=first;
    while(i < n1 && j<n2){
        if(L[i]>R[j]){
            a[k]=R[j];
            j++;k++;
        }
        else{
            a[k]=L[i];
            i++;k++;
        }
    }
    while (i<n1)
    {
        a[k]=L[i];
        i++,k++;
    }
    while(j<n2){
        a[k]=R[j];
        j++,k++;
    }
    delete []L;
    delete []R;
}

void merge_sort(int *a,int first,int last){
    if(first<last){
        int p = (first+last)/2;
        merge_sort(a,first,p);
        merge_sort(a,p+1,last);
        merge(a,first,p,last);
    }

}

int main(){
    srand(time(NULL));
    int *a = new int[max];
    for (int i =0;i<max;i++){
        int res = rand()%max+1;
        a[i]=res;
        cout<<a[i]<<"   ";
    }
    merge_sort(a,0,max-1);
    cout<<"\nsau khi sx\n";
    for (int i =0;i<max;i++){
        cout<<a[i]<<"   ";
    }
    
}