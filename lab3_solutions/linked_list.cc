// linked_list.cc -- functions for linked_list lab (cs221)

#include "linked_list.h"

/**
 * Inserts a new Node (with key=newKey) at the head of the linked_list.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty)
 * PRE: newKey is the value for the key in the new Node
 * POST: the new Node is now the head of the linked_list
 */
void insert(Node*& head, int newKey) {
  Node * curr = new Node;
  curr->key  = newKey;
  curr->next = head;

  head = curr;
}

/**
 * Print the keys of a linked_list in order, from head to tail
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty)
 */
void print(Node* head) {
  std::cout << "[";
  for (Node* curr = head; curr != NULL; curr = curr->next){
    std::cout << curr->key;
    if (curr->next != NULL) std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

/**
 * Returns the size (number of Nodes) of the linked_list
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty)
 */
int size(Node* head){
  if (! head) return 0;
  return 1 + size(head->next);
}

/**
 * Copies the keys in a linked list to a vector.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty)
 * POST: a new vector<int> containing the keys in the correct order has been returned.
 */
std::vector<int> to_vector(Node* head) {
  std::vector<int> result;
  for (Node* curr = head; curr != NULL; curr = curr->next){
    result.push_back(curr->key);
  }
  return result;
}

/**
 * Delete the last Node in the linked_list
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty)
 * POST: the last Node of the linked_list has been removed
 * POST: if the linked_list is now empty, head has been changed
 * POST: else head remains the first Node in the linked_list
 */
void delete_last_element(Node*& head){
  int s = size(head);
  if (s == 0) {
    return;
  }
  if (s == 1) {
    delete head;
    head = NULL;
  }
  else {
    Node* curr = head;
    for(curr; curr->next->next != NULL; curr = curr->next){}
    delete curr->next;
    curr->next = NULL;
  }
}

/**
 * Removes an existing Node (with key=oldKey) from the linked_list.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty)
 * PRE: oldKey is the value of the key in the Node to be removed
 * PRE: if no Node with key=oldKey exists, the linked_list has not changed
 * POST: if a Node with key=oldKey was found, then it was deleted
 * POST: other Nodes with key=oldKey might still be in the linked_list
 * POST: head is the new first Node of the linked_list, if updated
 */
void remove(Node*& head, int oldKey) {
  if(! head) return;
  Node* curr = head;
  if(curr->key == oldKey) {
    head = head->next;
    delete curr;
  } else {
    for(Node* curr = head; curr->next->key != oldKey; curr = curr->next) {}
    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
  }
}

/**
 * Insert a new Node (with key=newKey) after an existing Node (with key=oldKey)
 * If there is no existing Node with key=oldKey, then no action.
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty)
 * PRE: oldKey is the value to look for (in the key of an existing Node)
 * PRE: newKey is the value of the key in the new Node (that might be inserted)
 * POST: if no Node with key=oldKey was found, then the linked_list has not changed
 * POST: else a new Node (with key=newKey) is right after the Node with key = oldKey.
 */
void insert_after(Node* head, int oldKey, int newKey){
  // ******** WRITE YOUR CODE HERE ********
  Node* curr = head;
  for(int i=0; i < size(head); i++) {
    if(curr->key == oldKey) {
      Node* newNode = new Node;
      newNode->key = newKey;

      Node* temp = curr->next;
      curr->next = newNode;
      newNode->next = temp;
    }
    curr = curr->next;
  }
}

/**
 * Create a new linked_list by merging two existing linked_lists.
 * PRE: list1 is the first Node in a linked_list (if NULL, then it is empty)
 * PRE: list2 is the first Node in another linked_list (if NULL, then it is empty)
 * POST: A new linked_list is returned that contains new Nodes with the keys from
 * the Nodes in list1 and list2, starting with the key of the first Node of list1,
 * then the key of the first Node of list2, etc.
 * When one list is exhausted, the remaining keys come from the other list.
 * For example: [1, 2] and [3, 4, 5] would return [1, 3, 2, 4, 5]
 */
Node* interleave(Node* list1, Node* list2){
  //Initializing
  Node* start = new Node;
  Node* iter = start;

  //These guys go through the two lists along the correct path
  Node* sniffer = list1;
  Node* tempSniffer = list2;

  //Only if one or both of the lists is/are null
  if(list1 == NULL || list2 == NULL){
    if(list2 != NULL){
      sniffer = list2;
      tempSniffer = NULL;
    } else if (list1 != NULL) {
      sniffer = list1;
      tempSniffer = NULL;
    } else {
      return NULL;
    }
  }

  //Actually do the leafing
  while(tempSniffer != NULL) {
    iter->key = sniffer->key;

    Node* tempSniffer2 = sniffer->next;
    sniffer = tempSniffer;
    tempSniffer = tempSniffer2;

    Node* temp = new Node;
    iter->next = temp;
    iter = iter->next;
  }

  //Single list
  while(sniffer != NULL) {
    iter->key = sniffer->key;
    sniffer = sniffer->next;

    if(sniffer == NULL) break;

    Node* temp = new Node;
    iter->next = temp;
    iter = iter->next;
  }
  iter->next = NULL;
  return start;
}
