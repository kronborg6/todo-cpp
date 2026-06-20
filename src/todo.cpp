
#include "todo.hpp"
#include "file.hpp"
#include <iostream>
#include <string>

void Todo::updateName(std::string newName) { name_ = newName; }

int main(void) {

  File file = File("./log/");
  Todo todo = Todo("run", "do a 7k run");
  // std::cout << todo.getName() << std::endl;
  todo.updateName("7k run");
  // std::cout << todo.getName() << std::endl;
  file.save();

  return 0;
}
