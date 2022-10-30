#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextEdit>
#include <qtestsupport_core.h>





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
     ui->textEdit->paste();
}


void MainWindow::on_actionUndo_triggered()
{
     ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionNew_triggered()
{
 file =" ";
 ui->textEdit->setText(" ");
}


void MainWindow::on_actionOpen_triggered()
{

    QString Filter="All file (*.*)";
    QString file_name=QFileDialog::getOpenFileName(this,"",QDir::homePath(),Filter);
    file=file_name;
     QFile file(file_name);
     if(!file.open(QFile::ReadOnly | QFile::Text)){
             QMessageBox::warning(this,"error","File not opend");
             return;
         }
         QTextStream in(&file);
         QString text=in.readAll();
         ui->textEdit->setText(text);
         file.close();
}


void MainWindow::on_actionSave_As_triggered()
{
    QString Filter="All file (*.*)";
    QString file_name=QFileDialog::getOpenFileName(this,"",QDir::homePath(),Filter);
    file=file_name;
     QFile file(file_name);
     if(!file.open(QFile::WriteOnly | QFile::Text)){
             QMessageBox::warning(this,"error","File not Saved");
             return;
         }
         QTextStream out(&file);
         QString text=ui->textEdit->toPlainText();
        out << text;
         file.flush();
         file.close();
}


void MainWindow::on_actionHere_triggered()
{
QString about_me;
about_me= "EDUCATION: \n";
about_me += " 2006-2019  Delhi Public School Srinagar \n";
about_me += "2020-CURRENT  Islamic University OF Science And Technology \n";
about_me += " -------------------------------- \n";
about_me += "SIKLLS:  \n";
about_me += " WEB DEVELOPMENT \n";
about_me += " SOFTWARE DEVELOPMENT \n";
about_me += " MACHINE LEARNING \n";
about_me += " -------------------------------- \n";
about_me += "PERIOR EXPERIENCE: INTERSHIP IN DEVELOPING  FRONT-END FRAMEWORK USING REACT.JS IN A UNIVERSITY PROJECT \n";
about_me += " -------------------------------- \n";
about_me += "CERTIFICATIONS: \n";
about_me += " NPTL CERTIFICATE IN PROBLEM SOLVING THROUGH C \n";
about_me += " PROBLEM SOLVING THROUGH C++ \n";
about_me += " WEB-DEVELOPMET(REACTJS,JQUERY,NODEJS,CSS,MONGODB,MONGOOSE,\n";
about_me += " PROJECT MANAGEMENT BASIC \n";
about_me += " -------------------------------- \n";
about_me += " OTHER HOBBIES:  \n";
about_me += " PROJECT HANDLING \n";
about_me += " PLAYING GUITAR \n";
about_me += " GYM \n";
about_me += " CRICKET \n";
about_me += " Code \n";

QMessageBox ::about(this,"ME",about_me);

}




void MainWindow::on_actionSave_triggered()
{

    QString file_name(file);
     QFile file(file_name);
     if(!file.open(QFile::WriteOnly | QFile::Text)){
             QMessageBox::warning(this,"error","File not opend");
             return;
         }
         QTextStream out(&file);
         QString text=ui->textEdit->toPlainText();
        out << text;
        file.flush();
         file.close();
}


void MainWindow::on_actionSuperScript_triggered()
{

    QTextCharFormat format;
      format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
      if(ui->textEdit->hasFocus())
         ui->textEdit->mergeCurrentCharFormat(format);

}
;

void MainWindow::on_actionDownScript_triggered(){
    QTextCharFormat format;
      format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
      if(ui->textEdit->hasFocus())
         ui->textEdit->mergeCurrentCharFormat(format);


}


void MainWindow::on_actionBold_triggered()
{
    ui->textEdit->setFontWeight(QFont::Bold);

}


void MainWindow::on_actionUnBold_triggered()
{
 ui->textEdit->setFontWeight(QFont::Normal);

}

