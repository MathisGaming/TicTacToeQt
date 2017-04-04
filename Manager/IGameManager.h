#include "IManager.h"
#include <string>
#include <vector>

class IGameManager : public IManager
{
public:
    virtual void init() = 0;
    virtual void create_player(const std::string& name, const int &symbol) = 0;
    virtual void create_players(const std::vector<std::string>& names) = 0;
};
