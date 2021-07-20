#include "mybutton.h"

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{
    this->resize(50,50);
//    this->setStyleSheet("color:green");
    this->setStyleSheet("QPushButton{background-color:green}");
}
