//Name: Joanthan Gassner
//SID: 12299764
//Class: CS1575 Sec A
//Instructor: Dr. Morales
//Date: 9-24-19




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
void ArrayList<T>::clear() {
  delete [] m_data;
  m_data = NULL;
  m_size = 0;
  m_max = 0;
}
