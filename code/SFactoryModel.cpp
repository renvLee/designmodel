
#include <iostream>
#include"designmodel.h"
using namespace std;

// ��������
class AbstractCar
{
public:
    virtual void ShowCarName() = 0;
};

// �����Ʒ�������̳�-->���������࣬���Ҷ�������������д����
// ������
class Camry :public AbstractCar
{
    virtual void ShowCarName()
    {
        cout << "Camry Car." << endl;
    }
};

// ����
class Magotan :public AbstractCar
{
    virtual void ShowCarName()
    {
        cout << "Magotan Car." << endl;
    }
};

// �µ�
class Audi :public AbstractCar
{
    virtual void ShowCarName()
    {
        cout << "Audi Car." << endl;
    }
};

// ����
class Benz :public AbstractCar
{
    virtual void ShowCarName()
    {
        cout << "Benz Car." << endl;
    }
};

// ͨ�����ݲ�����ȷ����Ҫ����������
// ��������
class CarFactory
{
public:
    static AbstractCar* CreateCarFunc(string cname)
    {
        if (cname == "Camry")
            // ��������ϸ��......
            return new Camry;
        else if (cname == "Magotan")
            // ��������ϸ��......
            return new Magotan;
        else if (cname == "Audi")
            // ��������ϸ��......
            return new Audi;
        else if (cname == "Benz")
            // ��������ϸ��......
            return new Benz;
        else
            return nullptr;           

    }   
};


int testSFactoryModel()
{
    // ��������
    CarFactory* fty = new CarFactory;

    // ��������
    AbstractCar* car;

    // ָ��������Ҫ����������
    car = fty->CreateCarFunc("Benz");
    car->ShowCarName();
    delete car;

    car = fty->CreateCarFunc("Camry");
    car->ShowCarName();
    delete car;

    car = fty->CreateCarFunc("Audi");
    car->ShowCarName();
    delete car;

    car = fty->CreateCarFunc("Magotan");
    car->ShowCarName();
    delete car;

    return 0;
}

