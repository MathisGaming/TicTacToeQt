/**
 * @brief The Singleton class
 */
template <class T> class Singleton
{
public:
    /**
     * @brief Instance Singleton instance to have only one instance of the object. Call myClass::instance().
     * @return
     */
    static T* instance() {
        if (m_instance == nullptr) {
            m_instance = new T();
        }
        return m_instance;
    }

    /**
     * @brief destroy Delete the current singelton.
     */
    static void destroy() {
        if (m_instance != nullptr) {
            delete m_instance;
            m_instance = nullptr;
        }
    }
protected:
    /**
    * @brief Default Constructor
    */
    Singleton() {}
    /**
    * @brief Destructor
    */
    ~Singleton() { }
private:
    /// Unique instance of the class.
    static T* m_instance;
};

template<class T>
T* Singleton<T>::m_instance = 0;
