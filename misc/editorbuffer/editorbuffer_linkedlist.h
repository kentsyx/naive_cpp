/* File: editorbuffer_linkedlist.h
 * -------------------------------
 * Implements the buffer using linked list.
 */

#include <string>

class EditorBuffer {
public:
    EditorBuffer();
    ~EditorBuffer();

    void moveCursorForward();
    void moveCursorBackward();
    void moveCursorToStart();
    void moveCursorToEnd();
    void insertCharacter(char);
    void deleteCharactor();

    std::string getText() const;
    int getCursor() const;

private:
    struct Cell {
        char ch;
        Cell *link;
    };

    Cell *start;
    Cell *cursor;

    EditorBuffer(const EditorBuffer& value) { }
    EditorBuffer& operator=(const EditorBuffer& rhs) { return this; }
};

#ifndef EDITORBUFFER_LINKEDLIST_H
#define EDITORBUFFER_LINKEDLIST_H

#endif // EDITORBUFFER_LINKEDLIST_H
