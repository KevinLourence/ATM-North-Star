﻿#ifndef WIDGET_CENTER_ARRANGER_H
#define WIDGET_CENTER_ARRANGER_H

#include <QWidget>

class QRect;

class WidgetCenterArranger {
 public:
  static void MoveToCenter(QWidget* widget);
  static void MoveToCenterRelativelyOf(QWidget* move_widget,
                                       const QRect& position);
};

#endif  // WIDGET_CENTER_ARRANGER_H
