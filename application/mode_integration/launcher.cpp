﻿#include <launcher.h>

#include <QApplication>

#include <splash_screen.h>  // add console prefix

void Launcher::LaunchConsoleMode() {
  cli::SplashScreen splash_screen;
  splash_screen.ShowSplashScreen();

  initial_menu_ = std::unique_ptr<cli::InitialMenu>(new cli::InitialMenu);
  initial_menu_->RunInitialMenu();
}

void Launcher::LaunchGuiMode(int argc, char* argv[]) {
  QApplication application(argc, argv);
  Q_INIT_RESOURCE(atm_resources);

  gui_splash_creen_ = std::unique_ptr<gui::GraphicalSplashScreen>(
      new gui::GraphicalSplashScreen);
  gui_splash_creen_->RunInitialScreen();

  application.exec();
}
