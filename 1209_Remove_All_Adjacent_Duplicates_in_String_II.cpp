#include<iostream>
#include<vector>

using namespace std;


void removeDuplicates(string s, int k)
{
    vector<pair<char, int>> vecpair;

    for (char ch : s)
    {
        if (vecpair.size() == 0 || vecpair.back().first != ch)
        {
            vecpair.push_back({ch, 1});
        }
        else
        {
            vecpair.back().second++;
        }
        cout<<ch<<" "<<vecpair.back().first<<endl;
        if (vecpair.back().second == k)
        {
            vecpair.pop_back();
        }
    }
}

int main()
{
    string str = "deeedbbcccbdaa";
    int k = 3;

    removeDuplicates(str,k);

    return 0;
}