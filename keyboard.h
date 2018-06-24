#ifndef _KEYBOARD_HEADER
#define _KEYBOARD_HEADER

#include <SDL.h>

#define GP2X_BUTTON_UP              (0)
#define GP2X_BUTTON_DOWN            (4)
#define GP2X_BUTTON_LEFT            (2)
#define GP2X_BUTTON_RIGHT           (6)
#define GP2X_BUTTON_UPLEFT          (1)
#define GP2X_BUTTON_UPRIGHT         (7)
#define GP2X_BUTTON_DOWNLEFT        (3)
#define GP2X_BUTTON_DOWNRIGHT       (5)
#define GP2X_BUTTON_CLICK           (18)
#define GP2X_BUTTON_A               (12)
#define GP2X_BUTTON_B               (13)

//#define GP2X_BUTTON_X               (15)
//#define GP2X_BUTTON_Y               (14)
#define GP2X_BUTTON_X			14
#define GP2X_BUTTON_Y			15

#define GP2X_BUTTON_L               (10)
#define GP2X_BUTTON_R               (11)
#define GP2X_BUTTON_START           (8)
#define GP2X_BUTTON_SELECT          (9)
#define GP2X_BUTTON_VOLUP           (16)
#define GP2X_BUTTON_VOLDOWN         (17)


// Fake reversed buttons to get the mapping file loading code to work.
#define GP2X_REVERSED_BUTTONS_OFFSET	1000

#define GP2X_R_BUTTON_UP              (GP2X_REVERSED_BUTTONS_OFFSET+0)
#define GP2X_R_BUTTON_DOWN            (GP2X_REVERSED_BUTTONS_OFFSET+4)
#define GP2X_R_BUTTON_LEFT            (GP2X_REVERSED_BUTTONS_OFFSET+2)
#define GP2X_R_BUTTON_RIGHT           (GP2X_REVERSED_BUTTONS_OFFSET+6)
#define GP2X_R_BUTTON_UPLEFT          (GP2X_REVERSED_BUTTONS_OFFSET+1)
#define GP2X_R_BUTTON_UPRIGHT         (GP2X_REVERSED_BUTTONS_OFFSET+7)
#define GP2X_R_BUTTON_DOWNLEFT        (GP2X_REVERSED_BUTTONS_OFFSET+3)
#define GP2X_R_BUTTON_DOWNRIGHT       (GP2X_REVERSED_BUTTONS_OFFSET+5)
#define GP2X_R_BUTTON_CLICK           (GP2X_REVERSED_BUTTONS_OFFSET+18)
#define GP2X_R_BUTTON_A               (GP2X_REVERSED_BUTTONS_OFFSET+12)
#define GP2X_R_BUTTON_B               (GP2X_REVERSED_BUTTONS_OFFSET+13)

//#define GP2X_R_BUTTON_X               (GP2X_REVERSED_BUTTONS_OFFSET+15)
//#define GP2X_R_BUTTON_Y               (GP2X_REVERSED_BUTTONS_OFFSET+14)
#define GP2X_R_BUTTON_X               (GP2X_REVERSED_BUTTONS_OFFSET+14)
#define GP2X_R_BUTTON_Y               (GP2X_REVERSED_BUTTONS_OFFSET+15)


#define GP2X_R_BUTTON_L               (GP2X_REVERSED_BUTTONS_OFFSET+10)
#define GP2X_R_BUTTON_R               (GP2X_REVERSED_BUTTONS_OFFSET+11)
#define GP2X_R_BUTTON_START           (GP2X_REVERSED_BUTTONS_OFFSET+8)
#define GP2X_R_BUTTON_SELECT          (GP2X_REVERSED_BUTTONS_OFFSET+9)
#define GP2X_R_BUTTON_VOLUP           (GP2X_REVERSED_BUTTONS_OFFSET+16)
#define GP2X_R_BUTTON_VOLDOWN         (GP2X_REVERSED_BUTTONS_OFFSET+17)




// As I'll be adding new key syms to SDL, I want a liberal
// offset to make sure I don't effect any real SDL keys.
#define BEEBKEYOFFSET   ((1<<16)-1)

/* BBC Keys:
 */
#define BBC_BREAK		(BEEBKEYOFFSET+99)

