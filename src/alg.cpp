// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
  std::map<char, int> priority;
  priority['('] = 0;
  priority['+'] = 1;
  priority['-'] = 1;
  priority['*'] = 2;
  priority['/'] = 2;

  TStack<char, 100> op_stack;
  std::string pst;

  for (int i = 0; i < inf.length(); i++) {
    char c = inf[i];
    if (isdigit(c)) {
      pst += c;
      if (!isdigit(inf[i + 1])) {
        pst += " ";
      }
    } else if (c == '(') {
      op_stack.push(c);
    } else if (c == ')') {
      char s = op_stack.pop();
      while (s != '(') {
        pst += s;
        pst += " ";
        s = op_stack.pop();
      }
    } else {
      while (!op_stack.isEmpty() && priority[op_stack.get()] >= priority[c]) {
        pst += op_stack.pop();
        pst += " ";
      }
      op_stack.push(c);
    }
  }

  while (!op_stack.isEmpty()) {
    pst += op_stack.pop();
    pst += " ";
  }

  return pst;
}

int eval(std::string post) {
  TStack<int, 100> num_stack;

  for (int i = 0; i < post.length(); i++) {
    char c = post[i];
    if (isdigit(c)) {
      std::string num_str = "";
      while (isdigit(c)) {
        num_str += c;
        c = post[++i];
      }
      int num = std::stoi(num_str);
      num_stack.push(num);
    } else {
      int b = num_stack.pop();
      int a = num_stack.pop();
      switch (c) {
        case '+':
          num_stack.push(a + b);
          break;
        case '-':
          num_stack.push(a - b);
          break;
        case '*':
          num_stack.push(a * b);
          break;
        case '/':
          num_stack.push(a / b);
          break;
      }
    }
  }

  return num_stack.pop();
}
