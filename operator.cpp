/* 实现赋值运算符函数 */

/*需要注意的问题：1）返回值为引用
                  2）参数为const，且为引用传递，避免调用拷贝构造函数完成造成不必要的操作
                  3）实例赋值前必须先释放其内存，避免内存泄露
                  4）判断传入的实例和调用函数的实例是否相同，如果相同则直接返回*this，不进行赋值操作
*/

/*
class CMyString
{
  public:
      CMyString(char *pData = NULL);
      CMyString(const CMyString &str);
      ~CMyString(void)
  private:
    char * m_pData;
}
*/

CMyString & CMyString::operator =(const CMyString &str)
{
    //判断this和即将赋值的对象是否相等，相等的话不需要赋值操作,不能用*if(*this == str)判断，因为这样的话==两边均为对象，需重载==
    if(this == &str)
        return *this;
    delete []m_pData; //在赋值前要将实例的内存释放，防止内存泄露
    m_pData = NULL;
    this.m_pData = new char[strlen(str.m_data) + 1];
    strcpy(m_pData, str.m_pData);
    return *this;
}
