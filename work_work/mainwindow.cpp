#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_thread_server=new thread_sever;
    m_thread_server->start();
    qDebug()<<"start";
    connect(m_thread_server,&thread_sever::ButtonChanged,this,&MainWindow::getButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getButton(QString str)
{
    static int m=0;
    qDebug()<<"add button";
    MyButton *m_btn=new MyButton();
    str.append("+");
    str.append(QString::number(m));
    m_btn->setText(str);

    m_button_list.append(m_btn);
    for(int i=0;i<m_button_list.size();++i)
    {
        qDebug()<<i;
        m_button_list.at(i)->setParent(this);
        m_button_list.at(i)->move(i*50,50*(i/5));
        m_button_list.at(i)->show();
    }
//    update();
}
