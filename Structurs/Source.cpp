#include<iostream>
#include<string>
struct myDate
{
	int day = 1;
	int month = 1;
	int year = 1970;
};
struct myPerson
{
	std::string name = "noname";
	myDate birthday;
	std::string job = "programer";
	int salary = 45000;
};

void print_myPerson(const myPerson& MP) {
	std::cout << "Name   " << MP.name << std::endl;
	std::cout << " Birthday " << MP.birthday.day << '.' << MP.birthday.month << '.' << MP.birthday.year << std::endl;
	std::cout << "Job   " << MP.job << std::endl;
	std::cout << "salary  " << MP.salary << std::endl;
}

myPerson input_myPerson() {
	myPerson tmp;
	std::cout << " Enter name -> ";
	std::getline(std::cin, tmp.name);
	std::cout << " Enter birthday day -> ";
	std::cin>>tmp.birthday.day;
	std::cout << " Enter birthday month -> ";
	std::cin>>tmp.birthday.month;
	std::cout << " Enter birthday year -> ";
	std::cin>>tmp.birthday.year;
	std::cin.ignore();
	std::cout << " Enter job -> ";
	std::getline(std::cin, tmp.job);
	std::cout << " Enter salary -> ";
	std::cin>> tmp.salary;
	return tmp;
}

struct coinsKeeper
{
	std::string name = "noname";
	int age = 0;
	int coins_number = 0;
	int* coins = nullptr;
};

void print_coinsKeeper(const coinsKeeper& CK);
int year_of_birth(const coinsKeeper& CK, int year);
int cash(const coinsKeeper& CK);



int main() {
	setlocale(LC_ALL, "ru");
	// структура person
	/*struct person //структура person описывающая содержимое объектов
	{
		std::string name; //структура per
		int age;
		std::string gender;
		std::string job;
		int salary;
	} p1,p2{"Teresa Lucas", 24, "Female", "actres", 40000}; // создание объектов структура, один из которых мгновенно инициализируется

	// обращение к полям объектов
	p1.name = " Tom Smith";
	p1.age = 23;
	p1.gender = "male";
	p1.job = " programer";
	p1.salary = 80000;
	
	std::cout << "name " << p1.name << std::endl;
	std::cout << "age " << p1.age << std::endl;
	std::cout << "gender " << p1.gender << std::endl;
	std::cout << "job " << p1.job << std::endl;
	std::cout << "salary " << p1.salary << std::endl;

	std::cout << "________________________________\n";
	std::cout << "name   " << p2.name << std::endl;
	std::cout << "age    " << p2.age << std::endl;
	std::cout << "gender " << p2.gender << std::endl;
	std::cout << "job    " << p2.job << std::endl;
	std::cout << "salary " << p2.salary << std::endl;



	person p3{ // альтернативный способ создание объекта
		"Arnold Shvani",
		50,
		"male",
		"Directot",
		120000
	};



	person p4 =p3; // копирование значений полей объекта Р3 в поля объекта Р4
	std::cout << "________________________________\n";
	std::cout << "name   " << p4.name << std::endl;
	std::cout << "age    " << p4.age << std::endl;
	std::cout << "gender " << p4.gender << std::endl;
	std::cout << "job    " << p4.job << std::endl;
	std::cout << "salary " << p4.salary << std::endl;
	*/


	// структура date
	/*struct date // структура date с полями по умолчанию
	{
		int day=1;
		int month=1;
		int year=1970;
		std::string note="empty";
	};

	date d1{ 1,5,2010, " my bro" };
	std::cout <<d1.day << '.' << d1.month << '.' << d1.year << '-' << d1.note << std::endl;
	*/

	

	//myPerson mp{
	//	"Ivan Ivanov",
	//	{ 26,7,1998},
	//	"designer",
	//	90000
	//};
	//print_myPerson(mp);

	//std::cout << "Name   " << mp.name << std::endl;
	//std::cout << " Birthday " << mp.birthday.day << '.' << mp.birthday.month << '.' << mp.birthday.year << std::endl;
	//std::cout << "Job   " << mp.job << std::endl;
	//std::cout << "salary  " << mp.salary << std::endl;

	//myPerson* pointer = &mp;
	//std::cout << pointer->name << std::endl;

	//myPerson mp2 = input_myPerson();
	//std::cout << "______________________\n";
	//print_myPerson(mp2);


	// Задача 1
	std::cout << "Задача 1\n Объект:\n";
	coinsKeeper ck{
		"Peter",
		10,
		7,
		new int[7]{5,1,1,2,5,2,1}
	};

	print_coinsKeeper(ck);
	std::cout << "Год рождения: " << year_of_birth(ck, 2023) << std::endl;
	std::cout << " общие сбережения : " << cash(ck) << std::endl;

	delete[] ck.coins;
	return 0;
}

void print_coinsKeeper(const coinsKeeper& CK) {
	std::cout << "Имя  " << CK.name << std::endl;
	std::cout << "Возраст  " << CK.age << std::endl;
	std::cout << "Монеты  ";
	for (int i = 0; i < CK.coins_number; i++)
		std::cout << CK.coins[i] << ' ';
	std::cout << std::endl;

}
 inline int year_of_birth(const coinsKeeper& CK, int year) {

	return (year - CK.age);

}
 int cash(const coinsKeeper& CK) {
	 int sum = 0;
	 for (int i = 0; i < CK.coins_number; i++)
		 sum += CK.coins[i];
	 return sum;

 }