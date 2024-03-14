
#include <iostream>
using namespace std;

// Subject��Ŀ��ӿ�
class Person {
public:
	virtual void RentHouse() = 0;
};

//realSubject�������Ŀ�����
class Amy :public Person {
public:
	void RentHouse() {
		cout << "Amy��Ҫ�ⷿ��һ�׺���������" << endl;
	}
};

//realSubject�������Ŀ�����
class Sunny :public Person {
public:
	void RentHouse() {
		cout << "Sunny��Ҫ�ⷿ��һ�׺���������" << endl;
	}
};

// Proxy���������
class Proxy :public Person {
public:
	Proxy(Person* person) :objPerson(person) {
		cout << "����Proxy���������Ĺ��캯����" << endl;
	}
	void RentHouse() {
		objPerson->RentHouse();

		cout << "�����������Proxy�н鹫˾�������Һ���������" << endl;
	}

private:
	Person* objPerson;
};

int testProxyPattern()
{
	Person* amy = new Amy;
	Person* proxyamy1 = new Proxy(amy);
	proxyamy1->RentHouse();
	cout << endl;

	Person* sunny = new Sunny;
	Person* proxyamy2 = new Proxy(sunny);
	proxyamy2->RentHouse();
	cout << endl;

	return 0;
}


