#include <iostream>
#include <fstream>
#include <cstring>
#include "vector.h"
#include "dsstring.h"

using namespace std;


int sasint (String s){
    int val = 0;
    for (int i=0;i<s.size();i++){
        val *=10;
        val += (s[i]-48);
        cout << val <<endl;
    }
    return val;
}

int main(int argc, char* const argv[])
{
    //buffer
    char* buffer = new char[100];

    ifstream readFile;
    readFile.open(argv[1]);
    if (readFile.is_open()){

        //First line contains length of file
        readFile.getline(buffer, 100);
        int length_of_file = sasint(String(buffer));

        //Second line contains length of solution list
        readFile.getline(buffer, 100);
        int number_of_solutions = sasint(String(buffer));

        //Read in the words



    }
    else cout << "Failed to open file" << endl;

    return 0;
}

