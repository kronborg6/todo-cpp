#pragma once

#include <string>
class Todo {
public:
  Todo(std::string name, std::string desc) : name(name), desc(desc) {}
  Todo(std::string name, std::string desc, bool complete)
      : name(name), desc(desc), complete_(complete) {}

  bool iscomplte() const { return complete_; }
  void markCompleted() { complete_ = true; }
  void updateName(std::string);
  std::string getName() const { return name; }
  std::string getDesc() const { return desc; }

private:
  std::string name;
  std::string desc;
  bool complete_ = false;
};
