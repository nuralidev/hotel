#include <iostream>
#include <string>
#include <cctype>

using namespace std;
int main()
{
    int x;
    cin>>x;
    while(cin.fail()){
        cout<<"Error please Enter a valid NUmber\n";
        cin.clear();
        cin.ignore(256,'\n');
        cin>>x;
    }
}