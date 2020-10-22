#include <iostream>

using namespace std;

typedef struct{
    int left;
    int right;
    int sum;
}max_subarray_tuple;



max_subarray_tuple find_max_crossing_subarray(int A[], int low, int mid, int high){
    max_subarray_tuple ret = {0,0,0};
    int left_sum = INT16_MIN;
    int right_sum = INT32_MIN;
    int sum = 0;

    for(int i=mid-1;i>=low;i--){
        sum +=A[i];
        if(sum>left_sum){
            left_sum = sum;
            ret.left = i;
        }
    }
    sum=0;

    for(int i=mid;i<high;i++){
        sum+=A[i];
        if(sum>right_sum){
            right_sum=sum;
            ret.right =i;
        }
    }

    ret.sum = left_sum +right_sum;
    return ret;
}

max_subarray_tuple find_max_subarray(int A[], int low, int high){
    if(high == low +1){
        max_subarray_tuple ret ={low,high,A[low]};
        return ret;
    }
    else{
        int mid = (low+high)/2;
        max_subarray_tuple left = find_max_subarray(A,low,mid);
        max_subarray_tuple right = find_max_subarray(A,mid,high);
        max_subarray_tuple cross = find_max_crossing_subarray(A,low,mid,high);

        if (left.sum >= right.sum && left.sum >= cross.sum)
            return left;
        else if (right.sum >= left.sum && right.sum >= cross.sum)
            return right;
        else
            return cross;

    }
}


int main(){
    int arr[] = {-1,-2,-3,-5,-7,-10,-50,-30,-20,-15,-36};
    int n= sizeof(arr)/sizeof(arr[0]);

    max_subarray_tuple info = find_max_subarray(arr,0,n);
    cout<<info.left <<" "<<info.right<<" "<<info.sum;

}