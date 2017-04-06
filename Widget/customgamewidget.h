#ifndef CUSTOMGAMEWIDGET_H
#define CUSTOMGAMEWIDGET_H

#include <QWidget>

namespace Ui {
class CustomGameWidget;
}

/**
 * @brief The CustomGameWidget class Widget used to handle the game board.
 */
class CustomGameWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief CustomGameWidget Constructor.
     * @param parent Parent widget, default is null.
     */
    explicit CustomGameWidget(QWidget *parent = 0);
    /**
     * @brief Destructor.
     */
    ~CustomGameWidget();
    /**
     * @brief reset_buttons Reset the buttons of the board (style,enable etc..).
     */
    void reset_buttons();
    /**
     * @brief enable_buttons Enable the buttons or not (play buttons).
     * @param enable If true, will enable the buttons.
     */
    void enable_buttons(bool enable);
    /**
     * @brief set_button_value Set the button value, Either cross or circle depending on who played.
     * @param button Pointer to the button to be edited
     * @param value Value of the symbol of the player that pressed the button.
     */
    void set_button_value(class QPushButton* button, int value);
private slots:
    /**
     * @brief on_GameButton_0_0_clicked Called whenever the button 0 0 is clicked.
     */
    void on_GameButton_0_0_clicked();

    /**
     * @brief on_GameButton_0_1_clicked Called whenever the button 0 1 is clicked.
     */
    void on_GameButton_0_1_clicked();

    /**
     * @brief on_GameButton_0_2_clicked Called whenever the button 0 2 is clicked.
     */
    void on_GameButton_0_2_clicked();

    /**
     * @brief on_GameButton_1_0_clicked Called whenever the button 1 0 is clicked.
     */
    void on_GameButton_1_0_clicked();

    /**
     * @brief on_GameButton_1_1_clicked Called whenever the button 1 1 is clicked.
     */
    void on_GameButton_1_1_clicked();

    /**
     * @brief on_GameButton_1_2_clicked Called whenever the button 1 2 is clicked.
     */
    void on_GameButton_1_2_clicked();

    /**
     * @brief on_GameButton_2_0_clicked Called whenever the button 2 0 is clicked.
     */
    void on_GameButton_2_0_clicked();

    /**
     * @brief on_GameButton_2_1_clicked Called whenever the button 2 1 is clicked.
     */
    void on_GameButton_2_1_clicked();

    /**
     * @brief on_GameButton_2_2_clicked Called whenever the button 2 2 is clicked.
     */
    void on_GameButton_2_2_clicked();

private:
    /**
     * @brief button_clicked Called whenever a button is being clicked.
     * @param x Value on X of the button (regarding the board, 0 0 for top left).
     * @param y Value on Y of the button (regarding the board, 0 0 for top left).
     */
    void button_clicked(int x, int y);
    /**
     * @brief reset_button Reset the given button.
     * @param button Pointer to the button to be reset.
     */
    void reset_button(QPushButton* button);
    /// Our ui.
    Ui::CustomGameWidget *ui;
};

#endif // CUSTOMGAMEWIDGET_H
