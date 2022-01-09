#include <iostream>
#include <fstream>
#include <stack>

class SyntaxLine {
  private:
    std::string line;
    std::string open_pairs[4] = { "(", "[", "{", "<", };
    std::string close_pairs[4] = { ")", "]", "}", ">", };

    int get_open_index(std::string s) {
      for (int i = 0; i < 4; i++) {
        if (s == open_pairs[i]) {
          return i;
        }
      }
      return -1;
    }

    int get_close_index(std::string s) {
      for (int i = 0; i < 4; i++) {
        if (s == close_pairs[i]) {
          return i;
        }
      }
      return -1;
    }

  public:
    SyntaxLine(std::string s) {
      line = s;
    }

    std::string getLine() {
      return line;
    }

    bool doesMatchCase(std::string s1, std::string s2) {
      if (get_close_index(s2) != -1 && get_open_index(s1) == get_close_index(s2)) {
        return true;
      }
      return false;
    }

    bool doesMatch(std::string s1, std::string s2) {
      if (get_open_index(s1) == -1 || get_close_index(s2) == -1) {
        return false;
      }
      return true;
    }

    bool isMatching() {
      int parens[4] = {0,0,0,0};
      for (int i = 0; i < line.length(); i++) {
        std::string c = line.substr(i, 1);
        if (get_open_index(c) != -1) {
          parens[get_open_index(c)]++;
        } else {
          parens[get_close_index(c)]--;
          if (parens[get_close_index(c)] < 0) {
            return false;
          }
        }
      }
      for (int i = 0; i < 4; i++) {
        if (parens[i] != 0) {
          return false;
        }
      }
      return true;
    }

    int getIllegal() {
      std::stack<int> parens;
      for (int i = 0; i < line.length(); i++) {
        std::string c = line.substr(i, 1);
        if (get_open_index(c) != -1) {
          parens.push(get_open_index(c));
        } else {
          if (parens.top() != get_close_index(c)) {
            switch(get_close_index(c)) {
              case 0:
                return 3;
              case 1:
                return 57;
              case 2:
                return 1197;
              case 3:
                return 25137;
              default:
                return -1;
            }
          } else {
            parens.pop();
          }
        }
      }
      return -1;
    }

    bool isCorrupted() {
      if (!doesMatchCase(line.substr(0,1), line.substr(line.length()-1, 1))) {
        std::cout << line.substr(0,1) << std::endl;
        std::cout << line.substr(line.length()-1,1) << std::endl;
        return true;
      }
      return false;
    }

    long long getCompletion() {
      long long sum = 0;
      std::stack<int> parens;
      for (int i = 0; i < line.length(); i++) {
        std::string c = line.substr(i, 1);
        if (get_open_index(c) != -1) {
          parens.push(get_open_index(c));
        } else {
          parens.pop();
        }
      }
      while(!parens.empty()) {
        int a = parens.top();
        parens.pop();
        switch(a) {
          case 0:
            sum *= 5;
            sum += 1;
            break;
          case 1:
            sum *= 5;
            sum += 2;
            break;
          case 2:
            sum *= 5;
            sum += 3;
            break;
          case 3:
            sum *= 5;
            sum += 4;
            break;
          default:
            break;
        }
      }
      return sum;
    }

};

int main() {
  std::ifstream f("10input.txt");
  std::string s;
  int sum = 0;
  while (f >> s) {
    SyntaxLine line (s);
    if (line.getIllegal() == -1) {
      std::cout << line.getCompletion() << std::endl;
    }
  }
  return 0;
}
