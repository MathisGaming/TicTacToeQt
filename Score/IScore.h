/**
 * @brief The IScore class Interface used to template what a score will be.
 */
class IScore
{
public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void reset() = 0;
    virtual int get() const = 0;
};
