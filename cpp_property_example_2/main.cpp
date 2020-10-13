#include <QProperty>
#include <QColor>
#include <QString>
#include <QDebug>

/** This example shows how to highlevel data types with QSharedData and QProperty.
  * Expected output:
  *   "orange"
  *   "red"
  */
int main()
{
    struct Error {
        bool critical() const { return me->critical; }
        void setCritical(bool on) { me->critical = on; }

        QString color() const { return me->color; }

    private:
        struct State: public QSharedData {
            QProperty<bool> critical { false };
            QProperty<QString> color { [=]{ return critical ? "red" : "orange"; } };
        };
        QExplicitlySharedDataPointer<State> me { new State };
    };

    Error error;
    qDebug() << error.color();
    error.setCritical(true);
    qDebug() << error.color();

    return 0;
}
