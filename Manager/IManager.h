/**
 * @brief The IManager class Base interface class to template a manager object.
 * Manager object should be responsible of handling actions between data and ui.
 */
class IManager
{
public:
    /**
     * @brief init Initialize the interface.
     */
    virtual void init() = 0;
};
