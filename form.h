#ifndef FORM_H
#define FORM_H
#include <QMainWindow>
#include <QWidget>
#include <QString>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    enum a {PLUS = 0, RAZ, DELEN, UMNOG, RES,CE,SQR, SQRT1,GIP};

public slots:
    void plus();
    void raz();
    void delen();
    void umnog();
    void input();
    void rezults();
    void result2();
    void pushButton();
    void buttonKvadrat();
    void buttonSqrt();
    void gip();


private:
    Ui::Form *ui;
    double odd;
    a act;
    bool flag_clear_win;
    double prom;
};

#endif // FORM_H
