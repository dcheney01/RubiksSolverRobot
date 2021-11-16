#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Add cube to the scene
    scene = new QGraphicsScene(0,0,600,400);
    cube = new CubeView(scene);
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
        cube->setCube(ui->inputCubeText->toPlainText());
        ui->currCubeText->setText(ui->inputCubeText->toPlainText());
        cube->update();
    }
    else {
        QString output = cube->getCube();
        ui->currCubeText->setText(output);
    }
}

void MainWindow::resetBtnHandle()
{
    cube->reset();
    ui->scrambleOutput->setText("");
    cube->update();
}

void MainWindow::scrambleBtnHandle()
{
    ui->scrambleOutput->setText(cube->scramble());
    cube->update();
}

void MainWindow::FBtnHandle()
{
    cube->fTurn();
    cube->update();
}

void MainWindow::FprimeBtnHandle()
{
    cube->fprimeTurn();
    cube->update();
}

void MainWindow::BBtnHandle() {
    cube->bTurn();
    cube->update();
}
void MainWindow::BprimeBtnHandle(){
    cube->bprimeTurn();
    cube->update();
}
void MainWindow::UBtnHandle(){
    cube->uTurn();
    cube->update();
}
void MainWindow::UprimeBtnHandle(){
    cube->uprimeTurn();
    cube->update();
}
void MainWindow::DBtnHandle(){
    cube->dTurn();
    cube->update();
}
void MainWindow::DprimeBtnHandle(){
    cube->dprimeTurn();
    cube->update();
}
void MainWindow::LBtnHandle(){
    cube->lTurn();
    cube->update();
}
void MainWindow::LprimeBtnHandle(){
    cube->lprimeTurn();
    cube->update();
}
void MainWindow::RBtnHandle(){
    cube->rTurn();
    cube->update();
}
void MainWindow::RprimeBtnHandle(){
    cube->rprimeTurn();
    cube->update();
}
