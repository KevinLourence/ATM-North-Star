#ifndef INITIAL_SCREEN_H
#define INITIAL_SCREEN_H

#include "system_utility.h"

class InitialScreen {
 public:
  void Welcome() const;
  void Logotype() const;
  void Error() const;
private:
  SystemUtility utility;
};

#endif  // INITIAL_SCREEN_H
