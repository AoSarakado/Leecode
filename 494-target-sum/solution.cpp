// 0 ms | 12.3 MB
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin() , nums.end() , 0);

        if(abs(target) > sum || (target + sum) %2 !=0)return 0;
        
        int bag = (target + sum) / 2;
        
        vector<int> dp(bag+1 , 0);
        dp[0]=1;

        for(auto num : nums)
            for(int i =bag; i>=num;i--)
                dp[i] +=dp[i-num];

        return dp[bag];
    }
};