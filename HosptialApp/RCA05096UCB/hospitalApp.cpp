#include <iostream>
#include <string>
using namespace std;

bool isNumber(const string& input) {
    for (char c : input) {
        if (!isdigit(c))
            return false;
    }
    return !input.empty();
}

struct PatientsLL {
    int patient_id;
    string name;
    string dob;
    string gender;
    PatientsLL* next;

    PatientsLL(int patient_id, string name, string dob, string gender) {
        this->patient_id = patient_id;
        this->dob = dob;
        this->name = name;
        this->gender = gender;
        next = nullptr;
    }
};

struct DoctorsLL {
    int doctor_id;
    string name;
    string specialization;
    DoctorsLL* next;

    DoctorsLL(int doctor_id, string name, string specialization) {
        this->doctor_id = doctor_id;
        this->name = name;
        this->specialization = specialization;
        next = nullptr;
    }
};

struct Appointments {
    int appointment_id;
    int patient_id;
    int doctor_id;
    string appointment_date;
    Appointments* next;

    Appointments(int appointment_id, int patient_id, int doctor_id, string appointment_date) {
        this->appointment_id = appointment_id;
        this->patient_id = patient_id;
        this->doctor_id = doctor_id;
        this->appointment_date = appointment_date;
        next = nullptr;
    }
};

PatientsLL* patientReg(PatientsLL* head) {
    string input;
    int id;
    string name, dob, gender;

    cout << "ID: ";
    cin >> input;

    if (!isNumber(input)) {
        cout << "Invalid input. ID must be a number." << endl;
        return head;
    }
    id = stoi(input);

    PatientsLL* temp = head;
    while (temp != nullptr) {
        if (temp->patient_id == id) {
            cout << "Patient with ID " << id << " already exists." << endl;
            return head;
        }
        temp = temp->next;
    }

    cout << "Name: ";
    cin >> name;
    cout << "DoB: ";
    cin >> dob;
    cout << "GENDER: ";
    cin >> gender;

    PatientsLL* patient = new PatientsLL(id, name, dob, gender);
    patient->next = head;
    return patient;
}

DoctorsLL* doctorReg(DoctorsLL* head) {
    string input;
    int id;
    string name, specialization;

    cout << "ID: ";
    cin >> input;

    if (!isNumber(input)) {
        cout << "Invalid input. ID must be a number." << endl;
        return head;
    }
    id = stoi(input);

    DoctorsLL* temp = head;
    while (temp != nullptr) {
        if (temp->doctor_id == id) {
            cout << "Doctor with ID " << id << " already exists." << endl;
            return head;
        }
        temp = temp->next;
    }

    cout << "NAME: ";
    cin >> name;
    cout << "SPECIALIZATION: ";
    cin >> specialization;

    DoctorsLL* doctor = new DoctorsLL(id, name, specialization);
    doctor->next = head;
    return doctor;
}

Appointments* appointmentReg(PatientsLL* pat, DoctorsLL* doc, Appointments* head) {
    string input;
    int appointment_id, patient_id, doctor_id;
    string appointment_date;

    cout << "ID: ";
    cin >> input;
    if (!isNumber(input)) {
        cout << "Invalid input. ID must be a number." << endl;
        return head;
    }
    appointment_id = stoi(input);

    cout << "P_ID: ";
    cin >> input;
    if (!isNumber(input)) {
        cout << "Invalid input. Patient ID must be a number." << endl;
        return head;
    }
    patient_id = stoi(input);

    cout << "D_ID: ";
    cin >> input;
    if (!isNumber(input)) {
        cout << "Invalid input. Doctor ID must be a number." << endl;
        return head;
    }
    doctor_id = stoi(input);

    cout << "DATE: ";
    cin >> appointment_date;

    Appointments* existing_appt = head;
    while (existing_appt != nullptr) {
        if (existing_appt->appointment_id == appointment_id) {
            cout << "Appointment with ID " << appointment_id << " already exists." << endl;
            return head;
        }
        existing_appt = existing_appt->next;
    }

    PatientsLL* temp_pat = pat;
    bool patientExists = false;
    while (temp_pat != nullptr) {
        if (temp_pat->patient_id == patient_id) {
            patientExists = true;
            break;
        }
        temp_pat = temp_pat->next;
    }

    DoctorsLL* temp_doc = doc;
    bool doctorExists = false;
    while (temp_doc != nullptr) {
        if (temp_doc->doctor_id == doctor_id) {
            doctorExists = true;
            break;
        }
        temp_doc = temp_doc->next;
    }

    if (!patientExists || !doctorExists) {
        cout << "No patient or doctor with the provided ID." << endl;
        return head;
    }

    Appointments* appointment = new Appointments(appointment_id, patient_id, doctor_id, appointment_date);
    appointment->next = head;
    head = appointment;

    return head;
}

void displayPatient(PatientsLL* head) {
    if (!head) {
        cout << "No patients available" << endl;
        return;
    }

    PatientsLL* patient = head;
    while (patient) {
        cout << "Patient ID: " << patient->patient_id << ", Name: " << patient->name
             << ", DOB: " << patient->dob << ", Gender: " << patient->gender << endl;
        patient = patient->next;
    }
}

void displayDoctor(DoctorsLL* head) {
    if (!head) {
        cout << "No doctors available" << endl;
        return;
    }

    DoctorsLL* doctor = head;
    while (doctor) {
        cout << "Doctor ID: " << doctor->doctor_id << ", Name: " << doctor->name
             << ", Specialization: " << doctor->specialization << endl;
        doctor = doctor->next;
    }
}

void displayAppointment(Appointments* head) {
    if (!head) {
        cout << "No appointments available" << endl;
        return;
    }

    Appointments* appointment = head;
    while (appointment) {
        cout << "Appointment ID: " << appointment->appointment_id << ", Patient ID: " << appointment->patient_id
             << ", Doctor ID: " << appointment->doctor_id << ", Date: " << appointment->appointment_date << endl;
        appointment = appointment->next;
    }
}

int main() {
    PatientsLL* patient = nullptr;
    DoctorsLL* doctor = nullptr;
    Appointments* appointment = nullptr;

    string input;
    int choice;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Register Patient" << endl;
        cout << "2. Register Doctor" << endl;
        cout << "3. Register an appointment" << endl;
        cout << "4. Display Patients" << endl;
        cout << "5. Display Doctors" << endl;
        cout << "6. Display Appointments" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> input;

        if (!isNumber(input)) {
            cout << "Invalid choice. Please enter a number." << endl;
            continue;
        }
        choice = stoi(input);

        switch (choice) {
            case 1:
                patient = patientReg(patient);
                break;
            case 2:
                doctor = doctorReg(doctor);
                break;
            case 3:
                appointment = appointmentReg(patient, doctor, appointment);
                break;
            case 4:
                displayPatient(patient);
                break;
            case 5:
                displayDoctor(doctor);
                break;
            case 6:
                displayAppointment(appointment);
                break;
            case 7:
                cout << "Thank You" << endl;
                return 0;
            default:
                cout << "Invalid option chosen." << endl;
        }
    }

    return 0;
}
