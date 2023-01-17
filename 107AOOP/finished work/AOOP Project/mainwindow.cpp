#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fuction_processing.h"
#include "qcustomplot.h"
QString org;
int show_cursor_cnt=0;
bool show_equaiton=false;
bool show_cursor=false;
#define item_cnt 10
template<class node_type>
struct graph_node
{
    node_type* exe;
    graph_node* next;
};
void MainWindow::reset()
{
    show_equaiton=false;
    ui->function_plot->clearGraphs();
    ui->function_plot->clearItems();
    input_processing::ResetInput();
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    ui->tableWidget->setRowCount(item_cnt);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList hor_header={"x","y"};
    ui->tableWidget->setHorizontalHeaderLabels(hor_header);

    connect(ui->StandardPushButtom,SIGNAL(clicked()), this, SLOT(StandardpushButton()));
    connect(ui->PolarPushButtom,SIGNAL(clicked()), this, SLOT(PolarPushButtom()));
    connect(ui->ParameterPushButtom,SIGNAL(clicked()), this, SLOT(ParameterPushButtom()));
    connect(ui->saveButtom,SIGNAL(clicked()),this,SLOT(saveButton()));
    connect(ui->ShowEquationButton,SIGNAL(clicked()),this,SLOT(on_ShowEquationButton_clicked()));
    connect(ui->DrawPoints,SIGNAL(clicked()),this,SLOT(DrawPointsButton()));
    connect(ui->BasisOk,SIGNAL(clicked()),this,SLOT(BasisOkButton()));
    connect(ui->function_plot, SIGNAL(mouseMove(QMouseEvent*)), this,SLOT(onMouseMoveGraph(QMouseEvent*)));
    connect(ui->function_plot, SIGNAL(mouseRelease(QMouseEvent*)), this,SLOT(onMouseRelease(QMouseEvent* )));
    connect(ui->CursorButton,SIGNAL(clicked()),this,SLOT(on_CursorButton_clicked()));
    connect(ui->FittingHelpButton,SIGNAL(clicked()),this,SLOT(FittingHelpButtonClicked()));
    connect(ui->AddItem,SIGNAL(clicked()),this,SLOT(on_AddItem_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StandardpushButton()
{
    reset();
    //get string form ui
    graphics *exe=new graphics(ui->StandardTextEdit->toPlainText().toStdString(),ui);

    cout<<"Parentheses checking\n";
    QString s=ui->StandardTextEdit->toPlainText();
    org=s;
    if(exe->ParenthesesChecking()==false)
        QMessageBox::critical(this,"error","unbalanced parentheses!");
    if(exe->ParenthesesChecking()&&(s!=""))
    {
        exe->MathFunctionReplace();
        exe->AddMultiply();

        exe->AddSpace();
        exe->ExpReplace();
        qDebug()<<"s="<<exe->returns()<<"\n";
        exe->InfixToPostfix();
        qDebug()<<"postfix:\n";
        qDebug()<<"s="<<exe->returns()<<"\n";
        try {
            exe->GenerateXY_Standard();
        } catch (const char*s) {
            QMessageBox::critical(this,"error",s);
        }

        if(exe->error())
        {
            qDebug()<<"In StandardPushButtom:\n";
            qDebug()<<"incorrect standard equation\n";

        }
        else
            exe->draw();
     }
    ui->function_plot->replot();
}

void MainWindow::PolarPushButtom()
{

    //get string form ui
    /*graphics*exe=new graphics(ui->PolarlineEdit->text().toStdString(),ui);
    exe->SetState(input_processing::type::polar);*/
    QString s=ui->PolarlineEdit->text(),postfix;
    graphics*tmp=new graphics(ui->PolarlineEdit->text().toStdString(),ui,input_processing::type::polar);
    if(tmp->ParenthesesChecking()==false)
        QMessageBox::critical(this,"error","unbalanced parentheses!");
    if(tmp->ParenthesesChecking()==false||(s==""))return;
    tmp->MathFunctionReplace();
    tmp->AddMultiply();
    tmp->AddSpace();
    tmp->ExpReplace();
    tmp->InfixToPostfix();
    postfix=tmp->returns();
    reset();
    bool ok=true;
    double MaxTheta=ui->maxtheta->text().toDouble(&ok);
    if(!ok)
    {
        MaxTheta=2;
    }
    struct graph_node<graphics>*p,*head,*tail;
    head=tail=new graph_node<graphics>;
    tail->next=nullptr;
    double i;
    for(i=0;i<MaxTheta;i+=0.01)
    {
        //qDebug()<<"i="<<i<<endl;
        p=new graph_node<graphics>;
        p->exe=new graphics(ui->PolarlineEdit->text().toStdString(),ui,input_processing::type::polar);
        double start=i;
        double end=(i+0.02>MaxTheta)?MaxTheta:i+0.02;
        qDebug()<<"end:"<<end<<endl;
        p->exe->SetPolarRange(start,end);
        p->next=nullptr;
        qDebug()<<"s="<<s<<endl;

        //qDebug()<<"mathfunction replace:\n"<<p->exe->returns()<<endl;

        //qDebug()<<"Add Multiply and Space:\n"<<p->exe->returns()<<endl;

        //qDebug()<<"Postfix:\n"<<p->exe->returns()<<endl;
        p->exe->setS(postfix.toStdString());
        try {
            p->exe->GenerateXY_Polar();
        } catch (const char*s) {
            QMessageBox::critical(this,"error",s);
        }

        if(p->exe->error())
        {
            qDebug()<<"In PolarPushButtom:\n";
            qDebug()<<"incorrect polar equation\n";
            return;
        }
        p->exe->draw();

    org=s;

    }
    p=head;
    head=head->next;
    delete p;
    ui->function_plot->replot();
}

void MainWindow::ParameterPushButtom()
{
    reset();
    QString s1=ui->ParameterXlineEdit->text(),postfix1,postfix2;
    graphics*tmp1=new graphics(s1.toStdString(),ui,input_processing::type::polar);
    if(tmp1->ParenthesesChecking()==false)
        QMessageBox::critical(this,"error","unbalanced parentheses!");
    if(tmp1->ParenthesesChecking()==false||(s1==""))return;
    tmp1->MathFunctionReplace();
    tmp1->AddMultiply();
    tmp1->AddSpace();
    tmp1->ExpReplace();
    tmp1->InfixToPostfix();
    postfix1=tmp1->returns();
    reset();

    QString s2=ui->ParameterYlineEdit->text();
    calculation*tmp2=new graphics(s2.toStdString(),ui,input_processing::type::polar);
    if(tmp2->ParenthesesChecking()==false)
        QMessageBox::critical(this,"error","unbalanced parentheses!");
    if(tmp2->ParenthesesChecking()==false||(s2==""))return;
    tmp2->MathFunctionReplace();
    tmp2->AddMultiply();
    tmp2->AddSpace();
    tmp2->ExpReplace();
    tmp2->InfixToPostfix();
    postfix2=tmp2->returns();
    reset();
    bool ok=true;
    double MaxParameter=ui->ParameterStartlineEdit->text().toDouble(&ok);
    double MinParameter=ui->ParameterEndlineEdit->text().toDouble(&ok);
    if(!ok)
    {
        MinParameter=0;
        MaxParameter=10;
    }
    if(MinParameter>MaxParameter)//swap
    {
        double t=MinParameter+MaxParameter;
        MinParameter=t-MinParameter;
        MaxParameter=t-MinParameter;
    }
    struct graph_node<graphics>*p,*head,*tail;
    head=tail=new graph_node<graphics>;
    tail->next=nullptr;
    double i;

    reset();

    org=QString("X=")+ ui->ParameterXlineEdit->text()+QString("\n")+ QString("Y=")+ui->ParameterYlineEdit->text();
    for(i=MinParameter;i<MaxParameter;i+=0.02)
    {

        p=new graph_node<graphics>;
        p->exe=new graphics(postfix1.toStdString(),ui,input_processing::type::polar);
        double start=i;
        double end=(i+0.02>MaxParameter)?MaxParameter:i+0.02;
        qDebug()<<"end:"<<end<<endl;
        p->exe->SetParameterRange(start,end);
        p->next=nullptr;

        calculation *ypar=new calculation(postfix2.toStdString(),ui,input_processing::type::standard);
        //qDebug()<<"mathfunction replace:\n"<<p->exe->returns()<<endl;

        //qDebug()<<"Add Multiply and Space:\n"<<p->exe->returns()<<endl;

        //qDebug()<<"Postfix:\n"<<p->exe->returns()<<endl;
        try {
            p->exe->GenerateXY_Parameter(*ypar);
        } catch (const char*s) {
            QMessageBox::critical(this,"error",s);
        }

        if(p->exe->error()||ypar->error())
        {
            qDebug()<<"In ParameterPushButtom:\n";
            qDebug()<<"incorrect parameter equation\n";
            return;
        }

        p->exe->draw();

    }

    ui->function_plot->replot();

}

void MainWindow::saveButton()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "C:\\",
                               tr("Images (*.png);;Images (*.jpg)"));
    QFileInfo fi(fileName);

    if(fi.completeSuffix()=="png")
    {
        if(fi.exists())
        {
            switch(QMessageBox::warning(this,tr("message"),tr(fi.fileName().toStdString().append("already exists.\nDo you want to overwrite it?").c_str()),QMessageBox::Yes|QMessageBox::No))
            {
                 case QMessageBox::Yes:
                    //按下覆蓋覆蓋鍵後的處理
                {
                    QFile file(fileName);

                    if (!file.open(QIODevice::WriteOnly))
                    {
                        QMessageBox::warning(this,"error","Cannot save the file!");
                    }
                    ui->function_plot->savePng(fileName);
                    QString fileInformation("file has been successfully saved\n");
                    fileInformation.append("full path: ");
                    fileInformation.append(fileName).append("\n");
                    fileInformation.append("size: ").append(QString::number(fi.size())).append(" bytes\n");
                    QMessageBox::information(this,tr("message"),tr(fileInformation.toStdString().c_str()));
                    break;
                }

                 case QMessageBox::No:
                    //按下放棄鍵後的處理
                    break;
            }

        }
        else
        {
            QFile file(fileName);

            if (!file.open(QIODevice::WriteOnly))
            {
                QMessageBox::warning(this,"error","Cannot save the file!");
            }
            else
            {
                ui->function_plot->savePng(fileName);
                QString fileInformation("file has been successfully saved\n");
                fileInformation.append("full path: ");
                fileInformation.append(fileName).append("\n");
                fileInformation.append("size: ").append(QString::number(fi.size())).append(" bytes\n");
                QMessageBox::information(this,tr("message"),tr(fileInformation.toStdString().c_str()));
            }

        }
    }
    else if(fi.completeSuffix()=="jpg")
    {
        if(fi.exists())
        {
            switch(QMessageBox::warning(this,tr("message"),tr(fi.fileName().toStdString().append("already exists.\nDo you want to overwrite it?").c_str()),QMessageBox::Yes|QMessageBox::No))
            {
                 case QMessageBox::Yes:
                    //按下覆蓋覆蓋鍵後的處理
                {

                    QFile file(fileName);

                    if (!file.open(QIODevice::WriteOnly))
                    {
                        QMessageBox::warning(this,"error","Cannot save the file!");
                    }
                   else{
                        ui->function_plot->saveJpg(fileName);
                        QString fileInformation("file has been successfully saved\n");
                        fileInformation.append("full path: ");
                        fileInformation.append(fileName).append("\n");
                        fileInformation.append("size: ").append(QString::number(fi.size())).append(" bytes\n");
                        QMessageBox::information(this,tr("message"),tr(fileInformation.toStdString().c_str()));
                   }
                    break;
                }

                 case QMessageBox::No:
                    //按下放棄鍵後的處理
                    break;
            }

        }
        else
        {
            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly))
            {
                QMessageBox::warning(this,"error","Cannot save the file!");
            }
            else
            {
                ui->function_plot->saveJpg(fileName);
                QString fileInformation("file has been successfully saved\n");
                fileInformation.append("full path: ");
                fileInformation.append(fileName).append("\n");
                fileInformation.append("size: ").append(QString::number(fi.size())).append(" bytes\n");
                QMessageBox::information(this,tr("message"),tr(fileInformation.toStdString().c_str()));
            }

        }
    }
    else
    {
        QMessageBox::warning(this,tr("message"),tr("Incorrect filename extension\n"));
    }


}



