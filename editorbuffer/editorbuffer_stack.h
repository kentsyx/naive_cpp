/* File: editorbuffer_stack.h
 * --------------------------
 * A stack-based implemetation of the buffer, O(1) for insertion and deletion.
 */

#include <string>
#include "charstack.h"

class EditorBuffer {
public:
    EditorBuffer() { }
    ~EditorBuffer() { }

    void moveCursorForward();
    void moveCursorBackward();
    void moveCursorToStart();
    void moveCursorToEnd();
    void insertCharacter(char);
    void deleteCharacter();

    std::string getText() const;
    int getCursor() const;

private:
    CharStack before;
    CharStack after;

    EditorBuffer(const EditorBuffer& value) { }
    EditorBuffer& operator=(const EditorBuffer& rhs) { return *this; }

};
