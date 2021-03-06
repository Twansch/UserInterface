#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include "Communication.h"
#include "string.h"

Communication communication;
std::vector<Garment> Garments;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

MainWindow::~MainWindow()
{
    communication.Close();
    delete ui;
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
*/
void MainWindow::on_listWidgetGarments_clicked(const QModelIndex &index)
{
    //QListWidgetItem *object = ui->listWidgetGarments->currentItem();



    QString objectName = ui->listWidgetGarments->currentItem()->text();
    int id = objectName.toInt();
    Garment garment = findObject(id);

    std::string strInfo = "Garment ID = " + garment.GetId();
            //"\nWeight = " + garment.GetWeight() + "\n Material = " + garment.GetMaterial() + "\n Color = " + garment.GetColor() + "\n Dryer = " + garment.GetDryer() + "\n Steamer = " + garment.GetSteamer() + "\n Centrifuge = " + garment.GetCentrifuge();
    QString info = QString::fromStdString(strInfo);

    ui->lblAdminInfo->setText(info);
    //label.text = object.name;
    //label.text = object.Owner;
    //label.text = object.WashingProgram;
}

void MainWindow::on_btCallEmployee_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Chris is onderweg");
    msgBox.exec();
}

void MainWindow::addGarmentToListWidget(QString garmentId)
{
    ui->listWidgetGarments->addItem(garmentId);
}

void MainWindow::on_btAddGarmentTest_clicked()
{
    Garment *garment = new Garment(888, 88, "Cotton", "Black");

    QString garmentId = QString::number(garment->GetId());
    ui->listWidgetGarments->addItem(garmentId);
    Garments.push_back(*garment);



    //Garment garment = Garment(401, 40, "Wool", "Fuchsia");
    //listViewGarments.add(garment);
}

Garment MainWindow::findObject(int idName)
{
    Garment garment = Garment(0, 0, "", "");
    std::vector<Garment>::iterator it;
    int i = 0;
       for(it=Garments.begin(); it < Garments.end(); it++, i++)
       {
            if((*it).GetId() == idName)
            {
                return *it;
            }
       }
       return garment;
}
