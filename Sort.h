/*
Name:                   Jin Jung
Student ID:             2329401
Email:                  jijung@chapman.edu
Course no. & Section:   CS350-02
Assignment:             6
*/

/*
  .h file for Sort class. Class Invariant: Every instance of this object will have a string filePath, double* unsortedlist, and int size.
  double* unsortedlist and int size will be initialized automatically once data file is read.
*/

#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Sort {
public: //member variables
  string filePath;
  double* unsortedlist;
  int size;

public:
  Sort(string filePath);  //main constructor
  ~Sort();  //destructor
  static void quickSort(double arr[], int low, int high);
  static void insertionSort(double arr[], int size);
  static void bubbleSort(double arr[], int size);
  static void gnomeSort(double arr[], int size);

  static int partition(double arr[], int low, int high);  //helper function for quick sort
  static void swap(double& a, double& b); //swaps two indices in an array
  static void generateData(string filePath, int dataSize); //used when generating new data file
  void readData(string filePath); //used to read data
  void printArray(); //used to verify array has been sorted
};

#endif /*SORT_H*/
