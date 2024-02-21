#include <fstream>
#include <random>
#include <string>
#include <iostream>
int main(){
    for (int i = 11; i <= 1000; i++)
    {
        std::string filename = "./unittest/list_input_test/test_input_" + std::to_string(i);
        std::ofstream ofs;
        ofs.open(filename);
        if (!ofs.is_open()) {
            std::cout << "Failed to open file " << filename << std::endl;
            return 1;
        }
    // Seed the random number generator
        std::random_device rd;
        std::mt19937 gen(rd()); // Mersenne Twister pseudo-random generator engine

    // Define distributions for each variable
        std::uniform_int_distribution<> hp_distribution(0, 666);
        std::uniform_int_distribution<> exp_distribution(0, 600);
        std::uniform_int_distribution<> m_distribution(0, 3000);
        std::uniform_int_distribution<> e_distribution(0, 99);

    // Generate random numbers
        int hp1 = hp_distribution(gen);
        int hp2 = hp_distribution(gen);
        int exp1 = exp_distribution(gen);
        int exp2 = exp_distribution(gen);
        int m1 = m_distribution(gen);
        int m2 = m_distribution(gen);
        int e1 = e_distribution(gen);
        int e2 = e_distribution(gen);
        int e3 = e_distribution(gen);

    // Output the generated values
        ofs << hp1 << " " << hp2 << std::endl;
        ofs << exp1 << " " << exp2 << std::endl;
        ofs << m1 << " " << m2 << std::endl;
        ofs << e1 << " " << e2 << " " << e3 << std::endl;
    }
    return 0;
}