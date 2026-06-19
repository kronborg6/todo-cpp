#pragma once

#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
class File {
public:
  File(std::string d) {
    std::cout << d << std::endl;
    if (d.empty())
      throw std::invalid_argument("dir cannot be emtpy");

    char buffer[80];
    dir = d;

    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);

    std::tm tm = *std::localtime(&t);

    std::strftime(buffer, sizeof(buffer), "log %Y-%m-%d %H-%M-%S.txt", &tm);

    std::ofstream outFile(dir + buffer);

    if (!outFile)
      throw std::runtime_error(
          "failed to create file, make sure the path is cronect");

    name = buffer;
  };
  void save();

private:
  std::string dir;
  std::string name;
};
