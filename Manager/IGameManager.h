#include "IManager.h"
#include <string>
#include <vector>

/**
 * @brief The IGameManager class Interface created to implement a GameManager.
 */
class IGameManager : public IManager
{
public:
    /**
     * @brief init Initialize the interface
     */
    virtual void init() = 0;
    /**
     * @brief create_player Create a player and will store it in a container.
     * @param name Name of the player.
     * @param symbol Symbol / value used by the player to set a case in the board.
     */
    virtual void create_player(const std::string& name, const int &symbol) = 0;
};
