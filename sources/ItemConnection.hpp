#pragma once

#include <QGraphicsPathItem>

class ItemPort;

class ItemConnection : public QGraphicsPathItem {
public:
  enum { Type = QGraphicsItem::UserType + 3 };
public:
  ItemPort *p_portA,
               *p_portB;
  QPointF       posA, 
                posB;
public:
  ItemConnection();
 ~ItemConnection();
public:
  void AssignPortA(ItemPort *port);
  void AssignPortB(ItemPort *port);
  void SetPositionA(const QPointF &pt);
  void SetPositionB(const QPointF &pt);
  void UpdatePath();
  void UpdatePosFromPorts();
  int type() const { return Type; }
  ItemPort *GetPotrA() { return p_portA; }
  ItemPort *GetPotrB() { return p_portB; }
};