#define BBC_F0			(BEEBKEYOFFSET+20)
#define BBC_F1			(BEEBKEYOFFSET+71)
#define BBC_F2			(BEEBKEYOFFSET+72)
#define BBC_F3			(BEEBKEYOFFSET+73)
#define BBC_F4			(BEEBKEYOFFSET+14)
#define BBC_F5			(BEEBKEYOFFSET+74)
#define BBC_F6			(BEEBKEYOFFSET+75)
#define BBC_F7			(BEEBKEYOFFSET+16)
#define BBC_F8			(BEEBKEYOFFSET+76)
#define BBC_F9			(BEEBKEYOFFSET+77)
#define BBC_ESCAPE		(BEEBKEYOFFSET+70)
#define BBC_1			(BEEBKEYOFFSET+30)
#define BBC_EXCLAIMATION	BBC_1
#define BBC_2			(BEEBKEYOFFSET+31)
#define BBC_DOUBLEQUOTE		BBC_2
#define BBC_3			(BEEBKEYOFFSET+11)
#define	BBC_HASH		BBC_3
#define BBC_4			(BEEBKEYOFFSET+12)
#define BBC_DOLLAR		BBC_4
#define BBC_5			(BEEBKEYOFFSET+13)
#define BBC_PERCENT		BBC_5
#define BBC_6			(BEEBKEYOFFSET+34)
#define BBC_AMPERSAND		BBC_6
#define BBC_7			(BEEBKEYOFFSET+24)
#define BBC_QUOTE		BBC_7
#define	BBC_8			(BEEBKEYOFFSET+15)
#define	BBC_LEFTBRACKET		BBC_8
#define	BBC_9			(BEEBKEYOFFSET+26)
#define	BBC_RIGHTBRACKET	BBC_9
#define BBC_0			(BEEBKEYOFFSET+27)
#define	BBC_ZERO		BBC_0
#define BBC_EQUALS		(BEEBKEYOFFSET+17)
#define	BBC_MINUS 		BBC_EQUALS
#define BBC_DASH 		BBC_EQUALS
#define BBC_HYPHEN		BBC_EQUALS
#define BBC_CARET		(BEEBKEYOFFSET+18)
#define	BBC_TILDE		BBC_CARET
#define BBC_BACKSLASH		(BEEBKEYOFFSET+78)
#define	BBC_BAR 		BBC_BACKSLASH
#define BBC_VERTICALBAR		BBC_BACKSLASH
#define BBC_LEFT		(BEEBKEYOFFSET+19)
#define BBC_RIGHT		(BEEBKEYOFFSET+79)
#define BBC_TAB			(BEEBKEYOFFSET+60)
#define BBC_Q			(BEEBKEYOFFSET+10)
#define BBC_W			(BEEBKEYOFFSET+21)
#define BBC_E			(BEEBKEYOFFSET+22)
#define BBC_R			(BEEBKEYOFFSET+33)
#define BBC_T			(BEEBKEYOFFSET+23)
#define BBC_Y			(BEEBKEYOFFSET+44)
#define BBC_U			(BEEBKEYOFFSET+35)
#define BBC_I			(BEEBKEYOFFSET+25)
#define BBC_O			(BEEBKEYOFFSET+36)
#define BBC_P			(BEEBKEYOFFSET+37)
#define BBC_AT			(BEEBKEYOFFSET+47)
#define BBC_ATSIGN		BBC_AT
#define BBC_LEFTSQUAREBRACKET	(BEEBKEYOFFSET+38)
#define BBC_LEFTCURLYBRACKET	BBC_LEFTSQUAREBRACKET
#define BBC_UNDERSCORE		(BEEBKEYOFFSET+28)
#define BBC_POUND		BBC_UNDERSCORE
#define BBC_UP			(BEEBKEYOFFSET+39)
#define BBC_DOWN		(BEEBKEYOFFSET+29)
#define BBC_CAPSLOCK		(BEEBKEYOFFSET+40)
#define BBC_CTRL		(BEEBKEYOFFSET+1)
#define BBC_CONTROL		BBC_CTRL
#define BBC_A			(BEEBKEYOFFSET+41)
#define BBC_S			(BEEBKEYOFFSET+51)
#define BBC_D			(BEEBKEYOFFSET+32)
#define BBC_F			(BEEBKEYOFFSET+43)
#define BBC_G			(BEEBKEYOFFSET+53)
#define BBC_H			(BEEBKEYOFFSET+54)
#define BBC_J			(BEEBKEYOFFSET+45)
#define BBC_K			(BEEBKEYOFFSET+46)
#define BBC_L			(BEEBKEYOFFSET+56)
#define BBC_PLUS		(BEEBKEYOFFSET+57)
#define BBC_SEMICOLON		BBC_PLUS
#define BBC_ASTERIX		(BEEBKEYOFFSET+48)
#define	BBC_COLON		BBC_ASTERIX
#define BBC_RIGHTSQUAREBRACKET	(BEEBKEYOFFSET+58)
#define BBC_RIGHTCURLYBRACKET	BBC_RIGHTSQUAREBRACKET
#define BBC_RETURN		(BEEBKEYOFFSET+49)
#define	BBC_ENTER		BBC_RETURN
#define BBC_SHIFTLOCK		(BEEBKEYOFFSET+50)
#define BBC_SHIFT		(BEEBKEYOFFSET+0)
#define	BBC_LEFTSHIFT		BBC_SHIFT
#define BBC_LSHIFT		BBC_SHIFT
#define BBC_RIGHTSHIFT		BBC_SHIFT
#define BBC_RSHIFT		BBC_SHIFT
#define BBC_Z			(BEEBKEYOFFSET+61)
#define BBC_X			(BEEBKEYOFFSET+42)
#define BBC_C			(BEEBKEYOFFSET+52)
#define BBC_V			(BEEBKEYOFFSET+63)
#define BBC_B			(BEEBKEYOFFSET+64)
#define BBC_N			(BEEBKEYOFFSET+55)
#define BBC_M			(BEEBKEYOFFSET+65)
#define BBC_COMMA		(BEEBKEYOFFSET+66)
#define BBC_LEFTANGLEBRACKET	BBC_COMMA
#define BBC_PERIOD		(BEEBKEYOFFSET+67)
#define	BBC_RIGHTANGLEBRACKET	BBC_PERIOD
#define BBC_FORWARDSLASH	(BEEBKEYOFFSET+68)
#define	BBC_QUESTION 		BBC_FORWARDSLASH
#define	BBC_QUESTIONMARK	BBC_FORWARDSLASH
#define BBC_DELETE		(BEEBKEYOFFSET+59)
#define BBC_DEL			BBC_DELETE
#define BBC_BACKSPACE		BBC_DELETE
#define BBC_COPY		(BEEBKEYOFFSET+69)
#define BBC_SPACE		(BEEBKEYOFFSET+62)


