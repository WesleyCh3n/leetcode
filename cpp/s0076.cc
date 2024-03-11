class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> count;
    for (const auto& c: t) {
      count[c] += 1;
    }
    int begin = 0, end = 0, min_begin = 0, min_width = INT_MAX, to_match = t.size();
    while (end < s.size()) {
      if (count[s[end]] > 0) {
        to_match -= 1;
      }
      count[s[end]] -= 1;
      end += 1;
      while(to_match == 0) {
        if (end - begin < min_width) {
          min_width = end - begin;
          min_begin = begin;
        }
        if (count[s[begin]] == 0) {
          to_match += 1;
        }
        count[s[begin]] += 1;
        begin += 1;
      }
    }
    return min_width == INT_MAX ? "": s.substr(min_begin, min_width);
  }
};

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        if(t.size()>s.size()) return "";
        for(auto c:t){
            map[c]++;
        }
        int begin=0, end=0, head=0, len=INT_MAX, counter=t.size();
        while(end<s.size()){
            if(map[s[end]]>0){
                counter--;
            }
            map[s[end]]--;
            end++;

            while(counter==0){
                if(end-begin<len){
                    len=end-(head=begin);
                }
                if(map[s[begin]]==0){
                    counter++;
                }
                map[s[begin]]++;
                begin++;
            }
        }
        return len==INT_MAX?"":s.substr(head,len);
    }
};
