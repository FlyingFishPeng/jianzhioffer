/*ʵ�ֵ��߳��еĵ���ģʽ��Ҫ��ɵ�������������ֻ�ܴ���һ��ʵ����ʵ�����Ա�����ϵͳ���ʡ�
����ͨ�������캯��˽�л���ɵ�һ�����񣬲�����һ�����еľ�̬��Ա���������ù���
��������Ϊ��̬���������κζ���󶨣��ڶ�������ͨ������Ա��������Ϊstatic��ʵ�֡�

��Ҫע������⣺����ʹ��new�ڶ��ϴ���ʵ������������������ڣ�������Ҫ����������
Ҳ˽�л���������һ��destroy������ͨ��delete��ʽ���������������ͷŶ������⣬��
��Ҫ���������캯���͸�ֵ��������غ������أ���ֹ��ʹ�ù����п�����ֵ����ʵ�����ƻ�
ʵ��Ψһ�ԡ�
*/





#include <iostream>
using namespace std;

class Singleton{
private:
    Singleton() {}  //���캯��˽�У�ʵ��ֻ�ܴ���һ������
    Singleton (Singleton const&) {};            // ���ؿ������캯��
    Singleton & operator=( Singleton const&) {};    // ���ظ�ֵ�����
    ~Singleton();
    static Singleton* uInstance;
public:
    static Singleton* get(); //static���г�Ա����������class����֮�⣬���ز�������Ҳ����ʹ������
    void Destroy();
};

Singleton* Singleton::uInstance = NULL;  //��ʼ����̬����

Singleton::~Singleton(){
    if(uInstance == NULL){
        return;
    }
    cout<<"����"<<endl;
}

void Singleton:: Destroy() {
    delete this;
    cout<<"ɾ����ɣ�"<<endl;
}

Singleton* Singleton::get(){
    if(uInstance == NULL){
        uInstance = new Singleton;
    }
    return uInstance;
}

int main()
{
    Singleton * instance=Singleton::get();
    instance->Destroy();
    return 0;
}
