#include"calculator.h"

Calculator::Calculator(QWidget*parent):QWidget(parent){
displaystring = new QLabel("");
displaystring->setMinimumSize(200,50);//расположениевыводимыхдействий
QChar aButtons[4][4]={
{'7','8','9','/'},
{'4','5','6','*'},
{'1','2','3','-'},
{'0','.','=','+'}
};

QGridLayout *myLayout= new QGridLayout;
myLayout->addWidget(displaystring, 0, 0, 1, 4);
myLayout->addWidget(createButton("CE"), 1, 3);
for(int i=0; i<4; ++i){
for(int j=0; j<4; ++j){
myLayout->addWidget(createButton(aButtons [i] [j]), i+2, j);
}
}
setLayout(myLayout);
}

QPushButton* Calculator::createButton(const QString& str){
QPushButton* pcmd= new QPushButton(str);
pcmd->setMinimumSize(40,40);
connect(pcmd,SIGNAL(clicked()),this,SLOT(slotButtonClicked()));
return pcmd;
}

void Calculator::calculate (){
double dOperand2=stack.pop().toDouble();
QString strOperation=stack.pop();
double dOperand1=stack.pop().toDouble();
double dResult=0;
if(strOperation=="+"){dResult=dOperand1+dOperand2;}
else if(strOperation=="-"){dResult=dOperand1-dOperand2;}
else if(strOperation=="/"){dResult=dOperand1/dOperand2;}
else if(strOperation=="*"){dResult=dOperand1*dOperand2;}
displaystring->setText(QString("%1").arg(dResult,0,'f',3));
}

void Calculator::slotButtonClicked(){
QString str=((QPushButton*)sender())->text();//Получаемтекстснажатойкнопки
if(str=="CE"){//КнопкаОчистить
stack.clear();displaystring->setText("");return;
}

QString text=displaystring->text();//отображаемыйтекст
int len=text.length();
QString last="";
if(len>0)last=text.right(1);//самыйправыйсимволввода

if(((len==0 && stack.count()==0)||
((stack.count()==2&&len>1&&(last=="+"||last=="-"||last=="*"||last=="/"))))&&
(str.contains(QRegExp("[0-9]"))||str=="-")){
//Наэкранепустоистекпустиливведен1-йоперандиоперация
//иприэтомнажатацифраили"-"
text=str;//Стеретьто,чтобылоотображено,иотобразитьнажатыйсимвол
}
else if((text+str).contains(QRegExp("^-?[0-9]+\\.?[0-9]*$"))){
text+=str;//Покавводимчисло-добавлятьсимвол
}
else if(text.contains(QRegExp("^-?[0-9]+\\.?[0-9]*$"))){//Уженабраночисло
if(str=="*"||str=="/"||str=="+"||str=="-"||str=="="){//Вычислить
if(stack.count()==2){//Есть1-йоперандичисло
stack.push(text);//Положитьвстек2-йоперанд
calculate();//Вычислить
text=displaystring->text();//Показатьрезультат
}
if(str!="="){//Длявычисления"поцепочке"
stack.push(text);//Положитьвстек1-йоперанд
text+=str;//Отобразитьоперациюдослед.нажатиякнопки
stack.push(str);//Положитьвстекоперацию
}
}
}
displaystring->setText(text);
}
