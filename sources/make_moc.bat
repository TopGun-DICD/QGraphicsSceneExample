@echo off

set MOC=%QTDIR64%\bin\moc.exe
set RCC=%QTDIR64%\bin\rcc.exe

%MOC% -o moc_MainWindow.cpp MainWindow.hpp
%MOC% -o moc_View.cpp View.hpp
%MOC% -o moc_Scene.cpp Scene.hpp
%MOC% -o moc_SceneEventFilter.cpp SceneEventFilter.hpp

pause
exit /b
