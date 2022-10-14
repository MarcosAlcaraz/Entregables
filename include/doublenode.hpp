#ifndef __DOUBLENODE_H__
#define __DOUBLENODE_H__

#include<iostream>
#include"agent.hpp"

class DoubleNode
{
private:
    Agent data;
    DoubleNode* prev;
    DoubleNode* next;

public:
    DoubleNode();
    DoubleNode(const Agent&);

    Agent getData() const;
    DoubleNode *getNext();
    DoubleNode *getprev();

    void setData(const Agent&);
    void setNext(DoubleNode*);
    void setprev(DoubleNode*);

    //Operadores relacionales
    DoubleNode& operator = (const DoubleNode&);

    bool operator == (const DoubleNode&) const;
	bool operator != (const DoubleNode&) const;
	bool operator < (const DoubleNode&) const;
	bool operator <= (const DoubleNode&) const;
	bool operator > (const DoubleNode&) const;
	bool operator >= (const DoubleNode&) const;
};

#endif // __DOUBLENODE_H__