﻿#include <base_atm_frame.h>

#include <QEasingCurve>
#include <QList>
#include <QResizeEvent>
#include <QWidget>

#include <atm_button.h>
#include <atm_frame_setter.h>
#include <side.h>

BaseAtmFrame::BaseAtmFrame(QWidget* parent,
                           BackButtonCondition back_button_condition)
    : QFrame(parent), frame_setter_(new AtmFrameSetter(this)) {
  switch (back_button_condition) {
    case kBackButtonActivated:
      back_button_ = (new AtmButton("back", this));
      ColorizeBackButton();
      SetBackButtonScaling();
      SetBasicConnections();
      break;
    case kBackButtonDeactivated:
      SetBasicConnections();
      break;
  }
}

BaseAtmFrame::~BaseAtmFrame() {}

void BaseAtmFrame::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void BaseAtmFrame::SetInitialFrameGeometry(const QRect& geometry) {
  setGeometry(geometry);
  initial_frame_geometry_ = geometry;
}

void BaseAtmFrame::SetInitialBackButtonGeometry(const QRect& geometry) {
  back_button_->setGeometry(geometry);
  initial_back_button_geometry_ = geometry;
}

void BaseAtmFrame::SetFrameAnimation(unsigned int hide_to,
                                     unsigned int extrude_from,
                                     unsigned int duration_msec,
                                     QFrame* animated_frame) {
  // SetOperationFrame - always at the first position
  frame_setter_->SetOperationFrame(animated_frame);

  frame_setter_->SetAnimationDirection(hide_to, extrude_from);
  frame_setter_->SetAnimationDuration(duration_msec);
}

void BaseAtmFrame::ColorizeButtons(const QList<QPushButton*>& button_list) {
  frame_setter_->ColorizeButtons(button_list);
}

void BaseAtmFrame::ProcessBackButtonClick() {
  emit PassGeometryForHide(geometry());
  emit BackButtonClicked();
}

void BaseAtmFrame::Show() {
  QRect widget_geometry = {
      initial_frame_geometry_.x(), initial_frame_geometry_.y(),
      initial_frame_geometry_.width() + delta_size_.Width(),
      initial_frame_geometry_.height() + delta_size_.Height()};

  setGeometry(widget_geometry);
  emit PassGeometryForExtrude(widget_geometry);
}

void BaseAtmFrame::ScaleBackButton() {
  composer_.SetDeltaSize(delta_size_);
  composer_.SetShiftFactor(kXShiftFactor, kYShiftFactor);
  composer_.ComposeGeometry(initial_back_button_geometry_, back_button_);

  border_controller_.SetGeometryLimit(geometry());
  border_controller_.ControlWidget(back_button_);
}

void BaseAtmFrame::ColorizeBackButton() {
  QList<QPushButton*> button_list{back_button_};
  frame_setter_->ColorizeButtons(button_list);
}

void BaseAtmFrame::SetBasicConnections() {
  if (back_button_ != nullptr) {
    connect(back_button_, SIGNAL(clicked(bool)),
            SLOT(ProcessBackButtonClick()));
  }

  connect(this, SIGNAL(PassGeometryForExtrude(QRect)), frame_setter_,
          SLOT(StartExtrudingFrame(QRect)));
  connect(frame_setter_, SIGNAL(ExtrudingComplete()), SLOT(show()));
  connect(this, SIGNAL(PassGeometryForHide(QRect)), frame_setter_,
          SLOT(StartHidingFrame(QRect)));
  connect(frame_setter_, SIGNAL(HidingComplete()), SLOT(close()));
}

void BaseAtmFrame::SetBackButtonScaling() {
  composer_.SetShiftSide(Side::kRight | Side::kDown);
  composer_.SetStretchFactor(kXStretchFactor, kYStretchFactor);
  composer_.SetStretchSide(Side::kUp | Side::kRight);
  composer_.SetTransformationType(GeometryComposer::kScale);
}
