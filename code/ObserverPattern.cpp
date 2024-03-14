
#include <iostream>
#include <list>
using namespace std;

class Observer { // ����۲��ߵĽӿڣ�����۲��ߣ�
public:
    virtual void Update(int) = 0;
};

class Subject { // Ŀ����󣨳���֪ͨ�ߣ�
public:
    virtual void Attach(Observer*) = 0;
    virtual void Detach(Observer*) = 0;
    virtual void Notify() = 0;
};

// �۲��ߵľ���ʵ�ֶ���
class ConreteObserver1 :public Observer {
public:
    ConreteObserver1(Subject* psubject) :mpsubject(psubject) {}

    // Upadte()���������·�����
    void Update(int values) {
        cout << "ConreteObserver1��ȡ���£���״̬Ϊ��" << values << endl;
    }

private:
    Subject* mpsubject;
};

class ConreteObserver2 :public Observer {
public:
    ConreteObserver2(Subject* psubject) :mpsubject(psubject) {}

    // Upadte()���������·�����
    void Update(int values) {
        cout << "ConreteObserver2��ȡ���£���״̬Ϊ��" << values << endl;
    }

private:
    Subject* mpsubject;
};


// �����Ŀ��ʵ�ֶ���
class ConceteSubject :public Subject {
public:
    void Attach(Observer* pobserver) {
        mobserverlist.push_back(pobserver);
    }
    void Detach(Observer* pobserver) {
        mobserverlist.remove(pobserver);
    }
    void Notify() {
        std::list<Observer*>::iterator it = mobserverlist.begin();
        while (it != mobserverlist.end()) {
            (*it)->Update(mstate);
            ++it;
        }
    }

    void SetState(int state) { // ����״̬
        mstate = state;
    }

private:
    int mstate;
    std::list<Observer*>mobserverlist;
};


int testObserverPattern()
{
    // ����Ŀ�����
    ConceteSubject* psubject = new ConceteSubject();

    // �����۲���
    Observer* pobserver1 = new ConreteObserver1(psubject);
    Observer* pobserver2 = new ConreteObserver2(psubject);

    // ����״̬
    psubject->SetState(666);

    // ע��۲��߽ӿ�
    psubject->Attach(pobserver1);
    psubject->Attach(pobserver2);
    psubject->Notify();

    // ע���۲���
    psubject->Detach(pobserver1);
    cout << endl;

    psubject->SetState(888);
    psubject->Notify();

    delete pobserver1;
    delete pobserver2;
    delete psubject;


    return 0;
}



