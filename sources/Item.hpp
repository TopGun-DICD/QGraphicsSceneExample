#pragma once

#include <QGraphicsPathItem>

#include "ItemPort.hpp"
#include "CommonTypes.hpp"

class Item : public QGraphicsPathItem {
public:
  enum { Type = QGraphicsItem::UserType + 1 };
public:
  ItemType                  itemType;
  QPainterPath              pathShape,
                            pathHeader;
  QVector <ItemPort *>      inputPorts,
                            outputPorts;
public:
  Item(ItemType type);
public:
  virtual void paint_custom(QPainter *painter) = 0;
  virtual bool OnHandleEvent_Drop() = 0;
public:
  void addInputPort();
  void addOutputPort();
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
  int type() const { return Type; }
  virtual QString GetItemType() = 0;
protected:
  QVariant itemChange(GraphicsItemChange change, const QVariant &value);
};

class Item_Red : public Item {
public:
  Item_Red();
public:
  void paint_custom(QPainter *painter) final;
  bool OnHandleEvent_Drop();
  QString GetItemType() { return "RED"; }
};

class Item_Green : public Item {
public:
  Item_Green();
public:
  void paint_custom(QPainter *painter) final;
  bool OnHandleEvent_Drop();
  QString GetItemType() { return "GREEN"; }
};

class Item_Blue : public Item {
public:
  Item_Blue();
public:
  void paint_custom(QPainter *painter) final;
  bool OnHandleEvent_Drop();
  QString GetItemType() { return "BLUE"; }
};

class Item_Grey : public Item {
public:
  Item_Grey();
public:
  void paint_custom(QPainter *painter) final;
  bool OnHandleEvent_Drop();
  QString GetItemType() { return "GREY"; }
};

