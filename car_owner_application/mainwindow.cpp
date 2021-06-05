#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qjsondocument.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->carBrand->setPlaceholderText("Enter Brand");
    ui->carModel->setPlaceholderText("Enter Model");
    ui->carYearOfManufacture->setPlaceholderText("Enter Year");
    ui->ownerFirstname->setPlaceholderText("Enter Firstname");
    ui->ownerLastname->setPlaceholderText("Enter Lastname");
    ui->ownerAddress->setPlaceholderText("Enter Address");
    ui->carId->setPlaceholderText("Enter CarID");
    ui->ownerId->setPlaceholderText("Enter OwnerID");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkdatabasebutton_clicked()
{
    QString id;
           id=ui->carId->text();

    QNetworkRequest request(QUrl("https://ownercarapplication.herokuapp.com/car/"+id));
            request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
            //Authenticate
            QString username="admin";
            QString password="1234";
            QString concatenatedCredentials = username + ":" + password;
               QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
               QString headerData = "Basic " + data;
               request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

            QNetworkAccessManager qNetworkAccessManager;
            QNetworkReply *reply = qNetworkAccessManager.get(request);
            while (!reply->isFinished())
            {
                qApp->processEvents();
            }
            QByteArray response_data = reply->readAll();

            QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
            QJsonObject jsonObject = json_doc.object();
            QJsonArray jsonArray = jsonObject["rows"].toArray();

            QString car;
            foreach (const QJsonValue &value, jsonArray) {
              QJsonObject jsob = value.toObject();
              car+=QString::number(jsob["car_id"].toInt())+", "+jsob["brand"].toString()+", "+jsob["model"].toString()+", "+jsob["year_of_manufacture"].toString()+"\r";
              ui->textCars->setText(car);
            }

            reply->deleteLater();
}

void MainWindow::on_additemsbutton_clicked()
{
    QString brand, model, year_of_manufacture;
           brand=ui->carBrand->text();
           model=ui->carModel->text();
           year_of_manufacture=ui->carYearOfManufacture->text();

           QNetworkRequest request(QUrl("https://ownercarapplication.herokuapp.com/car"));
               request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
               //Authenticate
               QString username="admin";
               QString password="1234";
               QString concatenatedCredentials = username + ":" + password;
                  QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
                  QString headerData = "Basic " + data;
                  request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

               QJsonObject json;
               json.insert("brand",brand);
               json.insert("model",model);
               json.insert("year_of_manufacture",year_of_manufacture);
               QNetworkAccessManager qNetworkAccessManager;
               QNetworkReply *reply = qNetworkAccessManager.post(request, QJsonDocument(json).toJson());
               while (!reply->isFinished())
               {
                   qApp->processEvents();
               }
               QByteArray response_data = reply->readAll();
               qDebug()<<response_data;
               ui->label->setText("Added : "+response_data);
               this->on_checkdatabasebutton_clicked();
               reply->deleteLater();
}

void MainWindow::on_deleteitembutton_clicked()
{
    QString id=ui->carId->text();
           QNetworkRequest request(QUrl("https://ownercarapplication.herokuapp.com/car/"+id));
               request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
               //Authenticate
               QString username="admin";
               QString password="1234";
               QString concatenatedCredentials = username + ":" + password;
                  QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
                  QString headerData = "Basic " + data;
                  request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

               QNetworkAccessManager qNetworkAccessManager;
               QNetworkReply *reply = qNetworkAccessManager.deleteResource(request);
               while (!reply->isFinished())
               {
                   qApp->processEvents();
               }
               QByteArray response_data = reply->readAll();
               QJsonDocument json = QJsonDocument::fromJson(response_data);
               ui->label->setText("Deleted car id="+id);
               ui->carId->setText("");
               this->on_checkdatabasebutton_clicked();
               reply->deleteLater();
}

void MainWindow::on_editdatabasebutton_clicked()
{
    QString id, brand, model,year_of_manufacture;
           id=ui->carId->text();
           brand=ui->carBrand->text();
           model=ui->carModel->text();
           year_of_manufacture=ui->carYearOfManufacture->text();

           QNetworkRequest request(QUrl("https://ownercarapplication.herokuapp.com/car/"+id));
               request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
               //Authenticate
               QString username="admin";
               QString password="1234";
               QString concatenatedCredentials = username + ":" + password;
                  QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
                  QString headerData = "Basic " + data;
                  request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

               QJsonObject json;
               json.insert("brand",brand);
               json.insert("model",model);
               json.insert("year_of_manufacture",year_of_manufacture);
               QNetworkAccessManager qNetworkAccessManager;
               QNetworkReply *reply = qNetworkAccessManager.put(request, QJsonDocument(json).toJson());
               while (!reply->isFinished())
               {
                   qApp->processEvents();
               }
               QByteArray response_data = reply->readAll();
               qDebug()<<response_data;
               ui->label->setText("Updated : "+response_data);
               this->on_checkdatabasebutton_clicked();
               reply->deleteLater();
}

