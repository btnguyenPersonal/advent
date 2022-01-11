#include <iostream>
#include <fstream>
#include <vector>

class Paper {
  private:
    std::vector<std::vector<int>> p;
  public:
    Paper(std::vector<std::string> coordinates) {
      for (int x = 0; x < 1311; x++) {
        std::vector<int> tmp;
        for (int y = 0; y < 893; y++) {
          tmp.push_back(0);
        }
        p.push_back(tmp);
      }
      for (int i = 0; i < coordinates.size(); i++) {
        std::string input = coordinates[i];
        int xval = stoi(input.substr(0, input.find(",")));
        int yval = stoi(input.substr(input.find(",") + 1));
        p[xval][yval] = 1;
      }
    }

    void fold_up(int fold_y) {
      for (int i = 1; i < p[0].size() - fold_y; i++) {
        for (int x = 0; x < p.size(); x++) {
          if (p[x][fold_y + i] == 1) {
            p[x][fold_y - i] = 1;
          }
        }
      }
      for (int x = 0; x < p.size(); x++) {
        for (int y = 0; y < fold_y; y++) {
          p[x].pop_back();
        }
      }
    }

    void fold_left(int fold_x) {
      for (int i = 1; i < p.size() - fold_x; i++) {
        for (int y = 0; y < p[0].size(); y++) {
          if (p[fold_x + i][y] == 1) {
            p[fold_x - i][y] = 1;
          }
        }
      }
      for (int x = 0; x < fold_x + 1; x++) {
        p.pop_back();
      }
    }

    int get_dots() {
      int sum = 0;
      for (int y = 0; y < p[0].size(); y++) {
        for (int x = 0; x < p.size(); x++) {
          if (p[x][y] != 0) {
            sum++;
          }
        }
      }
      return sum;
    }

    void print() {
      std::cout << p[0].size() << std::endl;
      std::cout << p.size() << std::endl;
      for (int y = 0; y < p[0].size(); y++) {
        for (int x = 0; x < p.size(); x++) {
          if (p[x][y] == 1) {
            std::cout << "#";
          } else {
            std::cout << " ";
          }
        }
        std::cout << std::endl;
      }
    }
};


int main() {
  std::ifstream f("13input.txt");
  std::string s;
  std::vector<std::string> coors;
  while (f >> s && s != "fold") {
    coors.push_back(s);
  }
  Paper p(coors);
  p.fold_left(655);
  p.fold_up(447);
  p.fold_left(327);
  p.fold_up(223);
  p.fold_left(163);
  p.fold_up(111);
  p.fold_left(81);
  p.fold_up(55);
  p.fold_left(40);
  p.fold_up(27);
  p.fold_up(13);
  p.fold_up(6);
  p.print();
  return 0;
}

