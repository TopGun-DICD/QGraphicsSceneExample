#pragma once

#include <QTextEdit>

class Logger {
  static Logger *p_instance;
  QTextEdit     *p_console;
private:
  Logger() {};
public:
  static void Init();
  static Logger *Get();
  static void Free();
public:
  void AssignTextEdit(QTextEdit *textEdit);
  void Log(const QString &text);
  void Warning(const QString &text);
  void Error(const QString &text);
};