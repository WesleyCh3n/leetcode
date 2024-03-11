class Solution {
public:
  bool canJump(vector<int>& nums) {
    if (nums.size() <= 1)
      return true;
    int zero_idx = -1;
    for (int i = nums.size() - 2; i >= 0; i--) {
      if (zero_idx == -1 && nums[i] == 0) {
        zero_idx = i;
        continue;
      }
      if (zero_idx != -1) {
        if ((nums[i] + (i - zero_idx)) > 0) {
          zero_idx = -1;
        }
      }
    }
    return zero_idx == -1;
  }
};

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int goal = nums.size() - 1;
    for (int i = nums.size() - 2; i >= 0; i--) {
      if ((i + nums[i]) >= goal) {
        goal = i;
      }
    }
    return goal == 0;
  }
};
