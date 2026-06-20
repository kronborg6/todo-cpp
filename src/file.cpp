
#include "file.hpp"

#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <memory>
#include <ostream>
#include <stdexcept>
#include <string>

File::File(std::string d) {
  std::cout << d << std::endl;
  if (d.empty())
    throw std::invalid_argument("dir cannot be emtpy");

  todoList.reserve(15);
  Todo todo("hello", "g");
  std::cout << todo.getName() << std::endl;
  todoList.push_back(todo);

  char buffer[80];
  dir = d;

  auto now = std::chrono::system_clock::now();
  std::time_t t = std::chrono::system_clock::to_time_t(now);

  std::tm tm = *std::localtime(&t);

  std::strftime(buffer, sizeof(buffer), "todo %Y-%m-%d.txt", &tm);

  // openFile(d + buffer);
  // // load into the todo list
  // close();

  name = buffer;
};

void File::openFile(std::string path) {
  file.open(path, std::ios::app);

  if (!file)
    throw std::runtime_error(
        "failed to create file, make sure the path is cronect");
}

void File::save() {
  openFile(dir + name);
  for (const auto &todo : todoList) {
    std::string complted = todo.iscomplte() ? "complted" : "notComplted";
    file << todo.getName() << ";" << todo.getDesc() << ";" << complted
         << std::endl;
  }
  close();
}
