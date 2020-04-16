#include <QApplication>
#include <QLabel>

#include "MainWindow.hpp"

#if defined(_WIN32) || defined(_WIN64)
#define BULD_WITHOUT_CONSOLE            
#endif

int
#if defined(BULD_WITHOUT_CONSOLE)
__stdcall WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, char*, int nShowCmd) {
  int     argc = 0;
  char  **argv = nullptr;
#else
main(int argc, char *argv[]) {
#endif
  QApplication app(argc, argv);
  MainWindow *p_mainWindow = new MainWindow;
  if (!p_mainWindow)
    return EXIT_FAILURE;
  p_mainWindow->show();
  return app.exec();
}
