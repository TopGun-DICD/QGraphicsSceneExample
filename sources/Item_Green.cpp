#include "Item.hpp"

#include <QPen>
#include <QPainter>

#include "Logger.hpp"

Item_Green::Item_Green() : Item(it_itemGreen) {
  addInputPort();
  addInputPort();
  addInputPort();
  addOutputPort();
}

void Item_Green::paint_custom(QPainter *painter) {
  painter->setBrush(Qt::darkGreen);
  painter->drawPath(pathHeader);
  painter->setPen(QPen(Qt::white));
  painter->drawText(pathHeader.boundingRect(), Qt::AlignCenter, QString("GREEN"));
}

bool Item_Green::OnHandleEvent_Drop() {
  Logger::Get()->Log("Item \"GREEN\" was dropped");
  return true;
}
