#include "IBoard.h"

#define HLENGTH 3
#define VLENGTH 3

class Case
{
public:
    int x,y;
    int value;
    bool bIsUsed;
    Case() : x(0), y(0), bIsUsed(false), value(0) {}
    Case(int _x, int _y) : x(_x), y(_y), bIsUsed(false), value(0) {}
    ~Case() {}
    void reset(){
        bIsUsed = false;
        value = 0;
    }
};

/*
 * @brief TicTacToeBoard class will be holding the values for each
 *        each case of the board on a 3x3 for tictactoe.
 */
class TicTacToeBoard : public IBoard
{
public:
    TicTacToeBoard();
    ~TicTacToeBoard();

    void init();
    void reset();
    void play_once(int x, int y, int value);
    auto get_cases() const { return m_cases; }
    bool is_full() const {return m_update_count == (HLENGTH*VLENGTH);}
private:
    Case* m_cases[HLENGTH][VLENGTH];
    int m_update_count;
};
