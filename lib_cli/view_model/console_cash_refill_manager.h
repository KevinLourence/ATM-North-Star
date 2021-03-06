﻿#ifndef CONSOLE_CASH_REFILL_MANAGER_H
#define CONSOLE_CASH_REFILL_MANAGER_H

#include <user_input_handler.h>

class ConsoleCashRefillManager {
 public:
  void RunRefillMenu();
  void ShowCorrectRefillingNotification() const;
  void ShowIncorrectRefillingNotification() const;

  int SumOfCash() const;
  bool UserWantQuit() const;

 private:
  enum SubMenuItems { kNull, kMainMenu, kQuit };

  void ProcessUserInput();
  bool IsUserInputCorrect(int user_input);

  void ResetManipulationFlags();

  UserInputHandler user_input_handler_;

  bool user_want_quit_ = false;

  int sum_of_cash_ = 0;
};

#endif  // CONSOLE_CASH_REFILL_MANAGER_H
