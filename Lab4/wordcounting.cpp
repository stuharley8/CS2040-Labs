/*
 * Course: CS-2040-041
 * Spring 2020
 * Lab 4 - Term Frequency
 * Name: Stuart Harley
 * Created: 04/09/2020
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string removePunct(string word);
bool checkIfWordInStops(string word, string* stops, int stop_size);

/**
 * @brief Creates an array of stop words from the stop file
 * @param ptr a pointer to the input file stream for the stop words
 * @param a pointer where the array will be built
 * @return the size of the array
 */
int getStopWords(ifstream* finptr, string* stops) {
    string word;
    int index = 0;
    *finptr >> word;
    while(*finptr) {
        stops[index] = word;
        *finptr >> word;
        index++;
    }
    return index;
}

/**
 * @brief Creates an array of the words from the text file and counts their occurances
 * @param finptr the file pointer
 * @param words the words
 * @param wordcount an array of the word counts
 * @param stops the array of stop words
 * @param stop_size the size of the stop words array
 * @return the size of the array
 */
int getWords(ifstream* finptr, string* words, int* wordcount, string* stops, int stop_size) {
    string word;
    int size = 0;
    *finptr >> word;
    while(*finptr) {
        word = removePunct(word);
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        bool stop_word = checkIfWordInStops(word, stops, stop_size);
        if(!stop_word) {
            bool word_in_words = false;
            for(int i = 0; i < size; i++) {  // Checks if word already in array
                if(words[i] == word) {
                    word_in_words = true;
                    wordcount[i]++; // adds one to the count if already in array
                    break;
                }
            }
            if(!word_in_words) {
                words[size] = word; // adds the word to array if not already present
                wordcount[size] = 1;
                size++;
            }
        }
        *finptr >> word;
    }
    return size;
}

/**
 * @brief Calculates and prints the word frequencies (highest first)
 * @param words the array of words
 * @param wordcount the associated array of counts
 * @param words_size the size of the words and wordcount arrays
 * @param total_words the total number of counted words
 */
void printFrequencies(string* words, int* wordcount, int words_size, int total_words) {
    for(int x = 0; x < words_size; x++) {
        int max_index = 0;
        for(int i = 0; i < words_size; i++) {
            if(wordcount[i] > wordcount[max_index]) {
                max_index = i;
            }
        }
        cout << words[max_index] << ": " << wordcount[max_index]*1.0/total_words << endl;
        wordcount[max_index] = 0;
    }
}

/**
 * @brief Removes punctuation from a string
 * @param word the word
 * @return the word without punctuation
 */
string removePunct(string word) {
    for(int i = 0, len = word.size(); i < len; i++) {
        if(ispunct(word[i])) {
            word.erase(i--, 1);
            len = word.size();
        }
    }
    return word;
}

/**
 * @brief Checks if a word is a stop word
 * @param word the word to check
 * @param stops the array of stop words
 * @param stop_size the amount of words in stop words
 * @return true if a stop word, false if not
 */
bool checkIfWordInStops(string word, string* stops, int stop_size) {
    for(int i = 0; i < stop_size; i++) {
        if(word == stops[i]) {
            return true;
        }
    }
    return false;
}