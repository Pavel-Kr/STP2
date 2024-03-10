#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tpnumber.h"
#include <QPushButton>
#include <string>
#include <QString>
#include <QAction>
#include <QMessageBox>

void MainWindow::btn_input_click(QString par)
{
    if (par == "." and ui->le_input->text().contains('.', Qt::CaseInsensitive))
        return;

    if (par == "." and ui->le_input->text().size() == 0)
        par = "0.";
    ui->le_input->setText(ui->le_input->text() + par);
    ui->le_output->setText("");
}

void MainWindow::btn_delete_click()
{
    QString text = ui->le_input->text();
    if (text.size() == 0)
        return;
    text.chop(1);
    ui->le_input->setText(text);
}

void MainWindow::btn_clear_click()
{
    ui->le_input->setText("");
}

void MainWindow::action_close_triggered()
{
    this->close();
}

void MainWindow::action_story_triggered()
{
    QMessageBox storyMess;
    storyMess.setText("История");
    storyMess.setInformativeText(QString::fromStdString(story));
    storyMess.addButton("Прикольно", QMessageBox::AcceptRole);
    storyMess.exec();
}

void MainWindow::action_info_triggered()
{
    QMessageBox info;
    info.setText("ИП-017");
    info.setInformativeText("Кривошеев Павел, Могутова Сонечка<3");
    info.addButton("Понял принял", QMessageBox::AcceptRole);
    info.exec();
}

void MainWindow::story_add(string new_text)
{
    story = story + "\n" + new_text;
}

void MainWindow::btn_execute_click()
{
    //a+b*c

    QString base = ui->sb_in->text();
    QString res_base = ui->sb_out->text();
    int tocnost = 0;
    if (ui->le_input->text().contains('.', Qt::CaseInsensitive))
        tocnost = 5;
    else
        tocnost = 0;

    string input_text = ui->le_input->text().toStdString();

    cout << "_\n";
    string str_res = "";
    if(input_text.size() != 0)
    {
        TPNumber pnum(input_text, base.toStdString(), to_string(tocnost));
        story_add("Вase " + base.toStdString() + ": number = " + input_text);
        pnum.setBase(res_base.toStdString());
        story_add("Вase " + res_base.toStdString() + ": number = " + pnum.getNumberString());
        str_res = pnum.getNumberString();
        input_text = "";
    }

    if (str_res.find(".") != string::npos){
        while(str_res.back() == '0')
            str_res.pop_back();
        if (str_res.back() == '.')
            str_res.pop_back();
    }
    ui->le_output->setText(QString::fromStdString(str_res));
}

void MainWindow::set_buttons(int base){

    if (base < 16)
        ui->btn_f->setEnabled(false);
    else
        ui->btn_f->setEnabled(true);
    if (base < 15)
        ui->btn_e->setEnabled(false);
    else
        ui->btn_e->setEnabled(true);
    if (base < 14)
        ui->btn_d->setEnabled(false);
    else
        ui->btn_d->setEnabled(true);
    if (base < 13)
        ui->btn_c->setEnabled(false);
    else
        ui->btn_c->setEnabled(true);
    if (base < 12)
        ui->btn_b->setEnabled(false);
    else
        ui->btn_b->setEnabled(true);
    if (base < 11)
        ui->btn_a->setEnabled(false);
    else
        ui->btn_a->setEnabled(true);
    if (base < 10)
        ui->btn_9->setEnabled(false);
    else
        ui->btn_9->setEnabled(true);
    if (base < 9)
        ui->btn_8->setEnabled(false);
    else
        ui->btn_8->setEnabled(true);
    if (base < 8)
        ui->btn_7->setEnabled(false);
    else
        ui->btn_7->setEnabled(true);
    if (base < 7)
        ui->btn_6->setEnabled(false);
    else
        ui->btn_6->setEnabled(true);
    if (base < 6)
        ui->btn_5->setEnabled(false);
    else
        ui->btn_5->setEnabled(true);
    if (base < 5)
        ui->btn_4->setEnabled(false);
    else
        ui->btn_4->setEnabled(true);
    if (base < 4)
        ui->btn_3->setEnabled(false);
    else
        ui->btn_3->setEnabled(true);
    if (base < 3)
        ui->btn_2->setEnabled(false);
    else
        ui->btn_2->setEnabled(true);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action_close, &QAction::triggered, [this](){this->action_close_triggered();});
    connect(ui->action_story, &QAction::triggered, [this](){this->action_story_triggered();});
    connect(ui->action_info, &QAction::triggered, [this](){this->action_info_triggered();});

    connect(ui->btn_0, &QPushButton::clicked, this, [this](){this->btn_input_click("0");});
    connect(ui->btn_1, &QPushButton::clicked, this, [this](){this->btn_input_click("1");});
    connect(ui->btn_2, &QPushButton::clicked, this, [this](){this->btn_input_click("2");});
    connect(ui->btn_3, &QPushButton::clicked, this, [this](){this->btn_input_click("3");});
    connect(ui->btn_4, &QPushButton::clicked, this, [this](){this->btn_input_click("4");});
    connect(ui->btn_5, &QPushButton::clicked, this, [this](){this->btn_input_click("5");});
    connect(ui->btn_6, &QPushButton::clicked, this, [this](){this->btn_input_click("6");});
    connect(ui->btn_7, &QPushButton::clicked, this, [this](){this->btn_input_click("7");});
    connect(ui->btn_8, &QPushButton::clicked, this, [this](){this->btn_input_click("8");});
    connect(ui->btn_9, &QPushButton::clicked, this, [this](){this->btn_input_click("9");});
    connect(ui->btn_a, &QPushButton::clicked, this, [this](){this->btn_input_click("A");});
    connect(ui->btn_b, &QPushButton::clicked, this, [this](){this->btn_input_click("B");});
    connect(ui->btn_c, &QPushButton::clicked, this, [this](){this->btn_input_click("C");});
    connect(ui->btn_d, &QPushButton::clicked, this, [this](){this->btn_input_click("D");});
    connect(ui->btn_e, &QPushButton::clicked, this, [this](){this->btn_input_click("E");});
    connect(ui->btn_f, &QPushButton::clicked, this, [this](){this->btn_input_click("F");});
    connect(ui->btn_point, &QPushButton::clicked, this, [this](){this->btn_input_click(".");});
    connect(ui->btn_delete, &QPushButton::clicked, this, [this](){this->btn_delete_click();});
    connect(ui->btn_clear, &QPushButton::clicked, this, [this](){this->btn_clear_click();});
    connect(ui->btn_execute, &QPushButton::clicked, this, [this](){this->btn_execute_click();});
    connect(ui->sb_in, &QSpinBox::valueChanged, this, &MainWindow::set_buttons);

    ui->sb_in->setValue(10);
    ui->sb_out->setValue(10);

}

MainWindow::~MainWindow()
{
    delete ui;
}
