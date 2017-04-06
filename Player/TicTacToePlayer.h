#include "IPlayer.h"
#include "Score/TicTacToeScore.h"

/**
 * @brief The TicTacToePlayer class
 */
class TicTacToePlayer : public IPlayer
{
public:
    /**
     * @brief TicTacToePlayer Default constructor
     */
    TicTacToePlayer() : m_name(""), m_symbol(-1) { m_score.init();}
    /**
     * @brief TicTacToePlayer Parametrized constructor
     * @param name Name of the player
     * @param symbol Symbol of the player
     */
    TicTacToePlayer(const std::string& name, int symbol) : m_name(name), m_symbol(symbol) { m_score.init();}

    /**
      * @brief Destructor
      */
    ~TicTacToePlayer();

    /**
     * @brief set_name Set the name of the player
     * @param name of the player
     */
    void set_name(const std::string& name){
        m_name = name;
    }
    /**
     * @brief get_name Get the name of the player
     * @return the name of the player.
     */
    std::string get_name() const{
        return m_name;
    }
    /**
     * @brief get_score Get the score of the player
     * @return return the score of the player
     */
    int get_score() const
    {
        return m_score.get();
    }
    /**
     * @brief get_symbol Get the symbol of the player
     * @return return the symbol of the player
     */
    int get_symbol() const
    {
        return m_symbol;
    }
    /**
     * @brief update_score Update the score of the player
     */
    void update_score(){
        m_score.update();
    }
    /**
     * @brief reset_score Reset the score of the player.
     */
    void reset_score()
    {
        m_score.reset();
    }

protected:
    /// name of the player
    std::string m_name;
    /// score of the player
    TicTacToeScore m_score;
    /// symbol of the player
    int m_symbol;
};
