#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::Dialog(QString _name, RBTree *_tree, bool *_changed) : QDialog(0),
    ui(new Ui::Dialog), name(_name), tree(_tree), changed(_changed)
{
    ui->setupUi(this);
    if(tree->find(_name)->getType()==0)
        data = new Blank;
    else
        data = new CruiseBlank;
    *data = *tree->find(_name);
    ui->label->setText("Ship '"+data->getName()+"'");
    if(data->getType()==0)
    ui->tableWidget->setRowCount(6), this->setFixedSize(310,307);
    else ui->tableWidget->setRowCount(8), this->setFixedSize(310,375);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setColumnWidth(0, 150);
    ui->tableWidget->setVerticalHeaderItem(0,new QTableWidgetItem("Owners name: "));
    ui->tableWidget->setVerticalHeaderItem(1,new QTableWidgetItem("Owners surname: "));
    ui->tableWidget->setVerticalHeaderItem(2,new QTableWidgetItem("Ships name: "));
    ui->tableWidget->setVerticalHeaderItem(3,new QTableWidgetItem("Tonnage: "));
    ui->tableWidget->setVerticalHeaderItem(4,new QTableWidgetItem("Home port: "));
    ui->tableWidget->setVerticalHeaderItem(5,new QTableWidgetItem("Lineage: "));
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Data: "));
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(data->getOwner().name));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(data->getOwner().surname));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem(data->getName()));
    ui->tableWidget->setItem(0, 3, new QTableWidgetItem(QString::number(data->getTonnage())));
    ui->tableWidget->setItem(0, 4, new QTableWidgetItem(data->getHome()));
    ui->tableWidget->setItem(0, 5, new QTableWidgetItem(QString::number(data->getLineage())));
    if(data->getType() == 1)
    {
        ui->tableWidget->setVerticalHeaderItem(6,new QTableWidgetItem("Passengers: "));
        ui->tableWidget->setVerticalHeaderItem(7,new QTableWidgetItem("Destination: "));
        ui->tableWidget->setItem(0, 6, new QTableWidgetItem(QString::number(dynamic_cast<CruiseBlank*>(data)->getPassengersAmount())));
        ui->tableWidget->setItem(0, 7, new QTableWidgetItem(dynamic_cast<CruiseBlank*>(data)->getFinalDestination()));
    }
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(save()));
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(del()));
}

void Dialog::del()
{
    tree->deleteByKey(data->getName());
    *changed = true;
    this->close();
}

void Dialog::save()
{
    FI a;
    QTableWidgetItem *temp = ui->tableWidget->takeItem(0,0);
    tree->deleteByKey(data->getName());
    a.name = temp->text();
    temp = ui->tableWidget->takeItem(1,0);
    a.surname = temp->text();
    data->setOwner(a);
    temp = ui->tableWidget->takeItem(2,0);
    data->setName(temp->text());
    temp = ui->tableWidget->takeItem(3,0);
    data->setTonnage(temp->text().toFloat());
    temp = ui->tableWidget->takeItem(4,0);
    data->setHome(temp->text());
    temp = ui->tableWidget->takeItem(5,0);
    data->setLineage(temp->text().toFloat());
    if(data->getType()==1){
        temp = ui->tableWidget->takeItem(6,0);
        dynamic_cast<CruiseBlank*>(data)->setPassengersAmount(temp->text().toInt());
        temp = ui->tableWidget->takeItem(7,0);
        dynamic_cast<CruiseBlank*>(data)->setFinalDestination(temp->text());
    }
    tree->insertByKey(data);
    *changed = true;
    this->close();
}

Dialog::~Dialog()
{
    delete ui;
}
