/*
Name:                   Jin Jung
Student ID:             2329401
Email:                  jijung@chapman.edu
Course no. & Section:   CS350-02
Assignment:             6
*/

/*
  driver file to test functionality of Sort class and perform runtime analysis of four sorting algorithms.
*/

#include <ctime>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Sort.h"

using namespace std;

int main(int argc, char** argv) {
  //used to generate different size of input data. Uncomment to generate new file with different data size
/*
  srand(time(NULL));
  Sort::generateData("data1.txt",500000);
*/
  string filePath = "";
  if(argc > 1 && argc < 3) {  //check for valid number of terminal arguments
    filePath = argv[1];
    if (filePath.find(".txt") == -1)
    {
      filePath += ".txt";
    }
  }
  else
  {
    cout << "Invalid terminal arguments\nPlease use format: ./[executable] [filelocation]\n";
    return 0;
  }
  ifstream istream(filePath);
  if(istream.is_open()) { //verify filePath is valid
    istream.close();

    Sort bbTest(filePath);  //instantiate object Sort to perform bubble sort test
    std::clock_t start;
    double duration;
    //format output:
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(4);
    start = std::clock();
    cout << "Bubble Sort start time: " << start << endl;
    bbTest.bubbleSort(bbTest.unsortedlist, bbTest.size);

    cout << "Bubble Sort end time: " << std::clock() << endl;
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"Bubble Sort time elapsed: "<< duration << "s" << endl;;
    cout << "test data size: " << bbTest.size << endl;

    Sort insTest(filePath); //instantiate object Sort to perform insertion sort test

    start = std::clock();
    cout << "Insertion Sort start time: " << start << endl;
    insTest.insertionSort(insTest.unsortedlist, insTest.size);

    cout << "Insertion Sort end time: " << std::clock() << endl;
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"Insertion Sort time elapsed: "<< duration << "s" << endl;;
    cout << "test data size: " << insTest.size << endl;

    Sort qsTest(filePath); //instantiate object Sort to perform quick sort test

    start = std::clock(); //get processor time
    cout << "Quick Sort start time: " << start << endl;
    qsTest.quickSort(qsTest.unsortedlist, 0,qsTest.size);

    cout << "Quick Sort end time: " << std::clock() << endl;
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"Quick Sort time elapsed: "<< duration << "s" << endl;;
    cout << "test data size: " << qsTest.size << endl;

    Sort gnomeTest(filePath); //instantiate object Sort to perform gnome sort test
    start = std::clock();
    cout << "gnome Sort start time: " << start << endl;
    gnomeTest.gnomeSort(gnomeTest.unsortedlist, gnomeTest.size);

    cout << "gnome Sort end time: " << std::clock() << endl;
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"gnome Sort time elapsed: "<< duration << "s" << endl;;
    cout << "test data size: " << gnomeTest.size << endl;
  }
  else {
    cout << "File not found! Exiting..\n";
    exit(1);
  }
  getchar();
  return 0;
}
