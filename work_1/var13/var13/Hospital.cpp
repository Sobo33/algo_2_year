#include "Hospital.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

Hospital::Hospital()
{
    std::cout << "Создана больница\n";
}

Hospital::~Hospital()
{
    std::cout << "Уничтожена больница\n";
}

Hospital& Hospital::getInstance()
{
    static Hospital instance;
    return instance;
}

void Hospital::addDoctor(Doctor* doctor)
{
    if (doctor == nullptr)
        throw std::invalid_argument("Врач не указан");

    if (std::find(doctors.begin(), doctors.end(), doctor)
        != doctors.end())
        throw std::invalid_argument("Врач уже добавлен");

    doctors.push_back(doctor);
}

void Hospital::addPatient(Patient* patient)
{
    if (patient == nullptr)
        throw std::invalid_argument("Пациент не указан");

    if (std::find(patients.begin(), patients.end(), patient)
        != patients.end())
        throw std::invalid_argument("Пациент уже добавлен");

    patients.push_back(patient);
}

void Hospital::createAppointment(
    Doctor* doctor,
    Patient* patient,
    const std::string& dateTime)
{
    if (doctor == nullptr || patient == nullptr)
        throw std::invalid_argument(
            "Врач или пациент не указан");

    if (std::find(doctors.begin(), doctors.end(), doctor)
        == doctors.end() ||
        std::find(patients.begin(), patients.end(), patient)
        == patients.end())
    {
        throw std::invalid_argument(
            "Врач или пациент не зарегистрирован");
    }

    appointments.push_back(
        std::make_unique<Appointment>(
            doctor, patient, dateTime));
}

void Hospital::print() const
{
    std::cout << "\n=== Врачи ===\n";

    for (const Doctor* doctor : doctors)
        doctor->print();

    std::cout << "\n=== Пациенты ===\n";

    for (const Patient* patient : patients)
        patient->print();

    std::cout << "\n=== Записи ===\n";

    for (const auto& appointment : appointments)
    {
        appointment->print();
        std::cout << '\n';
    }
}

void Hospital::clear()
{
    appointments.clear();
    doctors.clear();
    patients.clear();
}
