﻿#ifndef INITIAL_INPUT_H
#define INITIAL_INPUT_H

#include <string>

class InitialInput {
 public:
  static int GetValueFromUser();

 private:
  static std::string GetString();
  static bool IsContainExitCharacter(const std::string& user_string);
  static bool IsDigit(const std::string& user_string);
  static int ConvertToDigit(const std::string& user_string);

  static constexpr int kConsoleMode = 1;
  static constexpr int kGuiMode = 2;
  static constexpr int kExit = 0;
  static constexpr int kInvalidChoice = -1;
};

#endif  // INITIAL_INPUT_H
