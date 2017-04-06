#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>

namespace Ui {
    class GameWindow;
}

/**
 * @brief The GameWindow class The game window class responsible of displaying the game.
 */
class GameWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief GameWindow Constructor
     * @param parent Parent widget of the window, default is null.
     */
    explicit GameWindow(QWidget *parent = 0);
    /**
      * @brief Destructor.
     */
    ~GameWindow();

    /**
     * @brief init_ui Initialize the ui.
     * @param fpname First Player Name.
     * @param spname Second Player Name.
     * @param currentPlayerName Current Player name.
     */
    void init_ui(QString fpname, QString spname, QString currentPlayerName);

    /**
     * @brief update_scores_ui Update the score from the different player
     * @param fpscore First player score.
     * @param spscore Second player score.
     */
    void update_scores_ui(QString fpscore, QString spscore);

    /**
     * @brief update_current_player_name_ui Update the current player labe.
     * @param name Name of the current player.
     */
    void update_current_player_name_ui(QString name);

    /**
     * @brief show_winner Will display who is the winner as well as replay button to restart a new game.
     * @param show True if we should show the winner.
     * @param name Name of the winner.
     */
    void show_winner(bool show, QString name = "");

    /**
     * @brief reset_game_buttons Reset the button of the game (style, enable, etc..)
     */
    void reset_game_buttons();

    /**
     * @brief enable_game_buttons Enable or not the button to be re usable.
     * @param enable True will enable the buttons.
     */
    void enable_game_buttons(bool enable);

    /**
     * @brief set_button_value Set the current button value (if it is a cross or circle).
     * @param button Button pointer to be set.
     * @param value New value of the button.
     */
    void set_button_value(QPushButton* button, int value);
private slots:
    /**
     * @brief on_ReplayButton_clicked Slot used for whenever the replay button gets hit.
     */
    void on_ReplayButton_clicked();

private:
    /// Our ui.
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
