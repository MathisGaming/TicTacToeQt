#include "IGameManager.h"
#include "Misc/Singleton.h"
#include <vector>
#include <string>

/**
 * @brief The TicTacToeGameManager class This is the core of the application.
 *        This class is responsible of handling data creating, modification, winning condition etc..
 *        It is the brain / core of the gameplay. Everything should pass through this singleton object.
 */
class TicTacToeGameManager : public IGameManager , public Singleton<TicTacToeGameManager>
{
    friend class Singleton<TicTacToeGameManager>;
    /// const variable used to define what is an empty case.
    static const int s_emptyPawn = 0;
public:
    /// const variable used to define what is the circle value.
    static const int s_circlePawn = 1;
    /// const variable used to define what is a cross value.
    static const int s_crossPawn = 2;

    /**
     * @brief play_once Play once and check for different condition to make sure
     *        it is a possible move as well as checking if someone won the current round.
     * @param x Position on the X axis.
     * @param y Position on the Y axis
     * @param button Pointer to the current button in the UI that has been selected so we can update the UI.
     * @return return -1 if something went wrong other return the symbol of the player.
     */
    int play_once(int x, int y,class QPushButton *button);

    /**
     * @brief update_score Update the score on both data (player score) as well as the ui.
     * @param winnerSymbol Takes the current symbol of the winner (last played symbol).
     * @return return true if it was updated.
     */
    bool update_score(int winnerSymbol);

    /**
     * @brief init Initialized the whole game. From player, board, score, data as well as UI.
     */
    void init();

    /**
     * @brief Reset the score and board to start a new round.
     */
    void reset_game();

    /**
     * @brief create_player Create a player based on its name and symbol.
     * @param name Name of the player
     * @param symbol Symbol (either cross or Circle) of the player.
     */
    void create_player(const std::string& name, const int &symbol);

    /**
     * @brief get_current_player
     * @return Return the currenty player.
     */
    class IPlayer* get_current_player(){ return m_current_player; }

    /**
     * @brief set_max_score Set the maximum score for th game.
     * @param max_score Maximum integer to be used. Depending on the widget limit
     */
    void set_max_score(const int& max_score){ m_maxScore = max_score;}

    /**
     * @brief get_max_score
     * @return return the max score.
     */
    int get_max_score() const {return m_maxScore;}

    /**
     * @brief find_player_from_symbol for the given symbol return the player and give its index as a reference parameter.
     * @param symbol symbol of the player
     * @param index reference to the index of the player (in parameter).
     * @return
     */
    class IPlayer* find_player_from_symbol(int symbol,int& index);

    /**
     * @brief get_players
     * @return return the players of the game.
     */
    std::vector<class IPlayer*> get_players() const{ return m_players; }

    void set_game_window(class GameWindow* gamewindow){ m_gameWindow = gamewindow; }

protected:
    /**
     * @brief check_vertical
     * @return return more than 0 if a player won verticaly.
     */
    int check_vertical();

    /**
     * @brief check_horizontal
     * @return return more than 0 if a player won horizontaly.
     */
    int check_horizontal();

    /**
     * @brief check_diagonal
     * @return return more than 0 if a player won on the diagonal.
     */
    int check_diagonal();

    /**
     * @brief get_next_player update the current player to be the next player.
     */
    void get_next_player();

    /**
     * @brief set_current_player_from_index Set the current player to be for the given index.
     * @param index index of the current player to be set.
     */
    void set_current_player_from_index(int index);

    /**
     * @brief check_player_score_limit
     * @return return true if one of the player reached the score limit. This should end the game.
     */
    bool check_player_score_limit();

    /**
     * @brief check_winner
     * @return Return more than 0 if a player won the current round.
     */
    int check_winner();
private:
    /**
    * @brief Constructor
    */
   TicTacToeGameManager();
   /**
    * @brief Destructor
    */
   ~TicTacToeGameManager();

   /// Game window class reference to.
   class GameWindow* m_gameWindow;

   /// Array of the players for the game.
   std::vector<class IPlayer*> m_players;
   /// Current selected player playing.
   class IPlayer* m_current_player;
   /// Board on which the players are playing.
   class TicTacToeBoard* m_board;
   /// Max score defined for the rule of the game.
   int m_maxScore;
   /// Index saved to keep track of the current player in the array.
   int m_index;
};
