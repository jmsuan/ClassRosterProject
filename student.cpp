#include <iostream>
#include "student.h"
#include "degree.h"
using std::cout;
using std::endl;
using std::string;

string Student::getId() {
    return student_id;
}
void Student::setId(string new_id) {
    student_id = new_id;
}

string Student::getFirstName() {
    return first_name;
}
void Student::setFirstName(string new_first_name) {
    first_name = new_first_name;
}

string Student::getLastName() {
    return last_name;
}
void Student::setLastName(string new_last_name) {
    last_name = new_last_name;
}

string Student::getEmail() {
    return email;
}
void Student::setEmail(string new_email) {
    email = new_email;
}

int Student::getAge() {
    return age;
}
void Student::setAge(int new_age) {
    age = new_age;
}

string Student::getProgram() {
    switch (program) {
    case DegreeProgram::SECURITY: {
        return "SECURITY";
        break;
    }
    case DegreeProgram::NETWORK: {
        return "NETWORK";
        break;
    }
    case DegreeProgram::SOFTWARE: {
        return "SOFTWARE";
        break;
    }
    default:
        return "Not set";
    }
}
void Student::setProgram(DegreeProgram new_program) {
    if (new_program > DegreeProgram::SOFTWARE || new_program < DegreeProgram::SECURITY)
        throw std::invalid_argument("Invalid Degree Program (0 - SECURITY, 1 - NETWORK, 2 - SOFTWARE)");
    else
        program = new_program;
}

int Student::getCompletionDay(int class_num) {
    return days_to_completion[class_num - 1];
}

void Student::setCompletionDay(int class_num, int num_days) {
    days_to_completion[class_num - 1] = num_days;
}

void Student::print() {
    cout
        << this->getId() << " \t"
        << "First Name: " << this->getFirstName() << " \t"
        << " Last Name: " << this->getLastName() << " \t"
        << " Age: " << this->getAge() << " \t"
        << "daysInCourse: {" << this->getCompletionDay(1) << ", " << this->getCompletionDay(2) << ", " << this->getCompletionDay(3) << "} "
        << "Degree Program: " << this->getProgram() << std::endl;
}
