#include "Logger.hpp"

Logger *Logger::p_instance = nullptr;

void Logger::Init() {
  if (!p_instance)
    p_instance = new Logger;
}

Logger *Logger::Get() {
  return p_instance;
}

void Logger::Free() {
  if (p_instance) {
    delete p_instance;
    p_instance = nullptr;
  }
}

void Logger::AssignTextEdit(QTextEdit *textEdit) {
  p_console = textEdit;
}

void Logger::Log(const QString &text) {
  p_console->append(text);
}

void Logger::Warning(const QString &text) {
  p_console->append(QString("Warning: %1").arg(text));
}

void Logger::Error(const QString &text) {
  p_console->append(QString("Error: %1").arg(text));
}
