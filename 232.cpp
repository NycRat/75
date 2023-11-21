// 232. Implement Queue using Stacks | Nov 21, 2023

#include <stack>

class MyQueue {
public:
  MyQueue() {}

  void push(int x) {
    while (q.size()) {
      temp.push(q.top());
      q.pop();
    }
    q.push(x);
    while (temp.size()) {
      q.push(temp.top());
      temp.pop();
    }
  }

  int pop() {
    int t = q.top();
    q.pop();
    return t;
  }

  int peek() {
    return q.top();
  }

  bool empty() {
    return q.empty();
  }

private:
  std::stack<int> q;
  std::stack<int> temp;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 *
 *
 *
 * [1,2,3,_,_,1] -> [3,1]
 *
 * 3 2 1
 * 
 * 
 */
