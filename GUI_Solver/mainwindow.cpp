#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Add cube to the scene
    scene = new QGraphicsScene(0,0,600,400);
    cubeView = new CubeView(scene, QString::fromStdString(cube.toString()));
    ui->cubeView->setScene(scene);

    //Set up push buttons
    connect(ui->inputDoneBtn, &QPushButton::released, this, &MainWindow::inputBtnHandle);
    connect(ui->resetBtn, &QPushButton::released, this, &MainWindow::resetBtnHandle);
    connect(ui->scrambleBtn, &QPushButton::released, this, &MainWindow::scrambleBtnHandle);
    connect(ui->FBtn, &QPushButton::released, this, &MainWindow::FBtnHandle);
    connect(ui->FprimeBtn, &QPushButton::released, this, &MainWindow::FprimeBtnHandle);
    connect(ui->BBtn, &QPushButton::released, this, &MainWindow::BBtnHandle);
    connect(ui->BprimeBtn, &QPushButton::released, this, &MainWindow::BprimeBtnHandle);
    connect(ui->UBtn, &QPushButton::released, this, &MainWindow::UBtnHandle);
    connect(ui->UprimeBtn, &QPushButton::released, this, &MainWindow::UprimeBtnHandle);
    connect(ui->DBtn, &QPushButton::released, this, &MainWindow::DBtnHandle);
    connect(ui->DprimeBtn, &QPushButton::released, this, &MainWindow::DprimeBtnHandle);
    connect(ui->LBtn, &QPushButton::released, this, &MainWindow::LBtnHandle);
    connect(ui->LprimeBtn, &QPushButton::released, this, &MainWindow::LprimeBtnHandle);
    connect(ui->RBtn, &QPushButton::released, this, &MainWindow::RBtnHandle);
    connect(ui->RprimeBtn, &QPushButton::released, this, &MainWindow::RprimeBtnHandle);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inputBtnHandle()
{
    if (!ui->inputCubeText->toPlainText().isEmpty()) {
//        cube.setCube(ui->inputCubeText->toPlainText());
//        ui->currCubeText->setText(ui->inputCubeText->toPlainText());
//        cubeView->setCube(QString::fromStdString(cube.toString()));
    }
    else {
        ui->currCubeText->setText(QString::fromStdString(cube.toString()));
    }
}

void MainWindow::resetBtnHandle()
{
    ui->scrambleOutput->setText("");
    cubeView->setCube(QString::fromStdString(cube.reset()));
}

void MainWindow::scrambleBtnHandle()
{
    ui->scrambleOutput->setText(QString::fromStdString(cube.scramble()));
    cubeView->setCube(QString::fromStdString(cube.toString()));
}

void MainWindow::FBtnHandle()
{
    cube.f();
    cubeView->setCube(QString::fromStdString(cube.toString()));
}

void MainWindow::FprimeBtnHandle()
{
    cube.fPrime();
    cubeView->setCube(QString::fromStdString(cube.toString()));
}

void MainWindow::BBtnHandle() {
    cube.b();
    cubeView->setCube(QString::fromStdString(cube.toString()));
}
void MainWindow::BprimeBtnHandle(){
    cube.bPrime();
    cubeView->setCube(QString::fromStdString(cube.toString()));
}
void MainWindow::UBtnHandle(){
    cube.u();
    cubeView->setCube(QString::fromStdString(cube.toString()));
}
void MainWindow::UprimeBtnHandle(){
    cube.uPrime();
    cubeView->setCube(QString::fromStdString(cube.toString()));
}
void MainWindow::DBtnHandle(){
    cube.d();
    cubeView->setCube(QString::fromStdString(cube.toString()));
}
void MainWindow::DprimeBtnHandle(){
    cube.dPrime();
    cubeView->setCube(QString::fromStdString(cube.toString()));
}
void MainWindow::LBtnHandle(){
    cube.l();
    cubeView->setCube(QString::fromStdString(cube.toString()));
}
void MainWindow::LprimeBtnHandle(){
    cube.lPrime();
    cubeView->setCube(QString::fromStdString(cube.toString()));
}
void MainWindow::RBtnHandle(){
    cube.r();
    cubeView->setCube(QString::fromStdString(cube.toString()));
}
void MainWindow::RprimeBtnHandle(){
    cube.rPrime();
    cubeView->setCube(QString::fromStdString(cube.toString()));
}
