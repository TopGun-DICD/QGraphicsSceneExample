#include "ItemPort.hpp"

#include <QPen>

#include "Item.hpp"
#include "ItemConnection.hpp"

ItemPort::ItemPort(Item *parent, PortDirection dir) : QGraphicsPathItem(parent), p_owner(parent), direction(dir), isConnected(false) {
  QPainterPath p;
  p.addEllipse(-PORT_RADIUS, -PORT_RADIUS, 2 * PORT_RADIUS, 2 * PORT_RADIUS);
  setPath(p);

  setPen(QPen(Qt::darkRed));
  setBrush(Qt::red);

  setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
}

ItemPort::~ItemPort() {
  foreach(ItemConnection *p_connection, connections)
    delete p_connection;
  connections.clear();
}

bool ItemPort::IsConnectedWith(ItemPort *port) {
  foreach(ItemConnection *p_connection, connections)
    if (p_connection->p_portA == port || p_connection->p_portB == port)
      return true;

  return false;
}

QVariant ItemPort::itemChange(GraphicsItemChange change, const QVariant &value) {
  if (change != ItemScenePositionHasChanged)
    return value;

  QPointF pt = pos();

  foreach(ItemConnection *p_connection, connections) {
    p_connection->UpdatePosFromPorts();
    p_connection->UpdatePath();
  }
  return value;
}



