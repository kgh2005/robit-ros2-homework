#include "../include/button/mainwindow.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindowDesign)
{
    ui->setupUi(this);

    QIcon icon("://ros-icon.png");
    this->setWindowIcon(icon);

    qnode = new QNode();
    qnode->init(); // QNode 초기화 호출

    // ROS 종료 시그널과 MainWindow 종료 연결
    QObject::connect(qnode, &QNode::rosShutDown, this, &MainWindow::close);

    // 버튼 클릭 시그널과 슬롯 연결
    QObject::connect(ui->right_button, &QPushButton::clicked, this, &MainWindow::on_right_button_clicked);
    QObject::connect(ui->left_button, &QPushButton::clicked, this, &MainWindow::on_left_button_clicked);
    QObject::connect(ui->jump_button, &QPushButton::clicked, this, &MainWindow::on_jump_button_clicked);
}

MainWindow::~MainWindow() // 소멸자 구현
{
    delete qnode; // QNode 객체 메모리 해제
    delete ui;    // UI 객체 메모리 해제
}

void MainWindow::closeEvent(QCloseEvent* event) // closeEvent 구현
{
    QMainWindow::closeEvent(event); // 부모 클래스의 closeEvent 호출
}

void MainWindow::on_right_button_clicked() {
    qnode->publishMessage("right"); // "right" 메시지 퍼블리시
}

void MainWindow::on_left_button_clicked() {
    qnode->publishMessage("left"); // "left" 메시지 퍼블리시
}

void MainWindow::on_jump_button_clicked() {
    qnode->publishMessage("jump"); // "jump" 메시지 퍼블리시
}
