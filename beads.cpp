/*//实在是蒟蒻，只能暴力了(看到这条的人莫怪hhh
ID: hlw88951
PROG: beads
LANG: C++14                 
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
using namespace std;
int find_max(string s)
{
    char curr = s[0];
    int len = s.size(), count_head = 1, count_foot = 1;
    for (int i = 1; i < len; ++i)
    {
        if (curr == 'w'&&s[i]!='w')
        {
            curr = s[i];
            count_head++;
        }
        else if(s[i]=='w'||s[i]==curr)
            {
                count_head++;
            }
            else
                break;
    }
    curr = s[len - 1];
    for (int i = len - 2; i >= 0 ; --i)
    {
        if (curr == 'w' && s[i] != 'w')
        {
            curr = s[i];
            count_foot++;
        }
        else if (s[i] == 'w' || s[i] == curr)
        {
            count_foot++;
        }
        else
            break;
    }
    return count_foot + count_head > len ? len : count_foot + count_head;
}
int main()
{
    int len;
    string source;

 
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    
    fin >> len;
    fin >> source;
  
    source += source;
    int max_beads = numeric_limits<int>::min();
    for (int i = 0; i < len; i++)
    {
        string s(source, i, len);
        max_beads = max(max_beads, find_max(s));
    }
    fout << max_beads << "\n";
}
