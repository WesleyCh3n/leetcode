struct TrieNode {
  TrieNode *children[26];
  bool is_word;
  TrieNode() {
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
      is_word = false;
    }
  }
};

class Solution {
  TrieNode *root;
  void add_word(string word) {
    TrieNode *curr = root;
    for (int i = 0; i < word.size(); i++) {
      int index = word[i] - 'a';
      if (curr->children[index] == nullptr)
        curr->children[index] = new TrieNode();
      curr = curr->children[index];
    }

    curr->is_word = true;
  }
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    root = new TrieNode();
    for(const string s: words){
      add_word(s);
    }
    vector<string> result{};
    for (int m = 0; m < board.size(); m++) {
      for (int n = 0; n < board[0].size(); n++) {
        dfs(board, m, n, root, "", result);
      }
    }
    return result;
  }

  void dfs(vector<vector<char>>& board, int m, int n, TrieNode *node, string word, vector<string> &result) {
    if (m < 0 || m >= board.size() || n < 0 || n >= board[0].size() || board[m][n] == '#') {
      return;
    }
    char c = board[m][n];

    // check if current char exist in trie
    node = node->children[c - 'a'];
    if (node == nullptr) {
      return;
    }

    // current node path is in words then add to result
    word += c;
    if (node->is_word) {
      result.emplace_back(word);
      // once word found remove is word to prevent duplicate answer
      node->is_word = false;
    }

    // mark visited
    board[m][n] = '#';

    // recusive called
    dfs(board, m - 1, n, node, word, result);
    dfs(board, m + 1, n, node, word, result);
    dfs(board, m, n - 1, node, word, result);
    dfs(board, m, n + 1, node, word, result);

    // unset visited
    board[m][n] = c;
  }
};
