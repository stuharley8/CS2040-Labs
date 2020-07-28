/*
 * Course: CS-2040-041
 * Spring 2020
 * Lab 4 - Term Frequency
 * Name: Stuart Harley
 * Created: 04/09/2020
 */

#include "wordcounting.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    cout << "Enter a text file to analyze (include the preceeding ../ and the file ext):" << endl;
    string filename;
    cin >> filename;
    ifstream wordsfin;
    wordsfin.open(filename);
    if(!wordsfin.good()) {
        cout << "Unable to load file" << endl;
        return 1;
    }
    cout << "Enter a text file of stop words (include the preceeding ../ and the file ext):" << endl;
    cin >> filename;
    ifstream stopfin;
    stopfin.open(filename);
    if(!stopfin.good()) {
        cout << "Unable to load file" << endl;
        return 1;
    }
    string stops[1000];
    int stops_size = getStopWords(&stopfin, &stops[0]);
    string words[1000];
    int wordcount[1000];
    int words_size = getWords(&wordsfin, &words[0], &wordcount[0], &stops[0], stops_size);
    int total_words = 0;
    for(int i = 0; i < words_size; i++) {
        total_words += wordcount[i];
    }
    cout << "\nThe term frequencies are:" << endl;
    printFrequencies(&words[0], &wordcount[0], words_size, total_words);
    return 0;
}