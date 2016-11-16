#include <iostream>

using namespace std;



//template<int N>
void comparison_sort(int a[], int N){
  int count[N];
  int sorted[N];
  for(int i=0;i<N;i++)
    count[i] = 0;

  for(int i=0; i<N-1; i++){
    for(int j=i+1; j<N; j++){
      if(a[i]<a[j])
        count[j]++;
      else
        count[i]++;
    }
  }
  for(int i=0; i<N; i++)
    sorted[count[i]] = a[i];

  for(int i=0; i<N; i++)
    a[i] = sorted[i];

}


void distributed_sort(int a[], int N, int l, int u){
  cout<<1;
  int freq[u-l];
  for(int i=0;i<(u-l);i++)
    freq[i]=0;
  cout<<1;
  for(int i=0;i<N;i++)
    freq[a[i]-l]++;

  for(int i=1;i<u-l;i++)
    freq[i] += freq[i-1];

  int sorted[N];
cout<<2;

  for(int i=N-1;i>=0;i--){
    int j = a[i]-l;
    sorted[freq[j]-1] = a[i];
    freq[j]--;
  }

  for(int i=0;i<N;i++)
    a[i] = sorted[i];

}

int main(){
  int a[5] = {5,2,1,4,3};
  //comparison_sort(a, 5);
  distributed_sort(a,5,1,5);
  for(int i=0; i<5; i++)
    cout<<a[i]<<"\t";
  cout<<endl;
  return 0;
}
