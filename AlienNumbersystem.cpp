#include<bits/stdc++.h>
using namespace std;

string succ_alien(string input, string NumberSys)
{
    vector<char> alienNumSys;
    string NumberInput = "", nextNum = "";
    for(int i=0; i<NumberSys.size(); i++)
    {
        alienNumSys.push_back(NumberSys[i]);
    }

    for(int i=0; i<input.size(); i++)
    {
        auto it = find(alienNumSys.begin(), alienNumSys.end(), input[i]);
        NumberInput += to_string(it - alienNumSys.begin());
    }

    int carry=0, curr =0;
    for(int i = NumberInput.size()-1; i>=0; i--)
    {
        curr = (int)NumberInput[i] - 48 + carry; 
        if(i == NumberInput.size() -1)
        {
            curr += 1;
        }
        if(curr == alienNumSys.size())
        {
            curr = 0;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        nextNum += alienNumSys[curr];
    }
    reverse(nextNum.begin(), nextNum.end());
    return nextNum;
}


int main()
{
    string str, alienNum;
    cout<<"Enter Number System:\n";
    cin>>alienNum;
    cout<<"Enter a number of above number System:\n";
    cin>>str;
    cout<<"Next Number According to Above Alien Number system:\n";
    cout<<succ_alien(str, alienNum);
    return 0;
}