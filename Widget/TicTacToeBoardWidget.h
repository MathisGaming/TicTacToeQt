#ifndef TICTACTOEBOARDWIDGET_H
#define TICTACTOEBOARDWIDGET_H

#include <QWidget>

namespace Ui {
class TicTacToeBoardWidget;
}

class TicTacToeBoardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TicTacToeBoardWidget(QWidget *parent = 0);
    ~TicTacToeBoardWidget();

private:
    Ui::TicTacToeBoardWidget *ui;
};

#endif // TICTACTOEBOARDWIDGET_H
