#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_checkdatabasebutton_clicked();

    void on_additemsbutton_clicked();

    void on_deleteitembutton_clicked();

    void on_editdatabasebutton_clicked();

    void on_checkownerdatabutton_clicked();

    void on_addownerdatabasebutton_clicked();

    void on_deleteownerdatabasebutton_clicked();

    void on_editownerdatabasebutton_clicked();

    void on_checkcarsownerships_clicked();

    void on_addownershipsbutton_clicked();

    void on_deleteownershipsbutton_clicked();

    void on_editownershipsbutton_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
