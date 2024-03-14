// ����ģ��
/*
#include <iostream>
using namespace std;

class TestA {
public: // Ψһpublic�ӿ�����Ϊ��̬���û�����Ҫ��������ֱ���������з���
	static TestA* GetInstnace() {
		return data;
	}

private: // ��ҪĿ�ģ������û����Ѵ������󣬱���ѹ��캯���������˽�л�
	TestA()
	{
		data = new TestA;
	}

private:
	static TestA* data;
};

TestA* TestA::data = NULL; // TestA����ⲿ��ʼ������

int main()
{
	TestA::GetInstnace();

	return 0;
}
*/

#include <iostream>
using namespace std;
// ����ʽ
class SingleTonlazy {
private:
	SingleTonlazy() {
		cout << "ִ�в���������ʽ���캯��������." << endl;
	}

public:
	static SingleTonlazy* GetInstance() {
		if (pSingletontest == NULL)
		{
			pSingletontest = new SingleTonlazy;
		}
		return pSingletontest;
	}

private:
	static SingleTonlazy* pSingletontest;
};
SingleTonlazy* SingleTonlazy::pSingletontest = NULL;


// ����ʽ
class Singletonhungry {
private:
	Singletonhungry() {
		cout << "ִ�в���������ʽ���캯��������." << endl;
	}

public:
	static Singletonhungry* GetInstance() {
		return pSingletontest;
	}

private:
	static Singletonhungry* pSingletontest;
};
// Singletonhungry���ⲿ��ʼ����ʱ��ֱ�Ӵ�������
Singletonhungry* Singletonhungry::pSingletontest = new Singletonhungry;

void TestFunction1() {
	SingleTonlazy* pobj1 = SingleTonlazy::GetInstance();
	SingleTonlazy* pobj2 = SingleTonlazy::GetInstance();

	if (pobj1 == pobj2)
	{
		cout << "pobj1��pobj2����ָ��ָ��ͬһ���ڴ浥Ԫ����Ϊ����ģʽ." << endl;
	}
	else
	{
		cout << "pobj1��pobj2����ָ��ָ����ͬһ���ڴ浥Ԫ�����ǵ���ģʽ." << endl;
	}
}

void TestFunction2() {
	Singletonhungry* pobj1 = Singletonhungry::GetInstance();
	Singletonhungry* pobj2 = Singletonhungry::GetInstance();

	if (pobj1 == pobj2)
	{
		cout << "pobj1��pobj2����ָ��ָ��ͬһ���ڴ浥Ԫ����Ϊ����ģʽ." << endl;
	}
	else
	{
		cout << "pobj1��pobj2����ָ��ָ����ͬһ���ڴ浥Ԫ�����ǵ���ģʽ." << endl;
	}
}


int testSingletonModel()
{
	cout << "main()������ʼִ��.\n" << endl;

	TestFunction1();
	TestFunction2();

	cout << "\nmain()��������ִ��.\n" << endl;

	return 0;
}
