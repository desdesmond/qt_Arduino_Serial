#include "serialcom.h"
#include <QSerialPortInfo>
#include <QtSerialPort>
#include <QDebug>

serialCom::serialCom(QObject *parent) : QObject(parent)
{   
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == arduino_duo_vendor_id){
                if(serialPortInfo.productIdentifier() == arduino_duo_product_id){
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_availble = true;
                    qDebug() << "Arduino is connected!";
                }
            }
        }
    }
}

void serialCom::sendMessageToArduino()
{
    if(arduino_is_availble){
        //opens Arduino Port when it is available

        arduino -> setPortName(arduino_port_name);
        arduino -> open(QSerialPort::WriteOnly);
        arduino -> setBaudRate(QSerialPort::Baud9600);
        arduino -> setDataBits(QSerialPort::Data8);
        arduino -> setParity(QSerialPort::NoParity);
        arduino -> setStopBits(QSerialPort::OneStop);
        arduino -> setFlowControl(QSerialPort::NoFlowControl);
        arduino -> write("p");

    } else {
        qDebug() << "No Arduino detected!";
        if(arduino -> isOpen()){
            arduino-> close();
        }
    }
}

void serialCom::helloFromTheOtherSide() //debug
{
    qDebug() << "Hello? Is it me you are looking for?";
}



