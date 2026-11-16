#include "Appointment.h"
#include <iostream>
#include <stdexcept>

Appointment::Appointment(
    Doctor* d,
    Patient* p,
    const std::string& time)
    : doctor(d), patient(p), dateTime(time)
{
    if (doctor == nullptr || patient == nullptr)
    {
        throw std::invalid_argument(
            "Врач или пациент не указан");
    }

    if (dateTime.empty())
    {
        throw std::invalid_argument(
            "Дата приёма не указана");
    }

    std::cout << "Создана запись на приём\n";
}

Appointment::~Appointment()
{
    std::cout << "Запись на приём удалена\n";
}

Doctor* Appointment::getDoctor() const
{
    return doctor;
}

Patient* Appointment::getPatient() const
{
    return patient;
}

std::string Appointment::getDateTime() const
{
    return dateTime;
}

void Appointment::print() const
{
    std::cout << "Пациент: "
        << patient->getName() << '\n';

    std::cout << "Врач: "
        << doctor->getName() << '\n';

    std::cout << "Специальность: "
        << doctor->getSpecialty() << '\n';

    std::cout << "Дата и время: "
        << dateTime << '\n';
}
