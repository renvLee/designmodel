#include <iostream>
#include"designmodel.h"
using namespace std;

class ProtoType {  // ���Ǻ��д��麯���������������
public:
	ProtoType(){
	}
	~ProtoType() {
	}

	virtual ProtoType* CloneFunc() = 0;  // ���麯��
};

class ConreteProtoType:public ProtoType
{
public:
	ConreteProtoType(int imember):_member(imember) {
		cout << "ִ��ConreteProtoType���ι��캯��.\n" << endl;
	}
	~ConreteProtoType() {
		cout << "ִ��ConreteProtoType��������." << endl;
	}

	// �������캯��������ָ���Ա������Ҫ����ʵ�������
	ConreteProtoType(const ConreteProtoType& rhs) {
		_member = rhs._member;
		cout << "���ݳ�Ա_member1��" << _member << endl;
	}

	ConreteProtoType* CloneFunc() { // ������ʵ��
		cout << "���ڴ����¡." << endl;
		cout << "���ݳ�Ա_member2��" << _member << endl;
		return new ConreteProtoType(*this);
	}

private:
	int _member;

};

int testProtoTypeModel()
{
	cout << "main()����-->ԭ��ģʽ��ʼ.\n" << endl;

	ConreteProtoType* CloneObjA = new ConreteProtoType(88);
	ConreteProtoType* CloneObjB = CloneObjA->CloneFunc();

	cout << endl;

	delete CloneObjA;
	CloneObjA = nullptr;
	delete CloneObjB;
	CloneObjB = nullptr;
	return 0;
}






