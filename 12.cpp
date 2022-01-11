#include <iostream>
#include <fstream>
#include <regex>

class Cave {
  private:
    std::string name;
    std::vector<std::string> connections;
  public:

    Cave(std::string s) {
      name = s;
    }

    std::string get_name() {
      return name;
    }

    bool is_start() {
      return name == "start";
    }

    bool is_end() {
      return name == "end";
    }

    bool is_big_cave() {
      return !std::regex_match(name, std::regex("^[a-z]+$"));
    }

    void add_connection(Cave c) {
      connections.push_back(c.get_name());
    }

    std::vector<std::string> get_connections() {
      return connections;
    }

    Cave get_connection(int index) {
      return connections[index];
    }

    int get_num_connections() {
      return connections.size();
    }

};

class Map {
  private:
    std::vector<Cave> caves;
  public:

    Map() {}

    void add_cave(std::string name) {
      Cave c(name);
      caves.push_back(c);
    }

    Cave get_cave(std::string name) {
      for (int i = 0; i < caves.size(); i++) {
        if (caves[i].get_name() == name) {
          return caves[i];
        }
      }
      std::cout << "error" << std::endl;
      return caves[0];
    }

    bool has_cave(std::string name) {
      for (int i = 0; i < caves.size(); i++) {
        if (caves[i].get_name() == name) {
          return true;
        }
      }
      return false;
    }

    void add_pair(std::string name1, std::string name2) {
      if (!has_cave(name1)) {
        add_cave(name1);
      }
      if (!has_cave(name2)) {
        add_cave(name2);
      }
      get_cave(name1).add_connection(get_cave(name2));
      get_cave(name2).add_connection(get_cave(name1));
    }

    void print_map() {
      for (int i = 0; i < caves.size(); i++) {
        std::cout << "Cave " << caves[i].get_name() << ": ";
        for (int j = 0; j < caves[i].get_connections().size(); j++) {
          std::cout << "hi";
          std::cout << caves[i].get_connections()[j] << " ";
        }
        std::cout << std::endl;
      }
    }

};

int main() {
  std::ifstream f("12testinput.txt");
  Map m;
  std::string s1;
  std::string s2;
  while (f >> s1 >> s2) {
    m.add_pair(s1, s2);
  }
  m.print_map();
  return 0;
}
