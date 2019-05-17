/*
Name:                   Jin Jung
Student ID:             2329401
Email:                  jijung@chapman.edu
Course no. & Section:   CS350-02
Assignment:             6
*/

/*
  .cpp implementation file for Sort class.
*/

#include "Sort.h"

Sort::Sort(string filePath) {
  filePath = filePath;
  readData(filePath);
}
Sort::~Sort() {}

void Sort::bubbleSort(double listtosort[], int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = i+1; j < size; ++j) {
      if(listtosort[i] > listtosort[j]) { //if left array element > right arry element, swap
        swap(listtosort[i],listtosort[j]);
      }
    }
  }
}

void Sort::insertionSort(double listtosort[], int size) {
  for (int i = 1; i < size; ++i) {
    double x = listtosort[i]; //initially choose index 1 as key index
    int j = i;
    while (j > 0 && listtosort[j-1] > x) { //while beginning of array has not been reached and listtosort[j-1] > key index
      listtosort[j] = listtosort[j-1]; //shift right
      --j;
    }
    listtosort[j] = x; //replace listtosort[j] with value in key index
  }
}
void Sort::gnomeSort(double listtosort[], int size) {
  int curr = 0;
  while (curr < size) {
    if (curr == 0)  //if at the front of the array, step forward
      ++curr;
    if(listtosort[curr] >= listtosort[curr-1]) //if the value of curr and curr-1 indices are in order, step forward
      curr++;
    else {
      swap(listtosort[curr],listtosort[curr-1]); //else swap them and step back
      curr--;
    }
  }
  return;
}
void Sort::swap(double& a, double& b) {
  double t = a;
  a = b;
  b = t;
}
int Sort::partition (double arr[], int low, int high) {
  double pivot = arr[high]; //set pivot as last element in array
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++) { //iterate through all elements <= the last element
    if (arr[j] <= pivot) { //if current element <= pivot
      i++; //increment partition midpoint by 1
      swap(arr[i], arr[j]); //move lower value to left and higher value to right
    }
  }
  swap(arr[i+1], arr[high]); //swap once more
  return (i+1); //return midpoint of partitioned array where the left contains all elements < pivot, right contains all elements > pivot
}
void Sort::quickSort(double arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high); //ues partition function to
    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);
  }
}
void Sort::generateData(string filePath, int dataSize) { //used to generate data of type double between 0 and 10000
  int num = 0;
  num = (rand() % 10000); //generate random values between 0 and 10000
  ofstream ostream;
  ostream = ofstream(filePath);
  ostream << dataSize << endl; //first line of file is datasize
  for (int i = 0; i < dataSize; ++i) {
    num = rand() % 10000;
    double value = num + (static_cast<double>(RAND_MAX - rand())/RAND_MAX); //add decimal values of precision 2
    if (rand() % 2 != 0) //make half of data negative
      value *= -1;
    ostream << value << endl; //output value to data file
  }
  ostream.close();
}
void Sort::readData(string filePath) { //opens filepath stream and initializes int size and double* unsortedlist.
  ifstream istream(filePath);
  string line = "";
  getline(istream, line);
  size = stoi(line);
  unsortedlist = new double[size];
  for (int i = 0; i < size; ++i) {
    getline(istream,line);
    unsortedlist[i] = stof(line);
  }
  istream.close();
}
void Sort::printArray() { //prints all elements of array
  cout << "___________________________\n";
  for (int i = 0; i < size; ++i) {
    cout << unsortedlist[i] << endl;
  }
  cout << "___________________________\n";
}
