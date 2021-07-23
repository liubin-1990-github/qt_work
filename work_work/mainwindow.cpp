#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMain();
    m_thread_server=new thread_sever;
    m_thread_server->start();
//    qDebug()<<"start";
    connect(m_thread_server,&thread_sever::ButtonChanged,this,&MainWindow::getButton);
    connect(m_thread_server,&thread_sever::sendData,this,&MainWindow::getDataFromSub);
    connect(this,&MainWindow::SendDataToMember,&m_treeWidget,&current_data_tree_view::getDataFromMain);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMain()
{
    this->setFixedSize(MAINWIDTH,MAINHEIGTH);
//    m_treeWidget=new current_data_tree_widget(this);
//    m_treeWidget->hide();
    QMenuBar *mBar=menuBar();
    QMenu *oper=mBar->addMenu("op");
    QAction *current_data=oper->addAction("current data");
    connect(current_data,&QAction::triggered,this,&MainWindow::showCurrentData);
    connect(&m_treeWidget,&current_data_tree_view::tree_Widget_close,this,&MainWindow::show);

}

void MainWindow::getButton(QString str,int fd)
{
    qDebug()<<"add button";
    MyButton *m_btn=new MyButton();
    str.append("+");
    str.append(QString::number(fd));
    m_btn->setText(str);
    m_btn->m_fd=fd;
    m_button_list.append(m_btn);
    for(int i=0;i<m_button_list.size();++i)
    {
        qDebug()<<i;
        m_button_list.at(i)->setParent(this);
        m_button_list.at(i)->move((i%5)*100,50*(i/5)+200);
        m_button_list.at(i)->show();
    }
    //    update();
}

void MainWindow::client_Disconnected(int fd)
{

}

void MainWindow::getDataFromSub(int fd, QString ip, int cpu, int gpu, int dis, int mem, QString time)
{
    emit SendDataToMember(fd,ip,cpu,gpu,dis,mem,time);
}

void MainWindow::showCurrentData()
{
    this->hide();
    m_treeWidget.show();
}
