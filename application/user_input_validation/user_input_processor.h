﻿#ifndef USER_INPUT_PROCESSOR
#define USER_INPUT_PROCESSOR

#include <string>

class UserInputProcessor {
 public:
  virtual ~UserInputProcessor();

  virtual int GetUserInput();

  std::string GetStringFromUser();

 protected:
  bool IsContainOnlyDigits(const std::string& user_string);
  int GetDigitsFromString(const std::string& user_string);

 private:
  int kInvalidChoice = -1;
};

#endif  // USER_INPUT_PROCESSOR