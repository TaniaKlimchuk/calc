#ifndef _Calculator_h_
#define _Calculator_h_
#include<QWidget>
#include<QStack>
#include<QLabel>
#include<QPushButton>
#include<QGridLayout>

class Calculator:public QWidget{
Q_OBJECT//макрос,нуженвначалевсехнашихклассов
private:
QLabel*displaystring;
QStack<QString>stack;
public:
Calculator(QWidget*pwgt=0);
QPushButton*createButton(const QString& str);
void calculate();
public slots://Общедоступныеобработчикисобытий
void slotButtonClicked();
};
#endif


