#include <iostream>
#include <fstream>
#include <vector>

class Polymer {
  private:
    std::string poly;
    std::vector<std::vector<std::string>> rules;
  public:
    /* use NN -> O to just add directly to num of NO and ON*/
    Polymer(std::string s, std::vector<std::vector<std::string>> r) {
      poly = s;
      rules = r;
    }
    void print_len() {
      std::cout << poly.length() << std::endl;
    }
    void print() {
      std::cout << poly << std::endl;
    }
    void grow() {
      for (int i = poly.length() - 2; i >= 0; i--) {
        for (int r = 0; r < rules.size(); r++) {
          if (poly.substr(i, 2) == rules[r][0]) {
            poly = poly.substr(0, i+1) + rules[r][1] + poly.substr(i+1);
            break;
          }
        }
      }
    }
    int get_poly_num() {
      int most = 0;
      int least = 0;
      std::string mc = get_most_common();
      std::string lc = get_least_common();
      for (int i = 0; i < poly.length(); i++) {
        if (poly.substr(i, 1) == mc) {
          most++;
        }
        if (poly.substr(i, 1) == lc) {
          least++;
        }
      }
      return most - least;
    }
    std::string get_most_common() {
      std::string tmp = poly;
      while (tmp.length() > 1) {
        std::string removed = "";
        for (int i = 0; i < tmp.length(); i++) {
          if (removed.find(tmp.substr(i, 1)) == std::string::npos) {
            removed += tmp.substr(i, 1);
            tmp = tmp.substr(0, i) + tmp.substr(i + 1);
            i--;
          }
        }
      }
      return tmp;
    }
    std::string get_least_common() {
      std::string tmp = poly;
      while (tmp.length() > 1) {
        std::string removed = "";
        for (int i = 0; i < tmp.length(); i++) {
          if (removed.find(tmp.substr(i, 1)) == std::string::npos) {
            removed += tmp.substr(i, 1);
            if ((tmp.substr(0, i) + tmp.substr(i + 1)).find(tmp.substr(i, 1)) == std::string::npos) {
              return tmp.substr(i, 1);
            }
            tmp = tmp.substr(0, i) + tmp.substr(i + 1);
            i--;
          }
        }
      }
      return tmp;
    }
};

int main() {
  std::ifstream f("14input.txt");
  std::string input;
  f >> input;
  std::string s1;
  std::string s2;
  std::string s3;
  std::vector<std::vector<std::string>> insertion_rules;
  while (f >> s1 >> s2 >> s3) {
    std::vector<std::string> tmp;
    tmp.push_back(s1);
    tmp.push_back(s3);
    insertion_rules.push_back(tmp);
  }
  Polymer p(input, insertion_rules);
  for (int i = 0; i < 40; i++) {
    std::cout << i << std::endl;
    p.grow();
  }
  p.print_len();
  std::cout << p.get_poly_num() << std::endl;
  std::cout << p.get_most_common() << std::endl;
  std::cout << p.get_least_common() << std::endl;
  return 0;
}

