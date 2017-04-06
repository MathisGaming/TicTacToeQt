/**
 * @brief The IBoard class interface is used as a template to create boards for board games.
 */
class IBoard
{
public:
    /**
     * @brief pure virtual method used to template initialization of the game board.
     */
    virtual void init() = 0;

    /**
     * @brief pure virtal method used to template the reset the game board method(cases, pawns, values etc..).
     */
    virtual void reset() = 0;
};
