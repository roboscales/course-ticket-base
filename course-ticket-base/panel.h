#include "core.h"


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


void render_main_panel(element_list** lists, size_t count) {
    int i = 0;
    window(1, 1, 80, 1);
    textattr(WHITE);
    textbackground(BLACK);
    clrscr();
    cprintf("   ");
    for (i = 0; i < count; i++) {
        if (lists[i]->hover) {
            textattr(WHITE);
            textbackground(LIGHTGREEN);
            cprintf(" %s ", lists[i]->label);
        }
        else {
            textattr(WHITE);
            textbackground(BLACK);
            cprintf(" %s ", lists[i]->label);
        }
    }

    textattr(WHITE);
    textbackground(BLACK);
}

void render_items(element_list* parent, item* items, size_t count) {
    int i = 0;
    int x = parent->sizes.x;
    int y = parent->sizes.y;
    int width = parent->sizes.width;


    window(x, y + 1, x + width, y + 3 + count);
    textattr(WHITE);
    textbackground(BLACK);
    clrscr();

    cprintf("Ú");
    for (i = 0; i < width - 1; i++)
        cprintf("Ä");
    cprintf("¿");
    
    gotoxy(0, y+1);
    
    for (i = 0; i < count; i++) {
        if (items[i].hover) {

            cprintf("³ ");
            textattr(WHITE);
            textbackground(LIGHTGREEN);
            
            cprintf(" %s%*c", items[i].label, width - 3 - strlen(items[i].label), ' ');

            textattr(WHITE);
            textbackground(BLACK);
            
            cprintf("³");
            gotoxy(0, y+1 + i+1);
            //cprintf("\r\n");
        }
        else {

            textattr(WHITE);
            textbackground(BLACK);
            cprintf("³ ");
            cprintf(" %s%*c", items[i].label, width - 3 - strlen(items[i].label), ' ');
            cprintf("³");
            gotoxy(0, y+1 + i+1);
            //cprintf("\r\n");
        }
    }

    textattr(WHITE);
    textbackground(BLACK);

    cprintf("À");
    for (i = 0; i < width - 1; i++)
        cprintf("Ä");
    cprintf("Ù");
}