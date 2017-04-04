#include "TicTacToeGameManager.h"
#include "Player/TicTacToePlayer.h"
#include "Board/TicTacToeBoard.h"
#include "Widget/customgamewidget.h"
#include "GameWindow.h"

const int emptyCase = 0;
const int whitePawn = 1;
const int blackPawn = 2;

TicTacToeGameManager::TicTacToeGameManager() :
m_current_player(nullptr),
m_maxScore(1),
m_index(0),
m_gameWindow(nullptr)
{
    m_board = new TicTacToeBoard();
}

TicTacToeGameManager::~TicTacToeGameManager()
{
    for(auto p : m_players){
        delete p;
    }

    if(m_board!= nullptr){
        delete m_board;
        m_board = nullptr;
    }
}

void TicTacToeGameManager::init()
{
    m_board->init();
    if(m_players.size()<2){
        // throw an error - not enough player.
        return;
    }
    m_index = 0;
    m_current_player = m_players[m_index];

    //init the ui
    if(m_gameWindow!=nullptr)
    {
        m_gameWindow->init_ui(QString::fromStdString(m_players[0]->get_name()),QString::fromStdString(m_players[1]->get_name()));
        m_gameWindow->update_scores_ui(QString::number(m_players[0]->get_score()),QString::number(m_players[1]->get_score()));
    }
}

void TicTacToeGameManager::create_player(const std::string& name, const int& symbol)
{
    m_players.push_back(new TicTacToePlayer(name,symbol));
}

void TicTacToeGameManager::create_players(const std::vector<std::string>& names)
{
    for(int i = 0; i < names.size(); ++i)
    {
        m_players.push_back(new TicTacToePlayer(names[i],i));
    }
}

int TicTacToeGameManager::play_once(int x, int y,QPushButton* button)
{
    // TODO : refactor this method.
    if(m_current_player == nullptr){
        // throw some error : current player is null.
        return -1;
    }

    int current_player_Symbol = m_current_player->get_symbol();

    if(current_player_Symbol == -1){
        // throw some error : player symbol was not initialized
        return -1;
    }

    if (current_player_Symbol != whitePawn || current_player_Symbol != blackPawn) {
        // throw error - invalid player value. Something went wrong.
    }

    if(m_board == nullptr){
        // throw error - m_board is not initialized
        return -1;
    }
    m_board->play_once(x,y,current_player_Symbol);
    //update ui
    // quick solution for that to avoid wrong communication.
    m_gameWindow->set_button_value(button,current_player_Symbol);


    // check if someone won the game
    int winner_symbol = check_winner();
    if(winner_symbol > 0)
    {
        update_score(winner_symbol);
    }
    else if(winner_symbol == -1)
    {
        // can no longer play.
        init();
    }
    else{
        // keep playing game is not over.
        get_next_player();
        if(m_gameWindow!=nullptr)
        {
            m_gameWindow->update_current_player_name_ui(QString::fromStdString(m_current_player->get_name()));
        }
    }
    return winner_symbol;
}

