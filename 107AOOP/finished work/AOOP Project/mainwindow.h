#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "qcustomplot.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QCPItemText *textItem;
    public:
        void reset();
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();


    private slots:
        void StandardpushButton();
        void PolarPushButtom();
        void ParameterPushButtom();
        void saveButton();

        //void ShowEquationButton_clicked();

        void FittingHelpButtonClicked();
        void DrawPointsButton();
        void on_ShowEquationButton_clicked();
        void BasisOkButton();
        void on_CursorButton_clicked();
        void on_AddItem_clicked();
        void onMouseMoveGraph(QMouseEvent* evt);
        void onMouseRelease(QMouseEvent* evt);

protected:
        Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
