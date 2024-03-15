class Solution {
public:
  int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int max_area = 0;
    while (left < right) {
      int min_h = min(height[left], height[right]);
      int area = (right - left) * min_h;
      max_area = max(area, max_area);
      if (height[left] == min_h) {
        left += 1;
      } else {
        right -= 1;
      }
    }
    return max_area;
  }
};
