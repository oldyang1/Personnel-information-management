#include <iostream>
using namespace std;
#include <string>
#include <regex>
#define MAX 1000


// �����ϵ�˵Ľṹ��
struct Person {
	// ����
	string m_Name;
	// �Ա�  1 ��   2 Ů
	int m_Sex;
	// ����
	int m_Age;
	// �绰
	string m_Phone;
	// ��ַ
	string m_Addr;

};


// ���ͨѶ¼�Ľṹ��
struct Addressbooks {

	// ͨѶ¼�б�����ϵ�˵�����
	struct Person personArray[MAX];

	// ͨѶ¼�е�ǰ��ϵ�˸���
	int m_Size;
};


// �����ϵ��
void addPerson(Addressbooks* abs) {

	// �ж�ͨѶ¼�Ƿ����������������
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼����Ա���޷������Ա��" << endl;
		return;
	}
	else {
		// ��Ӿ�����ϵ��
		
		// ����
		regex reg("^[\u4E00-\u9FA5]{2,4}$");  // 2-4λ��������
		string name;
		while (1) {
			cout << "������������" << endl;
			cin >> name;
			bool isit = regex_match(name, reg);
			if (isit) {
				abs->personArray[abs->m_Size].m_Name = name;
				break;
			}
			else {
				cout << "��������ȷ��������ʽ��" << endl;
			}
		}
		// �Ա�
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;

		while (true) {
			cin >> sex;
			// ֻ������1��2�ſɱ���
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		// ����
		int age = 0;
		while (1) {
			cout << "���������䣺" << endl;
			cin >> age;
			if (age > 0 && age < 150) {
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		// �绰
		regex reg1("^(13[0-9]|14[5-9]|15[0-35-9]|166|17[0-8]|18[0-9]|19[89])[0-9]{8}$");
		string phone;
		while (1) {
			cout << "��������ϵ�绰��" << endl;
			cin >> phone;
			bool isit1 = regex_match(phone, reg1);
			if (isit1) {
				abs->personArray[abs->m_Size].m_Phone = phone;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		
		// סַ
		string address;
		cout << "�������ͥ��ַ��" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		
		// ����ͨѶ¼����
		abs->m_Size++;

		cout << "�����Ա�ɹ���" << endl;

		system("pause");
		system("cls");
	}

}


// ��ʾ���е���ϵ��
void showPerson(Addressbooks* abs) {

	// �ж�ͨѶ¼�����Ƿ�Ϊ0
	if (abs->m_Size == 0) {

		cout << "��ǰ��Ա��¼Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {

			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
		}
	}

	system("pause");
	system("cls");
}


// �����ϵ���Ƿ���ڣ������ڷ��������еľ���λ�ã������ڷ���-1
int isExist(Addressbooks* abs, string name) {

	for (int i = 0; i < abs->m_Size; i++) {

		//�ҵ��û����������
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	// ������û�ҵ�����-1
	return -1;
}


// ɾ��ָ����ϵ��
void deletePerson(Addressbooks* abs) {

	regex reg("^[\u4E00-\u9FA5]{2,4}$");  // 2-4λ��������
	cout << "��������Ҫɾ������ϵ��" << endl;

	string name;
	cin >> name;
	bool isit = regex_match(name, reg);
	
	if (isit) {
		// ret=-1δ�鵽
		// ret��=-1�鵽
		int ret = isExist(abs, name);
		if (ret != -1) {
			// �鵽���˽���ɾ������
			for (int i = ret; i < abs->m_Size; i++) {

				// ����ǰ��
				abs->personArray[i] = abs->personArray[i + 1];
			}
			abs->m_Size--;  // ������Ա��
			cout << "ɾ���ɹ���" << endl;
		}
		else {
			cout << "���޴���" << endl;
		}
	}
	cout << "������������������!" << endl;

	system("pause");
	system("cls");

}


// ����ָ������ϵ��
void findPerson(Addressbooks* abs) {

	regex reg("^[\u4E00-\u9FA5]{2,4}$");  // 2-4λ��������
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	bool isit = regex_match(name, reg);

	// �ж�ָ����ϵ���Ƿ������ͨѶ¼��

	if (isit) {
		int ret = isExist(abs, name);

		if (ret != -1) {
			cout << "������" << abs->personArray[ret].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
			cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[ret].m_Addr << endl;
		}
		else {

			cout << "���޴���" << endl;
		}
	}
	else {
		cout << "�����������������룡" << endl;
	}
	
	system("puase");
	system("cls");
}


// �޸�ָ������ϵ����Ϣ
void modifyPerson(Addressbooks* abs) {

	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	// �ж�ָ����ϵ���Ƿ������ͨѶ¼��

	int ret = isExist(abs, name);

	if (ret != -1) {
		
		// ����
		regex reg("^[\u4E00-\u9FA5]{2,4}$");  // 2-4λ��������
		string name;
		while (1) {
			cout << "������������" << endl;
			cin >> name;
			bool isit = regex_match(name, reg);
			if (isit) {
				abs->personArray[ret].m_Name = name;
				break;
			}
			else {
				cout << "��������ȷ��������ʽ��" << endl;
			}
		}
		// �Ա�
		cout << "�������Ա�" << endl;
		cout << "1-------��" << endl;
		cout << "2-------Ů" << endl;
		int sex = 0;


		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else {
				cout << "�����������������룡" << endl;
			}
		}
		
		// ����
		int age = 0;
		while (1) {
			cout << "���������䣺" << endl;
			cin >> age;
			if (age > 0 && age < 150) {
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		// �绰
		regex reg1("^(13[0-9]|14[5-9]|15[0-35-9]|166|17[0-8]|18[0-9]|19[89])[0-9]{8}$");
		string phone;
		while (1) {
			cout << "��������ϵ�绰��" << endl;
			cin >> phone;
			bool isit1 = regex_match(phone, reg1);
			if (isit1) {
				abs->personArray[ret].m_Phone = phone;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		// סַ
		cout << "������סַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "�޸ĳɹ���" << endl;

	}
	else {

		cout << "���޴���" << endl;
	}

	system("puase");
	system("cls");


}


// �����ϵ��
void cleanPerson(Addressbooks* abs) {

	cout << "���Ƿ�Ҫ���ȫ����ϵ�ˣ�" << endl;
	cout << "�������ǻ��" << endl;
	string flag;

	cin >> flag;
	if (flag == "��" || flag == "��") {
		if (flag == "��") {
			// ��ͨѶ��������Ϊ0
			abs->m_Size = 0;
			cout << "ͨѶ¼�Ѿ����" << endl;
		}
		else {
			system("puase");
			system("cls");
			return;
			
		}
			
	}
	else {
		cout << "����ȷ����" << endl;
	}

	system("puase");
	system("cls");
}


// �˵�����
void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;  // ����ƥ��ȫ��
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;  // ����ƥ������
	cout << "*****  4��������ϵ��  *****" << endl;  // ����ƥ������
	cout << "*****  5���޸���ϵ��  *****" << endl;  // ����ƥ��ȫ��
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}


int main() {

	// ����ͨѶ¼�ṹ�����
	Addressbooks abs;
	// ��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;

	int select = 0;   // �û�ѡ������

	while (true) {
		showMenu();

		cin >> select;

		switch (select) {
		case 1:     // 1�������ϵ��
			addPerson(&abs);   // ��ֵ�����޷��޸�ʵ�Σ��˴��򴫵ݵ�ַ
			break;
		case 2:     // 2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:     // 3��ɾ����ϵ��
		//{
		//	// ���� �����ϵ���Ƿ���ڣ����ں�������
		//	cout << "������ɾ����ϵ������" << endl;
		//	string name;
		//	cin >> name;

		//	if (isExist(&abs, name) == -1) {
		//		cout << "���޴���" << endl;
		//	}
		//	else {
		//		cout << "�ҵ�����" << endl;
		//	}
		//}
			deletePerson(&abs);
			break;
		case 4:     // 4��������ϵ��
			findPerson(&abs);
			break;
		case 5:     // 5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6:     // 6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0:     // 0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		}
	}

	system("pause");
	return 0;
}
