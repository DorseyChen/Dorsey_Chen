#include "fuction_processing.h"
#include"mainwindow.h"
#include"qcustomplot.h"
#include"QDebug"
graphics::graphics(string str,Ui::MainWindow*ui,type state):calculation (str,ui,state)
{
}

graphics::graphics()
{
    cout<<"graphics() is called\n";
}

graphics::~graphics()
{
    cout<<"destructor of 'graphics' is called\n";
    delete pixmap;
    delete painter;
}

void graphics::draw()
{
    //qDebug()<<"id= "<<id<<endl;
    ui->function_plot->clearItems();
    //ui->function_plot->clearGraphs();
    pts::iterator ptsItr;
    QVector<QPoint> points2;
    QVector<double>X,Y;
    double a=3;
    QString::number(a);
    for(ptsItr=x_y.begin();ptsItr!=x_y.end();ptsItr++)
    {
        X.push_back(ptsItr->first);
        Y.push_back(ptsItr->second);
        //double a=ptsItr->first;
        //double b=ptsItr->second;
        //qDebug()<<QString::number(a)<<" "<<QString::number(b)<<endl;
    }

    // configure right and top axis to show ticks but no labels:
    // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
    ui->function_plot->xAxis2->setVisible(true);
    ui->function_plot->xAxis2->setTickLabels(false);
    ui->function_plot->yAxis2->setVisible(true);
    ui->function_plot->yAxis2->setTickLabels(false);

    ui->function_plot->addGraph();
    int graphcnt=ui->function_plot->graphCount();
    ui->function_plot->graph(graphcnt-1)->setPen(QPen(Qt::blue)); // line color blue for first graph
    //~ui->function_plot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
    //ui->function_plot->addGraph();
    //~ui->function_plot->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(ui->function_plot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->function_plot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->function_plot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->function_plot->yAxis2, SLOT(setRange(QCPRange)));

    // pass data points to graphs:
    ui->function_plot->graph(graphcnt-1)->setData(X, Y);
    //ui->function_plot->graph(1)->setData(x, y1);

    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
    ui->function_plot->graph(graphcnt-1)->rescaleAxes();

    // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
    //~ui->function_plot->graph(1)->rescaleAxes(true);
    // Note: we could have also just called ui->function_plot->rescaleAxes(); instead

    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
    ui->function_plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}
