#include "form.h"
#include "ui_form.h"
#include <QMessageBox>
#include <QDoubleValidator>
#include <cmath>
#include <QtCore/qmath.h>
#include <QtDebug>


 Form::Form(QWidget *parent):
      QWidget(parent),
   ui(new Ui::Form)
{
    prom=0;
    ui->setupUi(this);
    connect(ui->button0,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->button1,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->button2,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->button3,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->button4,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->button5,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->button6,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->button7,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->button8,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->button9,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->puttonPoint,SIGNAL(clicked(bool)),this,SLOT(input()));
    connect(ui->buttonPlus,SIGNAL(clicked(bool)),this,SLOT(plus()));
    connect(ui->buttonRaz,SIGNAL(clicked(bool)),this,SLOT(raz()));
    connect(ui->buttonDelen,SIGNAL(clicked(bool)),this,SLOT(delen()));
    connect(ui->buttonUmnog,SIGNAL(clicked(bool)),this,SLOT(umnog()));
    connect(ui->buttonRes,SIGNAL(clicked(bool)),this,SLOT(result2()));
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(pushButton()));
    connect(ui->buttonKvadrat,SIGNAL(clicked(bool)),this,SLOT(buttonKvadrat()));
    connect(ui->buttonSqrt,SIGNAL(clicked(bool)),this,SLOT(buttonSqrt()));
    connect(ui->buttonGip,SIGNAL(clicked(bool)),this,SLOT(gip()));


       ui->rezults->setValidator(new QDoubleValidator());


}

Form::~Form()
{
    delete ui;
}

void Form::plus()
{
    flag_clear_win = true;
   odd = ui->rezults->text().toDouble();
    rezults();
    act = PLUS;

}

void Form::raz()
{
    flag_clear_win = true;
   odd = ui->rezults->text().toDouble();
    rezults();
    act = RAZ;
}

void Form::delen()
{
    flag_clear_win = true;
   odd = ui->rezults->text().toDouble();
    rezults();
    act = DELEN;
}

void Form::umnog()
{
    flag_clear_win = true;
   odd = ui->rezults->text().toDouble();
    rezults();
    act = UMNOG;
}
void Form::rezults()
{
    switch (act) {
    case PLUS:
        prom=prom+QLocale::system().toDouble(ui->rezults->text());
        break;
    case RAZ:
        prom=prom-QLocale::system().toDouble(ui->rezults->text());
        break;
     case UMNOG:
         prom=prom*QLocale::system().toDouble(ui->rezults->text());
        break;
    //case CE:
      //  prom=0;
       // display->setText("0");
        //ui->rezults->void clear();
     //  ui->rezults->setText("0");
       //prom=0*QLocale::system().toDouble(ui->rezults->text());

    //    break;
    case SQR:
       prom=QLocale::system().toDouble(ui->rezults->text())*QLocale::system().toDouble(ui->rezults->text());
        break;


     case GIP:
        prom=1/(QLocale::system().toDouble(ui->rezults->text()));
        break;

    case DELEN:
       {

  QMessageBox box;
            box.setText("Error! Divide by zero");
            double chast = QLocale::system().toDouble(ui->rezults->text());
            if (chast==0)
                box.exec();
            else
            prom=prom/QLocale::system().toDouble(ui->rezults->text());
        }
break;
   case SQRT1:
{

   QString sr= ui->rezults->text();
   // qDebug() << sr;
    //QString finalStr
            prom = sqrt(sr.toDouble());
                    //number(sqrt(sr.toDouble()));
   // qDebug() << finalStr;
  //      ui->rezults->finalStr;

    //prom = QLocale::system().toDouble(finalStr);

   }
               break;

        case RES:
            flag_clear_win = true;
            ui->rezults->setText(QLocale::system().toString(prom));
            prom = 0;
            odd = 0;
        default:
            prom=QLocale::system().toDouble(ui->rezults->text());
            break;
        }

           if (act !=RES)
            ui->rezults->setText(QLocale::system().toString(prom));


}

void Form::input()
{
QPushButton* uk_bt;
if (flag_clear_win){
    flag_clear_win = false;
    ui->rezults->setText("");}
uk_bt = qobject_cast<QPushButton*>(sender());
QString str =ui->rezults->text()+uk_bt->text();
int i;
if (ui->rezults->validator()->validate(str,i)==QValidator::Invalid) return;
ui->rezults->setText(str);

}

void Form::result2()
{
    flag_clear_win = true;
      rezults();
    act = RES;

}

void Form::pushButton()
{

    flag_clear_win = true;
    //rezults();
    act = CE;
    ui->rezults->setText(" ");

}
void Form::buttonKvadrat()
{

    flag_clear_win = true;
   odd = ui->rezults->text().toDouble();
//    rezults();
    act = SQR;
}

void Form::buttonSqrt()
{
flag_clear_win = true;
odd = ui->rezults->text().toDouble();
//rezults();
act = SQRT1;


   // QString sr= ui->rezults->text();
      //  qDebug() << sr;
       // QString finalStr = QString::number(sqrt(sr.toDouble()));
        //  qDebug() << finalStr;
         //  ui->rezults->setText(finalStr);
}


void Form::gip()
{
    flag_clear_win = true;
   odd = ui->rezults->text().toDouble();
   // rezults();
    act = GIP;
}





