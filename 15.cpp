#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

class Cavern {
  private:
    std::vector<std::vector<int>> cave;
  public:
    Cavern(std::vector<std::vector<int>> input) {
      cave = input;
    }
    int get_pos(int x, int y) {
      return cave[x][y];
    }
    void print() {
      for (int i = 0; i < cave.size(); i++) {
        for (int j = 0; j < cave[0].size(); j++) {
          std::cout << get_pos(i, j);
        }
        std::cout << std::endl;
      }
    }
    int get_lowest_risk() {
      int sum = 0;
      return sum;
    }
};

int main() {
  std::ifstream f("15testinput.txt");
  std::string s;
  std::vector<std::vector<int>> input;
  while(f >> s) {
    std::vector<int> tmp;
    for (int i = 0; i < s.length(); i++) {
      tmp.push_back(stoi(s.substr(i, 1)));
    }
    input.push_back(tmp);
  }
  Cavern c(input);
  c.print();
  return 0;
}

