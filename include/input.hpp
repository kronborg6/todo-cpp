#pragma once

// #include <iostream>
// #include <ncurses.h>

struct InputState {
    int cursor_postion = 0;
};

enum class key_type {
  KEY_UP,
  KEY_DOWN,
  KEY_RIGHT,
  KEY_LEFT,
  NONE,
  OTHER
};

struct key_pressed {
    key_type key;
    char chather;
    int key_pressed;
};

void key_input();
