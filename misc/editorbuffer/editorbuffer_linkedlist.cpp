/* File: editorbuffer_linkedlist.cpp
 * ---------------------------------
 * Implements the editorbuffer_linkedlist.h interface.
 */

#include <string>
#include "editorbuffer_linkedlist.h"

using std::string;

EditorBuffer::EditorBuffer() {
    start = cursor = new Cell;
    start->link = nullptr;
}

EditorBuffer::~EditorBuffer() {
    Cell *cp = start;
    while (cp != nullptr) {
        Cell *next = cp->link;
        delete cp;
        cp = next;
    }
}

void EditorBuffer::moveCursorForward() {
    cursor = cursor->link;
}

void EditorBuffer::moveCursorBackward() {
    Cell *cp = start;
    if (cursor != start) {
        while (cp->link != cursor)
            cp = cp->link;
    }
    cursor = cp;
}

void EditorBuffer::moveCursorToStart() {
    cursor = start;
}

void EditorBuffer::moveCursorToEnd() {
    while (cursor != nullptr)
        cursor = cursor->link;
}

void EditorBuffer::insertCharacter(char ch) {
    Cell *cp = new Cell;
    cp->link = ch;
    cp->link = cursor->link->link;
    cursor->link = cp;
    cursor = cp;
}

void EditorBuffer::deleteCharacter() {
    if (cursor->link != nullptr) {
        Cell *oldCell = cursor->link;
        cursor->link = cursor->link->link;
        delete oldCell;
    }
}

string EditorBuffer::getText() const {
    string str = "";
    for (Cell *cp = start; cp != nullptr; cp = cp->link)
        str += cp->link;
    return str;
}

int EditorBuffer::getCursor() const {
    int nChars;
    for (Cell *cp = start; cp != cursor; cp = cp->link)
        nChars++;
    return nChars;
}
