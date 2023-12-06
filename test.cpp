#include <iostream>
#include "./sorting_hat.cpp"

using namespace std;

string vec_to_str(vector<string> vec)
{
    string out;

    for (const auto &item : vec)
    {
        out += item;
    }

    return out;
}

void test(int test_number, SortingHat sortingHat, vector<Student> students, string expectedStr)
{
    sortingHat.processRegistrations(students);
    auto out = sortingHat.displayBoardingHouses();

    if (vec_to_str(out) != expectedStr)
    {
        cout << "Test " << test_number << " FAILED\n";
        throw("Data not matching on test" + to_string(test_number));
    }

    cout << "Test " << test_number << " OK\n";
}

int main()
{
    test(0, SortingHat(12), {}, "");
}