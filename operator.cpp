/* ʵ�ָ�ֵ��������� */

/*��Ҫע������⣺1������ֵΪ����
                  2������Ϊconst����Ϊ���ô��ݣ�������ÿ������캯�������ɲ���Ҫ�Ĳ���
                  3��ʵ����ֵǰ�������ͷ����ڴ棬�����ڴ�й¶
                  4���жϴ����ʵ���͵��ú�����ʵ���Ƿ���ͬ�������ͬ��ֱ�ӷ���*this�������и�ֵ����
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
    //�ж�this�ͼ�����ֵ�Ķ����Ƿ���ȣ���ȵĻ�����Ҫ��ֵ����,������*if(*this == str)�жϣ���Ϊ�����Ļ�==���߾�Ϊ����������==
    if(this == &str)
        return *this;
    delete []m_pData; //�ڸ�ֵǰҪ��ʵ�����ڴ��ͷţ���ֹ�ڴ�й¶
    m_pData = NULL;
    this.m_pData = new char[strlen(str.m_data) + 1];
    strcpy(m_pData, str.m_pData);
    return *this;
}
