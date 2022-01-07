#include <iostream>
#include <fstream>

class Map {
  private:
    int graph[100][100];
    bool checked[100][100];
  public:
    Map(std::string input[100][100]) {
      for (int row = 0; row < 100; row++) {
        for (int col = 0; col < 100; col++) {
          checked[row][col] = false;
        }
      }
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

    int get_basin(int r, int c) {
      int sum = 0;
      for (int row = 0; row < 100; row++) {
        for (int col = 0; col < 100; col++) {
          if (is_connected_to(row, col, r, c)) {
            sum++;
          }
        }
      }
      return sum;
    }

    bool is_connected_to(int r, int c, int r_low, int c_low) {
      if (!is_lowpoint(r_low, c_low)) {
        return false;
      }
      if (get_height(r, c) == 9) {
        return false;
      }
      if (r == r_low && c == c_low) {
        return true;
      }
      if (get_height(r + 1, c) == get_height(r, c) - 1) {
        return is_connected_to(r + 1, c, r_low, c_low);
      }
      if (get_height(r - 1, c) == get_height(r, c) - 1) {
        return is_connected_to(r - 1, c, r_low, c_low);
      }
      if (get_height(r, c + 1) == get_height(r, c) - 1) {
        return is_connected_to(r, c + 1, r_low, c_low);
      }
      if (get_height(r, c - 1) == get_height(r, c) - 1) {
        return is_connected_to(r, c - 1, r_low, c_low);
      }
      return false;
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
      return true;
    }

    int get_risk_level() {
      int sum = 0;
      for (int r = 0; r < 100; r++) {
        for (int c = 0; c < 100; c++) {
          if (is_lowpoint(r, c)) {
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

    int get_basin() {
      int high1 = -1;
      int high2 = -1;
      int high3 = -1;
      for (int r = 0; r < 100; r++) {
        for (int c = 0; c < 100; c++) {
          if (get_basin(r, c) > high1) {
            high3 = high2;
            high2 = high1;
            high1 = get_basin(r, c);
          } else if (get_basin(r, c) > high2) {
            high3 = high2;
            high2 = get_basin(r, c);
          } else if (get_basin(r, c) > high3) {
            high3 = get_basin(r, c);
          }
        }
      }
      return high1 * high2 * high3;
    }

    void print_basin() {
      for (int r = 0; r < 100; r++) {
        for (int c = 0; c < 100; c++) {
          if (get_basin(r, c) > 20) {
            printf("%3d", get_basin(r, c));
            printf("\n");
          }
        }
      }
    }

    void print_map() {
      for (int r = 0; r < 100; r++) {
        for (int c = 0; c < 100; c++) {
          std::cout << get_height(r, c);
        }
        std::cout << std::endl;
      }
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
  /* std::cout << m.get_risk_level() << std::endl; */
  m.print_basin();
  std::cout << m.get_basin();
  return 0;
}

