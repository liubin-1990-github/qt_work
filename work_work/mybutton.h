#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT
public:

    int m_fd=0;
    explicit MyButton(QWidget *parent = nullptr);

signals:

public slots:
protected:

};

#endif // MYBUTTON_H
