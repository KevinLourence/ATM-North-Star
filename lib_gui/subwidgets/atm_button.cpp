﻿#include <atm_button.h>

#include <QEvent>
#include <QString>
#include <QWidget>

AtmButton::AtmButton(QWidget* widget) : QPushButton(widget) {}

AtmButton::AtmButton(const QString& text,
                     unsigned int offset_side,
                     QWidget* widget)
    : QPushButton(text, widget), offset_side_(offset_side) {}

void AtmButton::SetXHoverOffset(int x_offset) { x_offset_ = x_offset; }

void AtmButton::SetYHoverOffset(int y_offset) { y_offset_ = y_offset; }

AtmButton::~AtmButton() {}

void AtmButton::enterEvent(QEvent*) { OffsetButton(); }

void AtmButton::leaveEvent(QEvent*) { ReturnToInitialPosition(); }

void AtmButton::OffsetButton() {
  int x_pos = x();
  int y_pos = y();

  if (offset_side_ & kLeft) {
    x_pos -= x_offset_;
  }
  if (offset_side_ & kRight) {
    x_pos += x_offset_;
  }
  if (offset_side_ & kUp) {
    y_pos -= y_offset_;
  }
  if (offset_side_ & kDown) {
    y_pos += y_offset_;
  }
  if (offset_side_ & kNone) {
    x_pos = x();
    y_pos = y();
  }

  move(x_pos, y_pos);
}

void AtmButton::ReturnToInitialPosition() {
  int x_pos = x();
  int y_pos = y();

  if (offset_side_ & kLeft) {
    x_pos += x_offset_;
  }
  if (offset_side_ & kRight) {
    x_pos -= x_offset_;
  }
  if (offset_side_ & kUp) {
    y_pos += y_offset_;
  }
  if (offset_side_ & kDown) {
    y_pos -= y_offset_;
  }
  move(x_pos, y_pos);
}
