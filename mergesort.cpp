#include <iostream>

using namespace std;

void merge(int* a, int l, int h){
  int m = (l + h)/2;
  int n1 = m-l+1;
  int n2 = h-m;
  int lef[n1];
  int righ[n2];

  for(int i=0; i<n1; i++)
    lef[i] = a[l+i];

  for(int i=0; i<n2; i++)
    righ[i] = a[i+m+1];

  int i=0, j=0;
  int k = l;
  while(i<(m-l+1) && j<(h-m)){
    if(lef[i] <= righ[j]){
      a[k] = lef[i++];
    }
    else{
      a[k] = righ[j++];
    }
    k++;
  }

  while(i<(m-l+1))
    a[k++] = lef[i++];

  while(j<(h-m))
    a[k++] = righ[j++];
}

void mergesort(int* a, int l, int h){
  if(l<h){
    int m = (l + h)/2;
    mergesort(a,l,m);
    mergesort(a,m+1,h);
    merge(a,l,h);
  }
}

int main(){
  int a[5] = {5,3,1,4,2};
  mergesort(a,0,4);
  for(int i=0; i<5; i++)
    cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}
