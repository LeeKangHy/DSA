class Solution {
public:
    int rob(vector<int>& nums) {
        int length = (int)nums.size();
        if(length == 0) return 0 ; 
        if(length == 1) return nums[0] ; 
        vector<int> dp(length+3) ; 
        dp[0] = nums[0] ;
        dp[1] = nums[0] > nums[1] ? nums[0] : nums[1] ; 
        
        for(int i = 2 ; i <length ; i++ ) {
            dp[i] = max(dp[i-2] + nums[i] , dp[i-1]);
        }
        return dp[length - 1] ; 
    }
};
