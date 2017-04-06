#include "IScore.h"

/**
 * @brief The TicTacToeScore class Implement the way a score is calculate for a TicTacToe game.
 *        More information about this design can be found looking at the Strategy Pattern.
 */
class TicTacToeScore : public IScore
{
public:
    /**
     * @brief Constructor
     */
    TicTacToeScore(): m_score(0){}

    /**
     * @brief Destructor
     */
    ~TicTacToeScore(){}

    /**
     * @brief init Initialize the score.
     */
    void init() {m_score = 0;}

    /**
     * @brief update Update the score.
     */
    void update(){ update(1);}

    /**
     * @brief reset Reset the score.
     */
    void reset() {m_score = 0;}

    /**
     * @brief get Get the score
     * @return  Return the score.
     */
    int get() const {return m_score;}
private:

    /**
     * @brief update Update the score following the way it is designed for tic tac toe.
     * @param value Value to increment the score with.
     */
    void update(int value)
    {
        m_score += value;
    }

    // note : maybe we could have different way to store the score.
    // for instance we could have a way to score +3 on diagonales
    // or maybe lose a point when doing the same thing.
    // so here we could have rules about the score.
    /// Score.
    int m_score;
};