void MainWindow::on_ShowEquationButton_clicked()
{
    QCPItemText *textLabel = new QCPItemText(ui->function_plot);
    textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
    textLabel->position->setType(QCPItemPosition::ptAxisRectRatio);
    textLabel->position->setCoords(0.5, 0); // place position at center/top of axis rect
    textLabel->setText(org);
    textLabel->setFont(QFont(font().family(), 16)); // make font a bit larger
    textLabel->setPen(QPen(Qt::black)); // show black border around text
    show_equaiton=true;
    ui->function_plot->replot();
}
void MainWindow::DrawPointsButton()
{
    reset();
    data_points *pts = new data_points(ui);
    //cout<<"done"<<endl;
    try {
        pts->getpoints();
    } catch (const char* s) {
        QMessageBox::critical(this,"error",s);
        return;
    }
    //cout<<"done"<<endl;
    pts->drawpts();
    ui->function_plot->replot();
}
void MainWindow:: BasisOkButton()
{
    reset();
    data_points *pts = new data_points(ui);
    //cout<<"done"<<endl;
    try {
        pts->getpoints();
    } catch (const char* s) {
        QMessageBox::critical(this,"error",s);
        return;
    }
    //cout<<"done"<<endl;
    pts->drawpts();
    qDebug()<<"A";
    QString BasisString=ui->FittingBasis->text();
    QStringList BasisList=BasisString.split(',',QString::SkipEmptyParts);
    bool basis_error;
    fitting*fit;

    for(int i=0;i<BasisList.size();i++)
    {
        qDebug()<<BasisList.at(i).toStdString().c_str()<<endl;
        input_processing*fit1=new input_processing(BasisList.at(i).toStdString(),ui);
        if(fit1->ParenthesesChecking()==false)
        {
            QMessageBox::critical(this,"error","unbalanced parentheses!");
            return;
        }

    }

    try {
        qDebug()<<"In basis button, try to construct a fitting object";
        fit=new fitting(BasisList.size(),BasisList," ",ui,basis_error);
    } catch (const char*s1) {
        qDebug()<<"In basis button, fail to construct a fitting object";
        QMessageBox::critical(this,"error",s1);
        return;
    }
    catch(...)
    {
        return;
    }
    if(basis_error)
    {
        QMessageBox::critical(this,"error","incorrect input basis");
        return;
    }
    qDebug()<<"B";

    try {
        fit->calmatrix();
    } catch (const char*s) {
        QMessageBox::critical(this,"error",s);
        return;
    }
    org=fit->returns();
    graphics*fit2=new graphics(fit->returns().toStdString(),ui);
    if(fit2->ParenthesesChecking()&&(fit->returns()!=""))
    {
        fit2->MathFunctionReplace();
        fit2->AddMultiply();
        fit2->AddSpace();
        fit2->ExpReplace();
        qDebug()<<"s="<<fit2->returns()<<"\n";
        fit2->InfixToPostfix();
        qDebug()<<"postfix:\n";
        qDebug()<<"s="<<fit2->returns()<<"\n";
        try {
            fit2->GenerateXY_Fitting();
        } catch (const char*s) {
            QMessageBox::critical(this,"error",s);
        }

        if(fit2->error())
        {
            qDebug()<<"In StandardPushButtom:\n";
            qDebug()<<"incorrect standard equation\n";

        }
        else
            fit2->draw();
     }
     ui->function_plot->replot();
     ui->theleastsquared->setText(QString::number(fit->the_least_squared()));
}
void MainWindow::onMouseMoveGraph(QMouseEvent* evt)
{

    qDebug()<<"show_cursor="<<show_cursor;
    ui->function_plot->clearItems();
    if(show_equaiton==true)
        on_ShowEquationButton_clicked();
    if(!show_cursor)return;

    textItem = new QCPItemText(ui->function_plot);
    double x = ui->function_plot->xAxis->pixelToCoord(evt->pos().x());
    double y = ui->function_plot->yAxis->pixelToCoord(evt->pos().y());
    textItem->setText(QString("(%1, %2)").arg(x).arg(y));
    //qDebug()<<"x="<<x<<","<<"y="<<y;
    textItem->position->setCoords(x,y);
    textItem->setFont(QFont(font().family(), 10));


    ui->function_plot->replot();
}
void MainWindow:: onMouseRelease(QMouseEvent* evt)
{
    ui->function_plot->clearItems();
    if(show_equaiton==true)
        on_ShowEquationButton_clicked();
}
void MainWindow:: on_CursorButton_clicked()
{
    show_cursor_cnt++;
    //qDebug()<<"on_CursorButton_clicked";
    if(show_cursor_cnt==2)
    {
        show_cursor=!show_cursor;
        show_cursor_cnt=0;
    }

    //qDebug()<<"show_cursor="<<show_cursor;
    if(show_cursor==false)
    {
        ui->function_plot->clearItems();
        if(show_equaiton==true)
            on_ShowEquationButton_clicked();
    }
    ui->function_plot->replot();

}



void MainWindow::FittingHelpButtonClicked()
{
    const char*s="The input format should be \n\"f1,f2,f3,...,fn\"(use ',' as a delimeter), \nso that the output would be the linear combination of \"f1,f2,f3,...,fn\".\neg.Given the input is\" 1,xe^x,cosx\", the output will be displayed in the form of\nA*1+Bxe^x+Ccosx\n, where A, B, and C are coefficients that minimize the squared residual.";
    QMessageBox::information(this,tr("fitting"),tr(s));
}
void MainWindow:: on_AddItem_clicked()
{
    for(int i=0;i<5;i++)
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}
