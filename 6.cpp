#include <iostream>
#include <fstream>
#include <vector>

long long run_generations(long long fish[9]) {
  for (int g = 0; g < 256; g++) {
    long long temp = fish[0];
    fish[0] = fish[1];
    fish[1] = fish[2];
    fish[2] = fish[3];
    fish[3] = fish[4];
    fish[4] = fish[5];
    fish[5] = fish[6];
    fish[6] = fish[7] + temp;
    fish[7] = fish[8];
    fish[8] = temp;
    long long sum = 0;
    for (int i = 0; i < 9; i++) {
      sum += fish[i];
    }
    std::cout << sum << std::endl;
  }
  long long sum = 0;
  for (int i = 0; i < 9; i++) {
    sum += fish[i];
  }
  return sum;
}

int main() {
  std::ifstream f("6input.txt");
  std::string s;
  long long fish[9] = {0,0,0,0,0,0,0,0,0};
  while(std::getline(f, s)) {
    fish[(long long) std::stoi(s)]++;
  }
  std::cout << run_generations(fish) << std::endl;
}

