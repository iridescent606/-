#include<iostream>
#include<string>
const int Maxn = 1000;
struct Person
{
	std::string Name;
	int Sex;
	int Age;
	std::string Phone;
	std::string Adress;
};
struct Adressbooks
{
	Person personarray[Maxn];
	int Size;
};
void drawMenu()
{
	std::cout << "1.添加联系人" << std::endl;
	std::cout << "2.显示联系人" << std::endl;
	std::cout << "3.删除联系人" << std::endl;
	std::cout << "4.查找联系人" << std::endl;
	std::cout << "5.修改联系人" << std::endl;
	std::cout << "6.清空联系人" << std::endl;
	std::cout << "0.退出通讯录" << std::endl;
}
void addPerson(Adressbooks& abs)
{
	system("cls");
	if (abs.Size == Maxn)
	{
		std::cout << "通讯录已满" << std::endl;
		std::cout << "按任意键返回" << std::endl;
		system("pause");
	}
	else
	{
		std::string name;
		std::cout << "请输入名字" << std::endl;
		std::cin >> name;
		abs.personarray[abs.Size].Name = name;

		int Sex;
		std::cout << "请输入性别" << std::endl;
		std::cout << "1--男 2--女" << std::endl;
		while (1)
		{
			std::cin >> Sex;
			if (Sex == 1 || Sex == 2)
			{
				abs.personarray[abs.Size].Sex = Sex;
				break;
			}
			else
			{
				std::cout << "输入有误 请重新输入" << std::endl;
			}
		}

		int Age;
		std::cout << "请输入年龄" << std::endl;
		std::cin >> Age;
		abs.personarray[abs.Size].Age = Age;

		std::string Phone;
		std::cout << "请输入电话号码" << std::endl;
		std::cin >> Phone;
		abs.personarray[abs.Size].Phone = Phone;

		std::string Adress;
		std::cout << "请输入地址" << std::endl;
		std::cin >> Adress;
		abs.personarray[abs.Size].Adress = Adress;

		abs.Size++;
		std::cout << "已添加成功" << std::endl;

		std::cout << "按任意键返回" << std::endl;
		system("pause");
	}
}
void showPerson(Adressbooks& abs)
{
	if (abs.Size==0)
	{
		std::cout << "通讯录为空" << std::endl;
		std::cout << "按任意键返回" << std::endl;
		system("pause");
	}
	else
	{
		system("cls");
		for (int i = 0; i < abs.Size; i++)
		{
			std::cout << abs.personarray[i].Name<<" ";
			std::cout << abs.personarray[i].Age << " ";
			std::cout << abs.personarray[i].Sex << " ";
			std::cout << abs.personarray[i].Phone << " ";
			std::cout << abs.personarray[i].Adress << " "<<std::endl;
		}
		std::cout << "按任意键返回" << std::endl;
		system("pause");
	}
}
int isExist(Adressbooks& abs, std::string name)
{
	for (int i = 0; i < abs.Size; i++)
	{
		if (name == abs.personarray[i].Name)
		{
			return i;
		}
	}
	return -1;
}
void deletePerson(Adressbooks &abs)
{
	std::string name;
	std::cout << "请输入希望删除的名字：";
	std::cin >> name;
	int t = isExist(abs, name);
	if (t == -1)
	{
		std::cout << "删除对象不存在" << std::endl;
		std::cout << "按任意键返回" << std::endl;
		system("pause");
	}
	else
	{
		for (int i = t + 1; i < abs.Size; i++)
		{
			abs.personarray[i - 1] = abs.personarray[i];
		}
		abs.Size--;
		std::cout << "删除成功" << std::endl;
		std::cout << "按任意键返回" << std::endl;
		system("pause");
	}
}
void findperson(Adressbooks& abs)
{
	std::string name;
	std::cout << "请输入查询的名字：";
	std::cin >> name;
	int t = isExist(abs, name);
	if (t == -1)
	{
		std::cout << "查询对象不存在" << std::endl;
		std::cout << "按任意键返回" << std::endl;
		system("pause");
	}
	else
	{
		std::cout << abs.personarray[t].Name << std::endl;
		std::cout << abs.personarray[t].Age << std::endl;
		std::cout << abs.personarray[t].Adress << std::endl;
		std::cout << abs.personarray[t].Sex << std::endl;
		std::cout << abs.personarray[t].Phone << std::endl;
		std::cout << "按任意键返回" << std::endl;
		system("pause");
	}
}
void changePerson(Adressbooks& abs)
{
	std::string name;
	std::cout << "请输入修改的名字：";
	std::cin >> name;
	int t = isExist(abs, name);
	if (t == -1)
	{
		std::cout << "修改对象不存在" << std::endl;
		std::cout << "按任意键返回" << std::endl;
		system("pause");
	}
	else
	{
		std::string c_name;
		std::cout << "输入修改后名字：" << std::endl;
		std::cin >> c_name;
		abs.personarray[t].Name = c_name;

		int Sex;
		std::cout << "请输入修改后性别:" ;
		std::cout << "1--男 2--女" << std::endl;
		while (1)
		{
			std::cin >> Sex;
			if (Sex == 1 || Sex == 2)
			{
				abs.personarray[t].Sex = Sex;
				break;
			}
			else
			{
				std::cout << "输入有误 请重新输入" << std::endl;
			}
		}

		int Age;
		std::cout << "请输入修改后的年龄" << std::endl;
		std::cin >> Age;
		abs.personarray[t].Age = Age;

		std::string Phone;
		std::cout << "请输入修改后的电话号码" << std::endl;
		std::cin >> Phone;
		abs.personarray[t].Phone = Phone;

		std::string Adress;
		std::cout << "请输入修改后的地址" << std::endl;
		std::cin >> Adress;
		abs.personarray[t].Adress = Adress;

		std::cout << "修改完成" << std::endl;
		std::cout << "按任意键返回" << std::endl;
		system("pause");
	}
}
void clearAdressbooks(Adressbooks& abs)
{
	abs.Size=0;
	std::cout << "清空完成" << std::endl;
	std::cout << "按任意键返回" << std::endl;
	system("pause");
}
int main()
{
	Adressbooks abs;
	abs.Size = 0;
	int select = 0;
	while (1)
	{
		drawMenu();
		std::cin >> select;
		switch (select)
		{
		case 1:
			addPerson(abs);
			break;
		case 2:
			showPerson(abs);
			break;
		case 3:
			deletePerson(abs);
			break;
		case 4:
			findperson(abs);
			break;
		case 5:
			changePerson(abs);
			break;
		case 6:
			clearAdressbooks(abs);
			break;
		case 0:
			std::cout << "欢迎下次使用" << std::endl;
			return 0;
			break;
		}
		system("cls");
	}
	return 0;
}