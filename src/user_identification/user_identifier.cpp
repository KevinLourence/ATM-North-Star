#include "user_identifier.h"

static const int kMaxLenghtOfLogin = 21;
static const int kMaxLenghtOfPassword = 4;

void UserIdentifier::SetLogin(const string &login) { login_ = login; }

void UserIdentifier::SetPassword(const UserIdentifier::string &password) {
  password_ = password;
}

UserIdentifier::string UserIdentifier::GetLogin() const { return login_; }

UserIdentifier::string UserIdentifier::GetPassword() const { return password_; }

void UserIdentifier::EnterInitialLogin() {
  getline(cin, login_);
  cin.sync();
}

void UserIdentifier::EnterinitialPassword() {
  cin >> password_;
  cin.sync();
}

bool UserIdentifier::IsNormalLogin() {
  return !login_.empty() && login_.length() < kMaxLenghtOfLogin;
}

bool UserIdentifier::IsNormalPass() {
  return password_.length() == kMaxLenghtOfPassword;
}

UserIdentifier::string UserIdentifier::GetPasswordFromUser() {
  string password;
  cin >> password;
  utility_.IgnoreCinLine();
  return password;
}
