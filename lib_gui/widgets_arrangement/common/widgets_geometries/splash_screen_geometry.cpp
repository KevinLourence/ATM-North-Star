﻿#include <splash_screen_geometry.h>

QRect SplashScreenGeometry::kVersionLabel = {485, 17, 100, 15};
QRect SplashScreenGeometry::kCompanyNameLabel = {35, 40, 510, 70};
QRect SplashScreenGeometry::kDateLabel = {140, 360, 160, 20};
QRect SplashScreenGeometry::kTimeLabel = {300, 360, 160, 20};
QRect SplashScreenGeometry::kTextLabel = {150, 270, 280, 30};
QRect SplashScreenGeometry::kSplashScreenFrame = {10, 10, 580, 380};

QRect SplashScreenGeometry::VersionLabel() { return kVersionLabel; }

QRect SplashScreenGeometry::CompanyNameLabel() { return kCompanyNameLabel; }

QRect SplashScreenGeometry::DateLabel() { return kDateLabel; }

QRect SplashScreenGeometry::TimeLabel() { return kTimeLabel; }

QRect SplashScreenGeometry::TextLabel() { return kTextLabel; }

QRect SplashScreenGeometry::SplashScreenFrame() { return kSplashScreenFrame; }
