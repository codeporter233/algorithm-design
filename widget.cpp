#include "widget.h"
#include <QFont>
#include <QString>
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    init();
}

Widget::~Widget()
{
}

void Widget::init()
{
    resize(600,400);

    btn1 = new QPushButton("下一步",this);
    btn1->setFixedSize(90,50);
    btn1->move(490,320);
    btn1->show();

    btn2 = new QPushButton("退出",this);
    btn2->setFixedSize(90,50);
    btn2->move(20,320);
    btn2->show();

    QFont lbl_font;

    lbl_font.setPointSize(25);
    label_title = new QLabel(this);
    label_title->setFont(lbl_font);
    label_title->setText("算法实验:迷你正则表达式");
    label_title->setGeometry(50, 50, 600, 60);
    label_title->show();

    lbl_font.setPointSize(10);
    label_rep = new QLabel(this);
    label_rep->setFont(lbl_font);
    label_rep->setText("项目开源:https://github.com/codeporter233/algorithm-design");
    label_rep->setGeometry(20, 220, 600, 30);
    label_rep->show();

    lbl_font.setPointSize(16);
    label_info = new QLabel(this);
    label_info->setFont(lbl_font);
    label_info->setText("1807004534  凌超");
    label_info->setGeometry(20, 280, 220, 30);
    label_info->show();

    connect(btn2, &QPushButton::clicked, this, &Widget::close);
    connect(btn1, &QPushButton::clicked, this, &Widget::data);

}

void Widget::data()
{
    label_rep->close();
    label_title->close();
    label_info->close();

    btn3 = new QPushButton("开始",this);
    btn3->setFixedSize(90,50);
    btn3->move(255,320);
    btn3->show();

    QFont lbl_font;

    lbl_font.setPointSize(12);
    label_pstr = new QLabel(this);
    label_pstr->setFont(lbl_font);
    label_pstr->setText("模板字符串:");
    label_pstr->setGeometry(50, 100, 600, 60);
    label_pstr->show();

    lbl_font.setPointSize(12);
    label_str = new QLabel(this);
    label_str->setFont(lbl_font);
    label_str->setText("字符串:");
    label_str->setGeometry(70, 150, 600, 60);
    label_str->show();

    qle_pstr = new QLineEdit(this);
    qle_pstr->setPlaceholderText("可以带有'*'''?");
    qle_pstr->setGeometry(175,115,300,30);
    qle_pstr->show();

    qle_str = new QLineEdit(this);
    qle_str->setPlaceholderText("输入一个字符串");
    qle_str->setGeometry(175,165,300,30);
    qle_str->show();

    connect(btn3, &QPushButton::clicked, this, &Widget::handleData);
}

void Widget::handleData()
{

    QString pstr = qle_pstr->text();
    QString str = qle_str->text();

    bool ismatch = match(str,pstr);
    if (ismatch)
        QMessageBox::information(this, "提示", "匹配成功");

    else
        QMessageBox::critical(this, "提示", "匹配失败");

}

int Widget::match(const QString &s, const QString &p)
{
    int m = s.length();
    int n = p.length();

    bool dp[105][105];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;

    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = dp[0][i - 1] && p[i - 1] == '*';
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
           if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            }
           else if (p[j - 1] == '*') {
               dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
           }
        }
    }

    return dp[m][n];
}

