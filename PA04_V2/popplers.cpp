//Name: Joanthan Gassner
//SID: 12299764
//Class: CS1575 Sec A
//Instructor: Dr. Morales
//Date: 11-11-19


#include <iostream>
//#include <vector>
#include <string>
#include <sstream>
#include "abstractqueue.h"

using namespace std;



//For now, placing the queue class here in main program for simplicity.
//Will move to a seperate file once things are working.
template <typename T>
class ArrQueue : public AbstractQueue<T>
{
  public:
    int m_size;
    int m_max;
    T * m_data;
  public:
  ArrQueue(): m_size(0), m_max(0), m_data(NULL) {};
  ArrQueue(int s, const T& x);
  bool isEmpty() const;
  const T& front() const throw (Oops);
  const T& back() const throw (Oops);
  void enqueue(const T& x);
  void dequeue();
  void clear();
  ~ArrQueue();

  //My Functions
  void grow();
  int size() const;
  T& operator[](int i);

};
template <typename T>
std::ostream& operator<< (std::ostream& out, const ArrQueue<T>& list);

//Customer class
class Customers{
  public:
    string m_name;
    int m_numDesiredPopplers;
    int m_numEaten;

};

//MAIN
int main()
{
  ArrQueue<Customers> FisheyJoes;  //using the vector for now as a queue
  //std::vector<Customers> FisheyJoes; //For checking front-end
  int numCustomers, fewestPopplers, mostPopplers;
  string ateLeast, ateMost;
  Customers tmp;

  //Get the customers lined up!

  //Below is one way but I am not sure it is a gurantee about type conversion.

  cin >>numCustomers;
  for (int k=0; k<=numCustomers; k++) {
    cin >> tmp.m_name >> tmp.m_numDesiredPopplers;
    FisheyJoes.enqueue(tmp);
  }

//Below is buggy
/*
 string inputString;
 cin >> numCustomers;
 for (int k=0; k<=numCustomers; k++) {
  getline(cin,inputString);
  int pos = inputString.find(" ");

  //Start placing the data into the temporary customer placeholder
  tmp.m_name = inputString.substr(0,pos);
  string numToConvert = inputString.substr(pos+1);  //Get the number from the input
  stringstream woot(numToConvert);  //Using stringstream class for conversion
  woot >> tmp.m_numDesiredPopplers;  //Store it as an integer.  I guess the above would have worked.

  //Placing the customers in the queue
  FisheyJoes.enqueue(tmp);
 }
*/
for (int k=0; k<numCustomers; k++) {
  cout << FisheyJoes[k].m_name << " " << FisheyJoes[k].m_numDesiredPopplers << endl;
}





cout << endl << "End Program" << endl;
  return 0;
}

template <typename T>
bool ArrQueue<T>::isEmpty() const {
  if (m_size == 0)
    return true;
  else
    return false;
}

template <typename T>
const T& ArrQueue<T>::front() const throw (Oops) {
  try {
    if (m_size == 0) {
      throw Oops("x");
    }
    else {
      return m_data[0];
    }
  }
  catch (Oops) {
    cout << "Empty Queue!!!!" << endl;
  }
}

template <typename T>
const T& ArrQueue<T>::back() const throw (Oops) {
  try {
    if (m_size == 0) {
      throw Oops("x");
    }
    else {
      return m_data[m_size-1];
    }
  }
  catch (Oops) {
    cout << "Empty Queue!!!!" << endl;
  }

}

template <typename T>
void ArrQueue<T>::enqueue(const T& x) {
  //Check to see if array is full
  if (m_size == m_max) {
    grow();
  }
  m_data[m_size] = x;
  m_size++;
}

template <typename T>
void ArrQueue<T>::dequeue() {
  //Empty Queue Check
  if (m_size == 0) {
    return;
  }

 //m_size-1 prevents walking off list
  for (int k=0; k<(m_size-1);k++) {
    m_data[k] = m_data[k+1];
  }
  m_size--;

}

template <typename T>
void ArrQueue<T>::clear() {
  delete [] m_data;
  m_data = NULL;
  m_size = 0;
  m_max = 0;
}

template <typename T>
ArrQueue<T>::~ArrQueue() {
  delete [] m_data;
  m_data = NULL;
  m_size = 0;
  m_max = 0;
}

//Function defintions for my Functions
template <typename T>
ArrQueue<T>::ArrQueue(int s, const T& x) {
  //initialze values
  m_size = s;
  m_max =s;
  m_data = new T [m_max];

  //fill the array with copies of 'x'
  for (int k=0; k<m_size; k++)
    m_data[k] = x;
}




template <typename T>
void ArrQueue<T>::grow() {
  T * tmp; //Get a temporay pointer to a templated object of type T

  //Create new array
  if  (m_max == 0) {  //Checks for empty/new list
    tmp =  new T [2];
  }
  else {
    tmp = new T [m_max * 2];
  }

  //Copy over data
  for (int k=0; k<m_size; k++) {
    tmp[k] = m_data[k];
  }

  //delte old array
  delete [] m_data;

  //set pointer to newly created and copied array
  m_data = tmp;

  //set new upper bound
  if (m_max == 0) {
    m_max = 2;
  }
  else {
    m_max = m_max * 2;
  }
}

template <typename T>
int ArrQueue<T>::size() const {
  return m_size;
}

template <typename T>
T& ArrQueue<T>::operator[](int i) {
  try {
    if (i< 0 || i > m_max) {
      throw Oops("x");
    }
    else {
      return m_data[i];
    }
  }
  catch (Oops) {
    cout << "Empty Queue!!!!" << endl;
  }
}





// Purpose: prints an ArrayQueue
template <typename T>
std::ostream& operator<< (std::ostream& out, const ArrQueue<T>& alist)
{
  out << "[ ";
  for (int i=0; i < alist.m_size; i++){
    out << alist.m_data[i] << ", ";
  }
  out << "]";
  return out;
}
