//经典单例模式

class CSingleton
{
private:
    CSingleton() {}    //构造函数和析构函数私有化
    ~Singleton();
    CSingleton (CSingleton const&) {};            // 隐藏拷贝构造函数
    CSingleton & operator=(CSingleton const&) {};    // 隐藏赋值运算符
    static CSingleton* m_Instance;
public:
    static CSingleton* instance()  //静态成员函数用来调用构造函数
    {
        if (m_Instance == NULL)
            m_Instance = new singleton();
        return m_Instance;
    }

    void Destroy()   //防止内存泄露
    {
        delete this;
        cout<<"删除完成！"<<endl;
    }
};



/*
    单例有两种实现方法：懒汉与饿汉。

    懒汉：故名思义，不到万不得已就不会去实例化类，也就是说在第一次用到类实例的时候才会去实例化，所以上边的经典方法被归为懒汉实现.

    饿汉：饿了肯定要饥不择食。所以在单例类定义的时候就进行实例化。

特点与选择：

    由于要进行线程同步，所以在访问量比较大，或者可能访问的线程比较多时，采用饿汉实现，可以实现更好的性能。这是以空间换时间。

    在访问量较小时，采用懒汉实现。这是以时间换空间。
---------------------------------------------------------------------------------------
    线程安全的懒汉实现:

    线程不安全，怎么办呢？最直观的方法：加锁。

    方法1：加锁的经典懒汉实现：
*/

class singleton
{
protected:
    singleton()
    {
        pthread_mutex_init(&mutex);
    }
private:
    static singleton* p;
public:
    static pthread_mutex_t mutex;
    static singleton* initance();
};

pthread_mutex_t singleton::mutex;
singleton* singleton::p = NULL;
singleton* singleton::initance()
{
    if (p == NULL)
    {
        pthread_mutex_lock(&mutex);
        if (p == NULL)
            p = new singleton();
        pthread_mutex_unlock(&mutex);
    }
    return p;
}

/*
    方法2：内部静态变量的懒汉实现。

    此方法也很容易实现，在instance函数里定义一个静态的实例，也可以保证拥有唯一实例，在返回时只需要返回其指针就可以了。

*/
class singleton
{
protected:
    singleton()
    {
        pthread_mutex_init(&mutex);
    }
public:
    static pthread_mutex_t mutex;
    static singleton* initance();
    int a;
};
pthread_mutex_t singleton::mutex;
singleton* singleton::initance()
{
    pthread_mutex_lock(&mutex);
    static singleton obj;
    pthread_mutex_unlock(&mutex);
    return &obj;
}

/*
   饿汉模式，它本身就是线程安全的，不需要加锁
*/
class singleton
{
protected:
singleton()  {}
private:
    static singleton* p;
public:
    static singleton* initance();
};
singleton* singleton::p = new singleton;
singleton* singleton::initance()
{
    return p;
}
