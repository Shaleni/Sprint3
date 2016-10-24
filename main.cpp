#include <iostream>
#include <fstream>
#include <cstring>
#include "vector.h"
#include "dsstring.h"
#include "queue.h"

using namespace std;


int partition (Vector<String> &arr, int low, int high)
{
    int pivot = arr[low].size();    // pivot
    int i = (low);  // Index of smaller element

    for (int j = low; j < high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j].size() <= pivot)
        {
            i++;    // increment index of smaller element
            arr.swap(i, j);
            cout<<"i: "<<arr[i]<<" j: "<<arr[j]<<endl;
        }
    }
    arr.swap(i+1, high);
    return (i + 1);
}

int median(Vector<String> &words, int low, int high){
    int first = words[low].size();
    int middle = words[(low+high/2)].size();
    int last = words[high].size();
    int p = 0;

    if ((first<=middle && last>=middle) || (first>=middle && last<=middle)){
        //middle is the median
        p = words.size()/2;
    } else if ((middle<=first && last>=middle) || (middle>=first && last<=first)){
        //first is the median
        p = 1;
    } else {
        //last is the median
        p = words.size()-1;
    }
    return p;
}

void quicksort(Vector<String> &w, int low, int high){

    //choose pivot by median of 3
    int pivot = median(w, low, high);
    //cout<<"median: "<<pivot;

    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
              at right place */
        int pi = partition(w, low, high);

        // Separately sort elements before
        // partition and after partition
        quicksort(w, low, pi - 1);
        quicksort(w, pi + 1, high);
    }
}

int sasint (String s){
    int val = 0;
    for (int i=0;i<s.size();i++){
        val *=10;
        val += (s[i]-48);
        // cout << val <<endl;
    }
    return val;
}

void radixSort(Vector<String>& strings, int offset, int maxlen){
    if (offset <=maxlen){

        Queue<String> buckets[128];

        //Add all strings to buckets
        for (int i=0;i<strings.size();i++){
            buckets[(int)strings[i][-offset]].enqueue(strings[i]);
            //cout <<i<<endl;
        }

        strings.clear();

        //Dequeue all queues in order
        for (int j=0;j<128;j++){
            while (!buckets[j].isEmpty()){
                String s (buckets[j].dequeue());
                strings.add(s);
            }
        }

        radixSort(strings, ++offset, maxlen);
    }
}

int main(int argc, char* const argv[])
{
    //buffer
    char* buffer = new char[100];

    ifstream readFile;
    readFile.open(argv[1]);

    int number_of_solutions;
    int length_of_file;
    int max_word_length =0;

    if (readFile.is_open()){

        //First line contains length of file
        readFile.getline(buffer, 100);

    }
    length_of_file = sasint(String(buffer));

    //Create vector of words
    Vector<String> words (length_of_file);

    if(readFile.is_open()){
        //Second line contains length of solution list
        readFile.getline(buffer, 100);
        number_of_solutions = sasint(String(buffer));

        //Read in the words
        for (int i=0; i<length_of_file;i++){
            readFile >> buffer;
            String currentLine = buffer;
            words.add(currentLine);

            //Update max length
            if (currentLine.size()>max_word_length) max_word_length=currentLine.size();
        }
        readFile.close();
    }
    else cout << "Failed to open file" << endl;
    delete[] buffer;

    quicksort(words, 0, words.size()-1);
    //radixSort(words,0,max_word_length);



    //Write output file
    ofstream out;
    out.open(argv[2]);
    if (out.is_open()){
        for (int i=0; i<number_of_solutions; i++){
            out << words[i] <<endl;
        }
        out.close();
    }
    else cout << "Failed to write output file" <<endl;

    return 0;
}

