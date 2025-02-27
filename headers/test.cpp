#include <iostream>
#include <string>
#include <cctype>

using namespace std;
int main()
{
    string s;
    int x;
    cin>>x;
    if(s.empty()){
        cout<<"bos ola bilmez";
        return 0;
    }
    for (char c:s)
    {
        if(!isdigit(c)){
            cout<<"please enter a valid number";
        }
    }


   cout<<x;
}