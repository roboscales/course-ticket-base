#ifndef CORE
#define CORE

#include <stdio.h>
//standard sizes of array
#define N 10
#define MAXSTR 80

//keys
#define ESC 27
#define ENTER 13
#define TAB 9
#define BACKSPACE 8
#define UP 72
#define DOWN 80
#define PGUP 73
#define PGDN 81
#define HOME 71
#define END 79
#define RIGHT 77
#define LEFT 75

//saving things
#define WINDON 1
#define WINDOFF 0

//scrolling stuff
#define LEN 6

enum WINDOWS {
    MAINPANEL,
    SEE,
    FIND,
    SORT,
    LISTMENU1,
    LISTMENU2,
};

enum MAINPANEL {
    SEEL,
    EDIT,
    HELP,
};


enum STATES {
    APP_START,
    ACTIVE_TOOLBAR,
    ACTIVE_ITEM_TOOLBAR

};

typedef struct Sizes {
    int x;
    int y;
    int width;
    int height;
} Sizes;


typedef struct item {
    const char* label;
    Sizes sizes;

    int hover;
} item;

typedef struct element_list {
    const char* label;
    Sizes sizes;

    int hover;

    int select_item;

    item* items;

} element_list;

typedef struct radio_box {

    Sizes sizes;
    int select;

} radio_box;


typedef struct TicketTL {

    char cou[20];
    char tr[MAXSTR];
    int len;
    float rub;

    struct TicketTL* tprev, * tnext;

} TicketTL;

typedef struct Window {

    int x1;
    int y1;
    int x2;
    int y2;
} Window;

extern int str_count;
extern int app_state;
extern TicketTL* tfirst;

#ifdef MAIN
#endif
#ifdef INTERFACE


#include <conio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define IN 1
#define OUT 0

void interface(void);
void see(void);
void create(void);
void find(void);
void sort(void);
void del(TicketTL**);
void head(void);
void table(TicketTL*, int);
void choicetr(TicketTL**);
void endt(void);
void closemo(void);
void chisto(void);
void diagnos(void);
void entkey(char*);

void seeDialog(void);
void createDialog(void);
void findDialog(void);
void deleteDialog(void);
void sortDialog(void);
void exitDialog(void);
void helpDialog(char*);

void twoButtonDialog(int, int, int, int, char*, char*, char*);
void oneButtonDialog(int, int, int, int, char*, char*);
void mainPanel(size_t, char*, ...);
void listMenu(int, int, size_t, char*, ...);

void headConsole(void);
void tableConsole(TicketTL*);
void endConsole(void);

//this guy tried to pass Suslov...

void render_main_panel(element_list** lists, size_t count);

int windofch = WINDOFF;
int str_count = 0;
int app_state = APP_START;

#endif

#ifdef IMPL_LIST
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void load(void);
void save(void);

TicketTL* bsortssb(TicketTL** head);
TicketTL* bsortsbs(TicketTL** head);
TicketTL* bsortrsb(TicketTL** head);
TicketTL* bsortrbs(TicketTL** head);

void ListDestroy(TicketTL**);
TicketTL* getlast(TicketTL*);
TicketTL* addBegin(TicketTL**);
TicketTL* addEnd(TicketTL**);
TicketTL* deleteBegin(TicketTL**);
TicketTL* deleteMid(TicketTL**);
TicketTL* deleteEnd(TicketTL**);
void TLSwap(TicketTL**);

TicketTL* bottomRelativeScroll(TicketTL*);

extern int windofch;

TicketTL* tfirst = NULL;

#endif

#endif