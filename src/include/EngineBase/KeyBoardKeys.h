#ifndef KEYBOARDKEYS_H
#define KEYBOARDKEYS_H



typedef enum
{
    ENGINEBASE_KEY_NULL = 0, // Key: NULL, used for no key pressed
    // Alphanumeric keys
    ENGINEBASE_KEY_APOSTROPHE = 39, // Key: '
    ENGINEBASE_KEY_COMMA = 44, // Key: ,
    ENGINEBASE_KEY_MINUS = 45, // Key: -
    ENGINEBASE_KEY_PERIOD = 46, // Key: .
    ENGINEBASE_KEY_SLASH = 47, // Key: /
    ENGINEBASE_KEY_ZERO = 48, // Key: 0
    ENGINEBASE_KEY_ONE = 49, // Key: 1
    ENGINEBASE_KEY_TWO = 50, // Key: 2
    ENGINEBASE_KEY_THREE = 51, // Key: 3
    ENGINEBASE_KEY_FOUR = 52, // Key: 4
    ENGINEBASE_KEY_FIVE = 53, // Key: 5
    ENGINEBASE_KEY_SIX = 54, // Key: 6
    ENGINEBASE_KEY_SEVEN = 55, // Key: 7
    ENGINEBASE_KEY_EIGHT = 56, // Key: 8
    ENGINEBASE_KEY_NINE = 57, // Key: 9
    ENGINEBASE_KEY_SEMICOLON = 59, // Key: ;
    ENGINEBASE_KEY_EQUAL = 61, // Key: =
    ENGINEBASE_KEY_A = 65, // Key: A | a
    ENGINEBASE_KEY_B = 66, // Key: B | b
    ENGINEBASE_KEY_C = 67, // Key: C | c
    ENGINEBASE_KEY_D = 68, // Key: D | d
    ENGINEBASE_KEY_E = 69, // Key: E | e
    ENGINEBASE_KEY_F = 70, // Key: F | f
    ENGINEBASE_KEY_G = 71, // Key: G | g
    ENGINEBASE_KEY_H = 72, // Key: H | h
    ENGINEBASE_KEY_I = 73, // Key: I | i
    ENGINEBASE_KEY_J = 74, // Key: J | j
    ENGINEBASE_KEY_K = 75, // Key: K | k
    ENGINEBASE_KEY_L = 76, // Key: L | l
    ENGINEBASE_KEY_M = 77, // Key: M | m
    ENGINEBASE_KEY_N = 78, // Key: N | n
    ENGINEBASE_KEY_O = 79, // Key: O | o
    ENGINEBASE_KEY_P = 80, // Key: P | p
    ENGINEBASE_KEY_Q = 81, // Key: Q | q
    ENGINEBASE_KEY_R = 82, // Key: R | r
    ENGINEBASE_KEY_S = 83, // Key: S | s
    ENGINEBASE_KEY_T = 84, // Key: T | t
    ENGINEBASE_KEY_U = 85, // Key: U | u
    ENGINEBASE_KEY_V = 86, // Key: V | v
    ENGINEBASE_KEY_W = 87, // Key: W | w
    ENGINEBASE_KEY_X = 88, // Key: X | x
    ENGINEBASE_KEY_Y = 89, // Key: Y | y
    ENGINEBASE_KEY_Z = 90, // Key: Z | z
    ENGINEBASE_KEY_LEFT_BRACKET = 91, // Key: [
    ENGINEBASE_KEY_BACKSLASH = 92, // Key: '\'
    ENGINEBASE_KEY_RIGHT_BRACKET = 93, // Key: ]
    ENGINEBASE_KEY_GRAVE = 96, // Key: `
    // Function keys
    ENGINEBASE_KEY_SPACE = 32, // Key: Space
    ENGINEBASE_KEY_ESCAPE = 256, // Key: Esc
    ENGINEBASE_KEY_ENTER = 257, // Key: Enter
    ENGINEBASE_KEY_TAB = 258, // Key: Tab
    ENGINEBASE_KEY_BACKSPACE = 259, // Key: Backspace
    ENGINEBASE_KEY_INSERT = 260, // Key: Ins
    ENGINEBASE_KEY_DELETE = 261, // Key: Del
    ENGINEBASE_KEY_RIGHT = 262, // Key: Cursor right
    ENGINEBASE_KEY_LEFT = 263, // Key: Cursor left
    ENGINEBASE_KEY_DOWN = 264, // Key: Cursor down
    ENGINEBASE_KEY_UP = 265, // Key: Cursor up
    ENGINEBASE_KEY_PAGE_UP = 266, // Key: Page up
    ENGINEBASE_KEY_PAGE_DOWN = 267, // Key: Page down
    ENGINEBASE_KEY_HOME = 268, // Key: Home
    ENGINEBASE_KEY_END = 269, // Key: End
    ENGINEBASE_KEY_CAPS_LOCK = 280, // Key: Caps lock
    ENGINEBASE_KEY_SCROLL_LOCK = 281, // Key: Scroll down
    ENGINEBASE_KEY_NUM_LOCK = 282, // Key: Num lock
    ENGINEBASE_KEY_PRINT_SCREEN = 283, // Key: Print screen
    ENGINEBASE_KEY_PAUSE = 284, // Key: Pause
    ENGINEBASE_KEY_F1 = 290, // Key: F1
    ENGINEBASE_KEY_F2 = 291, // Key: F2
    ENGINEBASE_KEY_F3 = 292, // Key: F3
    ENGINEBASE_KEY_F4 = 293, // Key: F4
    ENGINEBASE_KEY_F5 = 294, // Key: F5
    ENGINEBASE_KEY_F6 = 295, // Key: F6
    ENGINEBASE_KEY_F7 = 296, // Key: F7
    ENGINEBASE_KEY_F8 = 297, // Key: F8
    ENGINEBASE_KEY_F9 = 298, // Key: F9
    ENGINEBASE_KEY_F10 = 299, // Key: F10
    ENGINEBASE_KEY_F11 = 300, // Key: F11
    ENGINEBASE_KEY_F12 = 301, // Key: F12
    ENGINEBASE_KEY_LEFT_SHIFT = 340, // Key: Shift left
    ENGINEBASE_KEY_LEFT_CONTROL = 341, // Key: Control left
    ENGINEBASE_KEY_LEFT_ALT = 342, // Key: Alt left
    ENGINEBASE_KEY_LEFT_SUPER = 343, // Key: Super left
    ENGINEBASE_KEY_RIGHT_SHIFT = 344, // Key: Shift right
    ENGINEBASE_KEY_RIGHT_CONTROL = 345, // Key: Control right
    ENGINEBASE_KEY_RIGHT_ALT = 346, // Key: Alt right
    ENGINEBASE_KEY_RIGHT_SUPER = 347, // Key: Super right
    ENGINEBASE_KEY_KB_MENU = 348, // Key: KB menu
    // Keypad keys
    ENGINEBASE_KEY_KP_0 = 320, // Key: Keypad 0
    ENGINEBASE_KEY_KP_1 = 321, // Key: Keypad 1
    ENGINEBASE_KEY_KP_2 = 322, // Key: Keypad 2
    ENGINEBASE_KEY_KP_3 = 323, // Key: Keypad 3
    ENGINEBASE_KEY_KP_4 = 324, // Key: Keypad 4
    ENGINEBASE_KEY_KP_5 = 325, // Key: Keypad 5
    ENGINEBASE_KEY_KP_6 = 326, // Key: Keypad 6
    ENGINEBASE_KEY_KP_7 = 327, // Key: Keypad 7
    ENGINEBASE_KEY_KP_8 = 328, // Key: Keypad 8
    ENGINEBASE_KEY_KP_9 = 329, // Key: Keypad 9
    ENGINEBASE_KEY_KP_DECIMAL = 330, // Key: Keypad .
    ENGINEBASE_KEY_KP_DIVIDE = 331, // Key: Keypad /
    ENGINEBASE_KEY_KP_MULTIPLY = 332, // Key: Keypad *
    ENGINEBASE_KEY_KP_SUBTRACT = 333, // Key: Keypad -
    ENGINEBASE_KEY_KP_ADD = 334, // Key: Keypad +
    ENGINEBASE_KEY_KP_ENTER = 335, // Key: Keypad Enter
    ENGINEBASE_KEY_KP_EQUAL = 336, // Key: Keypad =
    // Android key buttons
    ENGINEBASE_KEY_BACK = 4, // Key: Android back button
    ENGINEBASE_KEY_MENU = 82, // Key: Android menu button
    ENGINEBASE_KEY_VOLUME_UP = 24, // Key: Android volume up button
    ENGINEBASE_KEY_VOLUME_DOWN = 25 // Key: Android volume down button
} Key;

typedef enum
{
    ENGINEBASE_BUTTON_LEFT = 0, // Mouse button left
    ENGINEBASE_BUTTON_RIGHT = 1, // Mouse button right
    ENGINEBASE_BUTTON_MIDDLE = 2, // Mouse button middle _pressed wheel
    ENGINEBASE_BUTTON_SIDE = 3, // Mouse button side _advanced mouse device
    ENGINEBASE_BUTTON_EXTRA = 4, // Mouse button extra _advanced mouse device
    ENGINEBASE_BUTTON_FORWARD = 5, // Mouse button forward _advanced mouse device
    ENGINEBASE_BUTTON_BACK = 6, // Mouse button back _advanced mouse device
} Button;

#endif //KEYBOARDKEYS_H
