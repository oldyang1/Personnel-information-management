#include <iostream>
using namespace std;
#include <string>
#include <regex>
#define MAX 1000


// 设计联系人的结构体
struct Person {
	// 姓名
	string m_Name;
	// 性别  1 男   2 女
	int m_Sex;
	// 年龄
	int m_Age;
	// 电话
	string m_Phone;
	// 地址
	string m_Addr;

};


// 设计通讯录的结构体
struct Addressbooks {

	// 通讯录中保存联系人的数据
	struct Person personArray[MAX];

	// 通讯录中当前联系人个数
	int m_Size;
};


// 添加联系人
void addPerson(Addressbooks* abs) {

	// 判断通讯录是否已满，若满则不添加
	if (abs->m_Size == MAX) {
		cout << "通讯录已满员，无法添加人员！" << endl;
		return;
	}
	else {
		// 添加具体联系人
		
		// 姓名
		regex reg("^[\u4E00-\u9FA5]{2,4}$");  // 2-4位中文姓名
		string name;
		while (1) {
			cout << "请输入姓名：" << endl;
			cin >> name;
			bool isit = regex_match(name, reg);
			if (isit) {
				abs->personArray[abs->m_Size].m_Name = name;
				break;
			}
			else {
				cout << "请输入正确的姓名格式！" << endl;
			}
		}
		// 性别
		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;

		while (true) {
			cin >> sex;
			// 只有输入1或2才可保存
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		// 年龄
		int age = 0;
		while (1) {
			cout << "请输入年龄：" << endl;
			cin >> age;
			if (age > 0 && age < 150) {
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		// 电话
		regex reg1("^(13[0-9]|14[5-9]|15[0-35-9]|166|17[0-8]|18[0-9]|19[89])[0-9]{8}$");
		string phone;
		while (1) {
			cout << "请输入联系电话：" << endl;
			cin >> phone;
			bool isit1 = regex_match(phone, reg1);
			if (isit1) {
				abs->personArray[abs->m_Size].m_Phone = phone;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		
		// 住址
		string address;
		cout << "请输入家庭地址：" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		
		// 更新通讯录人数
		abs->m_Size++;

		cout << "添加人员成功！" << endl;

		system("pause");
		system("cls");
	}

}


// 显示所有的联系人
void showPerson(Addressbooks* abs) {

	// 判断通讯录人数是否为0
	if (abs->m_Size == 0) {

		cout << "当前人员记录为空！" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {

			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
		}
	}

	system("pause");
	system("cls");
}


// 检测联系人是否存在，若存在返回数组中的具体位置，不存在返回-1
int isExist(Addressbooks* abs, string name) {

	for (int i = 0; i < abs->m_Size; i++) {

		//找到用户输入的姓名
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	// 遍历完没找到返回-1
	return -1;
}


// 删除指定联系人
void deletePerson(Addressbooks* abs) {

	regex reg("^[\u4E00-\u9FA5]{2,4}$");  // 2-4位中文姓名
	cout << "请输入您要删除的联系人" << endl;

	string name;
	cin >> name;
	bool isit = regex_match(name, reg);
	
	if (isit) {
		// ret=-1未查到
		// ret！=-1查到
		int ret = isExist(abs, name);
		if (ret != -1) {
			// 查到此人进行删除操作
			for (int i = ret; i < abs->m_Size; i++) {

				// 数据前移
				abs->personArray[i] = abs->personArray[i + 1];
			}
			abs->m_Size--;  // 更新人员数
			cout << "删除成功！" << endl;
		}
		else {
			cout << "查无此人" << endl;
		}
	}
	cout << "输入有误，请重新输入!" << endl;

	system("pause");
	system("cls");

}


// 查找指定的联系人
void findPerson(Addressbooks* abs) {

	regex reg("^[\u4E00-\u9FA5]{2,4}$");  // 2-4位中文姓名
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	bool isit = regex_match(name, reg);

	// 判断指定联系人是否存在于通讯录中

	if (isit) {
		int ret = isExist(abs, name);

		if (ret != -1) {
			cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
			cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
			cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
			cout << "住址：" << abs->personArray[ret].m_Addr << endl;
		}
		else {

			cout << "查无此人" << endl;
		}
	}
	else {
		cout << "输入有误，请重新输入！" << endl;
	}
	
	system("puase");
	system("cls");
}


// 修改指定的联系人信息
void modifyPerson(Addressbooks* abs) {

	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;

	// 判断指定联系人是否存在于通讯录中

	int ret = isExist(abs, name);

	if (ret != -1) {
		
		// 姓名
		regex reg("^[\u4E00-\u9FA5]{2,4}$");  // 2-4位中文姓名
		string name;
		while (1) {
			cout << "请输入姓名：" << endl;
			cin >> name;
			bool isit = regex_match(name, reg);
			if (isit) {
				abs->personArray[ret].m_Name = name;
				break;
			}
			else {
				cout << "请输入正确的姓名格式！" << endl;
			}
		}
		// 性别
		cout << "请输入性别" << endl;
		cout << "1-------男" << endl;
		cout << "2-------女" << endl;
		int sex = 0;


		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else {
				cout << "输入有误请重新输入！" << endl;
			}
		}
		
		// 年龄
		int age = 0;
		while (1) {
			cout << "请输入年龄：" << endl;
			cin >> age;
			if (age > 0 && age < 150) {
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		// 电话
		regex reg1("^(13[0-9]|14[5-9]|15[0-35-9]|166|17[0-8]|18[0-9]|19[89])[0-9]{8}$");
		string phone;
		while (1) {
			cout << "请输入联系电话：" << endl;
			cin >> phone;
			bool isit1 = regex_match(phone, reg1);
			if (isit1) {
				abs->personArray[ret].m_Phone = phone;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		// 住址
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "修改成功！" << endl;

	}
	else {

		cout << "查无此人" << endl;
	}

	system("puase");
	system("cls");


}


// 清空联系人
void cleanPerson(Addressbooks* abs) {

	cout << "您是否要清空全部联系人？" << endl;
	cout << "请输入是或否" << endl;
	string flag;

	cin >> flag;
	if (flag == "是" || flag == "否") {
		if (flag == "是") {
			// 将通讯里人数置为0
			abs->m_Size = 0;
			cout << "通讯录已经清空" << endl;
		}
		else {
			system("puase");
			system("cls");
			return;
			
		}
			
	}
	else {
		cout << "请正确输入" << endl;
	}

	system("puase");
	system("cls");
}


// 菜单界面
void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;  // 正则匹配全部
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;  // 正则匹配姓名
	cout << "*****  4、查找联系人  *****" << endl;  // 正则匹配姓名
	cout << "*****  5、修改联系人  *****" << endl;  // 正则匹配全部
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}


int main() {

	// 创建通讯录结构体变量
	Addressbooks abs;
	// 初始化通讯录中当前人员个数
	abs.m_Size = 0;

	int select = 0;   // 用户选择输入

	while (true) {
		showMenu();

		cin >> select;

		switch (select) {
		case 1:     // 1、添加联系人
			addPerson(&abs);   // 因值传递无法修改实参，此处因传递地址
			break;
		case 2:     // 2、显示联系人
			showPerson(&abs);
			break;
		case 3:     // 3、删除联系人
		//{
		//	// 测试 检测联系人是否存在，便于后续操作
		//	cout << "请输入删除联系人姓名" << endl;
		//	string name;
		//	cin >> name;

		//	if (isExist(&abs, name) == -1) {
		//		cout << "查无此人" << endl;
		//	}
		//	else {
		//		cout << "找到此人" << endl;
		//	}
		//}
			deletePerson(&abs);
			break;
		case 4:     // 4、查找联系人
			findPerson(&abs);
			break;
		case 5:     // 5、修改联系人
			modifyPerson(&abs);
			break;
		case 6:     // 6、清空联系人
			cleanPerson(&abs);
			break;
		case 0:     // 0、退出通讯录
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		}
	}

	system("pause");
	return 0;
}
