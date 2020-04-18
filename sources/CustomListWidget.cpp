#include "CustomListWidget.hpp"

#include <QLayout>
#include <QDrag>
#include <QMimeData>

CustomListItem::CustomListItem(ItemType type) : QWidget(nullptr), type(type) {
  QVBoxLayout *p_textLayout = new QVBoxLayout;
  p_textLayout->addWidget(&textTop);
  p_textLayout->addWidget(&textBottom);
  textTop.setStyleSheet("font-weight: bold; color: blue; font-size: 16px");
  textBottom.setStyleSheet("font-style: italic");

  QHBoxLayout *p_mainLayout = new QHBoxLayout;
  p_mainLayout->addWidget(&icon, 0);
  p_mainLayout->addLayout(p_textLayout, 1);

  setLayout(p_mainLayout);
}

CustomListItem::CustomListItem(ItemType type, const QString &iconPath, const QString &topText, const QString &bottomText) : QWidget(nullptr), type(type) {
  QVBoxLayout *p_textLayout = new QVBoxLayout;
  p_textLayout->addWidget(&textTop);
  p_textLayout->addWidget(&textBottom);
  textTop.setStyleSheet("font-weight: bold; color: blue; font-size: 16px");
  textBottom.setStyleSheet("font-style: italic");

  QHBoxLayout *p_mainLayout = new QHBoxLayout;
  p_mainLayout->addWidget(&icon, 0);
  p_mainLayout->addLayout(p_textLayout, 1);

  setLayout(p_mainLayout);

  SetIcon(iconPath);
  SetTopText(topText);
  SetBottomText(bottomText);
}

void CustomListItem::SetIcon(const QString &path) {
  pixmap.load(path);
  icon.setPixmap(pixmap);
}

void CustomListItem::SetTopText(const QString &text) {
  textTop.setText(text);
}

void CustomListItem::SetBottomText(const QString &text) {
  textBottom.setText(text);
}

QPixmap CustomListItem::GetPixmap() {
  return pixmap;
}

ItemType CustomListItem::GetType() {
  return type;
}





CustomListWidget::CustomListWidget(QWidget *parent) : QListWidget(parent) {
  setDragEnabled(true);

  CustomListItem *p_li = nullptr;
  QListWidgetItem *p_lwi = nullptr;

  // Item 1
  p_li = new CustomListItem(it_itemRed);
  p_li->SetIcon(tr("icons/icon_red_48.png"));
  p_li->SetTopText(tr("RED item"));
  p_li->SetBottomText(tr("1 input, 1 output"));

  p_lwi = new QListWidgetItem(this);
  setItemWidget(p_lwi, p_li);
  p_lwi->setSizeHint(p_li->sizeHint());

  addItem(p_lwi);

  // Item 2
  p_li = new CustomListItem(it_itemGreen, tr("icons/icon_green_48.png"), tr("GREEN item"), tr("3 inputs, 1 output"));

  p_lwi = new QListWidgetItem(this);
  setItemWidget(p_lwi, p_li);
  p_lwi->setSizeHint(p_li->sizeHint());

  addItem(p_lwi);

  // Item 3
  p_li = new CustomListItem(it_itemBlue, tr("icons/icon_blue_48.png"), tr("BLUE item"), tr("1 input, 1 output"));

  p_lwi = new QListWidgetItem(this);
  setItemWidget(p_lwi, p_li);
  p_lwi->setSizeHint(p_li->sizeHint());

  addItem(p_lwi);

  // Item 4
  p_li = new CustomListItem(it_itemGrey, tr("icons/icon_grey_48.png"), tr("GREY item"), tr("You can't drop this item"));

  p_lwi = new QListWidgetItem(this);
  setItemWidget(p_lwi, p_li);
  p_lwi->setSizeHint(p_li->sizeHint());

  addItem(p_lwi);
}

void CustomListWidget::startDrag(Qt::DropActions supportedActions) {
  if (!(supportedActions & Qt::CopyAction)) {
    QListWidget::startDrag(supportedActions);
    return;
  }

  QListWidgetItem *p_widget = currentItem();
  if (!p_widget)
    return;

  CustomListItem *p_item = static_cast<CustomListItem *>(itemWidget(p_widget));

  QPixmap pixmap = p_item->GetPixmap();

  QByteArray itemData;
  QDataStream dataStream(&itemData, QIODevice::WriteOnly);
  dataStream << p_item->GetType();

  QMimeData *mimeData = new QMimeData;
  mimeData->setData("application/x-dnditemdata", itemData);

  QDrag *drag = new QDrag(this);
  drag->setPixmap(pixmap);
  drag->setMimeData(mimeData);
  drag->setHotSpot(pixmap.rect().center());
  drag->exec(Qt::CopyAction);
}




