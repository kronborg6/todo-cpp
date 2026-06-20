#pragma once

#include "todo.hpp"
#include <fstream>
#include <string>
#include <vector>
class File {
public:
  File(std::string d);
  void save();

private:
  std::ofstream file;
  // std::ofstream *file = nullptr;
  std::string dir;
  std::string name;
  std::vector<Todo> todoList;

  void openFile(std::string path, bool overRide);
  void close() { file.close(); }
};
