﻿#include <console_presenter.h>

void ConsolePresenter::RunApplication() {
  console_viewer_.DisplaySplashScreen();
  console_viewer_.RunApplication();
}
