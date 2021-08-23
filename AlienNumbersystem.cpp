#include<bits/stdc++.h>
using namespace std;

// Function to find the successor of given input number in New Alien Number system provided by user
string succ_alien(string input, string NumberSys)
{
    vector<char> alienNumSys;   // To map Alien alphabet with digits
    string NumberInput = "", nextNum = "";

    // Creating a dictionary to map Numbers with Alien Alphabet
    for(int i=0; i<NumberSys.size(); i++)
    {
        alienNumSys.push_back(NumberSys[i]);
    }

    // Converting Input alient system number to digits of Base = Number of characters in Alien Number system
    for(int i=0; i<input.size(); i++)
    {
        auto it = find(alienNumSys.begin(), alienNumSys.end(), input[i]);
        NumberInput += to_string(it - alienNumSys.begin());
    }

    // Adding 1 to the above number
    int carry=0, curr =0;
    for(int i = NumberInput.size()-1; i>=0; i--)
    {
        curr = (int)NumberInput[i] - 48 + carry; 
        if(i == NumberInput.size() -1)          // Add one to last digit
        {
            curr += 1;
        }
        if(curr == alienNumSys.size())          // Checking for carry
        {
            curr = 0;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        nextNum += alienNumSys[curr];           // Appeding the digits from right 
    }
    reverse(nextNum.begin(), nextNum.end());    // Reversing to get the origin Number
    return nextNum;
}


int main()
{
    string str, alienNum;
    cout<<"Enter Number System:\n";
    cin>>alienNum;                  // Input Alien Number System
    cout<<"Enter a number of above number System:\n";
    cin>>str;                       // Input Number 
    cout<<"Next Number According to Above Alien Number system:\n";
    cout<<succ_alien(str, alienNum);    //  Successor of given number in Alien Number System
    return 0;
}