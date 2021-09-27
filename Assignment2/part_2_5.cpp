#include<iostream>
using namespace std;

extern "C"
{
     #include<stdio.h>    // Include C Header
     int n;               // Declare a Variable
     void func(int,int);  // Declare a function (function prototype)
}

int main()
{
    int a, b;
    cin >> a >> b;
    func(a, b);   // Calling function . . .
    return 0;
}

// Function definition . . .
void func(int m, int n)
{
    cout << m + n << endl;
}

