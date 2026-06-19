#pragma once

#include <string>
class Todo {
public:
  Todo(std::string name, std::string desc) : name(name), desc(desc) {}

  bool iscomplte() const { return complete; }
  void markCompleted() { complete = true; }
  void updateName(std::string);
  std::string getName() const { return name; }

private:
  std::string name;
  std::string desc;
  bool complete = false;
};
