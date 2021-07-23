#ifndef CURRENT_DATA_TREE_VIEW_H
#define CURRENT_DATA_TREE_VIEW_H

#include <QWidget>
#include <QTreeView>
#include <QStandardItemModel>
#include <QList>

struct client_data
{
    int fd;
    QString ip;
//    bool operator ==(const client_data &a);
};

class current_data_tree_view : public QTreeView
{
    Q_OBJECT
public:
    explicit current_data_tree_view(QWidget *parent = nullptr);
private:
    QStandardItemModel* m_model;


    QList<QStandardItem*>m_data_items; //

    int m_Row=0;



signals:
    void tree_Widget_close();
public slots:
    void getDataFromMain(int fd,QString ip,int cpu,int gpu,int dis,int mem,QString time);
protected:
    void closeEvent(QCloseEvent*);
private:
    int ifIpSaved(QString ip); //return the pos


};

#endif // CURRENT_DATA_TREE_VIEW_H
