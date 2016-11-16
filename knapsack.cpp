#include <iostream>
#include <cmath>

using namespace std;

int knapsack(int W, int n, int wt[], int val[]){
  if(n==0 || W== 0)
    return 0;
  else{
    if(wt[n-1] > W)
      return knapsack(W, n-1, wt, val);
    else{
      return max(val[n-1] + knapsack(W-wt[n-1],n-1,wt,val), knapsack(W,n-1,wt,val));
    }
  }
}

int dynaKnapsack(int W, int n, int wt[], int val[]){
  int k[n+1][W+1];

  for(int i=0; i<=n; i++){
    for(int w=0; w<=W; w++){
      if(i==0||w==0)
        k[i][w] = 0;
      else if(wt[i-1] <= w)
        k[i][w] = max(val[i-1] + k[i-1][w-wt[i-1]], k[i-1][w]);
      else
        k[i][w] = k[i-1][w];
    }
  }
  return k[n][W];
}

int main(){
  int val[] = {60,100,120};
  int wt[] = {10,20,30};
  int W= 50;
  cout<<dynaKnapsack(W,3,wt,val);
  return 0;
}
