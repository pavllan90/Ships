#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    count = 0;
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(add()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(show_list()));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(search()));
}

void MainWindow::add()
{
    mass[count] = new Blank(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(), ui->lineEdit_4->text(), ui->lineEdit_6->text());
    count+=1;
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_6->clear();
}

void MainWindow::show_list()
{
    for(int i = 0; i<count; i++)
    {
        ui->textEdit->append("Blank #"+QString::number(i)+"\nOwners name: "+mass[i]->owner.name+"\nOwners surname: "+mass[i]->owner.surname+"\nShips name: "+mass[i]->name+"\nTonnage: "+QString::number(mass[i]->tonnage)+"\nHome port: "+mass[i]->home);
    }
}

void MainWindow::search()
{
    QString s_name = ui->lineEdit_5->text();
    ui->textEdit->append(s_name);
    bool f = false;
    for(int i = 0; i<count; i++)
        if(QString::compare(mass[i]->name, s_name)==0)
            f = true, ui->textEdit->append("Found:\nOwners name: "+mass[i]->owner.name+"\nOwners surname: "+mass[i]->owner.surname+"\nShips name: "+mass[i]->name+"\nTonnage: "+QString::number(mass[i]->tonnage)+"\nHome port: "+mass[i]->home);
    if(!f) ui->textEdit->append("No ships with such name\n");
    ui->lineEdit_5->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}



