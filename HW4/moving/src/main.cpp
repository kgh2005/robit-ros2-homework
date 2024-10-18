#include <QApplication>
#include <iostream>

#include "../include/moving/mainwindow.hpp"

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
