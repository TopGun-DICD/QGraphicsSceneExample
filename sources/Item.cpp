#include "Item.hpp"

#include <QPen>
#include <QPainter>

#define ITEM_WIDTH  200
#define ITEM_HEIGHT 50

Item::Item(ItemType type) : QGraphicsPathItem(nullptr), itemType(type) {
  pathShape.addRoundedRect(QRectF(-ITEM_WIDTH/2, -ITEM_HEIGHT/2, ITEM_WIDTH, ITEM_HEIGHT), 5, 5);
  setPath(pathShape);

  pathHeader.addRoundedRect(QRectF(-ITEM_WIDTH / 2, -ITEM_HEIGHT / 2, ITEM_WIDTH, ITEM_HEIGHT/3), 5, 5);

  setFlag(QGraphicsItem::ItemIsMovable);
  setFlag(QGraphicsItem::ItemIsSelectable);
  }

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
  Q_UNUSED(option)
  Q_UNUSED(widget)

  if (isSelected()) {
    painter->setPen(QPen(Qt::darkYellow));
    painter->setBrush(Qt::yellow);
  }
  else {
    painter->setPen(QPen(Qt::darkGreen));
    painter->setBrush(Qt::green);
  }

  painter->drawPath(path());

  paint_custom(painter);
}

void Item::addInputPort() {
  ItemPort *p_port = new ItemPort(this, pd_input);
  inputPorts.push_back(p_port);
  p_port->setPos(QPointF(p_port->pos().x(), p_port->pos().y() - ITEM_HEIGHT/2 - PORT_RADIUS));

  int x = pos().x() - (qreal)(inputPorts.size() - 1) / 2.0 * PORT_MARGIN;

  foreach(QGraphicsItem *port, inputPorts) {
    port->setPos(QPointF(x, p_port->pos().y()));
    x += PORT_MARGIN;
  }
}

void Item::addOutputPort() {
  if (!outputPorts.empty()) {
    //TODO: Generate error (show in log window?)
    return;
  }
  ItemPort *p_port = new ItemPort(this, pd_output);
  outputPorts.push_back(p_port);
  QPointF pos = QPointF(p_port->pos().x(), p_port->pos().y() + ITEM_HEIGHT / 2 + PORT_RADIUS);
  p_port->setPos(QPointF(p_port->pos().x(), p_port->pos().y() + ITEM_HEIGHT/2 + PORT_RADIUS));
}

QVariant Item::itemChange(GraphicsItemChange change, const QVariant &value) {
  Q_UNUSED(change);
  return value;
}

