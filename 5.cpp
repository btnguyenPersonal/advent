#include <iostream>
#include <fstream>
#include <sstream>

class graph {
  private:
    int _graph[1000][1000];

    void make_line_x(int y1, int y2, int x) {
      if (y1 > y2) {
        for (int i = y2; i <= y1; i++) {
          inc_coor(x, i);
        }
      } else {
        for (int i = y1; i <= y2; i++) {
          inc_coor(x, i);
        }
      }
    }

    void make_line_y(int x1, int x2, int y) {
      if (x1 > x2) {
        for (int i = x2; i <= x1; i++) {
          inc_coor(i, y);
        }
      } else {
        for (int i = x1; i <= x2; i++) {
          inc_coor(i, y);
        }
      }
    }
  public:
    graph() {
      for (int x = 0; x < 1000; x++) {
        for (int y = 0; y < 1000; y++) {
          _graph[x][y] = 0;
        }
      }
    }

    int get_coor(int x, int y) {
      return _graph[x][y];
    }

    void inc_coor(int x, int y) {
      _graph[x][y]++;
    }

    void make_line(int x1, int x2, int y1, int y2) {
      if (x1 == x2) {
        make_line_y(y1, y2, x1);
      } else if (y1 == y2) {
        make_line_x(x1, x2, y1);
      } else {
      }
    }

    int get_num_overlapping() {
      int sum = 0;
      for(int x = 0; x < 1000; x++) {
        for(int y = 0; y < 1000; y++) {
          if (_graph[x][y] > 1) {
            sum++;
          }
        }
      }
      return sum;
    }

    void print_graph() {
      std::cout << "--------------------------------" << '\n';
      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
          std::cout << _graph[i][j];
        }
        std::cout << std::endl;
      }
      std::cout << "--------------------------------" << '\n';
    }
};

int main() {
  std::ifstream f("input");
  std::string s;
  std::string coors[1000];
  int i = 0;
  while(std::getline(f, s)) {
    coors[i] = s;
    i++;
  }
  graph g = graph();
  for (int i = 0; i < 1000; i+=2) {
    int firstx = stoi(coors[i].substr(0, coors[i].find(",")));
    int firsty = stoi(coors[i].substr(coors[i].find(",") + 1, coors[i].length()));
    int secondx = stoi(coors[i + 1].substr(0, coors[i + 1].find(",")));
    int secondy = stoi(coors[i + 1].substr(coors[i + 1].find(",") + 1, coors[i + 1].length()));
    g.make_line(firstx, secondx, firsty, secondy);
  }
  g.print_graph();
  std::cout << g.get_num_overlapping() << std::endl;
  return 0;
}
