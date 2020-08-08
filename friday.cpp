/*
ID: hlw88951
PROG: friday
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
static constexpr int star_year = 1990;
static bool leap_year(int year)
{
    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
        return true;
    else
        return false;
}
int main()
{
    ifstream fin("friday.in");
    ofstream fout("friday.out");

    vector<int> week(7, 0);
    vector<int> week_day = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int n, day_13 = 6;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            week[day_13]++;
            if (leap_year(1900 + i) && j == 1)
            {
                day_13++;
            }
            day_13 = (day_13 + week_day[j]) % 7;
        }
    }
    fout << week[6];
    for (int i = 0; i <= 5; i++)
        fout << " " << week[i];

    fout <<endl;
}
