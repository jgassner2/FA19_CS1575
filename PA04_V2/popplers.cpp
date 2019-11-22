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



};


//MAIN
int main()
{
  ArrQueue<int> t;

  if(t.isEmpty())
    cout << endl <<"Banana Pancake" << endl;


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
