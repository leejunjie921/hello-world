#include <QApplication>
#include <QFile>
#include <QFontDatabase>
#include <QTranslator>
#include <QSharedMemory>
#include <windows.h>
#include <dbghelp.h>
#include <QApplication>
#include <QScreen>
#define CLASS_NAME "main"


#pragma comment(lib, "Dbghelp.lib")


#include <QObject>

int main(int argc, char *argv[])
{

    QGuiApplication::setAttribute(Qt::AA_DisableHighDpiScaling);
    QApplication a(argc, argv);


    return a.exec();

}

