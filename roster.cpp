#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"
#include "student.h"
using std::string;

Roster::Roster(const string students[]) {

    int arrSize{sizeof(*students) / sizeof(students)}; // Calculates number of elements in students

    for (size_t i{0}; i < arrSize; i++) {
        string student{students[i]}; // All info for one student

        // Store student information separated by comma into array of strings
        string student_info[6 + 3]; // 7 attributes, one is an array of 3 elements
        std::stringstream s_student(student);
        int info_i{0};
        while (s_student.good()) {
            string substr;
            getline(s_student, substr, ',');
            student_info[info_i] = substr;
            info_i++;
        }

        // String values, direct initialization
        string student_id{student_info[0]};
        string student_first{student_info[1]};
        string student_last{student_info[2]};
        string student_email{student_info[3]};

        // Int values, must convert string to int
        int student_age{std::stoi(student_info[4], nullptr, 0)};
        int student_days[3]{
            std::stoi(student_info[5], nullptr, 0),
            std::stoi(student_info[6], nullptr, 0),
            std::stoi(student_info[7], nullptr, 0)
        };

        // DegreeProgram value, must assign based on string input
        string chosen_program{student_info[8]};
        DegreeProgram student_program{};
        if (chosen_program == "SECURITY")
            student_program = DegreeProgram::SECURITY;
        else if (chosen_program == "NETWORK")
            student_program = DegreeProgram::NETWORK;
        else if (chosen_program == "SOFTWARE")
            student_program = DegreeProgram::SOFTWARE;
        else
            throw std::invalid_argument("Degree Program isn't valid.");

        // Create Student object
        *(classRosterArray + i) = new Student {
            student_id,
            student_first,
            student_last,
            student_email,
            student_age,
            student_days,
            student_program
        };
    }
}

int Roster::maxStudents() { // Returns the max number of students
    return sizeof(classRosterArray) / sizeof(*classRosterArray);
}

int Roster::studentIndexById(string studentID) {
    int found{-1};
    for (int i{0}; i < firstEmptySpot(); i++) {
        Student* current_student = classRosterArray[i];
        if (current_student->getId() == studentID) {
            found = i;
            break;
        }
    }
    return found;
}

size_t Roster::firstEmptySpot() {
    size_t empty_index{};
    int arrSize{maxStudents()}; // Max number of students
    for (int i{0}; i < arrSize; i++)
        if (i == (arrSize - 1)) {
            empty_index = arrSize;
        }
        else if (classRosterArray[i] == NULL) {
            empty_index = i;
            break;
        }
    return empty_index;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
    // Convert daysInCourse# to array
    int daysInCourses[]{
        daysInCourse1,
        daysInCourse2,
        daysInCourse3
    };

    // Find empty spot on roster array
    size_t empty_index{firstEmptySpot()};

    // Add to roster
    *(classRosterArray + empty_index) = new Student{
        studentID,
        firstName,
        lastName,
        emailAddress,
        age,
        daysInCourses,
        degreeprogram
    };
}

void Roster::remove(string studentID) {
    int arrSize{maxStudents()}; // Max number of students
    
    // Find index of student with id
    int found{studentIndexById(studentID)};
    if (found == -1) {
        std::cout << std::endl << "Could not find student ID \"" << studentID << "\" in roster." << std::endl;
    }
    // Delete student
    else {
        delete classRosterArray[found];

        // Move remaining students down on array
        for (int i{found}; i < (arrSize - 1); i++) {
            classRosterArray[i] = classRosterArray[i + 1];
        }
        Student* new_last[1] {}; // Workaround to duplicate behavior of initial student pointer array
        classRosterArray[arrSize - 1] = new_last[0];
    }
}

void Roster::printAll() {
    size_t empty_index{firstEmptySpot()};
    for (size_t i{0}; i < empty_index; i++) {
        Student* current_student = classRosterArray[i];
        current_student->print();
    }
    std::cout << std::endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
    // Point to desired student
    Student* current_student{classRosterArray[studentIndexById(studentID)]};

    // Calculate average
    int sumDays{current_student->getCompletionDay(1) + current_student->getCompletionDay(2) + current_student->getCompletionDay(3)};
    double avgDays{};
    avgDays = sumDays / 3;

    std::cout
        << current_student->getFirstName() << " " << current_student->getLastName() << " has an average of " << avgDays << " days for their courses." << std::endl;
}

void Roster::printInvalidEmails() {
    std::cout << "Invalid Emails:" << std::endl;

    for (int i{0}; i < firstEmptySpot(); i++) {
        Student* current_student{classRosterArray[i]};
        string student_email{current_student->getEmail()};
        if (student_email.find('@', 0) == string::npos || student_email.find(' ', 0) != string::npos) {
            std::cout << student_email << std::endl;
        }
    }
    std::cout << std::endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    // Convert degreeProgram to string
    string strProgram{};
    switch (degreeProgram) {
    case DegreeProgram::SECURITY: {
        strProgram = "SECURITY";
        break;
    }
    case DegreeProgram::NETWORK: {
        strProgram = "NETWORK";
        break;
    }
    case DegreeProgram::SOFTWARE: {
        strProgram = "SOFTWARE";
        break;
    }
    default:
        throw std::invalid_argument("Not a valid program.");
    };

    size_t empty_index{firstEmptySpot()};
    for (size_t i{0}; i < empty_index; i++) {
        Student* current_student = classRosterArray[i];
        if (current_student->getProgram() == strProgram) {
            current_student->print();
        }
    }
    std::cout << std::endl;
}

Roster::~Roster() {
    for (int i{}; i < maxStudents(); i++) {
        delete classRosterArray[i];
    }
}
