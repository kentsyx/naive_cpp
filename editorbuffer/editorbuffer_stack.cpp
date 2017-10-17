/* File: editorbuffer_stack.cpp
 * ----------------------------
 * Implements the editorbuffer_stack.h interface
 */

#include <string>
#include "editorbuffer_stack.h"

void EditorBuffer::moveCursorForward() {
    if (!after.empty())
        before.push(after.pop());
}

void EditorBuffer::moveCursorBackward() {
    if (!before.empty())
        after.push(before.pop());
}

void EditorBuffer::moveCursorToStart() {
    while (!before.empty())
        after.push(before.pop());
}

void EditorBuffer::moveCursorToEnd() {
    while (!after.empty())
        before.push(after.pop());
}

void EditorBuffer::insertCharacter(char ch) {
    after.push(ch);
}

void EditorBuffer::deleteCharacter() {
    if (!after.empty())
        after.pop();
}

std::string EditorBuffer::getText() const {
    CharStack beforeCopy = before;
    CharStack afterCopy = after;
    string str = "";
    while (!before.empty())
        str = beforeCopy.pop() + str;
    while (!after.empty())
        str += afterCopy.pop();
    return str;
}

int EditorBuffer::getCursor() const {
    return before.size();
}
