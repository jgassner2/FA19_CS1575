//Name: Joanthan Gassner
//SID: 12299764
//Class: CS1575 Sec A
//Instructor: Dr. Morales
//Date: 9-24-19


template <typename T>
LinkedList<T>::LinkedList(){
/*
  LLNode<T> * tmp;
  tmp = new LLNode;  //This line won't compile
  m_size = 0;
  m_head -> m_data = tmp -> m_data;
  m_back -> m_data = tmp -> m_data;
  delete tmp;
*/
  //I almost think it is this as the list has no nodes.
  m_head = m_back = NULL;
  m_size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList(){

}
