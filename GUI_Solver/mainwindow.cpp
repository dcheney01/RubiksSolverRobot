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
    connect(ui->solveBtn, &QPushButton::released, this, &MainWindow::solveBtnHandle);
    connect(ui->applySolveBtn, &QPushButton::released, this, &MainWindow::applySolveBtnHandle);

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
    connect(ui->F2Btn, &QPushButton::released, this, &MainWindow::F2BtnHandle);
    connect(ui->B2Btn, &QPushButton::released, this, &MainWindow::B2BtnHandle);
    connect(ui->U2Btn, &QPushButton::released, this, &MainWindow::U2BtnHandle);
    connect(ui->D2Btn, &QPushButton::released, this, &MainWindow::D2BtnHandle);
    connect(ui->L2Btn, &QPushButton::released, this, &MainWindow::L2BtnHandle);
    connect(ui->R2Btn, &QPushButton::released, this, &MainWindow::R2BtnHandle);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inputBtnHandle()
{
    QString s = "";
    for(int i = 0; i < cube.getSolverOutput().size(); i++) {
        s = s + QString::fromStdString(cube.getSolverOutput()[i]) + " ";
    }
    ui->currCubeText->setText(s);
}

void MainWindow::resetBtnHandle()
{
    ui->scrambleOutput->setText("");
    ui->currCubeText->setText("");
    ui->solutionOutput->setText("");
    ui->inputCubeText->clear();
    ui->timeToSolve->setText("0.0");
    ui->numMoves->setText("0");
    cubeView->setCube(QString::fromStdString(cube.reset()));
}

void MainWindow::scrambleBtnHandle()
{
    ui->scrambleOutput->setText(QString::fromStdString(cube.scramble()));
    cubeView->setCube(QString::fromStdString(cube.toString()));
}

void MainWindow::solveBtnHandle()
{
    //solve the cube
    solver = new Solver();
    std::vector<std::string> temp = cube.getSolverOutput();
    auto start = std::chrono::high_resolution_clock::now();
    solver->solve(temp);
    auto finish = std::chrono::high_resolution_clock::now();
    auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);

    //output the solution
    std::vector<std::string> solved = solver->getSolveMoves();
    QString output = "";
    for (int i = 0; i < solved.size(); i++) {
        output = output + QString::fromStdString(solved[i]) + " ";
    }

    ui->solutionOutput->setText(output);
    ui->timeToSolve->setText(QString::number(microseconds.count()/1000.0));
    ui->numMoves->setText(QString::number(solved.size()));
}

void MainWindow::applySolveBtnHandle()
{
    std::vector<std::string> solved = solver->getSolveMoves();
    MoveSimplify moveSimplify;
    std::vector<CubeModel::MOVE> moves = moveSimplify.simplify(solved);
    for (int i = 0; i < moves.size(); i++) {
        cube.move(moves[i]);
    }
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
void MainWindow::F2BtnHandle(){
    cube.f2();
    cubeView->setCube(QString::fromStdString(cube.toString()));
}
void MainWindow::B2BtnHandle(){
    cube.b2();
    cubeView->setCube(QString::fromStdString(cube.toString()));
}
void MainWindow::U2BtnHandle(){
    cube.u2();
    cubeView->setCube(QString::fromStdString(cube.toString()));
}
void MainWindow::D2BtnHandle(){
    cube.d2();
    cubeView->setCube(QString::fromStdString(cube.toString()));
}
void MainWindow::L2BtnHandle(){
    cube.l2();
    cubeView->setCube(QString::fromStdString(cube.toString()));
}
void MainWindow::R2BtnHandle(){
    cube.r2();
    cubeView->setCube(QString::fromStdString(cube.toString()));
}
