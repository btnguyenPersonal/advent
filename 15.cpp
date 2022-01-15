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
    bool is_valid(int x, int y) {
      if (x >= 0 && y >= 0 && x < cave.size() && y < cave.size()) {
        return true;
      }
      return false;
    }
    int get_temp_pos(int x, int y, std::vector<std::vector<int>> input) {
      if (x >= 0 && y >= 0 && x < input.size() && y < input.size()) {
        return input[x][y];
      } else {
        return 99999999;
      }
    }
    int get_pos(int x, int y) {
      if (x >= 0 && y >= 0 && x < cave.size() && y < cave.size()) {
        return cave[x][y];
      } else {
        return 99999999;
      }
    }
    void print() {
      for (int i = 0; i < cave.size(); i++) {
        for (int j = 0; j < cave[0].size(); j++) {
          std::cout << get_pos(i, j);
        }
        std::cout << std::endl;
      }
    }
    std::vector<std::vector<int>> get_temp_cave() {
      std::vector<std::vector<int>> temp_caves;
      for (int x = 0; x < cave.size(); x++) {
        std::vector<int> temp;
        for (int y = 0; y < cave.size(); y++) {
          temp.push_back(9999999);
        }
        temp_caves.push_back(temp);
      }
      return temp_caves;
    }
    int get_lowest_risk() {
      std::vector<std::vector<int>> temp = get_temp_cave();
      temp[cave.size() - 1][cave.size() - 1] = 0;
      return set_values(cave.size() - 1, cave.size() - 1, temp);
    }
    int set_values(int x, int y, std::vector<std::vector<int>> temp_caves) {
      for (int i = -1; i <= 0; i++) {
        for (int j = -1; j <= 0; j++) {
            std::cout << "x: " << x + i << std::endl;
            std::cout << "y: " << y + j << std::endl;
            std::cout << get_temp_pos(x + i, y + j, temp_caves) << std::endl;
            std::cout << get_pos(x + i, y + j) << std::endl;
            std::cout << get_temp_pos(x, y, temp_caves) << std::endl;
          if (is_valid(x + i, y + j) && get_temp_pos(x + i, y + j, temp_caves) > get_pos(x + i, y + j) + get_temp_pos(x, y, temp_caves)) {
            temp_caves[x + i][y + j] = get_pos(x + i, y + j) + get_temp_pos(x, y, temp_caves);
            set_values(x + i, y + j, temp_caves);
          }
        }
      }
      return temp_caves[0][0];
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
  std::cout << c.get_lowest_risk() << std::endl;
  return 0;
}

