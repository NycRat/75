// 208. Implement Trie (Prefix Tree) | Dec 29, 2023

#include <string>
#include <unordered_set>

class Trie {
public:
  Trie() {}

  void insert(std::string word) {
    words.insert(word);

    for (int i = 0; i < word.size(); i++) {
      prefixes.insert(word.substr(0, i));
    }
  }

  bool search(std::string word) { return words.count(word); }

  bool startsWith(std::string prefix) {
    return words.count(prefix) || prefixes.count(prefix);
  }

private:
  std::unordered_set<std::string> words;
  std::unordered_set<std::string> prefixes;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {}
