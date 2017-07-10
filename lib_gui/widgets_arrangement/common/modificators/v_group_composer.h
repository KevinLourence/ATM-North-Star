﻿#ifndef V_GROUP_COMPOSER_H
#define V_GROUP_COMPOSER_H

#include <QRect>
#include <QVector>

#include <conversion_factor.h>
#include <delta_size.h>

class QWidget;

class VGroupComposer {
 public:
  void SetDeltaSize(const DeltaSize& delta_size);

  void SetInitialGroupGeometry(const QVector<QRect>& widget_vector);
  void ScaleVGroup(QVector<QWidget*> scale_vector);

  void SetSpace(int widget_interval);

 private:
  void ComputeElementPosition(QWidget* widget_x_pos, QWidget* widget_y_pos);
  void ComputeElementSize(int element_number);
  void ComputeHeadGroupGeometry(QWidget* widget);

  DeltaSize delta_size_;

  QVector<QRect> geometry_vector_;

  QRect geometry_;

  int widget_interval_ = 10;
};

#endif  // V_GROUP_COMPOSER_H
