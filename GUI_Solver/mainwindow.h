#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QTextBrowser>

#include "CubeView.h"
#include "CubieView.h"
#include "FaceView.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void inputBtnHandle();
    void resetBtnHandle();
    void scrambleBtnHandle();
    void FBtnHandle();
    void FprimeBtnHandle();
    void BBtnHandle();
    void BprimeBtnHandle();
    void UBtnHandle();
    void UprimeBtnHandle();
    void DBtnHandle();
    void DprimeBtnHandle();
    void LBtnHandle();
    void LprimeBtnHandle();
    void RBtnHandle();
    void RprimeBtnHandle();

private:
    Ui::MainWindow *ui;
    QGraphicsView *view;
    QGraphicsScene *scene;
    CubeView *cube;
};
#endif // MAINWINDOW_H
