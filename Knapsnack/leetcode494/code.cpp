/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector> 

using namespace std ; 

int findTargetSumWays(vector<int> &nums , int target) {
    int sum = 0 ;
    int n = nums.size();
    for(int i = 0;i<n ; i++){
        sum += nums[i] ; 
    }
    if (target > sum || target < -sum) {
        return 0 ; 
    }
    int OFFSET = sum ; 
    vector <vector<int>> dp(n+1, vector<int>(2*sum+1,0)) ; 
    
    dp[0][OFFSET] = 1 ; 
    for (int i = 0 ; i<n ; i++){
        for(int s = -sum ; s<= sum ; s++){
            if (dp[i][s + OFFSET] == 0) 
                continue ;
            dp[i+1][s+OFFSET + nums[i]] += dp[i][s+OFFSET] ; 
            dp[i+1][s+OFFSET - nums[i]] += dp[i][s+OFFSET] ; 
        }
    }
    return dp[n][target+OFFSET];
}

int main()
{   
    vector <int> nums = {1,1,1,1,1} ; 
    int target = 3 ;
    int res = findTargetSumWays(nums , target) ; 
    cout << res ; 

    return 0;
}
