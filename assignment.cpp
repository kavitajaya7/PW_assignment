#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Student
{
public:
    int rollNumber;
    string classType;      // 'A' or 'B'
    string foodPreference; // 'V' or 'NV'

    Student(int roll, string classChar, string foodChar)
        : rollNumber(roll), classType(classChar), foodPreference(foodChar) {}
};

class SortingHat
{
private:
    int capPerHouse;
    unordered_map<string, unordered_map<string, queue<int>>> houses;
    unordered_set<int> acceptedStudents;
    queue<Student> unallocatedStudents;

public:
    SortingHat(int totalCap) : capPerHouse(totalCap / 4) {}

    void registerStudent(int roll, string classChar, string foodChar)
    {
        if (acceptedStudents.find(roll) != acceptedStudents.end())
        {
            return;
        }

        if (houses[classChar][foodChar].size() < capPerHouse)
        {

            houses[classChar][foodChar].push(roll);
            acceptedStudents.insert(roll);
        }

        else
        {
            unallocatedStudents.push(Student(roll, classChar, foodChar));
        }
    }

    void processRegistrations(const vector<Student> &students)
    {
        for (const auto &student : students)
        {
            registerStudent(student.rollNumber, student.classType,
                            student.foodPreference);
        }
    }

    void displayBoardingHouses()
    {
        for (auto &classPref : houses)
        {
            for (auto &foodPref : classPref.second)
            {
                cout << classPref.first << foodPref.first << " : [";
                while (!foodPref.second.empty())
                {
                    cout << foodPref.second.front();
                    foodPref.second.pop();
                    if (!foodPref.second.empty())
                    {
                        cout << ",";
                    }
                }
                cout << "]" << endl;
            }
        }

        cout << "NA: [";
        while (!unallocatedStudents.empty())
        {
            cout << unallocatedStudents.front().rollNumber;
            unallocatedStudents.pop();
            if (!unallocatedStudents.empty())
            {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
};

int main()
{
    string init;
    cin >> init;
    int totalCap;
    cin >> totalCap;

    SortingHat sortingHat(totalCap);

    vector<Student> students = {};

    while (true)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "fin")
            break;

        int roll;
        cin >> roll;
        string className;
        cin >> className;
        string foodPref;
        cin >> foodPref;

        students.push_back(Student(roll, className, foodPref));
    }

    sortingHat.processRegistrations(students);
    sortingHat.displayBoardingHouses();

    return 0;
}