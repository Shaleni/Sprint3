#include <iostream>
#include <fstream>
#include <cstring>
#include "vector.h"
#include "dsstring.h"

using namespace std;

void quicksort(&Vector<String> w){
    //choose pivot by median of 3
   int pivot = median(w);
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int median(Vector<String> w){
    int first = words[1].size();
    int middle = words[(words.size()/2)].size();
    int last = words[words.size()-1].size();
    int p = 0;

    if ((first<middle && last>middle) || (first>middle && last<middle)){
        //middle is the median
        p = words.size()/2;
    } else if ((middle<first && last>middle) || (middle>first && last<first)){
        //first is the median
        p = 1;
    } else {
        //last is the median
        p = words.size()-1;
    }
    return p;
}


int main(int argc, char* const argv[])
{
    //buffer
    char* entry = new char[100];

    ifstream readFile;
    readFile.open(argv[1]);
    readFile.getline(entry, 99);


    return 0;
}

