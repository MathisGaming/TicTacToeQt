#include "IGameManager.h"
#include "Misc/Singleton.h"
#include <vector>
#include <string>

class TicTacToeGameManager : public IGameManager , public Singleton<TicTacToeGameManager>
{
    friend class Singleton<TicTacToeGameManager>;

public:
    int play_once(int x, int y,class QPushButton *button);
    bool update_score(int winnerSymbol);
    void init();
    void reset_game();

    void create_player(const std::string& name, const int &symbol);
    void create_players(const std::vector<std::string>& names);

    class IPlayer* get_current_player(){ return m_current_player; }

    void set_max_score(const int& max_score){ m_maxScore = max_score;}
    int get_max_score() const {return m_maxScore;}


    class IPlayer* find_player_from_symbol(int symbol,int& index);
    std::vector<class IPlayer*> get_players() const{ return m_players; }

    void set_game_window(class GameWindow* gamewindow){ m_gameWindow = gamewindow; }


protected:
    int check_vertical();
    int check_horizontal();
    int check_diagonal();
    void get_next_player();
    void set_current_player_from_index(int index);
    bool check_player_score_limit();
    int check_winner();
private:
   TicTacToeGameManager();
   ~TicTacToeGameManager();

   class GameWindow* m_gameWindow;

   std::vector<class IPlayer*> m_players;
   class IPlayer* m_current_player;
   class TicTacToeBoard* m_board;
   int m_maxScore;
   int m_index;
};