/* Special keys:
 */
#define KEY_USEASVOLUME			BEEBKEYOFFSET+1000
#define KEY_NOTHING			BEEBKEYOFFSET+1001



/* Converts an SDL key into a BBC key.
 *
 */
struct BeebKeyTrans {
//  KeySym sym;
  int sym;
  int row;
  int col;
};

enum {
JOY_UP,   JOY_DOWN,   JOY_LEFT,   JOY_RIGHT,   JOY_A,   JOY_B,   JOY_X,   JOY_Y,   JOY_SELECT,   JOY_CLICK,   JOY_L,   JOY_R,   JOY_VOLUP,   JOY_VOLDOWN,
R_JOY_UP, R_JOY_DOWN, R_JOY_LEFT, R_JOY_RIGHT, R_JOY_A, R_JOY_B, R_JOY_X, R_JOY_Y, R_JOY_SELECT, R_JOY_CLICK, R_JOY_L, R_JOY_R, R_JOY_VOLUP, R_JOY_VOLDOWN};

const char* Keyboard_GetKeyName(int sdlk);
int Keyboard_GetKeyNumeric(const char *key_string);
int Keyboard_GetButtonMapping(int button);
void Keyboard_SetKey(int button, int sdlk);

int ConvertSDLKeyToBBCKey(int sym, int *col, int *row);

int gp2xButtonToSDLK(int button);
void apply_mapping(int gp2xButton, int sdlk);
int buttonnameToGP2XButton(char* name);
int keynameToSDLK( char* name);

void HandleButtonPress(int pressed, int joy);
void HandleButtonPressForKeysym(int pressed, int keysym);
void AllDirectionButtonsUp();

int LoadKeyboardMapping(char *filename);
int kbd_load_mapping(char *kbd_filename);

void AllButtonsUp(void);
#endif
