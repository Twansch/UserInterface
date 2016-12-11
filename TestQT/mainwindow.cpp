#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include "Communication.h"
#include "string.h"

Communication communication;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Chris is onderweg");
    msgBox.exec();
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Thank you for choosing Swash");
    msgBox.exec();
}

void MainWindow::on_tabUI_tabBarClicked(int index)
{
    int nummertje = index;
    nummertje += 1;
    //bool ok;
    //QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"), tr("User name: "), QLineEdit::Normal, QDir::home()dirName(), &ok);
   //if(ok && !text.isEmpty())
    //{textLabel->setText(text);}
}

void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox msgBox;


    if(communication.Connect())
    {
        msgBox.setText("Connected.");
        msgBox.exec();
    }
    else
    {
        msgBox.setText("Connection failed.");
        msgBox.exec();
    }

}

void MainWindow::on_pushButton_6_clicked()
{
    QMessageBox msgBox;

    if(communication.Write())
    {
        msgBox.setText("Message is sent.");
        msgBox.exec();
    }
    else
    {
        msgBox.setText("Message was not sent.");
        msgBox.exec();
    }



}

void MainWindow::on_pushButton_7_clicked()
{
    communication.Read();
}

void MainWindow::on_btStopSelectedMachine_clicked()
{
    /*std::string selectedMachineName = "";
    selectedMachineName = listViewMachines.selected;
    communication.Write("Stop " + selectedMachineName);*/

}

/*void MainWindow::on_btAlarmStop_clicked()
{
    Communication.send("Stop Everything!");

}

void MainWindow::on_listViewGarments_clicked(const QModelIndex &index)
{
    object = index.selected;
    label.text = object.name;
    label.text = object.Owner;
    label.text = object.WashingProgram;
}*/
