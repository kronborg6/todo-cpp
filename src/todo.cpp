
#include "todo.hpp"
#include "file.hpp"
#include <cstddef>
#include <filesystem>
#include <format>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

void Todo::updateName(std::string newName) { name_ = newName; }

int main(void) {

  // File file = File("./log/");
  // Todo todo = Todo("run", "do a 7k run");
  // todo.updateName("7k run");
  // file.save();

  std::vector<File> files;
  std::string path = "/home/kronborg/project/todo-cpp/log/";

  if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {
    for (auto entry : std::filesystem::directory_iterator(path)) {
      // File f(entry.path().filename());

      std::string fullpath = path + entry.path().filename().string();
      files.push_back(File(std::move(fullpath)));
    }
  } else {
    throw std::invalid_argument("path is wong");
  }

  size_t current_count = files.size();

  std::cout << "pick a todo\n";
  for (size_t i = 0; i < current_count; i++) {

    std::cout << std::format("[{}]: ", i) << files[i].getName() << std::endl;
  }

  int pick;

  std::cin >> pick;

  std::cout << pick << std::endl;

  if (pick > static_cast<int>(current_count)) {
    std::cout << "wong number stubid" << std::endl;
  }

  for (const auto &todo : files[static_cast<size_t>(pick)].todoList) {
    std::cout << todo.getName() << std::endl;
    std::cout << todo.getName() << std::endl;
    std::cout << todo.getName() << std::endl;
    std::cout << todo.getName() << std::endl;
  }

  return 0;
}
