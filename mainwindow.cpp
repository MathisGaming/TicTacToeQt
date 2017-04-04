#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GameWindow.h"
#include "Player/TicTacToePlayer.h"
#include <QString>
#include "Manager/TicTacToeGameManager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ScoreLineEdit->setValidator( new QIntValidator(1, 10, this) );
}

MainWindow::~MainWindow()
{
    TicTacToeGameManager::destroy();
    delete ui;
}

void MainWindow::create_game_window()
{
    //The game window needs to be created after the game manager has been initialized.
    std::string FPlayerNameStr = ui->FPlayerNameEdit->text().toStdString();
    std::string SPlayerNameStr = ui->SPlayerNameEdit->text().toStdString();

    // check if names are the same.
    if(FPlayerNameStr.compare(SPlayerNameStr)==0){
        // throw some error, names are the same.
        return;
    }

    int maxScore = ui->ScoreLineEdit->text().toInt();

    // Create the Players
    TicTacToeGameManager::instance()->create_player(FPlayerNameStr,1);
    TicTacToeGameManager::instance()->create_player(SPlayerNameStr,2);
    // Initialize max score.
    TicTacToeGameManager::instance()->set_max_score(maxScore);
    TicTacToeGameManager::instance()->init();

    // now we create the game window
    GameWindow* gameWindow = new GameWindow();

    gameWindow->show();
    TicTacToeGameManager::instance()->set_game_window(gameWindow);
    hide();
}

void MainWindow::on_pushButton_clicked()
{
    // Load the new page.
    create_game_window();
}
