
#include <iostream>
#include <vector>
using namespace std;

// ����Ԫ�أ����������ʵ��accept()����
class ConcreteElementA; 
class ConcreteElementB;

class Visitor { // �����������
public:
    virtual void VisitConcreteElementA(ConcreteElementA *pelementA) = 0;
    virtual void VisitConcreteElementB(ConcreteElementB* pelementB) = 0;
};


class ConreteVisitor1 :public Visitor { // ����������ࣨʵ��ÿ���������������������
public:
    void VisitConcreteElementA(ConcreteElementA* pelementA);
    void VisitConcreteElementB(ConcreteElementB* pelementB);
}; 
void ConreteVisitor1::VisitConcreteElementA(ConcreteElementA* pelementA)
{
    cout << "ִ��ConreteVisitor1::VisitConcreteElementA(...)����." << endl;
}
void ConreteVisitor1::VisitConcreteElementB(ConcreteElementB* pelementB)
{
    cout << "ִ��ConreteVisitor1::VisitConcreteElementB(...)����." << endl;
}


class ConreteVisitor2 :public Visitor { // ����������ࣨʵ��ÿ���������������������
public:
    void VisitConcreteElementA(ConcreteElementA* pelementA);
    void VisitConcreteElementB(ConcreteElementB* pelementB);
};
void ConreteVisitor2::VisitConcreteElementA(ConcreteElementA* pelementA)
{
    cout << "ִ��ConreteVisitor2::VisitConcreteElementA(...)����." << endl;
}
void ConreteVisitor2::VisitConcreteElementB(ConcreteElementB* pelementB)
{
    cout << "ִ��ConreteVisitor2::VisitConcreteElementB(...)����." << endl;
}





class Element { // ����Ԫ�أ�һ���ǳ������ӿڣ��˷�����һ�������������Ϊ����
public:
    virtual void Accept(Visitor* pvisitor) = 0;
};

class ConcreteElementA :public Element {
public:
    ConcreteElementA() {
        cout << "ִ��ConreteElementA()���캯��." << endl;
    }
    void Accept(Visitor* pvisitor);
};
void ConcreteElementA::Accept(Visitor* pvisitor)
{
    pvisitor->VisitConcreteElementA(this);     
}


class ConcreteElementB :public Element {
public:
    ConcreteElementB() {
        cout << "ִ��ConreteElementB()���캯��." << endl;
    }
    void Accept(Visitor* pvisitor);
};
void ConcreteElementB::Accept(Visitor* pvisitor)
{
    pvisitor->VisitConcreteElementB(this);
}

class ObjectStructure { // ����ṹ�ࣨ��һ��Ԫ�صļ��ϣ�����Ҫ���ڴ��Ԫ�ض��󣬲����ṩ�������ڲ�Ԫ�صķ���
public:
    void Attach(Element* pelement);
    void Detach(Element* pelement);
    void Accept(Visitor* pvisitor);

private:
    vector<Element*> elements;
};
void ObjectStructure::Attach(Element* pelement)
{
    elements.push_back(pelement);

}
//void ObjectStructure::Detach(Element* pelement)//ɾ�� 
//{
//    vector<Element*>::iterator it = find(elements.begin(),elements.end(),pelement);
//    if (it != elements.end())
//    {
//        elements.erase(it);
//    }
//}
void ObjectStructure::Accept(Visitor* pvisitor)
{
    // Ϊÿ��element����visitor
    for (vector<Element*>::const_iterator it = elements.begin(); it != elements.end(); it++)
    {
        (*it)->Accept(pvisitor);
    }
}


int testVisitorPattern()
{
    ObjectStructure* pobj = new ObjectStructure;

    ConcreteElementA* pelmtA = new ConcreteElementA;
    ConcreteElementB* pelmtB = new ConcreteElementB;

    pobj->Attach(pelmtA);
    pobj->Attach(pelmtB);
    cout << endl;

    ConreteVisitor1* pvist1 = new ConreteVisitor1;
    ConreteVisitor2* pvist2 = new ConreteVisitor2;

    pobj->Accept(pvist1);
    pobj->Accept(pvist2);

    if (pvist2) delete pvist2;
    if (pvist1) delete pvist1;

    if (pelmtB) delete pelmtB;
    if (pelmtA) delete pelmtA;

    if (pobj) delete pobj;

    return 0;
}


