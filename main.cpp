/* Student Note:
 * I use underscore styled variables in my code.
 * All camelcase styled are only kept that way for the grader's convenience when using Ctrl+F.
 * 
 * I ackowledge that it is best practice to be consistent when naming variables,
 * however I had written over half my program before I realized certain (provided) variables/parameters
 * were written in camelcase.
 * 
 * Thank you for grading!
 */

#include "student.h"
#include "roster.h"
#include "degree.h"
#include <iostream>

using namespace std;

int main() {
    cout
        << "C867 - SCRIPTING AND PROGRAMMING - APPLICATIONS" << endl
        << "Programming Language: C++" << endl
        << "WGU Student ID: #001264312" << endl
        << "Name: Jonathan Lane" << endl
        << endl;

    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jonathan,Lane,lane.jonathan@outlook.com,19,10,10,10,SOFTWARE"
    };

    Roster classRoster(studentData);

    classRoster.printAll();
    classRoster.printInvalidEmails();

    for (int i{0}; i < classRoster.firstEmptySpot(); i++) {
        Student* current_student{classRoster.classRosterArray[i]};
        classRoster.printAverageDaysInCourse(current_student->getId());
    }
    cout << endl;

    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}
