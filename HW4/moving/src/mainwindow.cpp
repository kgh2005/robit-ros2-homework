#include "../include/moving/mainwindow.hpp"
#include <QKeyEvent>
#include <QLabel>
#include <QTimer>

MainWindow::MainWindow(QWidget* parent, rclcpp::Node::SharedPtr node)
    : QMainWindow(parent),
      ui(new Ui::MainWindowDesign),
      characterX(280),
      characterY(290),
      isJumping(false),
      jumpCount(0) {
    ui->setupUi(this);
    QIcon icon("://ros-icon.png");
    this->setWindowIcon(icon);

    qnode = new QNode(node);
    qnode->init();

    // 시그널-슬롯 연결
    QObject::connect(qnode, &QNode::rosShutDown, this, &MainWindow::close);
    QObject::connect(qnode, &QNode::messageReceived, this, &MainWindow::processCommand);

    // QLabel을 사용하여 캐릭터를 생성
    label = new QLabel(this);
    label->setGeometry(characterX, characterY, 50, 50); // QLabel 위치 및 크기 설정

    // 주기적으로 ROS 콜백을 호출하기 위한 타이머 설정
    setupTimer();
}

void MainWindow::setupTimer() {
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this]() {
        rclcpp::spin_some(qnode->getNode()); // QNode의 노드를 통해 콜백 처리
        updateJump();
    });
    timer->start(16); // 60 FPS
}

void MainWindow::processCommand(const QString &command) {
    if (command == "left") {
        characterX -= 10; // 왼쪽으로 이동
    } else if (command == "right") {
        characterX += 10; // 오른쪽으로 이동
    } else if (command == "jump") {
        if (!isJumping) {
            isJumping = true; // 점프 상태 설정
            jumpCount = 0; // 점프 카운트 초기화
        }
    }

    // 캐릭터 위치 업데이트
    label->move(characterX, characterY); // QLabel의 위치를 직접 설정
}

void MainWindow::updateJump() {
    if (isJumping) {
        if (jumpCount < 10) {
            characterY -= 10; // 위로 10만큼 점프
            jumpCount++;
        } else if (jumpCount < 20) {
            characterY += 10; // 아래로 10만큼 내려오기
            jumpCount++;
        } else {
            isJumping = false; // 점프 상태 해제
            jumpCount = 0; // 점프 카운트 초기화
        }
    }

    label->move(characterX, characterY); // QLabel의 위치를 직접 설정
}

void MainWindow::closeEvent(QCloseEvent *event) {
    // 여기에 추가할 코드가 있으면 작성
    event->accept(); // 기본 동작을 수행
}

MainWindow::~MainWindow() {
    delete ui;
    delete label; // QLabel 삭제
    delete qnode;
}
