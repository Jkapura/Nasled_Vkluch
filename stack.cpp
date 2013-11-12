#include "stack.h"

struct Element
{
	Data datum;
	Element *next;
	Element *prev;
	Element(Data d)
	{
		next = 0;
		prev = 0;
		datum = d;
	}
	
};
class Stack::StackImplementation
{
    public:
        StackImplementation();
        ~StackImplementation();

        void push(Data datum);
        void DeleteAllStack();
		Data pop();
	
        bool nextDatum(bool firstTime, Data &datum) const;
    private:
        Element *pHead;
};

////////////  Stack //////////////

Stack::Stack()
{
	pimpl = 0;
    pimpl = new StackImplementation;
}

Stack::~Stack()
{
    delete pimpl;
    pimpl = 0;
}

void Stack::Push(Data datum)
{
    pimpl->push(datum);
}

void Stack::Pop()
{
	pimpl->pop();
	
}


bool Stack::nextDatum(bool firstTime, Data &datum) const
{
    return pimpl->nextDatum(firstTime, datum);
}
///// StackImplementation ////////

Stack::StackImplementation::StackImplementation()
{
	pHead = 0;

}

Stack::StackImplementation::~StackImplementation()
{
    DeleteAllStack();
}

void Stack::StackImplementation::push(Data datum)
{
    Element *temp = new Element(datum);
	temp->next = pHead;
	if ( pHead != 0 )
		pHead->prev = temp;
    pHead = temp ;
}
Data Stack::StackImplementation::pop()
{
	Element* old = pHead;
    if(old != 0)
	{
	    pHead = pHead->next; 
		char data = old->datum;
		delete old;
		return data;
	}
	else
	{
		return '\0';
	}
}

void Stack::StackImplementation::DeleteAllStack()
{
    while(pHead)
    {
        Element *p = pHead;
        pHead = pHead->next;
        delete p;
        p = 0;
    }
}

bool Stack::StackImplementation::nextDatum(bool firstTime, Data &datum) const
{
    static Element *cur;

    if(firstTime)
        cur = pHead;

    bool result = cur != 0;

    if(result)
    {
        datum = cur->datum;
        cur = cur->next;
    }

    return result;
}