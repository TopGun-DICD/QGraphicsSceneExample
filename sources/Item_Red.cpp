#include "Item.hpp"

#include <QPen>
#include <QPainter>

#include "Logger.hpp"

Item_Red::Item_Red() : Item(it_itemRed) {
  addInputPort();
  addOutputPort();
}

void Item_Red::paint_custom(QPainter *painter) {
  painter->setBrush(Qt::darkRed);
  painter->drawPath(pathHeader);
  painter->setPen(QPen(Qt::white));
  painter->drawText(pathHeader.boundingRect(), Qt::AlignCenter, QString("RED"));
}

bool Item_Red::OnHandleEvent_Drop() {
  Logger::Get()->Log("Item \"RED\" was dropped");
  return true;
}
