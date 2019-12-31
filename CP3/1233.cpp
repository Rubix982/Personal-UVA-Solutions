#include "stdc++.h"
using namespace std;

int main(void)
{

    std::tm time_in = { 0, 0, 0, 9, 10, 2020 - 1900 };

    std::time_t time_temp = std::mktime(&time_in);

    const std::tm * time_out = std::localtime(&time_temp);

    cout << time_out->tm_mday << "\n";

    return 0;
}