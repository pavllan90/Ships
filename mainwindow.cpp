#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cassert>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(add()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(show_list()));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(search()));
    QObject::connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(save()));
    QObject::connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(load()));
    QObject::connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(del()));
}

void MainWindow::add()
{
    if(ui->lineEdit_7->text()!="") tree.insertByKey(ui->lineEdit_7->text().toInt(), Blank(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(), ui->lineEdit_4->text().toFloat(), ui->lineEdit_6->text(), ui->lineEdit_10->text().toFloat()));
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
}

void MainWindow::del()
{
    tree.deleteByKey(ui->lineEdit_9->text().toInt());
    std::cout<<"====+++===="<<std::endl;
}

void MainWindow::show_list()
{
    tree.show();
}

void MainWindow::save()
{
    tree.writeToFile(ui->lineEdit_8->text());
}

void MainWindow::load()
{
    tree.readFromFile(ui->lineEdit_8->text());
}

void MainWindow::search()
{
    QString s_name = ui->lineEdit_5->text();
    RBTree res = tree.find(s_name);
    res.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

