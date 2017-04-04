#include "customgamewidget.h"
#include "ui_customgamewidget.h"
#include "Manager/TicTacToeGameManager.h"

CustomGameWidget::CustomGameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomGameWidget)
{
    ui->setupUi(this);
}

CustomGameWidget::~CustomGameWidget()
{
    delete ui;
}

void CustomGameWidget::on_GameButton_0_0_clicked()
{
    button_clicked(0,0);
}

void CustomGameWidget::on_GameButton_0_1_clicked()
{
    button_clicked(0,1);
}

void CustomGameWidget::on_GameButton_0_2_clicked()
{
    button_clicked(0,2);
}

void CustomGameWidget::on_GameButton_1_0_clicked()
{
    button_clicked(1,0);
}

void CustomGameWidget::on_GameButton_1_1_clicked()
{
    button_clicked(1,1);
}

void CustomGameWidget::on_GameButton_1_2_clicked()
{
    button_clicked(1,2);
}

void CustomGameWidget::on_GameButton_2_0_clicked()
{
    button_clicked(2,0);
}

void CustomGameWidget::on_GameButton_2_1_clicked()
{
    button_clicked(2,1);
}

void CustomGameWidget::on_GameButton_2_2_clicked()
{
    button_clicked(2,2);
}

void CustomGameWidget::button_clicked(int x, int y)
{
    QObject* senderObj = sender();
    if (senderObj->isWidgetType())
    {
        QPushButton* button = qobject_cast<QPushButton*>(senderObj);
        if (button)
        {
            TicTacToeGameManager::instance()->play_once(x,y,button);
        }
    }

}

void CustomGameWidget::reset_buttons()
{
    ui->GameButton_0_0->setText("");
    ui->GameButton_0_0->setEnabled(true);
    ui->GameButton_0_1->setText("");
    ui->GameButton_0_1->setEnabled(true);
    ui->GameButton_0_2->setText("");
    ui->GameButton_0_2->setEnabled(true);

    ui->GameButton_1_0->setText("");
    ui->GameButton_1_0->setEnabled(true);
    ui->GameButton_1_1->setText("");
    ui->GameButton_1_1->setEnabled(true);
    ui->GameButton_1_2->setText("");
    ui->GameButton_1_2->setEnabled(true);

    ui->GameButton_2_0->setText("");
    ui->GameButton_2_0->setEnabled(true);
    ui->GameButton_2_1->setText("");
    ui->GameButton_2_1->setEnabled(true);
    ui->GameButton_2_2->setText("");
    ui->GameButton_2_2->setEnabled(true);
}

void CustomGameWidget::enable_buttons(bool enable){
    ui->GameButton_0_0->setEnabled(enable);
    ui->GameButton_0_1->setEnabled(enable);
    ui->GameButton_0_2->setEnabled(enable);
    ui->GameButton_1_0->setEnabled(enable);
    ui->GameButton_1_1->setEnabled(enable);
    ui->GameButton_1_2->setEnabled(enable);
    ui->GameButton_2_0->setEnabled(enable);
    ui->GameButton_2_1->setEnabled(enable);
    ui->GameButton_2_2->setEnabled(enable);
}

void CustomGameWidget::set_button_value(QPushButton* button, int value)
{
    if(button!=nullptr){
        if(value == 1){
           button->setText("O");
           button->setEnabled(false);
        }
        else if (value == 2){
           button->setText("X");
           button->setEnabled(false);
        }
    }
}
