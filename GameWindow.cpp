#include "ui_GameWindow.h"
#include "GameWindow.h"
#include "Manager/TicTacToeGameManager.h"
#include <QDir>

GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/tttbackground.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    show_winner(false);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::init_ui(QString fpname, QString spname, QString currentPlayerName)
{
    ui->FPlayerNameLabel->setText(fpname);
    ui->SPlayerNameLabel->setText(spname);
    update_current_player_name_ui(currentPlayerName);
    enable_game_buttons(true);
    reset_game_buttons();
    show_winner(false);
}

void GameWindow::update_scores_ui(QString fpscore, QString spscore){
    ui->FPlayerScoreLabel->setText(fpscore);
    ui->SPlayerScoreLabel->setText(spscore);
}

void GameWindow::update_current_player_name_ui(QString name){
    ui->CurrentPlayerNameLabel->setText(name);
}

void GameWindow::show_winner(bool show, QString name){
    ui->WinnerLabel->setVisible(show);
    ui->WinnerNameLabel->setVisible(show);
    ui->WinnerNameLabel->setText(name);
    ui->ReplayButton->setEnabled(show);
    ui->ReplayButton->setVisible(show);
}

void GameWindow::on_ReplayButton_clicked()
{
    show_winner(false);
    reset_game_buttons();
    enable_game_buttons(true);
    show_winner(false);
    TicTacToeGameManager::instance()->reset_game();
}

void GameWindow::reset_game_buttons(){
    ui->widget->reset_buttons();
}

void GameWindow::enable_game_buttons(bool enable)
{
    ui->widget->enable_buttons(enable);
}

void GameWindow::set_button_value(QPushButton* button, int value){
    ui->widget->set_button_value(button, value);
}
