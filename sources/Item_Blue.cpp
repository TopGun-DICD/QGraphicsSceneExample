#include "Item.hpp"

#include <QPen>
#include <QPainter>

#include "Logger.hpp"

Item_Blue::Item_Blue() : Item(it_itemBlue) {
  addInputPort();
  addOutputPort();
}

void Item_Blue::paint_custom(QPainter *painter) {
  painter->setBrush(Qt::darkBlue);
  painter->drawPath(pathHeader);
  painter->setPen(QPen(Qt::white));
  painter->drawText(pathHeader.boundingRect(), Qt::AlignCenter, QString("BLUE"));
}

bool Item_Blue::OnHandleEvent_Drop() {
  Logger::Get()->Log("Item \"BLUE\" was dropped");
  return true;
}
