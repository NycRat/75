// 133. Clone Graph | Dec 25, 2023

#include "Node.h"
#include <unordered_map>

class Solution {
public:
  // (old, new)
  std::unordered_map<Node *, Node *> prev;

  Node *cloneNode(Node *node) {
    if (prev.count(node)) {
      return prev[node];
    }
    Node *new_node = new Node(node->val);
    prev[node] = new_node;
    for (Node *neighbour : node->neighbors) {
      new_node->neighbors.push_back(cloneNode(neighbour));
    }
    return new_node;
  }
  Node *cloneGraph(Node *node) {
    prev[nullptr] = nullptr;
    return cloneNode(node);
  }
  Solution() {}
};

int main() { Solution(); }
