#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>
#include "degree.h"

class Student
{
private:
    // Attributes
    std::string student_id{};
    std::string first_name{};
    std::string last_name{};
    std::string email{};
    int age{};
    int days_to_completion[3] {};
    DegreeProgram program{};
public:
    // Constructor
    Student(std::string new_id, std::string new_first, std::string new_last, std::string new_email, int new_age, int days_completion[3], DegreeProgram new_program)
        : student_id{new_id}, first_name{new_first}, last_name{new_last}, email{new_email}, age{new_age}, days_to_completion{days_completion[0], days_completion[1], days_completion[2]}, program{new_program}{
    }

    // Getters and Setters
    std::string getId();
    void setId(std::string new_id);

    std::string getFirstName();
    void setFirstName(std::string new_first_name);

    std::string getLastName();
    void setLastName(std::string new_last_name);

    std::string getEmail();
    void setEmail(std::string new_email);

    int getAge();
    void setAge(int new_age);

    std::string getProgram();
    void setProgram(DegreeProgram new_program);

    int getCompletionDay(int class_num);
    void setCompletionDay(int class_num, int num_days);

    // Methods
    void print();
};

#endif // !_STUDENT_H_
