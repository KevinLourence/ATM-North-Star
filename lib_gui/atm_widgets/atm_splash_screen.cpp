﻿#include <atm_splash_screen.h>
#include <ui_atm_splash_screen.h>

#include <QApplication>
#include <QCursor>
#include <QIcon>
#include <QKeyEvent>
#include <QList>
#include <QPixmap>
#include <QString>
#include <QTimer>

#include <exit_dialog.h>
#include <initial_property_installer.h>
#include <space_block_filter.h>
#include <text_color_swapper.h>
#include <timedate_changer.h>

AtmSplashScreen::AtmSplashScreen(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::AtmSplashScreen),
      exit_dialog_(new ExitDialog(this)) {
  ui->setupUi(this);
  exit_dialog_->setModal(true);

  setWindowTitle("ATM splash screen");

  PaintWidgets();
  SetBackgroundColor();

  InitializeObjects();
  SetWidgetProperties();
  BlockSpace();
  SetInitialSettings();
  PaintWidgets();
  SetConnections();
  RunTimers();
}

AtmSplashScreen::~AtmSplashScreen() {
  delete ui;
  delete color_swap_timer_;
  delete text_color_swapper_;
  delete date_timer_;
  delete time_timer_;
}

void AtmSplashScreen::SetCompanyName(const QString& atm_company_name) {
  ui->atm_company_name_label->setText(atm_company_name);
}

void AtmSplashScreen::PaintWidgets() {
  QList<QLabel*> label_list = {ui->atm_company_name_label, ui->text_label,
                               ui->date_label, ui->time_label,
                               ui->version_label};
  QList<QPushButton*> button_list = {ui->exit_button, ui->minimize_button,
                                     ui->maximize_button};
  QList<QFrame*> frame_list = {ui->frame};

  color_designer_.PaintWidgetSet(label_list);
  color_designer_.PaintWidgetSet(button_list);
  color_designer_.PaintWidgetSet(frame_list);
}

void AtmSplashScreen::SetBackgroundColor() {
  color_designer_.SetBackground(this);
}

void AtmSplashScreen::UnlockFixedGeometry() { setMinimumSize(0, 0); }

void AtmSplashScreen::BlinkAtmLabelColor() {
  text_color_swapper_->SwapColors(ui->atm_label);
}

void AtmSplashScreen::Tick() {
  TimeDateChanger::ChangeDate(ui->date_label);
  TimeDateChanger::ChangeTime(ui->time_label);
}

void AtmSplashScreen::ShowExitWidget() {
  exit_dialog_->ShowWidgetOnCenterAt(geometry());
}

void AtmSplashScreen::MaximizeButtonClicked() {
  if (!isFullScreen()) {
    showFullScreen();
  } else {
    showNormal();
  }
}

void AtmSplashScreen::keyPressEvent(QKeyEvent* event) {
  switch (event->key()) {
    case Qt::Key_Escape:
      emit Exit();
    case Qt::Key_Space:
      event->ignore();
      break;
    case Qt::Key_Enter:
      ProcessKeyEnterPressing();
      break;
    case Qt::Key_Return:
      ProcessKeyEnterPressing();
    default:
      break;
  }
  QWidget::keyPressEvent(event);
}

void AtmSplashScreen::resizeEvent(QResizeEvent*) {
  ComputeNewGeometry();
  ResizeWidgets();
}

void AtmSplashScreen::SetInitialSettings() {
  SetCompanyName("");

  setMinimumSize(kWidgetWidth, kWidgetHeight);

  QCursor custom_cursor(QPixmap(":/images/app_cursor.png"));
  setCursor(custom_cursor);
}

void AtmSplashScreen::SetWidgetProperties() {
  InitialPropertyInstaller::SetInitialProperties(
      this, kWidgetWidth, kWidgetHeight, InitialPropertyInstaller::kResize);
  setWindowIcon(QIcon(":/images/project_icon.png"));
}

void AtmSplashScreen::SetConnections() {
  connect(color_swap_timer_, SIGNAL(timeout()), SLOT(BlinkAtmLabelColor()));
  connect(date_timer_, SIGNAL(timeout()), SLOT(Tick()));
  connect(time_timer_, SIGNAL(timeout()), SLOT(Tick()));
  connect(this, SIGNAL(Exit()), SLOT(ShowExitWidget()));
  connect(ui->exit_button, SIGNAL(clicked(bool)), SLOT(ShowExitWidget()));
  connect(this, SIGNAL(EnterIsPressed()), SLOT(UnlockFixedGeometry()));
  connect(ui->maximize_button, SIGNAL(clicked(bool)),
          SLOT(MaximizeButtonClicked()));
}

void AtmSplashScreen::InitializeObjects() {
  color_swap_timer_ = new QTimer(ui->atm_label);
  text_color_swapper_ = new TextColorSwapper();
  date_timer_ = new QTimer(ui->date_label);
  time_timer_ = new QTimer(ui->time_label);
}

void AtmSplashScreen::RunTimers() {
  color_swap_timer_->start(kTimerValue);
  date_timer_->start(kOneSecond);
  time_timer_->start(kOneSecond);
}

void AtmSplashScreen::BlockSpace() {
  ui->exit_button->installEventFilter(new SpaceBlockFilter(ui->exit_button));
  ui->minimize_button->installEventFilter(
      new SpaceBlockFilter(ui->minimize_button));
  ui->maximize_button->installEventFilter(
      new SpaceBlockFilter(ui->maximize_button));
}

void AtmSplashScreen::ProcessKeyEnterPressing() {
  emit PassPositionWhenEnterPressed(this->geometry());
  emit EnterIsPressed();
  emit PassScreenSizeCondition(isFullScreen());
}

void AtmSplashScreen::ComputeNewGeometry() {
  composer_.ComputeDeltas(width(), height());
}

void AtmSplashScreen::ResizeWidgets() {
  composer_.ComposeFrame(ui->frame);
  composer_.ComposeVersionLabel(ui->version_label);
  composer_.ComposeCompanyNameLabel(ui->atm_company_name_label);
  composer_.ComposeSplashScreenLabels(ui->date_label, ui->time_label,
                                      ui->text_label);
  composer_.ComposeAtmLabel(ui->atm_label);
}
