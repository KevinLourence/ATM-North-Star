﻿#ifndef GRAPHICAL_REGISTRATION_MENU_H
#define GRAPHICAL_REGISTRATION_MENU_H

#include <base_atm_frame.h>

#include <QRect>

#include <delta_size.h>
#include <geometry_composer.h>
#include <widget_border_controller.h>

class GraphicalRegistrationMenu : public BaseAtmFrame {
  Q_OBJECT
 public:
  explicit GraphicalRegistrationMenu(QWidget* parent = nullptr);
  ~GraphicalRegistrationMenu();

  void SetDeltaSize(const DeltaSize& delta_size);

 protected:
  void resizeEvent(QResizeEvent*);

 private:
  GeometryComposer composer_;
  WidgetBorderController border_controller_;
  DeltaSize delta_size_;

  static const int kHalfASecond = 500;
};

#endif  // GRAPHICAL_REGISTRATION_MENU_H