void MainWindow::on_checkownerdatabutton_clicked()
{
    QString id;
           id=ui->ownerId->text();

    QNetworkRequest request(QUrl("https://ownercarapplication.herokuapp.com/owner/"+id));
            request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
            //Authenticate
            QString username="admin";
            QString password="1234";
            QString concatenatedCredentials = username + ":" + password;
               QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
               QString headerData = "Basic " + data;
               request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

            QNetworkAccessManager qNetworkAccessManager;
            QNetworkReply *reply = qNetworkAccessManager.get(request);
            while (!reply->isFinished())
            {
                qApp->processEvents();
            }
            QByteArray response_data = reply->readAll();

            QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
            QJsonObject jsonObject = json_doc.object();
            QJsonArray jsonArray = jsonObject["rows"].toArray();

            QString owner;
            foreach (const QJsonValue &value, jsonArray) {
              QJsonObject jsob = value.toObject();
              owner+=QString::number(jsob["owner_id"].toInt())+", "+jsob["firstname"].toString()+", "+jsob["lastname"].toString()+", "+jsob["address"].toString()+"\r";
              ui->textOwners->setText(owner);
            }

            reply->deleteLater();
}


void MainWindow::on_addownerdatabasebutton_clicked()
{
    QString firstname, lastname, address;
           firstname=ui->ownerFirstname->text();
           lastname=ui->ownerLastname->text();
           address=ui->ownerAddress->text();

           QNetworkRequest request(QUrl("https://ownercarapplication.herokuapp.com/owner"));
               request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
               //Authenticate
               QString username="admin";
               QString password="1234";
               QString concatenatedCredentials = username + ":" + password;
                  QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
                  QString headerData = "Basic " + data;
                  request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

               QJsonObject json;
               json.insert("firstname",firstname);
               json.insert("lastname",lastname);
               json.insert("address",address);
               QNetworkAccessManager qNetworkAccessManager;
               QNetworkReply *reply = qNetworkAccessManager.post(request, QJsonDocument(json).toJson());
               while (!reply->isFinished())
               {
                   qApp->processEvents();
               }
               QByteArray response_data = reply->readAll();
               qDebug()<<response_data;
               ui->label->setText("Added : "+response_data);
               this->on_checkownerdatabutton_clicked();
               reply->deleteLater();
}


void MainWindow::on_deleteownerdatabasebutton_clicked()
{
    QString id=ui->ownerId->text();
           QNetworkRequest request(QUrl("https://ownercarapplication.herokuapp.com/owner/"+id));
               request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
               //Authenticate
               QString username="admin";
               QString password="1234";
               QString concatenatedCredentials = username + ":" + password;
                  QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
                  QString headerData = "Basic " + data;
                  request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

               QNetworkAccessManager qNetworkAccessManager;
               QNetworkReply *reply = qNetworkAccessManager.deleteResource(request);
               while (!reply->isFinished())
               {
                   qApp->processEvents();
               }
               QByteArray response_data = reply->readAll();
               QJsonDocument json = QJsonDocument::fromJson(response_data);
               ui->label->setText("Deleted owner id="+id);
               ui->ownerId->setText("");
               this->on_checkownerdatabutton_clicked();
               reply->deleteLater();
}


void MainWindow::on_editownerdatabasebutton_clicked()
{
    QString id, firstname, lastname, address;
           id=ui->ownerId->text();
           firstname=ui->ownerFirstname->text();
           lastname=ui->ownerLastname->text();
           address=ui->ownerAddress->text();

           QNetworkRequest request(QUrl("https://ownercarapplication.herokuapp.com/owner/"+id));
               request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
               //Authenticate
               QString username="admin";
               QString password="1234";
               QString concatenatedCredentials = username + ":" + password;
                  QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
                  QString headerData = "Basic " + data;
                  request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

               QJsonObject json;
               json.insert("firstname",firstname);
               json.insert("lastname",lastname);
               json.insert("address",address);
               QNetworkAccessManager qNetworkAccessManager;
               QNetworkReply *reply = qNetworkAccessManager.put(request, QJsonDocument(json).toJson());
               while (!reply->isFinished())
               {
                   qApp->processEvents();
               }
               QByteArray response_data = reply->readAll();
               qDebug()<<response_data;
               ui->label->setText("Updated : "+response_data);
               this->on_checkownerdatabutton_clicked();
               reply->deleteLater();
}

