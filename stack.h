#ifndef STACK_H
#define STACK_H

typedef char Data;

class Stack
{
    public:
        Stack();
        ~Stack();
		
		void Push(Data datum);
		
		void Pop();
        
    protected:
        bool nextDatum(bool firstTime, Data &datum) const;
    private:
        class StackImplementation;
        StackImplementation *pimpl;

};

#endif // STACK_H