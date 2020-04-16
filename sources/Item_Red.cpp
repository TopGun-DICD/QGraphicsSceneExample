#include "Item.hpp"

#include <QPen>
#include <QPainter>
#include <QMessageBox>

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
  QMessageBox::information(nullptr, QString("RED"), QString("Dropped"));
  return true;
}
