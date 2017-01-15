
#include <QApplication>
#include "form.h"
#include <cmath>
int main(int argc,char*argv[]){
QApplication app(argc,argv);
Form calculator;
calculator.setWindowTitle("Calculator");
calculator.resize(430,360);
calculator.setFixedSize(430,360);
calculator.show();
return app.exec();
}

