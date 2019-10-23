//Name: Joanthan Gassner
//SID: 12299764
//Class: CS1575 Sec A
//Instructor: Dr. Morales
//Date: 9-24-19


template <typename T>
LinkedList<T>::LinkedList(){
  //I almost think it is this as the list has no nodes.
  m_head = m_back = NULL;
  m_size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList(){

}

template <typename T>
bool LinkedList<T>::isEmpty() const {
  if (m_size == 0) {
    return true;
  }
  else{
    return false;
  }
}
