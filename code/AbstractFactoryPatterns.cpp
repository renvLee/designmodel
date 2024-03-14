#include <iostream>
using namespace std;

// ��������
class AbstractWatermelon {
public:
	virtual void PrintName() = 0;
	AbstractWatermelon() {
		cout << "�������Ϲ��캯��." << endl;
	}
	~AbstractWatermelon() {
		cout << "����������������." << endl;
	}
};

// �������
class AbstractOrange {
public:
	virtual void PrintName() = 0;
	AbstractOrange() {
		cout << "������ӹ��캯��." << endl;
	}
	~AbstractOrange() {
		cout << "���������������." << endl;
	}
};

// �й�����
class ChinaWatermelon :public AbstractWatermelon {
public:
	virtual void PrintName() {
		cout << "�й�������ó�." << endl;
	}
	ChinaWatermelon() {
		cout << "�й����Ϲ��캯��." << endl;
	}
	~ChinaWatermelon() {
		cout << "�й�������������." << endl;
	}
};

// �й�����
class ChinaOrange :public AbstractOrange
{
public:
	virtual void PrintName() {
		cout << "�й����������.\n" << endl;
	}
	ChinaOrange() {
		cout << "�й����ӹ��캯��." << endl;
	}
	~ChinaOrange() {
		cout << "�й�������������" << endl;
	}
};

// �ձ�����
class JapanWatermelon :public AbstractWatermelon {
public:
	virtual void PrintName() {
		cout << "�ձ����ϣ�������ǧ��ǰ����ֲ����." << endl;
	}
	JapanWatermelon() {
		cout << "�ձ����Ϲ��캯��." << endl;
	}
	~JapanWatermelon() {
		cout << "�ձ�������������." << endl;
	}
};

// �ձ�����
class JapanOrange :public AbstractOrange {
public:
	virtual void PrintName() {
		cout << "�ձ����ӹ���������ã���Ӧ�������Ľ���." << endl;
	}
	JapanOrange() {
		cout << "�ձ����ӹ��캯��." << endl;
	}
	~JapanOrange() {
		cout << "�ձ�������������." << endl;
	}
};


// ���󹤳� ��Ҫ��Բ�Ʒת��
class AbstrctFactory {
public:
	virtual AbstractWatermelon* CreateWatermelon() = 0;
	virtual AbstractOrange* CreateOrange() = 0;

	AbstrctFactory() {
		cout << "���󹤳����캯��." << endl;
	}
	~AbstrctFactory() {
		cout << "���󹤳���������." << endl;
	}
};

// �й�����
class ChinaFactory :public AbstrctFactory
{
public:
	virtual AbstractWatermelon* CreateWatermelon() {
		return new ChinaWatermelon;
	}
	virtual AbstractOrange* CreateOrange() {
		return new ChinaOrange;
	}
	ChinaFactory() {
		cout << "�й��������캯��." << endl;
	}
	~ChinaFactory() {
		cout << "�й�������������." << endl;
	}


};

// �ձ�����
class JapanFactory :public AbstrctFactory {
public:
	virtual AbstractWatermelon* CreateWatermelon() {
		return new JapanWatermelon;
	}
	virtual AbstractOrange* CreateOrange() {
		return new JapanOrange;
	}
	JapanFactory() {
		cout << "�ձ��������캯��." << endl;
	}
	~JapanFactory() {
		cout << "�ձ�������������." << endl;
	}
};


int testAbstractFactoryPatterns()
{
	cout << "****************************************************************************" << endl;
	AbstrctFactory* cfactory = new ChinaFactory;
	AbstractWatermelon* cwatermelon = cfactory->CreateWatermelon();
	AbstractOrange* corange = cfactory->CreateOrange();
	cwatermelon->PrintName();
	corange->PrintName();

	delete corange; corange = nullptr;
	delete cwatermelon; cwatermelon = nullptr;
	delete cfactory; cfactory = nullptr;
	cout << "****************************************************************************" << endl;


	cout << "\n\n****************************************************************************" << endl;
	AbstrctFactory* efactory = new JapanFactory;
	AbstractWatermelon* ewatermelon = efactory->CreateWatermelon();
	AbstractOrange* eorange = efactory->CreateOrange();
	ewatermelon->PrintName();
	eorange->PrintName();

	delete eorange; eorange = nullptr;
	delete ewatermelon; ewatermelon = nullptr;
	delete efactory; efactory = nullptr;
	cout << "****************************************************************************" << endl;

	return 0;
}

