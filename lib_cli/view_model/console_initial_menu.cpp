﻿#include <console_initial_menu.h>

#include <initial_messenger.h>

void ConsoleInitialMenu::RunInitialMenu() {
  InitialMessenger::DisplayInitialMenu();
  ProcessUserInput();
}

void ConsoleInitialMenu::DisplayFarewellMessage() const {
  InitialMessenger::FarewellMessage();
}

ConsoleInitialMenu::SubMenu ConsoleInitialMenu::GetSubMenu() {
  return static_cast<ConsoleInitialMenu::SubMenu>(user_input_);
}

void ConsoleInitialMenu::ProcessUserInput() {
  for (;;) {
    user_input_ = user_input_handler_.GetDigitInputFromUser();
    if (IsInputContainSubMenu()) {
      break;
    } else {
      InitialMessenger::ShowIncorrectMenuInput();
    }
  }
}

void ConsoleInitialMenu::RunSplashScreen() const {
  InitialMessenger::DisplaySplashScreen();
}

bool ConsoleInitialMenu::IsInputContainSubMenu() {
  if (user_input_ == kLoginMenu) {
    return true;
  }
  if (user_input_ == kRegistrationMenu) {
    return true;
  }
  if (user_input_ == kDescriptionMenu) {
    return true;
  }
  if (user_input_ == kQuit) {
    return true;
  }
  return false;
}
