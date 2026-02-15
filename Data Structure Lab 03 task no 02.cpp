#include<iostream>
using namespace std;
int main() 
{
    //Allocating memory for a single character
    char*ch=new char;
    cout<<"Enter a character: ";
    cin>>*ch;
    cout<<"Stored character: "<<*ch<<endl;
    //Deallocating memory
    delete ch;
    ch=nullptr;
    return 0;
}
