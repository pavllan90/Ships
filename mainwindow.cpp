#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cassert>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(add()));
    QObject::connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(show_list(int)));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(search()));
    QObject::connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(save()));
    QObject::connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(load()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(isEmpty()));
    QObject::connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(size()));
    QObject::connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(showOne(QTreeWidgetItem*)));
    //item = new QTreeWidgetItem(0);
    timer = new QTimer;
    timer->start(200);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(check()));
    dial = NULL;
}

void MainWindow::add()
{
    if(!ui->checkBox->isChecked())
        tree.insertByKey(new Blank(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(), ui->lineEdit_4->text().toFloat(), ui->lineEdit_6->text(), ui->lineEdit_10->text().toFloat()));
    else
        tree.insertByKey(new CruiseBlank(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(), ui->lineEdit_4->text().toFloat(), ui->lineEdit_6->text(), ui->lineEdit_10->text().toFloat(), ui->lineEdit_7->text().toInt(),ui->lineEdit_11->text()));
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
}

void MainWindow::check()
{
    if(!ui->checkBox->isChecked()) ui->lineEdit_7->setVisible(false), ui->label_5->setVisible(false), ui->lineEdit_11->setVisible(false), ui->label_8->setVisible(false);
    else ui->lineEdit_7->setVisible(true), ui->label_5->setVisible(true), ui->lineEdit_11->setVisible(true), ui->label_8->setVisible(true);

}

void MainWindow::del()
{
    //tree.deleteByKey(ui->lineEdit_9->text());
    std::cout<<"====+++===="<<std::endl;
}

void MainWindow::show_list(int a)
{
    if(!tree.isEmpty()&&a==1){
    ui->treeWidget->clear();

    QTreeWidgetItem *item = new QTreeWidgetItem(0);
    item->setText(0, tree.root->data->getName());
    ui->treeWidget->addTopLevelItem(item);
    recursiveShow(tree.root, item);
    }
}

void MainWindow::recursiveShow(Node *_root, QTreeWidgetItem *_parent)
{
    if(!_root->is_Leaf)
    {
         if(!_root->left->is_Leaf)
         {
             QTreeWidgetItem* left = new QTreeWidgetItem(0);
             left->setText(0, _root->left->data->getName());
             //QObject::connect(*left, SIGNAL(clicked()),this, SLOT(del()));
             _parent->addChild(left);
            recursiveShow(_root->left, left);
         }
         if(!_root->right->is_Leaf)
         {
             QTreeWidgetItem* right = new QTreeWidgetItem(0);
             right->setText(0, _root->right->data->getName());
              _parent->addChild(right);
            recursiveShow(_root->right, right);
         }
    }
}

void MainWindow::showOne(QTreeWidgetItem *_item)
{
    dial = new Dialog(_item->text(0), &tree);
    dial->show();//;}
}

void MainWindow::save()
{
    tree.writeToFile(ui->lineEdit_8->text());
}

void MainWindow::load()
{
    tree.readFromFile(ui->lineEdit_8->text());
}

void MainWindow::isEmpty()
{
    if(tree.isEmpty()) ui->lineEdit_9->setText("Empty");
    else ui->lineEdit_9->setText("Not empty");
}

void MainWindow::size()
{
    ui->lineEdit_9->setText("Size is "+QString::number(tree.size()));
}

void MainWindow::search()
{
    QString s_name = ui->lineEdit_5->text();
    if(tree.find(s_name)) dial = new Dialog(s_name, &tree);
    dial->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

