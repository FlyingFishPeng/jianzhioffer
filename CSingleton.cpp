//���䵥��ģʽ

class CSingleton
{
private:
    CSingleton() {}    //���캯������������˽�л�
    ~Singleton();
    CSingleton (CSingleton const&) {};            // ���ؿ������캯��
    CSingleton & operator=(CSingleton const&) {};    // ���ظ�ֵ�����
    static CSingleton* m_Instance;
public:
    static CSingleton* instance()  //��̬��Ա�����������ù��캯��
    {
        if (m_Instance == NULL)
            m_Instance = new singleton();
        return m_Instance;
    }

    void Destroy()   //��ֹ�ڴ�й¶
    {
        delete this;
        cout<<"ɾ����ɣ�"<<endl;
    }
};



/*
    ����������ʵ�ַ����������������

    ����������˼�壬�����򲻵��ѾͲ���ȥʵ�����࣬Ҳ����˵�ڵ�һ���õ���ʵ����ʱ��Ż�ȥʵ�����������ϱߵľ��䷽������Ϊ����ʵ��.

    ���������˿϶�Ҫ������ʳ�������ڵ����ඨ���ʱ��ͽ���ʵ������

�ص���ѡ��

    ����Ҫ�����߳�ͬ���������ڷ������Ƚϴ󣬻��߿��ܷ��ʵ��̱߳Ƚ϶�ʱ�����ö���ʵ�֣�����ʵ�ָ��õ����ܡ������Կռ任ʱ�䡣

    �ڷ�������Сʱ����������ʵ�֡�������ʱ�任�ռ䡣
---------------------------------------------------------------------------------------
    �̰߳�ȫ������ʵ��:

    �̲߳���ȫ����ô���أ���ֱ�۵ķ�����������

    ����1�������ľ�������ʵ�֣�
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
    ����2���ڲ���̬����������ʵ�֡�

    �˷���Ҳ������ʵ�֣���instance�����ﶨ��һ����̬��ʵ����Ҳ���Ա�֤ӵ��Ψһʵ�����ڷ���ʱֻ��Ҫ������ָ��Ϳ����ˡ�

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
   ����ģʽ������������̰߳�ȫ�ģ�����Ҫ����
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
