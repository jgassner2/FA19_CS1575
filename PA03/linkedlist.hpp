//Name: Joanthan Gassner
//SID: 12299764
//Class: CS1575 Sec A
//Instructor: Dr. Morales
//Date: 10-21-19


template <typename T>
LinkedList<T>::LinkedList(){
  //I almost think it is this as the list has no nodes.
  m_head = m_back = NULL;
  m_size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList(){
  LLNode<T> * tmp;
  for(int i=0; i<m_size; i++) {
    tmp = m_head; //Set tmp pointer to element to be deleted
    m_head = m_head->m_next; //Point m_head to the next element in the list
    delete tmp;  //Remove element in list.
  }
  tmp = NULL;  //Not needed but good practice
//std::cout << "THe Default Destructor has finished" << std::endl;  //Just for testing
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

//Basic Mutator
template <typename T>
void LinkedList<T>::clear() {
  LLNode<T> * tmp;

  for (int i=0; i<m_size; i++) {
    tmp = m_head; //Set tmp to element needing to be deleted
    m_head = m_head->m_next; //Set head pointer to next element in the list
    delete tmp;  //Remove element from the list
  }
  //Reset everything
  m_size = 0;
  m_head = m_back = NULL;
  tmp = NULL; //Avoid dangling pointer.
}

template <typename T>
void LinkedList<T>::insert_front(const T& x) {
  LLNode<T> * tmp;  //Create a tmp LLNode pointer
  tmp = new LLNode<T>;  //Create a new LLNode
  tmp->m_data = x;  //Set the LLNode's data equal to 'x'
  tmp->m_next = m_head; //Set the LLNode's next pointer to point to the head of the list
  m_head = tmp; //Make the original head point to the new head, breaking the old link.
  m_size++; //Increment the size of the list.
  //delete tmp; //If this is here, segfault (core dump)
  //tmp = NULL;  //Needed?

}



template <typename T>
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& list)
{
  //LLNode<T> * tmp = list.m_head;  //m_head is private, need accessor
  //LLNode<T> * tmp = list.getFirstPtr();  //Wont' work unless it's const pointer
  const LLNode<T> * tmp = list.getFirstPtr(); //ASK!!!!


  out << "[ ";

  for (int i=0; i<list.size(); i++){
    out << tmp->m_data << ", "; //Access LLNode actual data
    //tmp->m_next; //move the tmp pointer to point to the next node's member data for the next round. JUST REPEATS!!!!!
    tmp = tmp->m_next; //move the tmp pointer to point to the next node's member data for the next round
  }

  out << "]";

  delete tmp;
  return out;
}
