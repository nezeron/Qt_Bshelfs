#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Book_shelf.h>
#include <PrintBook.h>
#include <shelf.h>
#include <vector>
#include <QListWidgetItem>

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
    void on_pushButton_add_Bshelf_clicked();

    void on_listWidget_Bshelf_itemClicked(QListWidgetItem *item);

    void on_pushButton_add_shelf_clicked();

private:
    Ui::MainWindow *ui;
    vector<Book_shelf> Book_shelfs;
    int bshelfID;
    int shelfID;
    int bookID;

};
#endif // MAINWINDOW_H
