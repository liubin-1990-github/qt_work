#include "current_data_tree_view.h"
#include <QModelIndex>
#include <QDebug>

current_data_tree_view::current_data_tree_view(QWidget *parent) : QTreeView(parent)
{



    m_model=new QStandardItemModel(this);
    m_model->setHorizontalHeaderLabels(QStringList()<<"device"<<"time"<<"cpu"<<"gpu"<<"disk"<<"memory");
    this->setModel(m_model);
    this->setFixedSize(1000,500);
    this->setEditTriggers(QTreeView::NoEditTriggers); //can not eidt
    this->setAlternatingRowColors(true); //if qss  invalid

//    m_model->appendRow(m_data_items);
//    m_model->appendColumn(m_data_items);


}


void current_data_tree_view::closeEvent(QCloseEvent*)
{
    emit tree_Widget_close();
}

void current_data_tree_view::getDataFromMain(int fd,QString ip,int cpu,int gpu,int dis,int mem,QString time)
{
    qDebug()<<ip<<time;

    int ret= ifIpSaved(ip);
    qDebug()<<"ret :"<<ret;
    QModelIndex temp_index=m_model->index(ret,0);
    if(ret>=0)
    {
        temp_index=m_model->index(ret,1);
        m_model->setData(temp_index,QVariant::fromValue(time));
        temp_index=m_model->index(ret,2);
        m_model->setData(temp_index,QVariant::fromValue(cpu));
        temp_index=m_model->index(ret,3);
        m_model->setData(temp_index,QVariant::fromValue(gpu));
        temp_index=m_model->index(ret,4);
        m_model->setData(temp_index,QVariant::fromValue(dis));
        temp_index=m_model->index(ret,5);
        m_model->setData(temp_index,QVariant::fromValue(mem));
    }
    else
    {
        qDebug()<<"ret=-1 zhuijia";
        QStandardItem* item1=new QStandardItem(ip);
        QStandardItem* item2=new QStandardItem(time);
        QStandardItem* item3=new QStandardItem(QString::number(cpu));
        QStandardItem* item4=new QStandardItem(QString::number(gpu));
        QStandardItem* item5=new QStandardItem(QString::number(dis));
        QStandardItem* item6=new QStandardItem(QString::number(mem));
        m_data_items.append(item1);
        m_data_items.append(item2);
        m_data_items.append(item3);
        m_data_items.append(item4);
        m_data_items.append(item5);
        m_data_items.append(item6);
        m_model->appendRow(m_data_items);
        m_data_items.clear();
        m_Row++;
        qDebug()<<"ret=-1 zhuijiawanbi";
    }
    update();
}

int current_data_tree_view::ifIpSaved(QString ip)
{
//    int i=0;
    for(int j=0;j<m_Row;j++)
    {
        QModelIndex index=m_model->index(j,0);
        QVariant data=m_model->data(index);
        QString str=data.toString();
        qDebug()<<"data.tostring   "<<str;
        if(ip!=str)
        {
            continue;
        }
        return j;
    }

    return -1;
}
