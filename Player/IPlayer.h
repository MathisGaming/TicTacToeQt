#include <string>

/**
 * @brief The IPlayer interface used as a template to implement players.
 */
class IPlayer
{
public:
    virtual std::string get_name() const = 0;
    virtual void set_name(const std::string& name) = 0;
    virtual int get_score() const = 0;
    virtual void update_score() = 0;
    virtual void reset_score() = 0;
    virtual int get_symbol() const = 0;
};
