#pragma once
#include <string>

class Doctor
{
private:
	std::string name;
	std::string specialty;
	static int activeCount;

public:
	Doctor(const std::string& n, const std::string& s);
	~Doctor();

	Doctor(const Doctor&) = delete;
	Doctor& operator=(const Doctor&) = delete;

	std::string getName() const;
	std::string getSpecialty() const;

	void print() const;
	static int getActiveCount();
};