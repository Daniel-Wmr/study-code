#include <iostream>
#include <string>

#include "helloWorld.hpp"


using namespace std;

void printFromHeader()
{
    cout << "Hello World from .hpp" << endl;
}


int main()
{
    cout << "Hello World!" << endl;
    printFromHeader();

    return 0;
}