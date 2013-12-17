﻿#ifndef QTCPCLIENTTEST_H
#define QTCPCLIENTTEST_H

#include <QMainWindow>
#include "qghtcpclient.h"
#include "ui_qtcpclienttest.h"
#include <QMap>
#include <QDateTime>
#include <QStandardItemModel>
#include <QStandardItem>
class QTcpClientTest : public QMainWindow
{
    Q_OBJECT

public:
    QTcpClientTest(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~QTcpClientTest();
    virtual void timerEvent(QTimerEvent * evt);
private:
    Ui::QTcpClientTestClass ui;
    QMap<QGHTcpClient *, QDateTime> m_clients;
    int nTimer;
    QStandardItemModel model;
public slots:
    void on_horizontalSlider_valueChanged(int);
    void on_action_Connect_triggered(bool);
    void new_data_recieved();
    void on_client_trasferred(qint64);
    void on_client_connected();
    void on_client_disconnected();
    void displayError(QAbstractSocket::SocketError);
    void displayMessage(const QString &str);
};

#endif // QTCPCLIENTTEST_H
