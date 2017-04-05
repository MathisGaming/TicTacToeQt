#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>

namespace Ui {
    class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
    void init_ui(QString fpname, QString spname, QString currentPlayerName);

    void update_scores_ui(QString fpscore, QString spscore);

    void update_current_player_name_ui(QString name);

    void show_winner(bool show, QString name = "");
    void reset_game_buttons();
    void enable_game_buttons(bool enable);
    void set_button_value(QPushButton* button, int value);
private slots:
    void on_ReplayButton_clicked();

private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
