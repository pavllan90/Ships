#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(ins()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(show_it()));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(del()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ins()
{
    Blank a;
    tree.insert(i);
}

void MainWindow::show_it()
{
    sh(tree.root, 0);
    ui->textEdit->append("---------------------");
}

void MainWindow::del()
{
    tree.deleteOne(tree.find(tree.root, ui->lineEdit->text().toInt()));
}

void MainWindow::sh(Node *root, int i)
{
    if(!root->is_Leaf)
    {
        if(root->left)sh(root->left, i+1);
        for(int j = 0; j<i; j++) h=h+"             ";
        if(root->parent)ui->textEdit->append(h+"Data: "+QString::number(root->data)+"  Color  "+ QString::number(root->red)+" Parent: "+QString::number(root->parent->data)+"\n");
        else ui->textEdit->append(h+"Data: "+QString::number(root->data)+"  Color  "+ QString::number(root->red)+" RoOt"+"\n");
        if(root->right)sh(root->right, i+1);
    }
}
