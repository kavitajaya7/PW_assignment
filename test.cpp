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
    test(0, SortingHat(12), {
                                Student(1, "B", "V"),
                                Student(2, "A", "V"),
                                Student(3, "A", "V"),
                                Student(4, "B", "NV"),
                                Student(5, "B", "V"),
                                Student(6, "A", "NV"),
                                Student(7, "A", "V"),
                                Student(8, "A", "NV"),
                                Student(9, "B", "NV"),
                                Student(10, "B", "V"),
                                Student(11, "A", "NV"),
                                Student(12, "B", "NV"),
                                Student(13, "A", "NV")
                            },
         "ANV : [6,8,11]\nAV : [2,3,7]\nBNV : [4,9,12]\nBV : [1,5,10]\nNA: [13]\n");
    test(0, SortingHat(12), {
                               Student(1, "B", "V"),
                               Student(2, "A", "V"),
                               Student(3, "A", "V"),
                               Student(4, "B", "NV"),
                               Student(5, "B", "V"),
                               Student(6, "A", "NV"),
                               Student(7, "A", "NV"),
                               Student(8, "A", "NV"),
                               Student(9, "B", "NV"),
                               Student(10, "B", "V"),
                               Student(11, "A", "NV"),
                               Student(12, "B", "NV"),
                               
                               
    }, 
    "ANV : [6,8,11]\nAV : [2,3,7]\nBNV : [4,9,12]\nBV : [1,5,10]\nNA : []\n");
    test(0, SortingHat(4), {}, "");
    test(0, SortingHat(16), {}, "");
}