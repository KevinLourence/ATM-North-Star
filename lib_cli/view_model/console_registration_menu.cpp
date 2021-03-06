﻿#include <console_registration_menu.h>

#include <confirmation_animator.h>
#include <password_input_handler.h>

void ConsoleRegistrationMenu::RunRegistrationMenu() {
  RegistrationMessenger::ShowRegistrationLogo();
  RegistrationMessenger::ShowRegistrationReference();
  ProcessMenuUserInput(user_want_to_registrate_);
}

void ConsoleRegistrationMenu::ReceiveRegistrationDataFromUser() {
  RegistrationMessenger::ClearScreen();
  RegistrationMessenger::ShowRegistrationLogo();
  GetLoginStringFromUser();
  GetPasswordStringFromUser();
}

void ConsoleRegistrationMenu::RunRegistrationConfirmation() {
  RegistrationMessenger::ShowConfirmationMessage();
  ProcessMenuUserInput(registration_confirmed_);
}

void ConsoleRegistrationMenu::RunIncorrectRegistrationNotification() {
  RegistrationMessenger::IncorrectRegistrationNotification();
  ProcessMenuUserInput(user_want_to_repeat_registration_);
}

void ConsoleRegistrationMenu::ShowConfirmationAnimation(
    const std::string& login_string,
    const std::vector<std::string>& processes_report) const {
  ConfirmationAnimator::SeFrameBasedOnLoginSymbols(login_string);
  ConfirmationAnimator::SetProcessesReport(processes_report);
  ConfirmationAnimator::ShowAnimation();
}

std::string ConsoleRegistrationMenu::LoginString() const { return login_; }

std::string ConsoleRegistrationMenu::PasswordString() const {
  return password_;
}

bool ConsoleRegistrationMenu::IsUserWantToRegistrate() const {
  return user_want_to_registrate_;
}

bool ConsoleRegistrationMenu::IsUserWantToRepeatRegistrate() const {
  return user_want_to_repeat_registration_;
}

bool ConsoleRegistrationMenu::IsUserWantToExitProgram() const {
  return user_want_to_quit_;
}

bool ConsoleRegistrationMenu::IsRegistrationConfirmed() const {
  return registration_confirmed_;
}

bool ConsoleRegistrationMenu::IsUserWantToInitialMenu() const {
  return user_want_to_initial_menu_;
}

void ConsoleRegistrationMenu::ShowLoginReport(
    const CONSOLE::RegistrationStatus login_status) const {
  reporter_.ShowLoginReport(login_status);
}

void ConsoleRegistrationMenu::ShowPasswordReport(
    const CONSOLE::RegistrationStatus password_status) const {
  reporter_.ShowPasswordReport(password_status);
}

void ConsoleRegistrationMenu::ProcessMenuUserInput(bool& action) {
  int user_input = 0;
  for (;;) {
    ResetManipulationFlags();
    user_input = input_handler_.GetDigitInputFromUser();
    if (user_input == kAction) {
      action = true;
      break;
    } else if (user_input == kInitialMenu) {
      user_want_to_initial_menu_ = true;
      break;
    } else if (user_input == kQuit) {
      user_want_to_quit_ = true;
      break;
    } else {
      RegistrationMessenger::ShowIncorrectInput();
    }
  }
}

void ConsoleRegistrationMenu::ResetManipulationFlags() {
  user_want_to_registrate_ = false;
  user_want_to_quit_ = false;
  registration_confirmed_ = false;
  user_want_to_repeat_registration_ = false;
  user_want_to_initial_menu_ = false;
}

void ConsoleRegistrationMenu::GetLoginStringFromUser() {
  RegistrationMessenger::ShowLoginTitle();
  login_ = input_handler_.GetStringInputFromUser();
}

void ConsoleRegistrationMenu::GetPasswordStringFromUser() {
  RegistrationMessenger::ShowPasswordTitle();
  password_ = PasswordInputHandler::GetPassword();
}
