#include <sumui.h>
//include <sum.h>

SumUi::SumUi(QObject *parent) : QObject(parent)
{
}

QString SumUi::sum(const QString &number1, const QString &number2) {
  int a = number1.toInt();
  int b = number2.toInt();
  //int sum = Sum::sum(a, b);
  int sum = a + b;
  return QString::number(sum);
}
