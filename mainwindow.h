#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "passwordgenerator.h"
#include "config.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void LoadConfig(char *argv[]);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    Config *config;

private slots:
    void GeneratePassword();
};

#endif // MAINWINDOW_H
