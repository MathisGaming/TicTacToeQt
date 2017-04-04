#include "TicTacToeBoardWidget.h"
#include "ui_TicTacToeBoardWidget.h"

TicTacToeBoardWidget::TicTacToeBoardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TicTacToeBoardWidget)
{
    ui->setupUi(this);
}

TicTacToeBoardWidget::~TicTacToeBoardWidget()
{
    delete ui;
}
