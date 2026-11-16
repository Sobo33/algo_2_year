#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"

class Hospital
{
private:
    std::vector<Doctor*> doctors;
    std::vector<Patient*> patients;
    std::vector<std::unique_ptr<Appointment>> appointments;

    Hospital();
    ~Hospital();

public:
    Hospital(const Hospital&) = delete;
    Hospital& operator=(const Hospital&) = delete;

    static Hospital& getInstance();

    void addDoctor(Doctor* doctor);

    void addPatient(Patient* patient);

    void createAppointment(
        Doctor* doctor,
        Patient* patient,
        const std::string& dateTime);

    void print() const;

    void clear();
};
