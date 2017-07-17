﻿#include <initial_menu.h>

#include <QList>
#include <QPushButton>
#include <QString>
#include <QVector>
#include <QWidget>

#include <application_color.h>
#include <atm_button.h>
#include <atm_color_designer.h>
#include <conversion_factor.h>
#include <initial_frame_geometry.h>
#include <side.h>

#include <QDebug>

InitialMenu::InitialMenu(QWidget* parent)
    : QFrame(parent),
      button_frame_(new QFrame(this)),
      sign_in_button_(new AtmButton("Sign-in", button_frame_)),
      registration_button_(new AtmButton("Registration", button_frame_)),
      demo_button_(new AtmButton("Demo", button_frame_)),
      v_layout_(new QVBoxLayout),
      atm_color_designer_(new AtmColorDesigner) {
  SetButtonFrame();
  SetInitialSetting();
}

InitialMenu::~InitialMenu() { delete atm_color_designer_; }

void InitialMenu::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void InitialMenu::PaintWidgets() {
  atm_color_designer_->PaintInitialFrame(this);
  atm_color_designer_->PaintWidgetSet(
      QList<QPushButton*>{sign_in_button_, registration_button_, demo_button_});
}

void InitialMenu::SetInitialSetting() {
  sign_in_button_->setGeometry(InitialFrameGeometry::SignInButton());
  registration_button_->setGeometry(InitialFrameGeometry::RegistrationButton());
  demo_button_->setGeometry(InitialFrameGeometry::DemoButton());

  SetResizeProperties();
}

void InitialMenu::SetResizeProperties() {
  composer_.SetShiftFactor(1.5, 1.3);
  composer_.SetShiftSide(Side::kRight | Side::kDown);

  composer_.SetStretchFactor(0.5, 0.1);
  composer_.SetStretchSide(Side::kRight | Side::kDown);

  composer_.SetTransformationType(GeometryComposer::kScale);
  composer_.KeepCenter(true);
}

void InitialMenu::SetButtonFrame() {
  button_frame_geometry_ = QRect{30, 30, 160, 160};

  button_frame_->setGeometry(button_frame_geometry_);

  v_layout_->addWidget(sign_in_button_);
  v_layout_->addWidget(registration_button_);
  v_layout_->addWidget(demo_button_);

  button_frame_->setLayout(v_layout_);

  button_frame_->setStyleSheet(
      "QFrame {"
      "border: 0px;}");
  PaintWidgets();
}

void InitialMenu::resizeEvent(QResizeEvent*) {
  SetResizeProperties();
  border_controller_.SetGeometryLimit(geometry());

  composer_.SetDeltaSize(delta_size_);
  composer_.ComposeGeometry(button_frame_geometry_, button_frame_);

  border_controller_.ControlWidget(button_frame_);
}
