class Solution {
public:
  int getSum(int a, int b) {
    while (b != 0) {
      int carrier = (a & b) << 1;
      a = a ^ b;
      b = carrier;
    }
    return a;
  }
};
