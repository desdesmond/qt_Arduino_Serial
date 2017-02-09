#ifndef SERIALCOM_H
#define SERIALCOM_H
#include <QSerialPortInfo>
#include <QtSerialPort>
#include <QObject>

class serialCom : public QObject
{
    Q_OBJECT

public:
    explicit serialCom(QObject *parent = 0);


public slots:
    void sendMessageToArduino();
    void helloFromTheOtherSide();

signals:

private:
    QSerialPort *arduino;
    //    static const quint16 arduino_duo_product_id = 62;
    //    static const quint16 arduino_duo_vendor_id = 9025;
    static const quint16 arduino_duo_product_id = 32822;
    static const quint16 arduino_duo_vendor_id = 9025;
    QString arduino_port_name;
    bool arduino_is_availble;

};
#endif // SERIALCOM_H

