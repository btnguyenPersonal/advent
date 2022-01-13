#include <iostream>
#include <fstream>
#include <vector>

class Polymer {
  private:
    std::string poly;
    std::vector<std::vector<std::string>> rules;
    std::vector<long long> poly_nums;
  public:
    /* use NN -> O to just add directly to num of NO and ON*/
    Polymer(std::string s, std::vector<std::vector<std::string>> r) {
      poly = s;
      rules = r;
      for (int i = 0; i < rules.size(); i++) {
        poly_nums.push_back(0);
      }
      for (int i = 0; i < poly.length() - 1; i++) {
        for (int rule = 0; rule < rules.size(); rule++) {
          if (poly.substr(i, 2) == rules[rule][0]) {
            poly_nums[rule]++;
          }
        }
      }
    }
    void print() {
      std::cout << poly << std::endl;
    }
    void print_len() {
      long long sum = 0;
      for (int i = 0; i < poly_nums.size(); i++) {
        sum += poly_nums[i];
      }
      std::cout << sum + 1 << std::endl;
    }
    void grow() {
      std::vector<long long> temp;
      for (int i = 0; i < poly_nums.size(); i++) {
        temp.push_back(0);
      }
      for (int i = 0; i < poly_nums.size(); i++) {
        std::string next1 = rules[i][0].substr(0, 1) + rules[i][1];
        std::string next2 = rules[i][1] + rules[i][0].substr(1, 1);
        for (int j = 0; j < rules.size(); j++) {
          if (rules[j][0] == next1 || rules[j][0] == next2) {
            temp[j] += poly_nums[i];
          }
        }
      }
      poly_nums = temp;
    }
    /* int get_poly_num() { */
    /*   int most = 0; */
    /*   int least = 0; */
    /*   std::string mc = get_most_common(); */
    /*   std::string lc = get_least_common(); */
    /*   for (int i = 0; i < poly.length(); i++) { */
    /*     if (poly.substr(i, 1) == mc) { */
    /*       most++; */
    /*     } */
    /*     if (poly.substr(i, 1) == lc) { */
    /*       least++; */
    /*     } */
    /*   } */
    /*   return most - least; */
    /* } */
    long long get_num_char(std::string s) {
      long long sum = 0;
      for (int i = 0; i < rules.size(); i++) {
        if (rules[i][0].substr(0, 1) == s) {
          sum += poly_nums[i];
        }
        if (rules[i][0].substr(1, 1) == s) {
          sum += poly_nums[i];
        }
      }
      if (poly.substr(poly.length() - 1, 1) == s) {
        sum++;
      }
      if (poly.substr(0, 1) == s) {
        sum++;
      }
      sum /= 2;
      return sum;
    }
    /* std::string get_most_common() { */
    /*   std::string tmp = poly; */
    /*   while (tmp.length() > 1) { */
    /*     std::string removed = ""; */
    /*     for (int i = 0; i < tmp.length(); i++) { */
    /*       if (removed.find(tmp.substr(i, 1)) == std::string::npos) { */
    /*         removed += tmp.substr(i, 1); */
    /*         tmp = tmp.substr(0, i) + tmp.substr(i + 1); */
    /*         i--; */
    /*       } */
    /*     } */
    /*   } */
    /*   return tmp; */
    /* } */
    /* std::string get_least_common() { */
    /*   std::string tmp = poly; */
    /*   while (tmp.length() > 1) { */
    /*     std::string removed = ""; */
    /*     for (int i = 0; i < tmp.length(); i++) { */
    /*       if (removed.find(tmp.substr(i, 1)) == std::string::npos) { */
    /*         removed += tmp.substr(i, 1); */
    /*         if ((tmp.substr(0, i) + tmp.substr(i + 1)).find(tmp.substr(i, 1)) == std::string::npos) { */
    /*           return tmp.substr(i, 1); */
    /*         } */
    /*         tmp = tmp.substr(0, i) + tmp.substr(i + 1); */
    /*         i--; */
    /*       } */
    /*     } */
    /*   } */
    /*   return tmp; */
    /* } */
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
    p.grow();
  }
  std::cout << "A " << p.get_num_char("A") << std::endl;
  std::cout << "B " << p.get_num_char("B") << std::endl;
  std::cout << "C " << p.get_num_char("C") << std::endl;
  std::cout << "D " << p.get_num_char("D") << std::endl;
  std::cout << "E " << p.get_num_char("E") << std::endl;
  std::cout << "F " << p.get_num_char("F") << std::endl;
  std::cout << "G " << p.get_num_char("G") << std::endl;
  std::cout << "H " << p.get_num_char("H") << std::endl;
  std::cout << "I " << p.get_num_char("I") << std::endl;
  std::cout << "J " << p.get_num_char("J") << std::endl;
  std::cout << "K " << p.get_num_char("K") << std::endl;
  std::cout << "L " << p.get_num_char("L") << std::endl;
  std::cout << "M " << p.get_num_char("M") << std::endl;
  std::cout << "N " << p.get_num_char("N") << std::endl;
  std::cout << "O " << p.get_num_char("O") << std::endl;
  std::cout << "P " << p.get_num_char("P") << std::endl;
  std::cout << "Q " << p.get_num_char("Q") << std::endl;
  std::cout << "R " << p.get_num_char("R") << std::endl;
  std::cout << "S " << p.get_num_char("S") << std::endl;
  std::cout << "T " << p.get_num_char("T") << std::endl;
  std::cout << "U " << p.get_num_char("U") << std::endl;
  std::cout << "V " << p.get_num_char("V") << std::endl;
  std::cout << "W " << p.get_num_char("W") << std::endl;
  std::cout << "X " << p.get_num_char("X") << std::endl;
  std::cout << "Y " << p.get_num_char("Y") << std::endl;
  std::cout << "Z " << p.get_num_char("Z") << std::endl;
  std::cout << p.get_num_char("C") - p.get_num_char("V") << std::endl;
  /* p.print_len(); */
  /* std::cout << p.get_poly_num() << std::endl; */
  /* std::cout << p.get_most_common() << std::endl; */
  /* std::cout << p.get_least_common() << std::endl; */
  return 0;
}
