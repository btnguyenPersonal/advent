#include <iostream>
#include <fstream>

class SyntaxLine {
  private:
    std::string line;
    std::string open_pairs[4] = { "(", "[", "{", "<", };
    std::string close_pairs[4] = { ")", "]", "}", ">", };
  public:
    SyntaxLine(std::string s) {
      line = s;
    }

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

    bool isCorrupted() {
      if (!doesMatchCase(line.substr(0,1), line.substr(line.length()-1, 1))) {
        std::cout << line.substr(0,1) << std::endl;
        std::cout << line.substr(line.length()-1,1) << std::endl;
        return true;
      }
      return false;
    }

};

int main() {
  SyntaxLine f("<]");
  std::cout << f.isCorrupted() << std::endl;
  SyntaxLine s("<>");
  std::cout << s.isCorrupted() << std::endl;
  return 0;
}
