#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bookID=0;
    bshelfID=0;
    shelfID=0;
    ui->groupBox_book->setEnabled(false);
    ui->groupBox_shelf->setEnabled(false);
    ui->pushButton_dell_Bshelf->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_add_Bshelf_clicked()
{
    Book_shelf bs;
    Book_shelfs.push_back(bs);
    ui->listWidget_Bshelf->addItem(QString::number(Book_shelfs.size()));
}

void MainWindow::on_listWidget_Bshelf_itemClicked(QListWidgetItem *item)
{
    bshelfID = item->text().toInt();
    ui->pushButton_dell_Bshelf->setEnabled(true);
    ui->groupBox_shelf->setEnabled(true);
    ui->pushButton_dell_shelf->setEnabled(false);
    int shelfN=Book_shelfs[bshelfID-1].getShelfsNumber();
    ui->listWidget_shelf->clear();
    ui->listWidget_book->clear();
    if (shelfN >0){
        for(int i=1;i<=shelfN;i++){
            ui->listWidget_shelf->addItem(QString::number(i));
        }
    }

}

void MainWindow::on_pushButton_add_shelf_clicked()
{
    Book_shelfs[bshelfID-1].addshelf();
    int ShelfN= Book_shelfs[bshelfID-1].getShelfsNumber();
    ui->listWidget_shelf->addItem(QString::number(ShelfN));
}
