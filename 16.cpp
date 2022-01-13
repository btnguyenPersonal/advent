#include <iostream>
#include <fstream>

std::string hex_to_binary(std::string input) {
  std::string output = "";
  for (int i = 0; i < input.length(); i++) {
    if (input.substr(i, 1) == "0") { output += "0000"; }
    if (input.substr(i, 1) == "1") { output += "0001"; }
    if (input.substr(i, 1) == "2") { output += "0010"; }
    if (input.substr(i, 1) == "3") { output += "0011"; }
    if (input.substr(i, 1) == "4") { output += "0100"; }
    if (input.substr(i, 1) == "5") { output += "0101"; }
    if (input.substr(i, 1) == "6") { output += "0110"; }
    if (input.substr(i, 1) == "7") { output += "0111"; }
    if (input.substr(i, 1) == "8") { output += "1000"; }
    if (input.substr(i, 1) == "9") { output += "1001"; }
    if (input.substr(i, 1) == "A") { output += "1010"; }
    if (input.substr(i, 1) == "B") { output += "1011"; }
    if (input.substr(i, 1) == "C") { output += "1100"; }
    if (input.substr(i, 1) == "D") { output += "1101"; }
    if (input.substr(i, 1) == "E") { output += "1110"; }
    if (input.substr(i, 1) == "F") { output += "1111"; }
  }
  return output;
}

int binary_to_decimal(std::string input) {
  int output = 0;
  int mult = 1;
  for (int i = input.length() - 1; i >= 0; i--) {
    std::string temp = input.substr(i, 1);
    output += mult * stoi(temp);
    mult *= 2;
  }
  return output;
}

int main() {
  std::cout << binary_to_decimal("011111100101") << std::endl;
  return 0;
}

