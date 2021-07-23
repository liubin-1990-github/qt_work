#if 0

#include "current_data_tree_widget.h"
#include <QDebug>

current_data_tree_widget::current_data_tree_widget(QWidget *parent) : QTreeWidget(parent)
{
    this->setItemsExpandable(true);
    this->expandAll();
    this->setFixedSize(1200,800);
    temp=new QTreeWidgetItem();
    data=new QTreeWidgetItem();
//    m_data.resize(100);
    this->setHeaderLabels(QStringList()<<"device"<<"cpu"<<"gpu"<<"disk"<<"memory");


}

void current_data_tree_widget::getDataFromMain(int fd, QString ip, int cpu, int gpu, int dis, int mem, QString time)
{

    this->expandAll();
    int ret=ifIpSaved(ip);
    if(ret>=0)
    {
        //fd do not equal; file described changed
        if(m_data[ret].fd!=fd)
        {
            m_data[ret].fd=fd;
        }
    }
    else
    {
        //do not exsit in m_data   save ip that is new connected
        client_data data;
        data.fd=fd;
        data.ip=ip;
        m_data.push_back(data);
    }
    //traverse m_data
    for(QVector<client_data>::iterator iter=m_data.begin();iter!=m_data.end();++iter)
    {
        if(iter->ip=="")
        {
            continue;
        }
        temp=new QTreeWidgetItem(QStringList()<<iter->ip);
        qDebug()<<"travers m_data  :"<<iter->ip;
        //put the cpu gpu data into temp
        data=new QTreeWidgetItem(QStringList()<<""
                                             <<QString::number(cpu)
                                             <<QString::number(gpu)
                                             <<QString::number(mem)
                                             <<QString::number(dis));
        this->addTopLevelItem(temp);
        temp->addChild(data);

    }
    update();


}

void current_data_tree_widget::closeEvent(QCloseEvent*)
{
    emit tree_Widget_close();
}

int current_data_tree_widget::ifIpSaved(QString ip)
{
    int i=0;
    for(QVector<client_data>::iterator iter=m_data.begin();iter!=m_data.end();++iter)
    {
        if(iter->ip==ip)
        {
            return i;
        }
        else
        {
            ++i;
            continue;
        }
    }
    return -1;
}
#endif
