#include "Doctor.h"
#include <iostream>
#include <stdexcept>

int Doctor::activeCount = 0;

Doctor::Doctor(const std::string& n, const std::string& s)
	: name(n), specialty(s)
{
	if (name.empty() || specialty.empty())
	{
		throw std::invalid_argument("Имя и специальность не должны быть пусты");
	}
	++activeCount;
	std::cout << "Создан врач " << name << '\n';
}

Doctor::~Doctor()
{
	--activeCount;
	std::cout << "Врач удален " << name << '\n';
}

std::string Doctor::getName() const
{
	return name;
}

std::string Doctor::getSpecialty() const
{
	return specialty;
}

void Doctor::print() const
{
	std::cout << "Врач: " << name << ", специалисты: " << specialty << '\n';
}

int Doctor::getActiveCount()
{
	return activeCount;
}