#ifndef CUSTOMGAMEWIDGET_H
#define CUSTOMGAMEWIDGET_H

#include <QWidget>

namespace Ui {
class CustomGameWidget;
}

class CustomGameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CustomGameWidget(QWidget *parent = 0);
    ~CustomGameWidget();
    void reset_buttons();
    void enable_buttons(bool enable);
    void set_button_value(class QPushButton* button, int value);
private slots:
    void on_GameButton_0_0_clicked();

    void on_GameButton_0_1_clicked();

    void on_GameButton_0_2_clicked();

    void on_GameButton_1_0_clicked();

    void on_GameButton_1_1_clicked();

    void on_GameButton_1_2_clicked();

    void on_GameButton_2_0_clicked();

    void on_GameButton_2_1_clicked();

    void on_GameButton_2_2_clicked();

private:
    void button_clicked(int x, int y);
    Ui::CustomGameWidget *ui;
};

#endif // CUSTOMGAMEWIDGET_H
