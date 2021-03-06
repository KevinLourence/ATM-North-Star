﻿#include "atm_user.h"

void AtmUser::SetLogin(const std::string& login) {
  identification_data_.SetLogin(login);
}

void AtmUser::SetPassword(const std::string& password) {
  identification_data_.SetPassword(password);
}

void AtmUser::SetCash(double cash) { cash_data_.SetCash(cash); }

void AtmUser::AddCash(double cash) { cash_data_.AddCash(cash); }

void AtmUser::WithdrawCash(double cash) { cash_data_.WithdrawCash(cash); }

void AtmUser::SetCreditSum(double credit_sum) {
  credit_data_.SetCreditSum(credit_sum);
}

void AtmUser::SetCreditTerm(int credit_term) {
  credit_data_.SetCreditTerm(credit_term);
}

void AtmUser::SetInterestRate(double interest_rate) {
  credit_data_.SetInterestRate(interest_rate);
}

void AtmUser::SetMonthlyPayment(double monthly_payment) {
  credit_data_.SetMonthlyPayment(monthly_payment);
}

void AtmUser::ResetData() {
  SetLogin("");
  SetPassword("");
  SetCash(0.0);
  SetCreditSum(0.0);
  SetCreditTerm(0);
  SetInterestRate(0.0);
  SetMonthlyPayment(0.0);
}

std::string AtmUser::Login() const { return identification_data_.Login(); }

std::string AtmUser::Password() const {
  return identification_data_.Password();
}

double AtmUser::Cash() const { return cash_data_.Cash(); }

double AtmUser::CreditSum() const { return credit_data_.CreditSum(); }

int AtmUser::CreditTerm() const { return credit_data_.CreditTerm(); }

double AtmUser::InterestRate() const { return credit_data_.InterestRate(); }

double AtmUser::MonthlyPayment() const { return credit_data_.MonthlyPayment(); }
