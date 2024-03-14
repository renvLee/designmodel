
#include <iostream>
#include <string>
using namespace std;

class systemtest1
{
public:
    void MethodFunc1()
    {
        cout << "MethodFunc1" << endl;
    }
};

class systemtest2
{
public:
    void MethodFunc2()
    {
        cout << "MethodFunc2" << endl;
    }
};

class systemtest3
{
public:
    void MethodFunc3()
    {
        cout << "MethodFunc3" << endl;
    }
};

class systemtest4
{
public:
    void MethodFunc4()
    {
        cout << "MethodFunc4" << endl;
    }
};

class systemtest5
{
public:
    void MethodFunc5()
    {
        cout << "MethodFunc5" << endl;
    }
};

class systemtest6
{
public:
    void MethodFunc6()
    {
        cout << "MethodFunc6" << endl;
    }
};

// ����࣬��Ҫ�������е���ϵͳ�ķ��������ԣ�������ʹĿ��Ϊ����������
class Facade {
public:
    Facade() {
        s1 = new systemtest1();
        s2 = new systemtest2();
        s3 = new systemtest3();
        s4 = new systemtest4();
        s5 = new systemtest5();
        s6 = new systemtest6();
    }
    void MethodFunc1() {
        s1->MethodFunc1();
        s2->MethodFunc2();
        s3->MethodFunc3();
    }
    void MethodFunc2() {
        s4->MethodFunc4();
        s5->MethodFunc5();
        s6->MethodFunc6();
    }


private:
    systemtest1* s1;
    systemtest2* s2;
    systemtest3* s3;
    systemtest4* s4;
    systemtest5* s5;
    systemtest6* s6;


};

int testFacade()
{
    Facade* fobj = new Facade(); // ����Facade���ܣ��ͻ��˿��Ը�����֪���⼸��ϵͳ��Ĵ���
    fobj->MethodFunc1();
    fobj->MethodFunc2();
    
    return 0;
}


