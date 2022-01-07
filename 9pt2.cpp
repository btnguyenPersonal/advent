#include <iostream>
#include <fstream>

class Map {
  private:
    int graph[5][10];
  public:
    Map(std::string input[5][10]) {
      for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 10; col++) {
          graph[row][col] = std::stoi(input[row][col]);
        }
      }
    }

    int get_height(int r, int c) {
      if (r < 0 || c < 0 || r >= 5 || c >= 10) {
        return 999999999;
      }
      return graph[r][c];
    }

    int get_basin(int r, int c) {
      if (get_height(r + 1, c) == get_height(r, c) + 1) {
        return 1 + get_basin(r + 1, c);
      }
      if (get_height(r - 1, c) == get_height(r, c) + 1) {
        return 1 + get_basin(r - 1, c);
      }
      if (get_height(r, c + 1) == get_height(r, c) + 1) {
        return 1 + get_basin(r, c + 1);
      }
      if (get_height(r, c - 1) == get_height(r, c) + 1) {
        return 1 + get_basin(r, c - 1);
      }
      return 0;
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
      for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 10; c++) {
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
      for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 10; c++) {
          if (is_lowpoint(r, c)) {
            sum++;
          }
        }
      }
      return sum;
    }

    void print_basin() {
      for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 10; c++) {
          std::cout << get_basin(r, c);
        }
        std::cout << std::endl;
      }
    }

    void print_map() {
      for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 10; c++) {
          std::cout << get_height(r, c);
        }
        std::cout << std::endl;
      }
    }
};

int main() {
  std::ifstream f("9testinput.txt");
  std::string s;
  std::string input[5][10];
  int r = 0;
  while (f >> s) {
    for (int i = 0; i < 10; i++) {
      input[r][i] = s.substr(i, 1);
    }
    r++;
  }
  Map m = Map(input);
  /* std::cout << m.get_risk_level() << std::endl; */
  /* m.print_map(); */
  m.print_basin();
  return 0;
}

