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

int get_packet_id(std::string input) {
  return binary_to_decimal(input.substr(3, 3));
}

int get_packet_version(std::string input) {
  return binary_to_decimal(input.substr(0, 3));
}

int get_length(std::string input) {
  if (get_packet_id(input) == 4) {
    int i = 6;
    bool last_packet = false;
    std::string binary_output;
    while(!last_packet) {
      if (input.substr(i, 1) == "0") {
        last_packet = true;
      }
      binary_output += input.substr(i + 1, 4);
      i += 5;
    }
    return i;
  } else {
    if (input.substr(6, 1) == "0") {
      std::cout << "15 " << input.substr(7, 15) << std::endl;
      return 7 + 15 + binary_to_decimal(input.substr(7, 15));
    } else {
      std::cout << "11 " << binary_to_decimal(input.substr(7, 11)) << std::endl;
      return 7 + 11 + 11 * binary_to_decimal(input.substr(7, 11));
    }
  }
}

/* int get_packet(std::string input) { */
/*   if (get_packet_id(input) == 4) { */
/*     int i = 6; */
/*     bool last_packet = false; */
/*     std::string binary_output; */
/*     while(!last_packet) { */
/*       if (input.substr(i, 1) == "0") { */
/*         last_packet = true; */
/*       } */
/*       binary_output += input.substr(i + 1, 4); */
/*       i += 5; */
/*     } */
/*     std::cout << binary_output << std::endl; */
/*     return binary_to_decimal(binary_output); */
/*   } else { */
/*     int length; */
/*     hex_to_binary(input.substr(6, 1)) == "1" ? length = 11: length = 15; */
/*     int i = 7; */
/*     bool last_packet = false; */
/*     std::string binary_output; */
/*     while(!last_packet) { */
/*       if (input.substr(i, 1) == "0") { */
/*         last_packet = true; */
/*       } */
/*       binary_output += input.substr(i + 1, length); */
/*       i += length + 1; */
/*     } */
/*     std::cout << binary_output << std::endl; */
/*     return binary_to_decimal(binary_output); */
/*   } */
/* } */

int main() {
  std::ifstream f("16input.txt");
  std::string s;
  f >> s;
  std::string binary = hex_to_binary(s);
  int sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += get_packet_version(binary);
    std::cout << binary <<std::endl;
    binary = binary.substr(get_length(binary));
    std::cout << binary <<std::endl;
  }
  return 0;
}
