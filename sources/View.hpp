#pragma once

#include <QGraphicsView>

#include "Scene.hpp"

class ItemConnection;
class SceneEventFilter;

class View : public QGraphicsView {
  Q_OBJECT
private:
  Scene            *p_scene;
  SceneEventFilter *p_eventFilter;
public:
  View(QWidget *parent);
private:
private slots:
  void dragEnterEvent(QDragEnterEvent *event) override;
  void dropEvent(QDropEvent *event) override;
};
