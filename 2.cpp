#include <fstream>
#include <string>
#include <iostream>

int calc_pos(std::string direc[], int dist[]) {
  int x = 0;
  int depth = 0;
  int aim = 0;
  for (int i = 0; i < 1000; i++) {
    if (direc[i].compare("forward") == 0) {
      x += dist[i];
      depth += aim * dist[i];
    } else if (direc[i].compare("up") == 0) {
      aim -= dist[i];
    } else if (direc[i].compare("down") == 0) {
      aim += dist[i];
    }
  }
  return x * depth;
}

int main() {

  std::ifstream infile("input.txt");

  std::string a;
  int b;
  std::string dir[1000];
  int dis[1000];
  int i = 0;
  while (infile >> a >> b) {
    dir[i] = a;
    dis[i] = b;
    i++;
  }
  std::cout << calc_pos(dir, dis) << std::endl;
  return 0;
}
