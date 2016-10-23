#include <iostream>
#include <cstring>
#include <dsstring.h>
#include <vector.h>

String::String(){
    len=0;
    st=new char[len+1];
    //create null terminator
    st[len]=0;
}

String::String(const char* s){
    //length of s
    len=strlen(s);

    //initalize the new string
    st=new char[len+1];
    if (len!=0){
    //copy over string
    strcpy(st, s);
    }
    //create null terminator
    st[len]=0;
}

String::String(const String& s){

    //length of the string being passed from s
    len=s.len;

    //initialize the new string
    st=new char[len+1];
    if(len!=0){
        //copy s into st
        strcpy(st, s.st);
    }
    //create null terminator
    st[len]=0;

}

String& String::operator= (const char* RHS){
    //get the length of RHS
    len=strlen(RHS);

    st=new char[len+1];
    //copy RHS into st
    strcpy(st, RHS);

    //create null terminator
    st[len]=0;

    return *this;
}

String& String::operator= (const String& RHS){
    len=RHS.len;
    st=new char[len+1];

    //copy RHS into st
    strcpy(st, RHS.st);

    //create null terminator
    st[len]=0;

    return *this;
}

String String::operator+ (const String& RHS){
    int RHSlen=RHS.len;
    int LHSlen=len;
    //length of concatenated string
    int newLen=RHSlen+LHSlen;

    char* newSt=new char [newLen+1];

    //put in the LHS
    for (int i=0; i<LHSlen; i++){
        newSt[i]=st[i];
    }

    //add RHS
    int cnt=0;
    for (int j=LHSlen; j<newLen; j++){
        newSt[j]=RHS.st[cnt];
        cnt+=1;
    }

    //add null terminator
    newSt[newLen]=0;

    String concat(newSt);

    delete[] newSt;

    return concat;
}

bool String::operator== (const char* RHS){
    //if strcomp is 0, they are the same
    if (strcmp(RHS, st)==0){
        return true;
    }

    //otherwise
    return false;
}

bool String::operator== (const String& RHS){
    //if strcomp is 0, they are the same
    if (strcmp(RHS.st, st)==0){
        return true;
    }

    //otherwise
    return false;
}

bool String::operator!= (const char* RHS){
    //if strcomp is 0, they are the same
    if (strcmp(RHS, st)==0){
        return false;
    }

    //otherwise
    return true;
}

bool String::operator!= (const String& RHS){
    //if strcomp is 0, they are the same
    if (strcmp(RHS.st, st)==0){
        return false;
    }

    //otherwise
    return true;


}

//case sensitive function that uses strcmp to determine alphabetical order
bool String::operator> (const String& RHS){
    if (strcmp(st, RHS.st)>0){
        return true;

    }
    return false;
}

char& String::operator[] (const int RHS){
    int index=RHS;
    //for negative cases
    if (RHS<0){
        index=RHS+len;
    }
    return st[index];
}

int String::size(){
    return(len);
}

void String::toLowerCase(){
    for (int i=0; i<len; i++){
        st[i]=tolower(st[i]);
    }
}


void String::toUpperCase(){
    for (int i=0; i<len; i++){
        st[i]=toupper(st[i]);
    }
}

int String::toNum(){
    char* num = new char[len];
    for (int i=0; i<len; i++){
        num[i]=st[i];
    }
    int n=atoi(num);
    delete[] num;
    return n;
}

Vector<String> String::split(char delim){
    Vector<String> splitVec;
    int i=0;
    do {
        char* part = new char[100];
        int j=0;
        do {
            part[j]=st[i];
            j++;
            i++;
        } while(st[i]!=delim && i!=len);
        i++;

        String temp(part);
        splitVec.add(temp);
        delete[] part;
    } while (i!=len+1);

    return splitVec;
}

String String::substring(int start, int end){
    //if start is negative
    if (start<0){
        start+=len;
    }

    //if end is negative
    if (end<0){
        end+=len;
    }

    //length of the substring
    int length=(end-start);

    //create substring
    char* substr=new char[length+1];


    for (int i=0; i<length; i++){
        substr[i]=st[start];
        start+=1;
    }
    //add null terminator
    substr[length]=0;

    String substring(substr);


    delete[] substr;

    return substring;
}

char* String::c_str(){
    return st;
}

std::ostream& operator<< (std::ostream& output, const String& RHS){
    return output<<RHS.st;
}

String::~String(){
    delete[] st;
}
