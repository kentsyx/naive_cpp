/* File: EditorBuffer_array.h
 * --------------------------
 * This interface exports the EditorBuffer class, which represents the buffer of a
 * text editor (model part of a typical MVC design pattern). Here the buffer is implemented
 * as a character array.
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
    void deleteCharacter();

    std::string getText() const;
    int getCursor() const;

private:
    static const int INITIAL_CAPACITY = 10;

    EditorBuffer(const EditorBuffer&);
    const EditorBuffer& operator=(const EditorBuffer&);

    void expandCapacity();

    int cursor;
    int length;
    int capacity;
    char *array;
};

#ifndef EDITORBUFFER_ARRAY_H
#define EDITORBUFFER_ARRAY_H

#endif // EDITORBUFFER_ARRAY_H
