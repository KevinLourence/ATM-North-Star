﻿#include <graphical_splash_screen.h>

#include <QObject>
#include <QRect>

gui::GraphicalSplashScreen::GraphicalSplashScreen()
    : splash_screen_(new AtmSplashScreen) {
  hider_.SetWidgetForHideAnimation(&splash_screen_);
  QObject::connect(&splash_screen_, SIGNAL(EnterIsPressed(const QRect&)),
                   &hider_, SLOT(Hide(const QRect&)));
  QObject::connect(&hider_, SIGNAL(IsAlreadyHidden()), &splash_screen_,
                   SLOT(CloseBeforeMainWidget()));
}

void gui::GraphicalSplashScreen::RunInitialScreen() {
  SetSplashScreen();
  splash_screen_.show();
}

bool gui::GraphicalSplashScreen::IsMainWidgetReadyToShow() {
  return splash_screen_.IsMainWidgetReadyToShow();
}

void gui::GraphicalSplashScreen::SetSplashScreen() {
  splash_screen_.SetCompanyName("North Star");
  splash_screen_.SetSplashScreenAppearance("#00FFFF", "#001933", "#009999");
  splash_screen_.SetAtmBlinkColor("#00FFFF", "#009999");
  splash_screen_.SetBackgroundColor();
}
