#pragma once

#include <QMainWindow>

#include "CustomListWidget.hpp"

class MainWindow : public QMainWindow {
  Q_OBJECT
private:
  QDockWidget      *p_dockFlowItems,
                   *p_dockLayout,
                   *p_dockConsole;
  QTabWidget       *p_tabFlowItems,
                   *p_tabFlowWindows,
                   *p_tabConsole;
  CustomListWidget *p_itemListWidget;
  /*
  QAction      *p_actFileNew,
    *p_actFileOpen,
    *p_actFileSave,
    *p_actFileExit,
    *p_actViewFlowItems,
    *p_actViewConsole,
    *p_actToolsAccount,
    *p_actHelpAbout;
  */
  //QTextEdit    *p_textConsole;
  //LayoutDrawWidget *p_layout;
public:
  MainWindow();
  ~MainWindow();
private:
  void InitMainUI();
  void InitActions();
  void InitMenubar();
  void InitToolbar();

private slots:
  void OnMenu_File_Exit();
  void OnMenu_Help_About();
};
