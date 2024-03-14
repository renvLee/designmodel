
#include <iostream>
#include"designmodel.h"
using namespace std;

// 抽象汽车
class AbstractCar
{
public:
    virtual void ShowCarName() = 0;
};

// 具体产品的汽车继承-->抽象汽车类，并且对它方法进行重写操作
// 凯美瑞
class Camry :public AbstractCar
{
    virtual void ShowCarName()
    {
        cout << "Camry Car." << endl;
    }
};

// 迈腾
class Magotan :public AbstractCar
{
    virtual void ShowCarName()
    {
        cout << "Magotan Car." << endl;
    }
};

// 奥迪
class Audi :public AbstractCar
{
    virtual void ShowCarName()
    {
        cout << "Audi Car." << endl;
    }
};

// 奔驰
class Benz :public AbstractCar
{
    virtual void ShowCarName()
    {
        cout << "Benz Car." << endl;
    }
};

// 通过传递参数来确定需要生成那汽车
// 汽车工厂
class CarFactory
{
public:
    static AbstractCar* CreateCarFunc(string cname)
    {
        if (cname == "Camry")
            // 具体生产细节......
            return new Camry;
        else if (cname == "Magotan")
            // 具体生产细节......
            return new Magotan;
        else if (cname == "Audi")
            // 具体生产细节......
            return new Audi;
        else if (cname == "Benz")
            // 具体生产细节......
            return new Benz;
        else
            return nullptr;           

    }   
};


int testSFactoryModel()
{
    // 创建工厂
    CarFactory* fty = new CarFactory;

    // 创建汽车
    AbstractCar* car;

    // 指定工厂需要创建的汽车
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