bool TicTacToeGameManager::update_score(int winnerSymbol)
{
    // update player scoer (data) and ui (view)
    int player_index = -1;
    IPlayer* p = find_player_from_symbol(winnerSymbol,player_index);

    if(p!= nullptr)
    {
        p->update_score();
        if(m_gameWindow!=nullptr)
        {
            init();
            // override previous operation from the init.
            // we want the winner to start first.
            // if provided new design, this could be randomized.
            set_current_player_from_index(player_index);
            m_gameWindow->update_current_player_name_ui(QString::fromStdString(m_current_player->get_name()));

            // check if we passed the score limit so display the winner
            if(check_player_score_limit())
            {
                m_gameWindow->show_winner(true,QString::fromStdString(p->get_name()));
                m_gameWindow->enable_game_buttons(false);
            }
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

int TicTacToeGameManager::check_vertical(){
    // TODO: Warning : This is not thread safe
    // Best way to do that is to make a copy at this point and go through it.
    // if for some reason someone is accessing here and deleting we could have issues.
    auto cases = m_board->get_cases();
    if (cases[0][0]->value == cases[1][0]->value &&
        cases[1][0]->value == cases[2][0]->value) {
        if (cases[0][0]->value != emptyCase) {
            return cases[0][0]->value;
        }
    }
    if (cases[0][1]->value == cases[1][1]->value &&
        cases[1][1]->value == cases[2][1]->value)
    {
        if (cases[0][1]->value != emptyCase) {
            return cases[0][1]->value;
        }
    }
    if (cases[0][2]->value == cases[1][2]->value &&
        cases[1][2]->value == cases[2][2]->value)
    {
        if (cases[0][2]->value != emptyCase) {
            return cases[0][2]->value;
        }
    }
    return 0; // no winner.
}

int TicTacToeGameManager::check_horizontal()
{
    // TODO: Warning : This is not thread safe
    // Best way to do that is to make a copy at this point and go through it.
    // if for some reason someone is accessing here and deleting we could have issues.
    auto cases = m_board->get_cases();
    if (cases[0][0]->value == cases[0][1]->value &&
        cases[0][1]->value == cases[0][2]->value) {
        if (cases[0][0]->value != emptyCase) {
            return cases[0][0]->value;
        }
    }
    if (cases[1][0]->value == cases[1][1]->value &&
        cases[1][1]->value == cases[1][2]->value)
    {
        if (cases[1][0]->value != emptyCase) {
            return cases[1][0]->value;
        }
    }
    if (cases[2][0]->value == cases[2][1]->value &&
        cases[2][1]->value == cases[2][2]->value)
    {
        if (cases[2][0]->value != emptyCase) {
            return cases[2][1]->value;
        }
    }
    return 0; // no winner.
}

int TicTacToeGameManager::check_diagonal(){
    // TODO: Warning : This is not thread safe
    // Best way to do that is to make a copy at this point and go through it.
    // if for some reason someone is accessing here and deleting we could have issues.
    auto cases = m_board->get_cases();
    if (cases[0][0]->value == cases[1][1]->value && cases[1][1]->value == cases[2][2]->value) {
        if (cases[0][0]->value != emptyCase) {
            return cases[0][0]->value;
        }
    }
    if (cases[0][2]->value == cases[1][1]->value && cases[1][1]->value == cases[2][0]->value) {
        if (cases[0][2]->value != emptyCase) {
            return cases[0][2]->value;
        }
    }
    return 0;
}

int TicTacToeGameManager::check_winner(){
    // the checks here returns the symbol of the winner.
    int h = check_horizontal();
    if(h != 0){
        return h;
    }
    int v = check_vertical();
    if(v != 0){
        return v;
    }
    int d = check_diagonal();
    if(d != 0){
        return d;
    }

    if(m_board->is_full()){
        return -1; // end of game;
    }

    return 0;
}

bool TicTacToeGameManager::check_player_score_limit()
{
    for(auto p : m_players){
        if(p->get_score() >= m_maxScore){
            return true;
        }
    }
    return false;
}

void TicTacToeGameManager::set_current_player_from_index(int index){
    if(m_players.size()>0)
    {
        m_index = index;
        if(m_index>=m_players.size()) m_index = 0;
        m_current_player = m_players[m_index];
    }
}

void TicTacToeGameManager::get_next_player(){
    if(m_players.size()>0){
        m_index++;
        if(m_index>=m_players.size()) m_index = 0;
        m_current_player = m_players[m_index];
    }
}

IPlayer* TicTacToeGameManager::find_player_from_symbol(int symbol, int& index){
    for(int i = 0; i < m_players.size();++i){
        if(m_players[i]->get_symbol() == symbol){
            index = i;
            return m_players[i];
        }
    }
    index = -1;
    return nullptr;
}

void TicTacToeGameManager::reset_game(){
    m_board->reset();
    for(auto p : m_players)
    {
        p->reset_score();
    }
    if(m_gameWindow!=nullptr){
        QString fpscore = QString::number(m_players[0]->get_score());
        QString spscore = QString::number(m_players[1]->get_score());
        m_gameWindow->update_scores_ui(fpscore,spscore);
        m_gameWindow->update_current_player_name_ui(QString::fromStdString(m_current_player->get_name()));
    }
}
