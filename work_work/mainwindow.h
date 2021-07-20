#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "thread_sever.h"
#include <QList>
#include "mybutton.h"


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

private:
    void getButton(QString str);



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
