#pragma once

#include <QMainWindow>
#include <QTextEdit>

#include "CustomListWidget.hpp"
#include "View.hpp"

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
  View             *p_view;
  QTextEdit        *p_console;
  QAction          *p_actFileNew,
                   *p_actFileExit,
                   *p_actHelpAbout;
public:
  MainWindow();
 ~MainWindow();
private:
  void InitMainUI();
  void InitActions();
  void InitMenubar();
  void InitToolbar();
  void InitStatusbar();
private slots:
  void OnMenu_File_New();
  void OnMenu_File_Exit();
  void OnMenu_Help_About();
};
