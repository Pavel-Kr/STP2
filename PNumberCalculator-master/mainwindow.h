#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "tpnumber.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void btn_input_click(QString par);
    void btn_delete_click();
    void btn_clear_click();
    void btn_execute_click();
    void btn_reverse_click();
    void action_close_triggered();
    void action_story_triggered();
    void action_info_triggered();
    void action_log_triggered();
    void story_add(string new_text);

public slots:
    void set_buttons(int base);

private:
    Ui::MainWindow *ui;
    std::string story;
    std::string log;
};

#endif // MAINWINDOW_H
