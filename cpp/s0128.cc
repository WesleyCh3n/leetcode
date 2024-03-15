class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> set(nums.begin(), nums.end());
    int res = 0;
    for(auto& n : set) {
      if(!set.count(n - 1)) {
        // start count
        int len = 1;
        int curr = n + 1;
        while(set.count(curr)) {
          len += 1;
          curr += 1;
        }
        res = max(res, len);
      }
    }

    return res;
  }
};
