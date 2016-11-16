#include <iostream>

using namespace std;

int partition(int* a, int pivot, int l, int h){
  int i = l;
  int j = h;

  while(i<j){
    while(a[i]<a[pivot]) i++;
    while(a[j]>a[pivot]) j--;
    if(i>=j)
      break;
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }
  int temp = a[j];
  a[j] = a[pivot];
  a[pivot] = temp;
  return j;
}

void quicksort(int* a, int l, int h){
  if(l<h){
    int p = partition(a,l,l,h);
    quicksort(a,l,p-1);
    quicksort(a,p+1,h);
  }
}

int main(){
  int a[5] = {5,3,1,4,2};
  quicksort(a,0,4);
  for(int i=0; i<5; i++)
    cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}
