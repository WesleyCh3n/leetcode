#include <climits>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

template <typename T> void print_vec(vector<T> &v) {
  cout << '[' << ' ';
  for (auto i : v)
    cout << i << ' ';
  cout << ']' << '\n';
}

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int max_profit = 0, min_val = INT_MAX;
    for (int i = 0; i < (int)prices.size(); ++i) {
      min_val = min(min_val, prices[i]);
      max_profit = max(max_profit, prices[i] - min_val);
    }
    return max_profit;
  }
  int maxProfit_dp(vector<int> &prices) {
    int min_val = INT_MAX;
    // auto dp = std::make_unique<int[]>(prices.size() + 1);
    std::vector<int> dp(prices.size() + 1);
    dp[0] = 0;
    for (int i = 1; i <= (int)prices.size(); ++i) {
      if (prices[i - 1] < min_val) {
        min_val = prices[i - 1];
      }
      dp[i] = max(dp[i - 1], prices[i - 1] - min_val);
    }
    return dp[prices.size()];
  }
  int maxProfit_bad_n2(vector<int> &prices) {
    int max_profit = 0;
    for (int i = 0; i < (int)prices.size(); ++i) {
      for (int j = i + 1; j < (int)prices.size(); ++j) {
        max_profit = max(prices[j] - prices[i], max_profit);
      }
    }
    return max_profit;
  }
};

int main() {
  std::vector<int> v = {7, 1, 5, 3, 6, 4};

  Solution s;
  cout << s.maxProfit_dp(v) << '\n';
  v = {7, 6, 4, 3, 1};
  cout << s.maxProfit_dp(v) << '\n';

  return 0;
}
