#include "ItemConnection.hpp"

#include <QPen>

#include "Item.hpp"

ItemConnection::ItemConnection() : QGraphicsPathItem(nullptr), p_portA(nullptr), p_portB(nullptr) {
  setPen(QPen(Qt::black, 2));
  setBrush(Qt::NoBrush);
  setZValue(-1);
}

ItemConnection::~ItemConnection() {
  if (p_portA)
    p_portA->connections.remove(p_portA->connections.indexOf(this));
  if (p_portB)
    p_portB->connections.remove(p_portB->connections.indexOf(this));
}

void ItemConnection::AssignPortA(ItemPort *port) {
  p_portA = port;
  p_portA->connections.append(this);
}

void ItemConnection::AssignPortB(ItemPort *port) {
  p_portB = port;
  p_portB->connections.append(this);
}

void ItemConnection::SetPositionA(const QPointF &pt) {
  posA = pt;
}

void ItemConnection::SetPositionB(const QPointF &pt) {
  posB = pt;
}

void ItemConnection::UpdatePath() {
  QPainterPath p;

  p.moveTo(posA);

  qreal dx = posB.x() - posA.x();
  qreal dy = posB.y() - posA.y();

  QPointF ctr1(posA.x() + dx * 0.25, posA.y() + dy * 0.1);
  QPointF ctr2(posA.x() + dx * 0.75, posA.y() + dy * 0.9);

  p.cubicTo(ctr1, ctr2, posB);

  setPath(p);
}

void ItemConnection::UpdatePosFromPorts() {
  posA = p_portA->scenePos();
  posB = p_portB->scenePos();
}

