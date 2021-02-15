#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags( (windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowMaximizeButtonHint);
    this->setFixedSize(360,133);
}

void MainWindow::LoadConfig(char *argv[]){
    this->config = new Config( QString( argv[0] ) );
    this->config->Load();
    this->ui->cbUpper->setChecked( this->config->bUpperCase );
    this->ui->cbLower->setChecked( this->config->bLowerCase );
    this->ui->cbNumbers->setChecked( this->config->bNumbers );
    this->ui->cbSpecChars->setChecked( this->config->bSpecChars  );
    this->ui->sbLength->setValue( this->config->iPasswordLength );
}

MainWindow::~MainWindow()
{
    this->config->bUpperCase = this->ui->cbUpper->checkState();
    this->config->bLowerCase = this->ui->cbLower->checkState();
    this->config->bNumbers = this->ui->cbNumbers->checkState();
    this->config->bSpecChars = this->ui->cbSpecChars->checkState();
    this->config->iPasswordLength = this->ui->sbLength->value();

    if(!this->config->CreateXMLFile()){
        QMessageBox::critical(0, "Error", "Failed to save XML file! [" + this->config->GetXmlFile() + "]");
    }
    delete ui;
}

void MainWindow::GeneratePassword(){
    this->ui->tbPassword->setText(
        PasswordGenerator(
            this->ui->cbUpper->checkState(),
            this->ui->cbLower->checkState(),
            this->ui->cbNumbers->checkState(),
            this->ui->cbSpecChars->checkState(),
            this->ui->sbLength->value()
            ).GeneratePassword()
        );
}
