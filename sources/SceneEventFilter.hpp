#pragma once

#include <QGraphicsView>

class ItemConnection;

class SceneEventFilter : public QObject {
  Q_OBJECT
private:
  QGraphicsScene     *p_scene;
  ItemConnection *p_connection;
public:
  SceneEventFilter(QWidget *parent);
public:
  void AssignGraphicsScene(QGraphicsScene *scene);
private:
  QGraphicsItem *GetItemAtXY(const QPointF&);
  bool eventFilter(QObject *, QEvent *);
};
