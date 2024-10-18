#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "../include/moving/qnode.hpp" // QNode 헤더 포함
#include "ui_mainwindow.h" // Ui 헤더 파일 추가

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, rclcpp::Node::SharedPtr node = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MainWindowDesign *ui; // Ui::MainWindowDesign 포인터
    QNode *qnode;
    QLabel *label; // QLabel을 여기에 선언
    int characterX, characterY;
    bool isJumping;
    int jumpCount;

    void processCommand(const QString &command);
    void setupTimer();
    void updateJump();
};

#endif // MAINWINDOW_H
