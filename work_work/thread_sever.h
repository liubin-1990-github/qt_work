#ifndef THREAD_SEVER_H
#define THREAD_SEVER_H

#include <QWidget>
#include <QThread>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <arpa/inet.h>
#include "mybutton.h"
#include <QList>
#include <QPushButton>
#include <QString>
class thread_sever : public QThread
{
    Q_OBJECT
public:
    explicit thread_sever(QWidget *parent = nullptr);

signals:
    void ButtonChanged(QString str);

public slots:
protected:
    void run();
public:

//    QList<MyButton*>m_button_list;

private:
    void addButtonToList(struct sockaddr_in* addr);

};

#endif // THREAD_SEVER_H
