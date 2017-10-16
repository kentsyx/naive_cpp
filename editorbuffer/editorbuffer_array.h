/* File: EditorBuffer_array.h
 * --------------------------
 * This interface exports the EditorBuffer class, which represents the buffer of a
 * text editor (model part of a typical MVC design pattern). Here the buffer is implemented
 * as a character array.
 */


#ifndef EDITORBUFFER_ARRAY_H
#define EDITORBUFFER_ARRAY_H

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
    char *array;
    int capacity;
    int length;
    int cursor;

    /* Make it illegal to copy the editor buffers */
    EditorBuffer(const EditorBuffer&);
    EditorBuffer& operator=(const EditorBuffer&);

    void expandCapacity();
};

#endif // EDITORBUFFER_ARRAY_H
