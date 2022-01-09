#include <iostream>
#include <fstream>
#include <vector>

class Board {
  private:
    std::vector<std::vector<int>> board;
    int flashes = 0;
  public:

    Board(std::vector<std::vector<int>> input) {
      board = input;
    }

    int get_flashes() {
      return flashes;
    }

    void set_energy(int x, int y, int energy) {
      if (!(x < 0 || y < 0 || x >= board.size() || y >= board.size())) {
        board[x][y] = energy;
      }
    }

    int get_energy(int x, int y) {
      if (x < 0 || y < 0 || x >= board.size() || y >= board.size()) {
        return -1;
      }
      return board[x][y];
    }

    void flash(int x, int y) {
      set_energy(x, y, 0);
      flashes++;
      for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
          if (get_energy(x + i, y + j) != 0) {
            set_energy(x + i, y + j, get_energy(x + i, y + j) + 1);
          }
        }
      }
    }

    void take_step() {
      for (int x = 0; x < board.size(); x++) {
        for (int y = 0; y < board.size(); y++) {
          set_energy(x, y, get_energy(x, y) + 1);
        }
      }
      while (is_flash()) {
        for (int x = 0; x < board.size(); x++) {
          for (int y = 0; y < board.size(); y++) {
            if (get_energy(x, y) > 9) {
              flash(x, y);
            }
          }
        }
      }
    }

    bool is_flash() {
      for (int x = 0; x < board.size(); x++) {
        for (int y = 0; y < board.size(); y++) {
          if (get_energy(x, y) > 9) {
            return true;
          }
        }
      }
      return false;
    }

    void print_board() {
      for (int x = 0; x < board.size(); x++) {
        for (int y = 0; y < board.size(); y++) {
          std::cout << get_energy(x, y);
        }
        std::cout << std::endl;
      }
    }

    bool are_all_flashing() {
      for (int x = 0; x < board.size(); x++) {
        for (int y = 0; y < board.size(); y++) {
          if (get_energy(x, y) != 0) {
            return false;
          }
        }
      }
      return true;
    }

};

int main() {
  std::ifstream f("11input.txt");
  std::string tmp;
  std::vector<std::vector<int>> v;
  std::vector<int> tempv;
  for (int x = 0; x < 10; x++) {
    tempv.clear();
    for (int y = 0; y < 10; y++) {
      f >> tmp;
      tempv.push_back(stoi(tmp));
    }
    v.push_back(tempv);
  }
  Board b(v);
  b.print_board();
  int i = 0;
  while (!b.are_all_flashing()) {
    b.take_step();
    i++;
  }
  b.print_board();
  std::cout << i << std::endl;
  return 0;
}

