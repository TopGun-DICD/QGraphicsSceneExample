#pragma once

#include <QGraphicsPathItem>

#define PORT_RADIUS 5
#define PORT_MARGIN 3*PORT_RADIUS

enum PortDirection {
  pd_undefnied = 0,
  pd_input,
  pd_output,
};

class Item;
class ItemConnection;

class ItemPort : public QGraphicsPathItem {
public:
  enum { Type = QGraphicsItem::UserType + 2 };
  QVector<ItemConnection *> connections;
public:
  Item           *p_owner;
  PortDirection   direction;
  bool            isConnected;
public:
  ItemPort(Item *parent, PortDirection dir);
 ~ItemPort();
public:
  bool IsConnectedWith(ItemPort *port);
  QVariant itemChange(GraphicsItemChange change, const QVariant &value);
  int type() const { return Type; }
  Item *GetOwner() { return p_owner; }
};
