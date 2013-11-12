#include <iostream>
#include "stack.h"
using namespace std;


class ConsoleStack: public Stack
{
    public:
        void output(ostream &out) const;
		
};

ostream &operator << (ostream &out, const ConsoleStack &stack);

int main()
{
    ConsoleStack stack;

    stack.Push('a');
    stack.Push('(');
    stack.Push('(');
    stack.Push('[');
    cout << stack << endl;
	system("pause"); 
    return 0;
}

ostream &operator<<(ostream &out, const ConsoleStack &stack)
{
    stack.output(out);
    return out;
}

void ConsoleStack::output(ostream &out) const
{
    Data datum;

    if(nextDatum(true, datum))
        out << datum << " ";

    while(nextDatum(false, datum))
        out << datum << " ";
}

