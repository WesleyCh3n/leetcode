class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size() + 1, 0);
    dp[nums.size()] = 1;
    int max_len = 1;
    for (int i = nums.size() - 1; i >= 0 ; i--) {
      int tmp_len = 0;
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[j] > nums[i]) {
          tmp_len = max(tmp_len, dp[j]);
        }
      }
      dp[i] = 1 + tmp_len;
      max_len = max(max_len, dp[i]);
    }
    return max_len;
  }
};
