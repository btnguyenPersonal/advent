#include <fstream>
#include <iostream>
#include <iterator>
#include <math.h>

int get_oxy_place(int input[12][1000], int pos, int lastnum[1000]) {
  int sum = 0;
  for (int i = 0; i < 1000; i++) {
    if (lastnum[i] == 1)
      input[pos][i] == 1 ? sum += 1 : sum -= 1;
  }
  std::cout << "sum = " << sum << std::endl;
  if sum == 0
    return 0;
  return sum > 0 ? 1 : 0;
}

int get_co_place(int input[12][1000], int pos, int lastnum[1000]) {
  int sum = 0;
  for (int i = 0; i < 1000; i++) {
    if (lastnum[i] == 1)
      input[pos][i] == 1 ? sum += 1 : sum -= 1;
  }
  std::cout << "sum = " << sum << std::endl;
  if (sum == 0)
    return 0;
  return sum > 0 ? 0 : 1;
}

bool is_one_left(int input[1000]) {
  bool foundOne = false;
  for(int i = 0; i < 1000; i++) {
    if (foundOne && input[i] == 1) {
      return false;
    } else if (input[i] == 1) {
      foundOne = true;
    }
  }
  return true;
}

int get_num_left(int input[1000]) {
  int sum = 0;
  for (int i = 0; i < 1000; i++) {
    sum += input[i];
  }
  return sum;
}

int get_co(int input[12][1000]) {
  int lastnum[1000];
  for(int i = 0; i < 1000; i++) {
    lastnum[i] = 1;
  }
  int lastbit = 0;
  while(!is_one_left(lastnum)) {
    int divider = get_co_place(input, lastbit, lastnum);
    int numdiv = 0;
    for (int i = 0; i < 1000; i++) {
      if (input[lastbit][i] != divider) {
        if (lastnum[i] == 1) {
          numdiv++;
        }
        lastnum[i] = 0;
      }
    }
    std::cout << numdiv << std::endl;
    lastbit++;
  }
  for(int i = 0; i < 1000; i++) {
    if (lastnum[i] == 1) {
      std::cout << input[0][i]
        << input[1][i]
        << input[2][i]
        << input[3][i]
        << input[4][i]
        << input[5][i]
        << input[6][i]
        << input[7][i]
        << input[8][i]
        << input[9][i]
        << input[10][i]
        << input[11][i]
        << std::endl;
      return pow(2, 0 ) * input[11][i] +
        pow(2, 1 )* input[10][i]  +
        pow(2, 2 )* input[9][i]  +
        pow(2, 3 )* input[8][i]  +
        pow(2, 4 )* input[7][i]  +
        pow(2, 5 )* input[6][i]  +
        pow(2, 6 )* input[5][i]  +
        pow(2, 7 )* input[4][i]  +
        pow(2, 8 )* input[3][i]  +
        pow(2, 9 )* input[2][i]  +
        pow(2, 10) * input[1][i] +
        pow(2, 11) * input[0][i];
    }
  }
  return -1;
}

int get_oxy(int input[12][1000]) {
  int lastnum[1000];
  for(int i = 0; i < 1000; i++) {
    lastnum[i] = 1;
  }
  int lastbit = 0;
  while(!is_one_left(lastnum)) {
    int divider = get_oxy_place(input, lastbit, lastnum);
    int numdiv = 0;
    for (int i = 0; i < 1000; i++) {
      if (input[lastbit][i] != divider) {
        if (lastnum[i] == 1) {
          numdiv++;
        }
        lastnum[i] = 0;
      }
    }
    std::cout << numdiv << std::endl;
    lastbit++;
  }
  for(int i = 0; i < 1000; i++) {
    if (lastnum[i] == 1) {
      std::cout << input[0][i]
        << input[1][i]
        << input[2][i]
        << input[3][i]
        << input[4][i]
        << input[5][i]
        << input[6][i]
        << input[7][i]
        << input[8][i]
        << input[9][i]
        << input[10][i]
        << input[11][i]
        << std::endl;
      return pow(2, 0 )* input[11][i] +
        pow(2, 1 )* input[10][i]  +
        pow(2, 2 )* input[9][i]  +
        pow(2, 3 )* input[8][i]  +
        pow(2, 4 )* input[7][i]  +
        pow(2, 5 )* input[6][i]  +
        pow(2, 6 )* input[5][i]  +
        pow(2, 7 )* input[4][i]  +
        pow(2, 8 )* input[3][i]  +
        pow(2, 9 )* input[2][i]  +
        pow(2, 10) * input[1][i] +
        pow(2, 11) * input[0][i];
    }
  }
  return -1;
}

int get_life_support(int input[12][1000]) {
  return get_oxy(input) * get_co(input);
}

int main() {
  std::ifstream infile("input.txt");
  int a0;
  int a1;
  int a2;
  int a3;
  int a4;
  int a5;
  int a6;
  int a7;
  int a8;
  int a9;
  int a10;
  int a11;
  int b[12][1000];
  int i = 0;
  while (infile
      >> a0
      >> a1
      >> a2
      >> a3
      >> a4
      >> a5
      >> a6
      >> a7
      >> a8
      >> a9
      >> a10
      >> a11
      ) {
    b[0][i] = a0;
    b[1][i] = a1;
    b[2][i] = a2;
    b[3][i] = a3;
    b[4][i] = a4;
    b[5][i] = a5;
    b[6][i] = a6;
    b[7][i] = a7;
    b[8][i] = a8;
    b[9][i] = a9;
    b[10][i] = a10;
    b[11][i] = a11;
    i++;
  }
  std::cout << get_oxy(b) << std::endl;
  std::cout << get_co(b) << std::endl;
  std::cout << get_life_support(b) << std::endl;
  return 0;
}
