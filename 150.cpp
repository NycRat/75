// 150. Evaluate Reverse Polish Notation | Dec 29, 2023

#include <cctype>
#include <string>
#include <vector>

enum Type { Number, Operator };

struct Token {
  Type type;
  int value;
};

class Solution {
public:
  int evalRPN(std::vector<std::string> &tokens) {
    std::vector<Token> tokens_parsed(tokens.size());
    for (int i = 0; i < tokens.size(); i++) {
      if (isdigit(tokens[i][tokens[i].size() - 1])) {
        tokens_parsed[i] = {Number, std::stoi(tokens[i])};
      } else {
        tokens_parsed[i] = {Operator, tokens[i][0]};
      }
    }

    int i = 0;
    while (tokens_parsed.size() > 1) {
      switch (tokens_parsed[i].type) {
        case Number:
          i++;
          break;
        case Operator:
          int a = tokens_parsed[i-2].value;
          int b = tokens_parsed[i-1].value;
          switch (tokens_parsed[i].value) {
            case '+':
              tokens_parsed[i].value = a + b;
              break;
            case '-':
              tokens_parsed[i].value = a - b;
              break;
            case '*':
              tokens_parsed[i].value = a * b;
              break;
            case '/':
              tokens_parsed[i].value = a / b;
              break;
          }
          tokens_parsed[i].type = Number;
          tokens_parsed.erase(tokens_parsed.begin() + i - 2);
          tokens_parsed.erase(tokens_parsed.begin() + i - 2);
          i--;
          break;
      }
    }
    return tokens_parsed[0].value;
  }
  // int evalRPN(std::vector<std::string> &tokens) {
  //   int i = 0;
  //   while (tokens.size() > 1) {
  //     if (std::isdigit(tokens[i][tokens[i].size() - 1])) {
  //       i++;
  //       continue;
  //     }
  //
  //     int a = std::stoi(tokens[i - 2]);
  //     int b = std::stoi(tokens[i - 1]);
  //     if (tokens[i] == "+") {
  //       tokens[i] = std::to_string(a + b);
  //     } else if (tokens[i] == "-") {
  //       tokens[i] = std::to_string(a - b);
  //     } else if (tokens[i] == "*") {
  //       tokens[i] = std::to_string(a * b);
  //     } else if (tokens[i] == "/") {
  //       tokens[i] = std::to_string(a / b);
  //     }
  //     tokens.erase(tokens.begin() + i - 2);
  //     tokens.erase(tokens.begin() + i - 2);
  //     i--;
  //   }
  //   return std::stoi(tokens[0]);
  // }
  Solution() {}
};

int main() { Solution(); }
