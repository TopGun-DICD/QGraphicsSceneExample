#pragma once

#include <QListWidget>
#include <QLabel>

#include "CommonTypes.hpp"

class CustomListItem : public QWidget {
  QPixmap   pixmap;
  QLabel    icon,
            textTop,
            textBottom;
  ItemType  type;
public:
  CustomListItem(ItemType type = it_unknown);
  CustomListItem(ItemType type, const QString &iconPath, const QString &topText, const QString &bottomText);
public:
  void SetIcon(const QString &path);
  void SetTopText(const QString &text);
  void SetBottomText(const QString &text);
  QPixmap GetPixmap();
  ItemType GetType();
};

class CustomListWidget : public QListWidget {
public:
  CustomListWidget(QWidget *parent);
public:
  void startDrag(Qt::DropActions supportedActions);
};