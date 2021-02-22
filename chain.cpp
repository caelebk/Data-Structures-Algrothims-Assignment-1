#include "chain.h"
#include "chain_given.cpp"
#include <cmath>
#include <iostream>

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain()
{
/* your code here */
    clear();
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block &ndata)
{
/* your code here */
    Node * add = new Node(ndata);
    Node * temp = walk(head_, length_);
    temp->next = add;
    add->next = head_;
    length_++;
}


/**
 * Swaps the two nodes at the indexes "node1" and "node2".
 * The indexes of the nodes are 1 based.
 * assumes i and j are valid (in {1,length_} inclusive)
 * Case1 : i < j
 * Case2 : i > j
 * Case3 : i = j
 */
void Chain::swap(int i, int j)
{
/* your code here */
    //case3
    if(i == j) return;
    //case1 & 2
    if((i < j && j-i > 1) || (j < i && i-j > 1)) {
        Node * prevNode1 = walk(head_, i-1);
        Node * prevNode2 = walk(head_, j-1);
        Node * node1 = prevNode1->next;
        Node * node2 = prevNode2->next;
        Node * nNode1 = node1->next;
        Node * nNode2 = node2->next;
        prevNode1->next = node2;
        node2->next = nNode1;
        prevNode2->next = node1;
        node1->next = nNode2;
    } else {
        if(j < i) {
            int old = i;
            i = j;
            j = old;
        }
        Node * prevINode = walk(head_,i-1);
        Node * iNode = prevINode->next;
        Node * jNode = iNode->next;
        Node * temp = iNode->next->next;
        prevINode->next = jNode;
        iNode->next = temp;
        jNode->next = iNode;
    }
    
}

/**
 * Reverses the chain
 */
void Chain::reverse()
{
/* your code here */
    for(int x = 1; x < (length_/2) + 1; x++){
        swap(x,length_ - x + 1);
    }
}

/*
* Modifies the current chain by "rotating" every group of k nodes by one position.
* In every k-node sub-chain, remove the first node, and place it in the last 
* position of the sub-chain. If the last sub-chain has length less than k,
* then don't change it at all. 
* Some examples with the chain a b c d e:
*   k = 1: a b c d e
*   k = 2: b a d c e
*   k = 3: b c a d e
*   k = 4: b c d a e
*/
void Chain::rotate(int k)
{
/* your code here */
    int pos = length_/k;
    Node * prev = head_;
    while (pos > 0 && k > 1) {
        pos--;
        Node * aNext = walk(prev,k);
        Node * a = prev->next;
        prev->next = a->next;
        a->next = aNext->next;
        aNext->next = a;
        prev = a;
    }
}

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::clear()
{
/* your code here */
    if(head_ == NULL) return;
    
    Node* temp = head_->next;
    for (int x = 0; x < length_; x++) {
        delete head_;
        head_ = temp;
        temp = temp->next;
    }
    delete head_;
    head_ = NULL;
    length_ = 0;
}

/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const &other)
{
/* your code here */
    head_ = new Node();
    Node * temp = other.head_->next; 
    length_ = 0;
    for(int x = 0; x < other.length_; x++){
        insertBack(temp->data); //increments length by 1
        temp = temp->next;
    }
    //temp->next = head;
    height_ = other.height_;
    width_ = other.width_;
}
