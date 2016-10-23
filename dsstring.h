#ifndef STRING
#define STRING

#include <iostream>
#include <cstring>
#include <vector.h>

class String{

public:

    String();
    String(const char*);
    String(const String&);

    String& operator= (const char*);
    String& operator= (const String&);
    String operator+ (const String&);
    bool operator== (const char*);
    bool operator== (const String&);
    bool operator!= (const char*);
    bool operator!= (const String&);
    bool operator> (const String&);
    char& operator[] (const int);
    void sCopy(char* dest, int maxLength, char const* source);

    int size();
    void toLowerCase();
    void toUpperCase();
    int toNum();

    String substring(int, int);

    Vector<String> split(char);

    char* c_str();

    friend std::ostream& operator<< (std::ostream&, const String&);

    ~String();

private:

    int len; //length of the string (not including the null terminator)
    char * st; //the string


};


#endif

