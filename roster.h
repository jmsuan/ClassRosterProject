#ifndef _ROSTER_H_
#define _ROSTER_H_

#include "student.h"
#include "degree.h"

using std::string;

class Roster
{
private:
    // Private Methods
    int maxStudents(); // Returns the max number of students
    int studentIndexById(string studentID);
public:
    // Attributes (needs to be accessed by main.cpp)
    Student* classRosterArray[50]{}; // Supports up to 50 Students (I wish I could use a vector)
    // Constructor
    Roster(const string []);
    // Methods
    size_t firstEmptySpot(); // Returns an index
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    ~Roster();
};

#endif // !_ROSTER_H_
