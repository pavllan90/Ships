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
}

void MainWindow::add()
{
    mass[count] = Blank(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(), ui->lineEdit_4->text(), ui->lineEdit_6->text());
    count+=1;
}

void MainWindow::show_list()
{
    for(int i = 0; i<count; i++)
    {
        ui->textEdit->append("Blank #"+QString::number(i)+"\nOwners name: "+mass[i].owner.name+"\nOwners surname: "+mass[i].owner.surname+"\nShips name: "+mass[i].name+"\nTonnage: "+QString::number(mass[i].tonnage)+"\nHome port: "+mass[i].home);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}



