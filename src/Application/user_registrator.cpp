#include "user_registrator.h"

void UserRegistrator::RegisterUser(CashOperator &cash_operator,
                                   UserIdentifier &user_identifier) {
  set_is_correct_registration(false);

  registation_messenger_.ShowRegistrationScreen();

  EnterLogin(user_identifier);
  if (user_identifier.IsNormalLogin()) {
    EnterPassword(user_identifier);
    if (user_identifier.IsNormalPass()) {
      notice_messenger_.ShowAcceptableMessageFrame();
      AssignInitialValues(cash_operator);
      set_is_correct_registration(true);
    } else {
      notice_messenger_.ShowIncorrectFormatPassword();
    }
  } else {
    notice_messenger_.ShowIncorrectLoginFrame();
  }
}

bool UserRegistrator::IsCorrectRegistration() { return correct_registration_; }

void UserRegistrator::EnterLogin(UserIdentifier &user_identifier) {
  identification_messenger_.ShowInitialLoginText();
  user_identifier.SetLogin(provider_.GetLoginFromUser());
}

void UserRegistrator::EnterPassword(UserIdentifier &user_identifier) {
  identification_messenger_.ShowInitialPasswordText();
  user_identifier.SetPassword(provider_.GetPasswordFromUser());
}

void UserRegistrator::set_is_correct_registration(bool correct_registration) {
  correct_registration_ = correct_registration;
}

void UserRegistrator::AssignInitialValues(CashOperator &cash_operator) {
  cash_operator.SetCash(0);
  cash_operator.SetCredit(0);
  cash_operator.SetMonthlyPayment(0.0);
  cash_operator.SetAmountOfCreditMonth(0);
}
