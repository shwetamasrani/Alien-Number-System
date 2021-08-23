#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> alienNum = {'!', '@', '^', '&', '*'};
    string n, number = "", nextNum = "";
    cin>>n;
    for(int i=0; i<n.size(); i++)
    {
        auto it = find(alienNum.begin(), alienNum.end(), n[i]);
        number += to_string(it - alienNum.begin());
    }
    //cout<<number<<endl<<number.size()<<endl;
    int carry=0, curr =0;
    for(int i = number.size()-1; i>=0; i--)
    {
        curr = (int)number[i] - 48 + carry; 
        //cout<<curr<<" ";
        if(i == number.size() -1)
        {
            curr += 1;
        }
        if(curr == alienNum.size())
        {
            curr = 0;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        //cout<<curr<<"curr ";
        nextNum += alienNum[curr];
    }
    reverse(nextNum.begin(), nextNum.end());
    cout<<nextNum;
    return 0;
}