#pragma once

#include <string>
class Todo {
  public:
    Todo(std::string name, std::string desc) : name_(name), desc_(desc) {
    }
    Todo(std::string name, std::string desc, bool complete)
        : name_(name), desc_(desc), complete_(complete) {
    }

    bool iscomplte() const {
      return complete_;
    }
    void markCompleted() {
      complete_ = true;
    }
    void updateName(std::string);
    std::string getName() const {
      return name_;
    }
    std::string getDesc() const {
      return desc_;
    }

  private:
    std::string name_;
    std::string desc_;
    bool complete_ = false;
};
