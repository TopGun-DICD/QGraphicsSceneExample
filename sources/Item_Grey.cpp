#include "Item.hpp"

#include <QPen>
#include <QPainter>

#include "Logger.hpp"

Item_Grey::Item_Grey() : Item(it_itemGrey) {
  addInputPort();
  addOutputPort();
}

void Item_Grey::paint_custom(QPainter *painter) {
  painter->setBrush(Qt::darkGray);
  painter->drawPath(pathHeader);
  painter->setPen(QPen(Qt::white));
  painter->drawText(pathHeader.boundingRect(), Qt::AlignCenter, QString("GREY"));
}

bool Item_Grey::OnHandleEvent_Drop() {
  Logger::Get()->Log("Item \"GREY\" was dropped, but will not be placed");
  return false;
}
