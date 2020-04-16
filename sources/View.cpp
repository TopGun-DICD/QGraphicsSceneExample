#include "View.hpp"

#include <QDropEvent>
#include <QMimeData>
#include <QDebug>

#include "Item.hpp"
#include "ItemPort.hpp"
#include "ItemConnection.hpp"
#include "SceneEventFilter.hpp"
#include "CommonTypes.hpp"

View::View(QWidget *parent) : p_scene(nullptr), p_eventFilter(nullptr) {
  setAcceptDrops(true);

  p_scene = new Scene(this);
  setScene(p_scene);
  p_scene->setSceneRect(0, 0, 200, 200);

  p_eventFilter = new SceneEventFilter(this);
  p_eventFilter->AssignGraphicsScene(p_scene);

}

void View::dragEnterEvent(QDragEnterEvent *event) {
  if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
    if (event->source() == this) {
      event->setDropAction(Qt::MoveAction);
      event->accept();
    }
    else
      event->acceptProposedAction();
  }
  else
    event->ignore();
}

void View::dropEvent(QDropEvent *event) {
  if (!event->mimeData()->hasFormat("application/x-dnditemdata"))
    event->ignore();

  QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
  QDataStream dataStream(&itemData, QIODevice::ReadOnly);

  QPointF scenePos = mapToScene(event->pos());

  ItemType itemId = it_unknown;
  int val = 0;
  dataStream >> val;
  itemId = static_cast<ItemType>(val);

  Item *p_item = nullptr;

  switch (itemId) {
    case it_itemRed:
      p_item = new Item_Red;
      break;
    case it_itemGreen:
      p_item = new Item_Green;
      break;
    case it_itemBlue:
      p_item = new Item_Blue;
      break;
    case it_itemGrey:
      p_item = new Item_Grey;
      break;
    default:
      //TODO: Ругнуться в консоль и выйти
      ;
  }

  if (p_item == nullptr) {
    event->ignore();
    return;
  }

  if (!p_item->OnHandleEvent_Drop()) {
    delete p_item;
    p_item = nullptr;
    event->ignore();
    return;
  }

  p_scene->addItem(p_item);
  p_item->setPos(scenePos);

  if (event->source() == this) {
    event->setDropAction(Qt::MoveAction);
    event->accept();
  }
  else {
    event->acceptProposedAction();
  }
}

