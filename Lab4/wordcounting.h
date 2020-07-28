/*
 * Course: CS-2040-041
 * Spring 2020
 * Lab 4 - Term Frequency
 * Name: Stuart Harley
 * Created: 04/09/2020
 */

#ifndef WORDCOUNTING_H
#define WORDCOUNTING_H

#include <fstream>

/**
 * @brief Creates an array of stop words from the stop file
 * @param ptr a pointer to the input file stream for the stop words
 * @param a pointer where the array will be built
 * @return the size of the array
 */
int getStopWords(std::ifstream* finptr, std::string* stops);

/**
 * @brief Creates an array of the words from the text file and counts their occurances
 * @param finptr the file pointer
 * @param words the words
 * @param wordcount an array of the word counts
 * @param stops the array of stop words
 * @param stop_size the size of the stop words array
 * @return the size of the array
 */
int getWords(std::ifstream* finptr, std::string* words, int* wordcount, std::string* stops, int stop_size);

/**
 * @brief Calculates and prints the word frequencies (highest first)
 * @param words the array of words
 * @param wordcount the associated array of counts
 * @param words_size the size of the words and wordcount arrays
 * @param total_words the total number of counted words
 */
void printFrequencies(std::string* words, int* wordcount, int words_size, int total_words);

#endif