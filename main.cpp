#include "calculator.h"
#include <QApplication>
#include "form.h"
int main(int argc,char*argv[]){
QApplication app(argc,argv);
Form calculator;
calculator.setWindowTitle("Calculator");
calculator.resize(430,300);
calculator.setFixedSize(430,300);
calculator.show();
return app.exec();
}

