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

// Основная функция
void interface(void);

void deleteOneRecord(TicketTL**);
void exitApp(void);


void showCreateDialog(void);
void showDeleteDialog(void); 
void showSortDialog(void);

void findDialog(void); // todo
void helpDialog(char*); //todo

void twoButtonDialog(int, int, int, int, char*, char*, char*);

void showTable(void);
void tableHead(void);
void tableElement(TicketTL*);
void tableBottom(void);

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