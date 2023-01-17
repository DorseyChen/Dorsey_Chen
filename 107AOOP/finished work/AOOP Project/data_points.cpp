#include "fuction_processing.h"
#include "mainwindow.h"
#include "qcustomplot.h"
#include "QDebug"
#include "stdio.h"

data_points::data_points()
{

}
data_points::data_points(Ui::MainWindow*ui)
{
    this->data_points_ui=ui;
}

void data_points::getpoints()throw(const char*)
{
    QString numx,numy;
    pt_cnt=0;
    for(int i=0;i<50;i++)
    {
        QTableWidgetItem *xitem(data_points_ui->tableWidget->item(i,0));
        QTableWidgetItem *yitem(data_points_ui->tableWidget->item(i,1));
        if(xitem&&yitem&&xitem->text().isEmpty()==false&&yitem->text().isEmpty()==false)
            pt_cnt++;
        else
            break;
    }

    qDebug()<<"pt_cnt"<<pt_cnt;
    pt = new QPointF[pt_cnt];
    bool okx=true,oky=true;
    char*exception=new char[50];
    for(int i=0;i<pt_cnt;i++)
    {
        okx=true;
        oky=true;
        numx = data_points_ui->tableWidget->item(i,0)->text();
        numy = data_points_ui->tableWidget->item(i,1)->text();
        qDebug()<<"numx="<<numx<<"numy"<<numy;
        pt[i].setX(numx.toDouble(&okx));
        pt[i].setY(numy.toDouble(&oky));
        //cout<<pt[i].x()<<endl;
        //cout<<pt[i].y()<<endl;
        if(!okx||!oky)
        {
            if(i+1==1)
                sprintf(exception,"Error occurs at the 1st item.");
            else if(i+1==2)
                sprintf(exception,"Error occurs at the 2nd item.");
            else if(i+1==3)
                sprintf(exception,"Error occurs at the 3rd item.");
            else
                sprintf(exception,"Error occurs at the %dth item.",i+1);
            throw exception;
        }
    }
}

void data_points::drawpts()
{
    //qDebug()<<"id= "<<id<<endl;
    data_points_ui->function_plot->clearItems();
    //ui->function_plot->clearGraphs();
    QVector<double>X,Y;

    for(int i=0;i<pt_cnt;i++)
    {
        X.push_back(pt[i].x());
        Y.push_back(pt[i].y());
        //cout<<"success."<<endl;
    }

    // configure right and top axis to show ticks but no labels:
    // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
    data_points_ui->function_plot->xAxis2->setVisible(true);
    data_points_ui->function_plot->xAxis2->setTickLabels(false);
    data_points_ui->function_plot->yAxis2->setVisible(true);
    data_points_ui->function_plot->yAxis2->setTickLabels(false);

    data_points_ui->function_plot->addGraph();
    int graphcnt=data_points_ui->function_plot->graphCount();
    data_points_ui->function_plot->graph(graphcnt-1)->setPen(QPen(Qt::blue)); // line color blue for first graph
    data_points_ui->function_plot->graph(graphcnt-1)->setLineStyle(QCPGraph::lsNone);
    data_points_ui->function_plot->graph(graphcnt-1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssSquare, QColor("#000080"), QColor("#6495ED"), 10));

    // pass data points to graphs:
    data_points_ui->function_plot->graph(graphcnt-1)->setData(X, Y);
    //ui->function_plot->graph(1)->setData(x, y1);

    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
    data_points_ui->function_plot->graph(graphcnt-1)->rescaleAxes();

    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
    data_points_ui->function_plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

data_points::~data_points()
{
    delete pt;
}
