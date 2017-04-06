#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

/**
 * @brief The MainWindow class First window to setup the name and rule of the tic tac toe.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow Constructor
     * @param parent Parent widget, default is null.
     */
    explicit MainWindow(QWidget *parent = 0);

    /**
     * @brief Destructor
     */
    ~MainWindow();

    /**
     * @brief create_game_window Create the game window.
     */
    void create_game_window();
private slots:
    /**
     * @brief on_pushButton_clicked Called whenever the play button gets hit.
     */
    void on_pushButton_clicked();

private:
    /// our ui
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
