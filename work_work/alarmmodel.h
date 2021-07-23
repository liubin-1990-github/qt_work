#ifndef ALARMMODEL_H
#define ALARMMODEL_H

#include <QWidget>
#include <QStandardItemModel>

class alarmModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit alarmModel(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // ALARMMODEL_H
