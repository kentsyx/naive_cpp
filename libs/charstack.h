/* File: charstack.h
 * -----------------
 * This interface defines the CharStack class, which implements
 * the stack abstraction for characters.
 */


#ifndef CHARSTACK_H
#define CHARSTACK_H

class CharStack {
public:
    CharStack();
    CharStack(const CharStack&);
    CharStack& operator=(const CharStack&);
    ~CharStack();

    int size() const;
    bool empty() const;
    void clear();
    void push(char);
    char pop();
    char top() const;

private:
    static const int INITIAL_CAPACITY = 10;
    int capacity;
    int count;
    char *array;
    void deepCopy(const CharStack&);
    void expandCapacity();
};

#endif // CHARSTACK_H
