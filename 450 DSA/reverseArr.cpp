#include <iostream>
using namespace std;

//REVERSE ARRAY
void revArr(int arr[],int size){
  int start = 0;
  int last = size-1;
  while(start<=last){
    swap(arr[start],arr[last]);
    start = start + 2;
    last = last - 2;
  }
}

void printArr(int arr[], int size){
  for(int i=0; i< size; i++){
    cout << arr[i]<< " ";
  }
  cout << endl;
}

int main(){
  int arr[100];
  int size;
  cin >> size;
  for(int i=0; i< size; i++){
    cin >> arr[i];
  }
  revArr(arr,size);
  printArr(arr,size);
}