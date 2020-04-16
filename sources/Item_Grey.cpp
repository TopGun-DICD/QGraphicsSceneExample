#include "Item.hpp"

#include <QPen>
#include <QPainter>
#include <QMessageBox>

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
  QMessageBox::information(nullptr, QString("BLUE"), QString("Dropped, but will no be placed"));
  return false;
}
