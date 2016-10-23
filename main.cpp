#include <iostream>
#include <fstream>
#include <cstring>
#include "vector.h"
#include "dsstring.h"

using namespace std;

int partition (&Vector<String> arr, int low, int high, int p)
{
    int pivot = arr[p].size();    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j].size() <= pivot)
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

void quicksort(&Vector<String> w, int low, int high){
    //choose pivot by median of 3
   int pivot = median(w);

   if (low < high)
       {
           /* pi is partitioning index, arr[p] is now
              at right place */
           int pi = partition(w, low, high, pivot);

           // Separately sort elements before
           // partition and after partition
           quicksort(arr, low, pi - 1);
           quicksort(arr, pi + 1, high);
       }
}


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

    readFile.getline(entry, 100);
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

