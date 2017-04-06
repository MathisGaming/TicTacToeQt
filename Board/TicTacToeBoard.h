#include "IBoard.h"

#define HLENGTH 3
#define VLENGTH 3

class Case
{
public:
    /// x and y values for the position of the case.
    int x,y;
    /// value of the case (1 for first player 2 for the second player for example).
    int value;
    /// flag to say if the case is used by something else than empty.
    bool bIsUsed;
    /**
     * @brief Default constructor
     */
    Case() : x(0), y(0), bIsUsed(false), value(0) {}
    /**
     * @brief Parametrized constructor
     * @param _x x position on the board (related to the 2D array position).
     * @param _y y position on the board (related to the 2D array position).
     */
    Case(int _x, int _y) : x(_x), y(_y), bIsUsed(false), value(0) {}

    /**
      * @brief Destructor
      */
    ~Case() {}

    /**
     * @brief reset the case values to default (empty case) but keeps the x,y values.
     */
    void reset(){
        bIsUsed = false;
        value = 0;
    }
};

/**
 * @brief TicTacToeBoard class will be holding the values for each
 *        each case of the board on a 3x3 for tictactoe.
 **/
class TicTacToeBoard : public IBoard
{
public:
    /**
     * @brief default constructor
     */
    TicTacToeBoard();
    /**
      * @brief destructor
      */
    ~TicTacToeBoard();

    /**
     * @brief init Initialize the board.
     */
    void init();

    /**
     * @brief reset Reset the board
     */
    void reset();

    /**
     * @brief play_once Select the given case and give the value to set it played by a player.
     * @param x X Coordinate to be played
     * @param y Y Coordinate to be played
     * @param value Value of the player (also called symbol).
     */
    void play_once(int x, int y, int value);

    /**
     * @brief get_cases return access to the cases of the board. The GameManager will need it to check winning conditions.
     */
    auto get_cases() const { return m_cases; }

    /**
     * @brief is_full Check if the board has used all its cases.
     * @return Return true if the board is fully used
     */
    bool is_full() const {return m_update_count == (HLENGTH*VLENGTH);}
private:
    /// All the cases for the board, here a 3x3 for tic tac toe.
    Case* m_cases[HLENGTH][VLENGTH];
    /// Simple count updated everytime a player plays a case.
    int m_update_count;
};
