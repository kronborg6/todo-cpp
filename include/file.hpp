#pragma once

#include <string>
class File {
public:
  File(std::string d);
  void save();

private:
  std::string dir;
  std::string name;
};
