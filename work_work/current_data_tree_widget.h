#if 0

#ifndef CURRENT_DATA_TREE_WIDGET_H
#define CURRENT_DATA_TREE_WIDGET_H

#include <QWidget>
#include <QVector>
#include <QTreeWidget>
#include <QList>

/*
thread emit data , this class get data.
This class maintain an array that holds(save) the file describe in the data that obtained(get) from main thread;
every time the new data come,if the file des from the new data is in the array ,update the data
if not in the array, put the fd into the array,update the data



*/
//struct client_data
//{
//    int fd;
//    QString ip;
////    bool operator ==(const client_data &a);
//};
//bool client_data::operator ==(const client_data &a)
//{
//    return ip==a.ip;
//}



class current_data_tree_widget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit current_data_tree_widget(QWidget *parent = nullptr);

    QVector<client_data>m_data;
//    QList<QTreeWidgetItem*>m_item;

signals:
    void tree_Widget_close();
public slots:
    void getDataFromMain(int fd,QString ip,int cpu,int gpu,int dis,int mem,QString time);
protected:
    void closeEvent(QCloseEvent*);
private:
    int ifIpSaved(QString ip); //return the pos
    QTreeWidgetItem *temp;
    QTreeWidgetItem *data;

};

#endif // CURRENT_DATA_TREE_WIDGET_H

#endif
