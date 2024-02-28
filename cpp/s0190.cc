class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (uint8_t i = 0; i < 32; i++) {
      // get the i-th bit
      bool bit = (n & (1 << i)) != 0;
      // set bit
      result = result | (bit << (31 - i));
    }
    return result;
  }
};
