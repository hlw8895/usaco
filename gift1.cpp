/*
ID: hlw88951
PROG: gift1
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
int main()
{

    ifstream fin("gift1.in");
    ofstream fout("gift1.out");

    map<string, int> name_money;
    int people_number = 0, money = 0, friend_number = 0;
    string name;
    vector<string> people;
    fin >> people_number;

    for (int i = 0; i < people_number; i++)
    {
        fin >> name;
        name_money[name] = 0;
        people.push_back(name);
    }
    while (people_number--)
    {
        fin >> name >> money >> friend_number;
        if (friend_number != 0)
        {
            name_money[name] -= (money / friend_number) * friend_number;
        }

        for (int i = 0; i < friend_number; ++i)
        {
            fin >> name;
            name_money[name] += money / friend_number;
        }
    }
    for (string ss : people)
    {
        fout << ss << " " << name_money[ss] << endl;
    }
}
