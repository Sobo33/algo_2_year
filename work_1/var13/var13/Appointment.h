#pragma once

#include <string>
#include "Doctor.h"
#include "Patient.h"

class Appointment
{
private:
    Doctor* doctor;
    Patient* patient;
    std::string dateTime;

public:
    Appointment(Doctor* d, Patient* p,
        const std::string& time);

    ~Appointment();

    Appointment(const Appointment&) = delete;
    Appointment& operator=(const Appointment&) = delete;

    Doctor* getDoctor() const;
    Patient* getPatient() const;
    std::string getDateTime() const;

    void print() const;
};
