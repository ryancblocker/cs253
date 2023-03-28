#include "ll.h"

using namespace std;

ostream &operator<<(ostream &print, LinkedList &list) {
	return print << list.grab(); //return print method string to ostream
}

LinkedList::Link::Link(unsigned int uiData, Link *pNext) : m_uiData(uiData), m_pNext(pNext) { //member init
	//m_uiData = uiData;
	//m_pNext = pNext;
}

LinkedList::LinkedList() : m_pHead(nullptr) { 					//member init
	//m_pHead = nullptr;							// This linked list is empty.
}

bool LinkedList::insert(unsigned uiData) {
	Link* new_link = new LinkedList::Link(uiData, m_pHead);			// Get a new node and fill it
	m_pHead = new_link;							// Put it at the head.
    	return true;								// Indicate success.
}

bool LinkedList::remove(unsigned &pData) {
	if (!m_pHead)								// Empty list?
		return false;							// Indicate failure.
	Link *temp = m_pHead;							// Point to the first node.
	m_pHead = m_pHead->m_pNext;						// Remove the first node.
	pData = temp->m_uiData;							// Obtain first node’s data.
	delete temp;								//delete old memory
	return true;								// Indicate success.
}

string LinkedList::grab() const {
	string result = "";							//empty string to output values
	Link *cNode = m_pHead;
	while(cNode != nullptr) {						//While the linked list != null
        	result += to_string(cNode->m_uiData);				//the loop will add link data
        	if(cNode->m_pNext == nullptr) {					//to the result string and once
                	result += "\n";						//the string is null it adds
        	} else {							//a newline
                	result += ' ';
        	}
		cNode = cNode->m_pNext;						//shift to next value in the
        }									//Linked List
	return result;
}

bool LinkedList::stop() {
	Link *cLink = m_pHead;
	unsigned positionLink;							//data that is pointed too
	while (cLink != nullptr) {						//loop that removes the nodes
		positionLink = cLink->m_uiData;
		remove(positionLink);
		cLink = cLink->m_pNext;
	}
	return true;								//succesfully quitted
}

