#include "MainWindow.hpp"

#include <QDockWidget>
#include <QTextEdit>
#include <QListWidget>

#include "View.hpp"

MainWindow::MainWindow() : QMainWindow(nullptr) {
  setWindowTitle(tr("QGraphicsSceneExample"));
  resize(QSize(800, 600));

  InitMainUI();
}

MainWindow::~MainWindow() {
}

void MainWindow::InitMainUI() {
  p_tabFlowItems = new QTabWidget(this);
  p_tabFlowItems->addTab(new View(this), tr("New scene view"));
  setCentralWidget(p_tabFlowItems);

  p_dockFlowItems = new QDockWidget(tr("Item List"), this);
  p_dockFlowItems->setFixedWidth(200);
  p_dockFlowItems->setMinimumWidth(200);
  p_dockFlowItems->setFeatures(QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
  p_dockFlowItems->setAllowedAreas(Qt::RightDockWidgetArea | Qt::LeftDockWidgetArea);
  p_tabFlowItems = new QTabWidget(this);
  p_tabFlowItems->setTabPosition(QTabWidget::South);

  p_itemListWidget = new CustomListWidget(p_tabFlowItems);
  p_tabFlowItems->addTab(p_itemListWidget, tr("Items"));
  p_dockFlowItems->setWidget(p_tabFlowItems);
  addDockWidget(Qt::LeftDockWidgetArea, p_dockFlowItems);

  p_dockConsole = new QDockWidget(tr("Console"), this);
  p_dockConsole->setFeatures(QDockWidget::DockWidgetClosable);
  p_dockConsole->setAllowedAreas(Qt::BottomDockWidgetArea);
  p_tabConsole = new QTabWidget(this);
  p_tabConsole->setTabPosition(QTabWidget::South);
  p_tabConsole->addTab(new QTextEdit(this), tr("Console"));
  p_dockConsole->setWidget(p_tabConsole);
  addDockWidget(Qt::BottomDockWidgetArea, p_dockConsole);
}


void MainWindow::OnMenu_File_Exit() {
  close();
}

void MainWindow::OnMenu_Help_About() {

}
