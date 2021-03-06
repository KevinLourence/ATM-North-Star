﻿#include <launcher.h>

#include <iostream>

#include <QApplication>

void Launcher::LaunchConsoleMode() {
  initial_menu_ = std::unique_ptr<ConsoleInitialPresenter>(new ConsoleInitialPresenter);
  initial_menu_->RunApplication();

  // interface_presenter_ = std::unique_ptr<BaseInterfacePresenter> (new
  // ConsolePresenter);
  // interface_presenter_->RunApplication();
}

void Launcher::LaunchGuiMode(int argc, char* argv[]) {
  QApplication application(argc, argv);
  Q_INIT_RESOURCE(atm_resources);

  gui_splash_creen_ = std::unique_ptr<GUIPresenter>(new GUIPresenter);
  gui_splash_creen_->RunInitialScreen();

  application.exec();

  // interface_presenter_ = std::unique_ptr<BaseInterfacePresenter> (new
  // ConsolePresenter);
  // interface_presenter_->RunApplication();
}

void Launcher::DisplayErrorReport() const {
  std::cout
      << "Error while reading configuration file \"app_config.txt\"\n"
         "Configuration file was not created or contain incorrect data...\n\n\n"
         "For successful program launching you must to create a "
         "\"app_config.txt\" file\n"
         "and put it near the executed file.\n"
         "In configuration file you must write which mode of app you want to "
         "use.\n"
         "If you want to run app in console mode, write \"Mode: cli\"\n"
         "Or if you want to run app in graphical mode, write \"Mode: gui\"\n";
}
