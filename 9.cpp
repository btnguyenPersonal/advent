#include <iostream>
#include <fstream>

class Map {
  private:
    int graph[100][100];
  public:
    Map(std::string input[100][100]) {
      for (int row = 0; row < 100; row++) {
        for (int col = 0; col < 100; col++) {
          graph[row][col] = std::stoi(input[row][col]);
        }
      }
    }

    int get_height(int r, int c) {
      if (r < 0 || c < 0 || r >= 100 || c >= 100) {
        return 999999999;
      }
      return graph[r][c];
    }

    bool is_lowpoint(int r, int c) {
      if (get_height(r + 1, c) <= get_height(r, c)) {
        return false;
      }
      if (get_height(r - 1, c) <= get_height(r, c)) {
        return false;
      }
      if (get_height(r, c + 1) <= get_height(r, c)) {
        return false;
      }
      if (get_height(r, c - 1) <= get_height(r, c)) {
        return false;
      }
      if (get_height(r, c) == 9) {
        std::cout << r << " " << c << " " << get_height(r+1,c) << get_height(r,c-1) << get_height(r,c+1) << get_height(r-1,c) << std::endl;
      }
      return true;
    }

    int get_risk_level() {
      int sum = 0;
      for (int r = 0; r < 100; r++) {
        for (int c = 0; c < 100; c++) {
          if (is_lowpoint(r, c)) {
            /* std::cout << get_height(r, c) << std::endl; */
            sum += get_height(r, c) + 1;
          }
        }
      }
      return sum;
    }

    int get_num_lowpoints() {
      int sum = 0;
      for (int r = 0; r < 100; r++) {
        for (int c = 0; c < 100; c++) {
          if (is_lowpoint(r, c)) {
            sum++;
          }
        }
      }
      return sum;
    }
};

int main() {
  std::ifstream f("9input.txt");
  std::string s;
  std::string input[100][100];
  int r = 0;
  while (f >> s) {
    for (int i = 0; i < 100; i++) {
      input[r][i] = s.substr(i, 1);
    }
    r++;
  }
  Map m = Map(input);
  std::cout << m.get_risk_level() << std::endl;
  return 0;
}

