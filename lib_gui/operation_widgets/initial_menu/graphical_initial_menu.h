﻿#ifndef GRAPHICAL_INITIAL_MENU_H
#define GRAPHICAL_INITIAL_MENU_H

#include <base_atm_frame.h>

#include <QRect>
#include <QVBoxLayout>

#include <delta_size.h>
#include <geometry_composer.h>
#include <widget_border_controller.h>

class QWidget;
class QPushButton;
class AtmButton;

class GraphicalInitialMenu : public BaseAtmFrame {
  Q_OBJECT
 public:
  explicit GraphicalInitialMenu(QWidget* parent = nullptr);
  ~GraphicalInitialMenu();

  void SetDeltaSize(const DeltaSize& delta_size);

 public slots:
  void ProcessDemoButtonClick();
  void ProcessRegistraionButtonClick();
  void ProcessLoginButtonClick();

 signals:
  void DemoButtonClicked();
  void RegistrationButtonClicked();
  void LoginButtonClicked();

 protected:
  void resizeEvent(QResizeEvent*);

 private:
  void PaintWidgets();
  void SetButtonGeometry();
  void SetButtonFrameScalingProperties();
  void SetButtonFrame();
  void SetConnections();

  QFrame* button_frame_ = nullptr;
  AtmButton* login_button_ = nullptr;
  AtmButton* registration_button_ = nullptr;
  AtmButton* description_button_ = nullptr;
  QVBoxLayout* v_layout_ = nullptr;

  DeltaSize delta_size_;
  WidgetBorderController border_controller_;
  GeometryComposer composer_;

  static constexpr double kXFactor = 0.5;
  static constexpr double kYFactor = 0.5;

  static const int kHalfASecond = 500;
};

#endif  // GRAPHICAL_INITIAL_MENU_H
