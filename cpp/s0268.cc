class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int sum = 0;
    for (int &n: nums) {
      sum += n;
    }
    int n = nums.size();
    return (n * (0 + (n+1)) / 2) - sum;
  }
};

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < nums.size() + 1; i++) {
      result ^= i;
    }
    for (int &n: nums) {
      result ^= n;
    }
    return result;
  }
};
