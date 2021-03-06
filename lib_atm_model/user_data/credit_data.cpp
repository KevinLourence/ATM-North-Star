﻿#include "credit_data.h"

CreditData::CreditData()
    : credit_sum_(0.0),
      credit_term_(0),
      interest_rate_(0.0),
      monthly_payment_(0.0) {}

void CreditData::SetCreditSum(double credit_sum) { credit_sum_ = credit_sum; }

void CreditData::SetCreditTerm(int credit_term) { credit_term_ = credit_term; }

void CreditData::SetInterestRate(double interest_rate) {
  interest_rate_ = interest_rate;
}

void CreditData::SetMonthlyPayment(double monthly_payment) {
  monthly_payment_ = monthly_payment;
}

double CreditData::CreditSum() const { return credit_sum_; }

int CreditData::CreditTerm() const { return credit_term_; }

double CreditData::InterestRate() const { return interest_rate_; }

double CreditData::MonthlyPayment() const { return monthly_payment_; }
