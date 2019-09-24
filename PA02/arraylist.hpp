//Name: Joanthan Gassner
//SID: 12299764
//Class: CS1575 Sec A
//Instructor: Dr. Morales
//Date: 9-24-19

template <typename T>
void ArrayList<T>::grow() {
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
ArrayList<T>::~ArrayList() {
  delete [] m_data;
  m_data = NULL;
  m_size = 0;
  m_max = 0;
}


template <typename T>
int ArrayList<T>::size() const {
  return m_size;
}

template <typename T>
const T& ArrayList<T>::first() const {
  //Check to see if empty.  If so, return dummy object
  if (m_size == 0)
    return m_errobj;
  else
    return m_data[0]; //Return first element
}


template <typename T>
void ArrayList<T>::clear() {
  delete [] m_data;
  m_data = NULL;
  m_size = 0;
  m_max = 0;
}

template <typename T>
void ArrayList<T>::insert_back(const T& x) {
  //Check to see if array is full
  if (m_size == m_max) {
    grow();
  }
  m_data[m_size] = x;
  m_size++;
}
