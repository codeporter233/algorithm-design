#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QString>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void init();
    void data();
    void handleData();
    int match(const QString &s, const QString &p);

private:
    QPushButton *btn1, *btn2, *btn3;
    QLabel *label_rep, *label_info, *label_title;
    QLabel *label_str,*label_pstr;
    QLineEdit * qle_pstr,*qle_str;
};
#endif // WIDGET_H
