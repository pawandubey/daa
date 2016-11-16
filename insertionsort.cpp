#include <iostream>

using namespace std;

void insertion(int a[], int n){
  for(int i=1;i<n;i++){
    int key = a[i];
    int j;
    for(j=i; a[j]>=key;j--){
      a[j] = a[j-1];
    }
    a[j+1] = key;
  }
}

int main(){
  int a[5] = {4,3,5,1,2};
  insertion(a,5);
  for(int i=0; i<5; i++)
    cout<<a[i]<<"\t";
  cout<<endl;
  return 0;
}
