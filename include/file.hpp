#pragma once

#include "todo.hpp"
#include <fstream>
#include <string>
#include <vector>
class File {
  public:
    std::vector<Todo> todoList;
    File(std::string d);
    std::string getName() const {
      return name_;
    }
    void save();

  private:
    std::ofstream file;
    // std::ofstream *file = nullptr;
    std::string dir;
    std::string name_;

    void openFile(std::string path, bool overRide);
    void close() {
      file.close();
    }
};
