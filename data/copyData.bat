@echo off

echo Copying .qml files to %2
echo %1
echo %2
xcopy /d /y /s %1\..\..\data\QmlData\*.* %2\QmlData\
echo Qml files are copied.