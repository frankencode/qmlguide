#include <QProperty>
#include <QColor>
#include <QString>
#include <QDebug>

/** This example shows the basic usage of QProperty.
  * Expected output:
  *   no subscribers, no reads
  *   evaluate
  *   "red"
  */
int main()
{
    QProperty<bool> critical { true };
    QProperty<QString> color {[&]{
        qDebug() << "evaluate";
        return critical ? "red" : "orange" ;
    }};

    qDebug() << "no subscribers, no reads";

    qDebug() << color;

    return 0;
}
