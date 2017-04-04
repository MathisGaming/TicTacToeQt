template <class T>
class Singleton
{
public:
    static T* instance() {
        if (m_instance == nullptr) {
            m_instance = new T();
        }
        return m_instance;
    }

    static void destroy() {
        if (m_instance != nullptr) {
            delete m_instance;
            m_instance = nullptr;
        }
    }
protected:
    Singleton() {}
    ~Singleton() { }
private:
    static T* m_instance;
};

template<class T>
T* Singleton<T>::m_instance = 0;