void MainWindow::on_checkcarsownerships_clicked()
{
    QString id;
           id=ui->ownerId->text();

    QNetworkRequest request(QUrl("https://ownercarapplication.herokuapp.com/car_owner/"+id));
            request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
            //Authenticate
            QString username="admin";
            QString password="1234";
            QString concatenatedCredentials = username + ":" + password;
               QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
               QString headerData = "Basic " + data;
               request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

            QNetworkAccessManager qNetworkAccessManager;
            QNetworkReply *reply = qNetworkAccessManager.get(request);
            while (!reply->isFinished())
            {
                qApp->processEvents();
            }
            QByteArray response_data = reply->readAll();

            QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
            QJsonObject jsonObject = json_doc.object();
            QJsonArray jsonArray = jsonObject["rows"].toArray();

            QString car_owner;
            foreach (const QJsonValue &value, jsonArray) {
              QJsonObject jsob = value.toObject();
              car_owner+=QString::number(jsob["car_id"].toInt())+", "+jsob["brand"].toString()+", "+jsob["model"].toString()+", "+jsob["year_of_manufacture"].toString()+"\r is owned by "+
                      QString::number(jsob["owner_id"].toInt())+", "+jsob["firstname"].toString()+", "+jsob["lastname"].toString()+", "+jsob["address"].toString()+"\r";
              ui->textCarOwners->setText(car_owner);
            }

            reply->deleteLater();
}


void MainWindow::on_addownershipsbutton_clicked()
{
    QString car_id, owner_id;
           car_id=ui->carId->text();
           owner_id=ui->ownerId->text();

           QNetworkRequest request(QUrl("https://ownercarapplication.herokuapp.com/car_owner"));
               request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
               //Authenticate
               QString username="admin";
               QString password="1234";
               QString concatenatedCredentials = username + ":" + password;
                  QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
                  QString headerData = "Basic " + data;
                  request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

               QJsonObject json;
               json.insert("car_id",car_id);
               json.insert("owner_id",owner_id);
               QNetworkAccessManager qNetworkAccessManager;
               QNetworkReply *reply = qNetworkAccessManager.post(request, QJsonDocument(json).toJson());
               while (!reply->isFinished())
               {
                   qApp->processEvents();
               }
               QByteArray response_data = reply->readAll();
               qDebug()<<response_data;
               ui->label->setText("Added : "+response_data);
               this->on_checkownerdatabutton_clicked();
               reply->deleteLater();
}


void MainWindow::on_deleteownershipsbutton_clicked()
{
    QString id=ui->carId->text();
            id=ui->ownerId->text();

           QNetworkRequest request(QUrl("https://ownercarapplication.herokuapp.com/car_owner/"+id));
               request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
               //Authenticate
               QString username="admin";
               QString password="1234";
               QString concatenatedCredentials = username + ":" + password;
                  QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
                  QString headerData = "Basic " + data;
                  request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

               QNetworkAccessManager qNetworkAccessManager;
               QNetworkReply *reply = qNetworkAccessManager.deleteResource(request);
               while (!reply->isFinished())
               {
                   qApp->processEvents();
               }
               QByteArray response_data = reply->readAll();
               QJsonDocument json = QJsonDocument::fromJson(response_data);
               ui->label->setText("Deleted car id="+id);
               ui->carId->setText("");
               this->on_checkownerdatabutton_clicked();
               reply->deleteLater();
}


void MainWindow::on_editownershipsbutton_clicked()
{
    QString car_id, owner_id;
           car_id=ui->carId->text();
           owner_id=ui->ownerId->text();

           QNetworkRequest request(QUrl("https://ownercarapplication.herokuapp.com/car_owner/"+car_id));
               request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
               //Authenticate
               QString username="admin";
               QString password="1234";
               QString concatenatedCredentials = username + ":" + password;
                  QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
                  QString headerData = "Basic " + data;
                  request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

               QJsonObject json;
               json.insert("car_id",car_id);
               json.insert("owner_id",owner_id);
               QNetworkAccessManager qNetworkAccessManager;
               QNetworkReply *reply = qNetworkAccessManager.put(request, QJsonDocument(json).toJson());
               while (!reply->isFinished())
               {
                   qApp->processEvents();
               }
               QByteArray response_data = reply->readAll();
               qDebug()<<response_data;
               ui->label->setText("Updated : "+response_data);
               this->on_checkownerdatabutton_clicked();
               reply->deleteLater();
}
