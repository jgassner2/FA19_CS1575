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
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs){
  //Check for equality or "alias" test
  if (this != &rhs) {
    //If we get here, that means we can do the assignment
    //Delete the old arrayList first
    delete [] m_data;

    //copy values and create new arrayList for deep copy
    m_size = rhs.m_size;
    m_max = rhs.m_max;
    m_data = new T[m_max];

    //Perform deep copy
    for (int k=0; k<m_size; k++)
      m_data[k] = rhs.m_data[k];
  }
  return *this;  //Need to return a pointer!!!!!!
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
int ArrayList<T>::find (const T & x) const {
  bool isFound = false;  //Constants defined above
  int index;

  for (int k=0; k<m_size; k++) {
    if (m_data[k] == x)
    {
      isFound = true;
      index = k;
    }
  }

  if (isFound)
    return index;
  else
    return -1;

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

template <typename T>
void ArrayList<T>::insert(const T& x, int i) {
  //boundary check
  if (i < 0  || i > m_max) {
    return;
  }
  //Make sure there's room before shifting data
  if (m_size == m_max) {
    grow();
  }
  //Shift data in the list right one
  for (int k=m_size; i<k; k--) {
    m_data[k] = m_data[k-1];
  }
  //Insert element and increase size
  m_data[i] = x;
  m_size++;
}

template <typename T>
void ArrayList<T>::remove(int i) {
  //boundary detection/empty list detection, just returns at the moment.
  if (i < 0 || i > m_size )
    return;

    for (int k=i; k<(m_size-1);k++)  //m_size-1 prevents walking off list
      m_data[k] = m_data[k+1];

    m_size--;

    //Test to see if list needs to be shrinked
    if (m_size < (0.25*m_max)) {
       //shrink();
    }

}

template <typename T>
void ArrayList<T>::swap(int i, int k) {
  //TODO - add boundary checks for i and k
  //Create a temporary storage container
  T * temp;
  temp = new T [1];

  //Copy data into temp container, swap, and cleanup
  temp[0] = m_data[i];
  m_data[i] = m_data[k];
  m_data[k] = temp[0];
  delete [] temp;
}
