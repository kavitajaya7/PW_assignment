#include <iostream>

#include "sorting_hat.cpp"

using namespace std;

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