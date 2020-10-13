#include <QProperty>
#include <QColor>
#include <QString>
#include <QDebug>

/** This example tests a binding loop.
  * Expected output:
  *   Warning: Binding loop detected.
  */
int main()
{
    struct {
        QProperty<int> x { [&]{ return y + 1; } };
        QProperty<int> y { [&]{ return x + 1; } };
    } shape;

    qDebug() << shape.x << shape.y;

    return 0;
}
