/**
 * @file /include/button/main_window.hpp
 *
 * @brief Qt based gui for %(package)s.
 *
 * @date August 2024
 **/

#ifndef button_MAINWINDOW_H
#define button_MAINWINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QMainWindow>
#include <QIcon>
#include <QDebug>  // qDebug() 사용을 위해 추가
#include "qnode.hpp"
#include "ui_mainwindow.h"

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();
  QNode* qnode;

private slots:
  void on_right_button_clicked();
  void on_left_button_clicked();
  void on_jump_button_clicked();

private:
  Ui::MainWindowDesign* ui;
  void closeEvent(QCloseEvent* event);
};

#endif  // button_MAINWINDOW_H
