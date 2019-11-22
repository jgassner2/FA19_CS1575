//Name: Joanthan Gassner
//SID: 12299764
//Class: CS1575 Sec A
//Instructor: Dr. Morales
//Date: 11-11-19


#include <iostream>
#include "abstractqueue.h"
using namespace std;

//For now, placing the queue class here in main program for simplicity.
//Will move to a seperate file once things are working.
template <typename T>
class ArrQueue : public AbstractQueue<T>
{
  private:
    int m_size;
    int m_max;
    T * m_data;
  public:
  ArrQueue(): m_size(0), m_max(0), m_data(NULL) {};
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


};


//MAIN
int main()
{
  ArrQueue<int> t;

  if(t.isEmpty())
    cout << endl <<"Banana Pancake" << endl;
cout << endl << "Queue Size: " << t.size() << endl;
t.enqueue(1);
cout << endl << "Queue Size: " << t.size() << endl;




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

}

template <typename T>
const T& ArrQueue<T>::back() const throw (Oops) {

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

}

template <typename T>
void ArrQueue<T>::clear() {

}

template <typename T>
ArrQueue<T>::~ArrQueue() {
  delete [] m_data;
  m_data = NULL;
  m_size = 0;
  m_max = 0;
cout << endl << "Default destructor called." << endl;
}

//Function defintions for my Functions
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
