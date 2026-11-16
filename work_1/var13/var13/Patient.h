#pragma once
#include <iostream>

class Patient
{
private:
	std::string name;
	int age;

public:
	Patient(const std::string& n, int a);

	~Patient();

	Patient(const Patient&) = delete;
	Patient& operator=(const Patient&) = delete;

	std::string getName() const;
	int getAge() const;

	void setAge(int a);
	void print() const;
};
