#include <string>

class Student
{
public:
    int rollNumber;
    std::string classType;      // 'A' or 'B'
    std::string foodPreference; // 'V' or 'NV'

    Student(int roll, std::string classChar, std::string foodChar)
        : rollNumber(roll), classType(classChar), foodPreference(foodChar) {}
};