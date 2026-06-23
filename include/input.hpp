#pragma once

#include <iostream>
#include <ncurses.h>

struct InputState {
  int cursor_postion = 0;
};

void key_input();
