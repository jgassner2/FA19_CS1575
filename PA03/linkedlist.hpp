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
std::cout << "THe Default Destructor has finished" << std::endl;  //Just for testing
}

template <typename T>
int LinkedList<T>::size() const {
  return m_size;
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

template <typename T>
const LLNode<T> * LinkedList<T>::getFirstPtr() const {
  if (m_size == 0) {
    return NULL;
  }
  else {
    return m_head;
  }
}





/*
template <typename T>
LinkedList<T>& operator<< (std::ostream& out, const LinkedList<T>& list)
{
  LLNode<T> * tmp = list.m_head;
  out << "[ ";

  out << "]";
  delete tmp;
  return out;
}
*/
template <typename T>
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& list)
{
  //LLNode<T> * tmp = list.m_head;  //m_head is private, need accessor
  //LLNode<T> * tmp = list.getFirstPtr();  //Wont' work unless it's const pointer
  const LLNode<T> * tmp = list.getFirstPtr(); //ASK!!!!
  out << "[ ";
  for (int i=0; i<list.size(); i++){
    out << tmp->m_data << ", "; //Access LLNode actual data
    tmp->m_next; //move the tmp pointer to point to the next node's member data for the next round
  }
  out << "]";
  delete tmp;
  return out;
}
