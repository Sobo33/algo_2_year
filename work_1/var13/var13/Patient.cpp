#include "Patient.h"
#include <iostream>
#include <stdexcept>

Patient::Patient(const std::string& n, int a)
	: name(n), age(0)
{
	if (name.empty())
	{
		throw std::invalid_argument("Имя пациента не должно быть пустым");
	}
	setAge(a);
	std::cout << "Создан пациент: " << name << '\n';
}

Patient::~Patient()
{
	std::cout << "Уничтожен пациент: " << name << '\n';
}

std::string Patient::getName() const
{
	return name;
}

int Patient::getAge() const
{
	return age;
}

void Patient::setAge(int a)
{
	if (a < 0)
	{
		throw std::invalid_argument("Возраст не может быть отрицательным");
	}
	age = a;
}
void Patient::print() const
{
	std::cout << "Пациент: " << name << ", возраст: " << age << '\n';
}