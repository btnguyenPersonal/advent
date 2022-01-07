#include <iostream>
#include <fstream>
#include <cmath>

int get_pos(int crabs[1000]) {
  int leastsum = -1;
  int leastindex = -1;
  for (int i = 0; i < 1884; i++) {
    int sum = 0;
    for (int c = 0; c < 1000; c++) {
      for (int j = 1; j <= std::abs(crabs[c] - i);j++) {
        sum += j;
      }
    }
    if (leastsum > sum || leastsum == -1) {
      leastsum = sum;
      leastindex = i;
    }
  }
  return leastsum;
}

int main() {
  std::ifstream f("7input.txt");
  std::string s;
  int crabs[1000];
  int i = 0;
  while (std::getline(f, s)) {
    crabs[i] = stoi(s);
    i++;
  }
  std::cout << get_pos(crabs) << std::endl;
  return 0;
}
