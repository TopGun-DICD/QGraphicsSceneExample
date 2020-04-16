#include "Scene.hpp"

#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>

Scene::Scene(QWidget *parent) {

}

void Scene::dragMoveEvent(QGraphicsSceneDragDropEvent *event) {
  if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
    if (event->source() == (QObject *)this) {
      event->setDropAction(Qt::MoveAction);
      event->accept();
    }
    else {
      event->acceptProposedAction();
    }
  }
  else {
    event->ignore();
  }
}
