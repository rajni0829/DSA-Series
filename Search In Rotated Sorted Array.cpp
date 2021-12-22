#include <iostream>
#include<vector>
using namespace std;


int binarySearch(vector<int>& arr,int s,int e,int k){
  int st = 0;
  int end = e;
  int mid = st + (end-st)/2;

  while(st<=end){
    if(arr[mid] == k){
      return mid;
    }
    else if(arr[mid] > k){
      end = mid - 1;
    }else{
      st = mid + 1;
    }
    mid = st + (end-st)/2;
  }
  return -1;
}

//Finding Pivot
int findPivot(vector<int>& arr,int n){
  int s = 0;
  int e = n-1;
  int mid = s + (e-s)/2;
  while(s<e){
    if(arr[mid] >= arr[0]){
      s = mid +1;
    }else{
      e = mid;
    }
    mid = s + (e-s)/2;
  }
  return s;
}


//DRIVER CODE
int main() {
  vector<int> arr{9,8,1,2,3,4};
  int n = 6;
  int k = 3;  

  int pivot = findPivot(arr,n);
  if(k >= arr[pivot] && k<= arr[n-1]){
    return binarySearch(arr,pivot,n-1,k);
  }else{
    return binarySearch(arr,0,pivot-1,k);
  }
} 