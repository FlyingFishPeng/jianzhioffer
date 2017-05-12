/*实现单线程中的单例模式需要完成的任务有两个：只能创建一个实例，实例可以被整个系统访问。
考虑通过将构造函数私有化完成第一个任务，并构造一个公有的静态成员函数来调用构造
函数，因为静态函数不与任何对象绑定；第二个任务通过将成员变量声明为static来实现。

需要注意的问题：可以使用new在堆上创建实例，方便管理生命周期，但是需要将析构函数
也私有化，并声明一个destroy函数，通过delete隐式调用析构函数来释放对象。另外，还
需要将拷贝构造函数和赋值运算符重载函数隐藏，防止在使用过程中拷贝或赋值对象实例，破坏
实例唯一性。
*/





#include <iostream>
using namespace std;

class Singleton{
private:
    Singleton() {}  //构造函数私有，实现只能创建一个对象
    Singleton (Singleton const&) {};            // 隐藏拷贝构造函数
    Singleton & operator=( Singleton const&) {};    // 隐藏赋值运算符
    ~Singleton();
    static Singleton* uInstance;
public:
    static Singleton* get(); //static公有成员函数独立于class对象之外，不必产生对象也可以使用它们
    void Destroy();
};

Singleton* Singleton::uInstance = NULL;  //初始化静态变量

Singleton::~Singleton(){
    if(uInstance == NULL){
        return;
    }
    cout<<"析构"<<endl;
}

void Singleton:: Destroy() {
    delete this;
    cout<<"删除完成！"<<endl;
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
