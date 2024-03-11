class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1)
      return intervals;

    // O(Nlog(N))
    sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
      return a[0] < b[0];
    });

    vector<vector<int>> result = {intervals[0]};

    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] <= result.back()[1]) {
        result.back()[0] = min(result.back()[0], intervals[i][0]);
        result.back()[1] = max(result.back()[1], intervals[i][1]);
      } else {
        result.emplace_back(intervals[i]);
      }
    }
    return result;
  }
};
