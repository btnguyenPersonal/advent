#include <iostream>
#include <fstream>
#include <string>

std::string decrypt(std::string cipher[200][15]) {
  std::string output = "";
  /*
     .0..
     1    2
     .    .
     ..3.
     .    .
     4    5
     ..6..
     */
  for (int line = 0; line < 200; line++) {
    std::string key[7] = {"","","","","","",""};
    // get create key
    // should go from smallest to largest length
    for (int i = 0; i < 10; i++) {
      std::string input = cipher[line][i];
      switch(input.length()) {
        case 2: // must be 1
          key[2] += input.substr(0,1);
          key[2] += input.substr(1,2);
          key[3] += input.substr(0,1);
          key[3] += input.substr(1,2);
          break;
        case 3: // must be 7
          key[0] += input.substr(0,1);
          key[0] += input.substr(1,2);
          key[0] += input.substr(2,3);
          key[2] += input.substr(0,1);
          key[2] += input.substr(1,2);
          key[2] += input.substr(2,3);
          key[3] += input.substr(0,1);
          key[3] += input.substr(1,2);
          key[3] += input.substr(2,3);
          break;
        case 4: // must be 4
          key[1] += input.substr(0,1);
          key[1] += input.substr(1,2);
          key[1] += input.substr(2,3);
          key[1] += input.substr(3,4);
          key[2] += input.substr(0,1);
          key[2] += input.substr(1,2);
          key[2] += input.substr(2,3);
          key[2] += input.substr(3,4);
          key[3] += input.substr(0,1);
          key[3] += input.substr(1,2);
          key[3] += input.substr(2,3);
          key[3] += input.substr(3,4);
          key[5] += input.substr(0,1);
          key[5] += input.substr(1,2);
          key[5] += input.substr(2,3);
          key[5] += input.substr(3,4);
          break;
        case 5: // could be 2, 3, 5
          key[0] += input.substr(0,1);
          key[0] += input.substr(1,2);
          key[0] += input.substr(2,3);
          key[0] += input.substr(3,4);
          key[0] += input.substr(4,5);
          key[1] += input.substr(0,1);
          key[1] += input.substr(1,2);
          key[1] += input.substr(2,3);
          key[1] += input.substr(3,4);
          key[1] += input.substr(4,5);
          key[2] += input.substr(0,1);
          key[2] += input.substr(1,2);
          key[2] += input.substr(2,3);
          key[2] += input.substr(3,4);
          key[2] += input.substr(4,5);
          key[3] += input.substr(0,1);
          key[3] += input.substr(1,2);
          key[3] += input.substr(2,3);
          key[3] += input.substr(3,4);
          key[3] += input.substr(4,5);
          key[4] += input.substr(0,1);
          key[4] += input.substr(1,2);
          key[4] += input.substr(2,3);
          key[4] += input.substr(3,4);
          key[4] += input.substr(4,5);
          key[5] += input.substr(0,1);
          key[5] += input.substr(1,2);
          key[5] += input.substr(2,3);
          key[5] += input.substr(3,4);
          key[5] += input.substr(4,5);
          key[6] += input.substr(0,1);
          key[6] += input.substr(1,2);
          key[6] += input.substr(2,3);
          key[6] += input.substr(3,4);
          key[6] += input.substr(4,5);
          break;
        case 6:
          break;
        default:
          key[0] += 'abcdefg';
          key[1] += 'abcdefg';
          key[2] += 'abcdefg';
          key[3] += 'abcdefg';
          key[4] += 'abcdefg';
          key[5] += 'abcdefg';
          key[6] += 'abcdefg';
          break;
      }
    }
    for (int i = 0; i < 7; i++) {
      std::cout << key[i] << std::endl;
    }
    // decrypt output
    for (int i = 11; i < 15; i++) {
    }
  }
  return output;
}

int main () {
  std::ifstream f("8input.txt");
  std::string cipher[200][15];
  int i = 0;
  while (f
      >> cipher[i][0]
      >> cipher[i][1]
      >> cipher[i][2]
      >> cipher[i][3]
      >> cipher[i][4]
      >> cipher[i][5]
      >> cipher[i][6]
      >> cipher[i][7]
      >> cipher[i][8]
      >> cipher[i][9]
      >> cipher[i][10]
      >> cipher[i][11]
      >> cipher[i][12]
      >> cipher[i][13]
      >> cipher[i][14]
      ) {
    i++;
  }
  decrypt(cipher);
  return 0;
}
