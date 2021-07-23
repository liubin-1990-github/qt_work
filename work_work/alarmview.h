#ifndef ALARMVIEW_H
#define ALARMVIEW_H

#include <QWidget>
#include <QTreeView>

class alarmView : public QTreeView
{
    Q_OBJECT
public:
    explicit alarmView(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // ALARMVIEW_H
