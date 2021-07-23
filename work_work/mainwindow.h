#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "thread_sever.h"
#include <QList>
#include "mybutton.h"
#include "current_data_tree_widget.h"
#include <QMenu>
#include <QMenuBar>
#include "current_data_tree_view.h"
#define MAINWIDTH 1200
#define MAINHEIGTH 800


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    thread_sever *m_thread_server;

    QList<MyButton *>m_button_list;
    current_data_tree_view  m_treeWidget;

private:
    void initMain();
    void getButton(QString str,int fd);
    void client_Disconnected(int fd);
public slots:
    void getDataFromSub(int fd,QString ip,int cpu,int gpu,int dis,int mem,QString time);
    void showCurrentData();

signals:
    void SendDataToMember(int fd,QString ip,int cpu,int gpu,int dis,int mem,QString time);



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
