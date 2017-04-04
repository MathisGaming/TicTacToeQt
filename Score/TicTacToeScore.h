#include "IScore.h"

class TicTacToeScore : public IScore
{
public:
    TicTacToeScore(): m_score(0){}
    ~TicTacToeScore(){}

    void init() {m_score = 0;}
    void update(){ update(1);}
    void reset() {m_score = 0;}
    int get() const {return m_score;}
private:

    void update(int value)
    {
        m_score += value;
    }

    // note : maybe we could have different way to store the score.
    // for instance we could have a way to score +3 on diagonales
    // or maybe lose a point when doing the same thing.
    // so here we could have rules about the score.
    int m_score;
};
