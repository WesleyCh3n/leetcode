#include <string>
using namespace std;

struct Node {
  Node *children[26];
  bool is_word;
  Node() {
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
    is_word = false;
  }
};

class WordDictionary {
  Node *root;

public:
  WordDictionary() { root = new Node(); }

  void addWord(string word) {
    Node *curr = root;
    for (int i = 0; i < word.size(); i++) {
      int index = word[i] - 'a';
      if (curr->children[index] == nullptr) {
        curr->children[index] = new Node();
      }
      curr = curr->children[index];
    }
    curr->is_word = true;
  }

  bool search(string word) {
    return search(root, 0, word);
  }

private:
  bool search(Node *node, int i, string &word) {
    if (node == nullptr) // nothing furtuer
      return false;
    if (i == word.size()) // because the root are the first 0 level
      return node->is_word;
    if (word[i] != '.')
      return search(node->children[word[i] - 'a'], i + 1, word);
    for (int c = 0; c < 26; c++) {
      if (search(node->children[c], i + 1, word)) {
        return true;
      }
    }
    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
