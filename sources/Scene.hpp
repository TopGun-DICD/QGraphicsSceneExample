#pragma once

#include <QGraphicsView>

class Scene : public QGraphicsScene {
  Q_OBJECT
public:
  Scene(QWidget *parent);
private slots:
  void dragMoveEvent(QGraphicsSceneDragDropEvent *event) override;
};
