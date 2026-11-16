#include <iostream>
#include <stdexcept>
#include <windows.h>
#include "Hospital.h"

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    try
    {
        Doctor d1("Иванов", "Терапевт");
        Doctor d2("Петров", "Хирург");

        Patient p1("Алексей", 20);
        Patient p2("Мария", 25);

        Hospital& hospital = Hospital::getInstance();

        Hospital& another = Hospital::getInstance();

        std::cout << std::boolalpha;
        std::cout << "Одна больница: "
            << (&hospital == &another) << '\n';

        hospital.addDoctor(&d1);
        hospital.addDoctor(&d2);

        hospital.addPatient(&p1);
        hospital.addPatient(&p2);

        hospital.createAppointment(
            &d1, &p1, "15.11.2026 14:30");

        hospital.createAppointment(
            &d2, &p2, "16.11.2026 10:00");

        hospital.print();

        std::cout << "\n=== ПРОВЕРКА ОШИБОК ===\n";

        try
        {
            hospital.addDoctor(nullptr);
        }
        catch (const std::exception& error)
        {
            std::cout << "Ошибка 1: "
                << error.what() << '\n';
        }

        try
        {
            hospital.addPatient(&p1);
        }
        catch (const std::exception& error)
        {
            std::cout << "Ошибка 2: "
                << error.what() << '\n';
        }

        Doctor d3("Сидоров", "Невролог");

        try
        {
            hospital.createAppointment(
                &d3, &p1, "17.11.2026 12:00");
        }
        catch (const std::exception& error)
        {
            std::cout << "Ошибка 3: "
                << error.what() << '\n';
        }

        try
        {
            hospital.createAppointment(
                &d1, &p1, "");
        }
        catch (const std::exception& error)
        {
            std::cout << "Ошибка 4: "
                << error.what() << '\n';
        }

        try
        {
            Patient wrong("Николай", -5);
        }
        catch (const std::exception& error)
        {
            std::cout << "Ошибка 5: "
                << error.what() << '\n';
        }

        std::cout << "\nКоличество врачей: "
            << Doctor::getActiveCount() << '\n';

        std::cout << "\n=== ОЧИСТКА БОЛЬНИЦЫ ===\n";

        hospital.clear();

        std::cout << "\nВрач и пациент после очистки:\n";

        d1.print();
        p1.print();

        std::cout << "Количество врачей: "
            << Doctor::getActiveCount() << '\n';
    }
    catch (const std::exception& error)
    {
        std::cerr << error.what() << '\n';
        return 1;
    }

    return 0;
}
