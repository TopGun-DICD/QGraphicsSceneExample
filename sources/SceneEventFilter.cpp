#include "SceneEventFilter.hpp"

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

#include "ItemConnection.hpp"
#include "ItemPort.hpp"
#include "Item.hpp"

SceneEventFilter::SceneEventFilter(QWidget *parent) : QObject(parent), p_scene(nullptr), p_connection(nullptr) {
}

void SceneEventFilter::AssignGraphicsScene(QGraphicsScene *scene) {
  p_scene = scene;
  if (!p_scene)
    return;
  p_scene->installEventFilter(this);
}

QGraphicsItem *SceneEventFilter::GetItemAtXY(const QPointF &pos) {
  QList<QGraphicsItem*> items = p_scene->items(QRectF(pos - QPointF(1, 1), QSize(3, 3)));

  foreach(QGraphicsItem *p_item, items)
    if (p_item->type() > QGraphicsItem::UserType)
      return p_item;

  return nullptr;
}

bool SceneEventFilter::eventFilter(QObject *object, QEvent *event) {

  QGraphicsSceneMouseEvent *p_mouseEvent = nullptr;
  QGraphicsItem *p_item = nullptr;

  int a = 0, b = 0;

  switch (event->type()) {
    case QEvent::GraphicsSceneMousePress:
      p_mouseEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
      
      switch (p_mouseEvent->button()) {
        case Qt::LeftButton:
    
          p_item = GetItemAtXY(p_mouseEvent->scenePos());
          if(!p_item)
            return QObject::eventFilter(object, event);

          if (p_item->type() == ItemPort::Type) {
            p_connection = new ItemConnection;
            p_scene->addItem(p_connection);
            p_connection->AssignPortA(static_cast<ItemPort *>(p_item));
            p_connection->SetPositionA(p_item->scenePos());
            p_connection->SetPositionB(p_mouseEvent->scenePos());
            p_connection->UpdatePath();

            return true;
          }
          break;
    
        case Qt::RightButton: 
          p_item = GetItemAtXY(p_mouseEvent->scenePos());
          if (p_item && (p_item->type() == ItemConnection::Type || p_item->type() == Item::Type))
            delete p_item;
          break;
        
      }
  
    case QEvent::GraphicsSceneMouseRelease:
      p_mouseEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
      if (!p_connection || p_mouseEvent->button() != Qt::LeftButton)
        break;
      
      p_item = GetItemAtXY(p_mouseEvent->scenePos());
      if (p_item && p_item->type() == ItemPort::Type) {
        ItemPort *p_portA = p_connection->p_portA;
        ItemPort *p_portB = static_cast<ItemPort *>(p_item);

        if (p_portA->p_owner != p_portB->p_owner && p_portA->direction != p_portB->direction && !p_portA->IsConnectedWith(p_portB)) {
          p_connection->SetPositionB(p_portB->scenePos());
          p_connection->AssignPortB(p_portB);
          p_connection->UpdatePath();
          p_connection = nullptr;
          return true;
        }
      }

      delete p_connection;
      p_connection = nullptr;
      return true;
      
    case QEvent::GraphicsSceneMouseMove:  
      if (!p_connection)
        break;
      p_mouseEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
      p_connection->SetPositionB(p_mouseEvent->scenePos());
      p_connection->UpdatePath();
      return true;
 
  }
  return QObject::eventFilter(object, event);
}



