/*
ID: hlw88951
PROG: ride
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main()
{
    /*
    ofstream fout("test.out");
    ifstream fin("test.in");
    int a, b;
    fin >> a >> b;
    fout << a + b << endl;
*/
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    map<char, int> char_int;
    char c = 'A';
    int num1 = 1, num2 = 1;
    for (int i = 1; i <= 26; i++)
    {
        char_int[c++] = i;
    }
    string str1, str2;
    fin >> str1 >> str2;
    for (char ch : str1)
    {
        num1 *= char_int[ch];
    }
    for (char ch : str2)
    {
        num2 *= char_int[ch];
    }
    if(num1%47==num2%47)
        fout << "GO\n";
    else
        fout << "STAY\n";
    return 0;
}
