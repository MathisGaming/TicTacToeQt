#include "IPlayer.h"
#include "Score/TicTacToeScore.h"

class TicTacToePlayer : public IPlayer
{
public:
    TicTacToePlayer() : m_name(""), m_symbol(-1) { m_score.init();}
    TicTacToePlayer(const std::string& name, int symbol) : m_name(name), m_symbol(symbol) { m_score.init();}

    ~TicTacToePlayer();

    void set_name(const std::string& name){
        m_name = name;
    }
    std::string get_name() const{
        return m_name;
    }

    int get_score() const
    {
        return m_score.get();
    }

    int get_symbol() const
    {
        return m_symbol;
    }

    void update_score(){
        m_score.update();
    }

    void reset_score()
    {
        m_score.reset();
    }

protected:
    std::string m_name;
    TicTacToeScore m_score;
    int m_symbol;
};
