#include "Item.hpp"

#include <QPen>
#include <QPainter>
#include <QMessageBox>

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
  QMessageBox::information(nullptr, QString("BLUE"), QString("Dropped"));
  return true;
}
