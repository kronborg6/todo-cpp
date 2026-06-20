
#include "file.hpp"
#include "string_utils.hpp"
#include "todo.hpp"

#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

File::File(std::string d) {
  std::cout << d << std::endl;
  if (d.empty())
    throw std::invalid_argument("dir cannot be emtpy");

  todoList.reserve(15);
  // Todo todo("hello", "g");
  // std::cout << todo.getName() << std::endl;
  // todoList.push_back(todo);

  char buffer[80];
  dir = d;

  auto now = std::chrono::system_clock::now();
  std::time_t t = std::chrono::system_clock::to_time_t(now);

  std::tm tm = *std::localtime(&t);

  std::strftime(buffer, sizeof(buffer), "todo %Y-%m-%d.txt", &tm);

  // load into the todo list
  std::string line;
  std::ifstream readFile(d + buffer);
  while (std::getline(readFile, line)) {
    std::cout << line << std::endl;
    std::vector<std::string> l = utils::split(line, ";");
    if (l.size() == 3) {
      if (l[2] == "Complted") {
        Todo t(l[0], l[1], true);
        todoList.push_back(t);
      } else {
        Todo t(l[0], l[1], false);
        todoList.push_back(t);
      }
    }
  }

  name = buffer;
};

void File::openFile(std::string path, bool overwrite = false) {
  std::cout << path << std::endl;
  if (overwrite)
    file.open(path);
  else
    file.open(path, std::ios::app);

  if (!file)
    throw std::runtime_error(
        "failed to create file, make sure the path is cronect");
}

void File::save() {
  openFile(dir + name, true);
  for (const auto &todo : todoList) {
    std::string complted = todo.iscomplte() ? "complted" : "notComplted";
    file << todo.getName() << ";" << todo.getDesc() << ";" << complted
         << std::endl;
  }
  close();
}
