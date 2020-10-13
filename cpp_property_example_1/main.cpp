#include <QProperty>
#include <QColor>
#include <QString>
#include <QDebug>

/** This example shows the basic usage of QProperty.
  * Expected output:
  *   "red"
  *   changed to "orange"
  *   "orange"
  *   changed to "red"
  *   "red"
  */
int main()
{
    QProperty<bool> critical { true };
    QProperty<QString> color { [&]{ return critical ? "red" : "orange" ; } }; // try: [=]

    color.onValueChanged([&]{ // try: [=]
        qDebug() << "changed to" << color;
    });

    qDebug() << color;
    critical = false;
    qDebug() << color;
    critical = true;
    qDebug() << color;

    return 0;
}
