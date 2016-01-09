#ifndef SUMUI_H
#define SUMUI_H

#include <QObject>

class SumUi : public QObject
{
    Q_OBJECT
public:
    explicit SumUi(QObject *parent = 0);

    Q_INVOKABLE QString sum(const QString& number1, const QString& number2);

public slots:
};

#endif // SUMUI_H
