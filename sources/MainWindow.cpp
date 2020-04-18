#include "MainWindow.hpp"

#include <QDockWidget>
#include <QTextEdit>
#include <QListWidget>
#include <QAction>
#include <QMenuBar>

#include "Logger.hpp"

MainWindow::MainWindow() : QMainWindow(nullptr) {
  setWindowTitle(tr("QGraphicsSceneExample"));
  resize(QSize(800, 600));

  Logger::Init();

  InitMainUI();
  Logger::Get()->AssignTextEdit(p_console);

  InitActions();
  InitMenubar();

  Logger::Get()->Log("Hello!");
  Logger::Get()->Log("Drop items from left docking widget into main area.");
  Logger::Get()->Log("Then you can connect these items by connecting inputs with outputs.");
}

MainWindow::~MainWindow() {
  Logger::Free();
}

void MainWindow::InitMainUI() {
  p_tabFlowItems = new QTabWidget(this);
  p_view = new View(this);
  p_tabFlowItems->addTab(p_view, tr("New scene view"));
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
  p_console = new QTextEdit(this);
  p_console->setEnabled(false);
  p_tabConsole->addTab(p_console, tr("Console"));
  p_dockConsole->setWidget(p_tabConsole);
  addDockWidget(Qt::BottomDockWidgetArea, p_dockConsole);
}

void MainWindow::InitActions() {
  p_actFileNew = new QAction(tr("&New"), this);
  //p_actFileExit->setShortcuts(QKeySequence::Quit);
  p_actFileNew->setStatusTip(tr("Clear view and create new"));
  connect(p_actFileNew, SIGNAL(triggered()), SLOT(OnMenu_File_New()));
  p_actFileExit = new QAction(tr("&Exit"), this);
  //p_actFileExit->setShortcuts(QKeySequence::Quit);
  p_actFileExit->setStatusTip(tr("Quit the application"));
  connect(p_actFileExit, SIGNAL(triggered()), SLOT(OnMenu_File_Exit()));
}

void MainWindow::InitMenubar() {
  QMenu *p_menuFile = menuBar()->addMenu(tr("&File"));
  p_menuFile->addAction(p_actFileNew);
  p_menuFile->addSeparator();
  p_menuFile->addAction(p_actFileExit);

}

void MainWindow::OnMenu_File_New() {
  p_view->Clear();
}

void MainWindow::OnMenu_File_Exit() {
  close();
}

void MainWindow::OnMenu_Help_About() {

}
