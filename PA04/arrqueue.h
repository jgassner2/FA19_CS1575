//Name: Joanthan Gassner
//SID: 12299764
//Class: CS1575 Sec A
//Instructor: Dr. Morales
//Date: 11-11-19



#ifndef ARRQUEUE_H
#define ARRQUEUE_H

#include "abstractqueue.h"

template <typename T>
class ArrQueue : public AbstractQueue<T>
{
  private:
    //int m_size;
    //int m_max;
    //T * m_data;

  public:
    bool isEmpty() const;
};

#include "arrqueue.hpp"
#endif
