#include<bits/stdc++.h>
using namespace std;

int minSteps(int n){
  vector<int>dp(n+2,0);
  dp[1] = 0 ; 
  for(int i = 2 ; i <= n ;i++){
    dp[i] = i ; 
    for(int j = 2 ; j*j <= i ; j++){
      if(i%j == 0){
        dp[i] = min(dp[i] , dp[i/j] + j) ; 
        dp[i] = min(dp[i] , dp[j] + i/j );
      }
    }
  }
  return dp[n] ; 
}



signed main(){
  int n ; 
  cin >> n ; 
  cout << minSteps(n) ; 
}
