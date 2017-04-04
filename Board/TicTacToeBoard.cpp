#include "TicTacToeBoard.h"

TicTacToeBoard::TicTacToeBoard()
{
    m_update_count = 0;
}

TicTacToeBoard::~TicTacToeBoard()
{
    for(int i = 0; i < HLENGTH; ++i){
        for(int j = 0; j < HLENGTH; ++j){
            if(m_cases[i][j] != nullptr){
                delete m_cases[i][j];
                m_cases[i][j] = nullptr;
            }
        }
    }
}

void TicTacToeBoard::init()
{
    m_update_count = 0;
    for(int i = 0; i < HLENGTH; ++i){
        for(int j = 0; j < HLENGTH; ++j)
        {
            if(m_cases[i][j]==0 || m_cases[i][j] != nullptr)
                m_cases[i][j] = new Case(i,j);
            else
                m_cases[i][j]->reset();
        }
    }
}

void TicTacToeBoard::reset()
{
    for(int i = 0; i < HLENGTH; ++i){
        for(int j = 0; j < HLENGTH; ++j){
            if(m_cases[i][j] != nullptr){
                m_cases[i][j]->reset();
            }
        }
    }
}

void TicTacToeBoard::play_once(int x, int y, int value)
{
    if(x < 0 || x >= HLENGTH){
        // throw error saying the position is out of bound horizontaly.
        return;
    }
    if(y < 0 || y >= VLENGTH){
        // throw error saying the position is out of bound verticaly
        return;
    }

    if(m_cases[x][y] ==nullptr){
        // throw error : case was not initialized.
        return;
    }

    Case* c = m_cases[x][y];

    if(!c->bIsUsed){
        c->bIsUsed = true;
        c->value = value;
        m_update_count++;
    }
    else{
        // throw error, for some reason the case was already set
        // and we don't want to override it.
    }
}
