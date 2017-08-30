﻿#include <console_account_informer.h>

#include <account_messenger.h>

ConsoleAccountInformer::ConsoleAccountInformer() { FillTitles(); }

void ConsoleAccountInformer::SetAccountInfo(
    const std::vector<std::string>& account_info) {
  account_info_ = account_info;
}

void ConsoleAccountInformer::ShowAccountInfo() const {}

void ConsoleAccountInformer::FillTitles() {
  info_title_.push_back(AccountMessenger::LoginText());
  info_title_.push_back(AccountMessenger::CashText());
  info_title_.push_back(AccountMessenger::CreditText());
  info_title_.push_back(AccountMessenger::PaymentText());
  info_title_.push_back(AccountMessenger::InterestRateText());
  info_title_.push_back(AccountMessenger::CreditTermText());
}
