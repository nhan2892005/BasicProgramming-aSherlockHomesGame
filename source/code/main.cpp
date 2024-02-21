/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2023
* Author: Vu Van Tien
* Date: 02.02.2023
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "study_in_pink1.h"
using namespace std;

void sa_tc_01() {
    for (int i = 11; i <= 1000; i++)
    {
        string input_file("./unittest/list_input_test/test_input_");
        string output_file("./unittest/list_output_test/test_output_");
        input_file += to_string(i);
        output_file += to_string(i);
        ofstream out(output_file);
        int HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3;
        if (!readFile(input_file, HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3)) {
            return;
        }

        out << "----- Mission 1 -----" << endl;
        out << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", E1: " << E1 << endl;
        int result = firstMeet(EXP1, EXP2, E1);
        out << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", result: " << result << endl;

        out << "----- Mission 2 -----" << endl;
        out << "HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", E2: " << E2 << endl;
        result = traceLuggage(HP1, EXP1, M1, E2);
        out << "HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << endl;

        out << "----- Mission 3 -----" << endl;
        out << "HP1: " << HP1 << ", EXP1: " << EXP1 << ", HP2: " << HP2 << ", EXP2: " << EXP2 << ", E3: " << E3 << endl;
        result = chaseTaxi(HP1, EXP1, HP2, EXP2, E3);
        out << "HP1: " << HP1 << ", EXP1: " << EXP1 << ", HP2: " << HP2 << ", EXP2: " << EXP2 << ", result: " << result << endl;
        
        out.close();
    }
}

int main(int argc, const char * argv[]) {
    sa_tc_01();
/*
    cout << checkPassword("Password@123", "example@example.com") << endl;
    cout << checkPassword("123xyz", "pink@gmail.com") << endl;
    cout << checkPassword("012345pink#pink", "pink@gmail.com") << endl;

    const char *arr_pwds[] = {"pink123", "xxxx@xxxx", "123xyz", "pink#pink", "pink#pink", "pink123"};
    int num_pwds = sizeof(arr_pwds) / sizeof(arr_pwds[0]);

    cout <<  findCorrectPassword(arr_pwds, num_pwds) << endl;
*/
    return 0;
}