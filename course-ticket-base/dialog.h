#include "core.h"

void showCreateDialog(void) {

    int i;

    window(9, 5, 71, 22);
    textattr(LIGHTGRAY);
    textbackground(BLACK);
    clrscr();

    cprintf("╔");

    for (i = 0; i < 61; i++)
        cprintf("═");

    cprintf("╗");

    for (i = 2; i < 16; i++) {
        gotoxy(1, i);
        cprintf("║");
        gotoxy(63, i);
        cprintf("║");
    }

    cprintf("╚");

    for (i = 0; i < 61; i++)
        cprintf("═");

    cprintf("╝");

    gotoxy(26, 1);
    cputs(" Cоздание ");

    gotoxy(3, 3);
    cputs("Страна:");

    gotoxy(3, 5);
    cputs("Выберите вид транспорта:");

    gotoxy(3, 10);
    cputs("Время:");

    gotoxy(3, 12);
    cputs("Стоимость в руб.:");

}

void showSortDialog(void) {

    int i;

    window(20, 9, 61, 17);
    textattr(WHITE);
    textbackground(BLACK);
    clrscr();

    cprintf("╔");

    for (i = 0; i < 38; i++)
        cprintf("═");

    cprintf("╗");

    for (i = 2; i < 9; i++) {
        gotoxy(1, i);
        cprintf("║");
        gotoxy(40, i);
        cprintf("║");
    }

    cprintf("  ╚");

    for (i = 0; i < 38; i++)
        cprintf("═");

    cprintf("╝");

    gotoxy(14, 1);
    cputs(" Сортировка ");

    gotoxy(3, 3);
    cprintf("┌");

    for (i = 0; i < 17; i++)
        cprintf("─");

    cprintf("┐");

    for (i = 4; i < 8; i++) {
        gotoxy(3, i);
        cprintf("│");
        gotoxy(21, i);
        cprintf("│");
    }

    gotoxy(3, 8);
    cprintf("└");

    for (i = 0; i < 17; i++)
        cprintf("─");

    cprintf("┘");


    gotoxy(22, 3);
    cprintf("┌");

    for (i = 0; i < 15; i++)
        cprintf("─");

    cprintf("┐");

    for (i = 4; i < 8; i++) {
        gotoxy(22, i);
        cprintf("│");
        gotoxy(38, i);
        cprintf("│");
    }

    gotoxy(22, 8);
    cprintf("└");

    for (i = 0; i < 15; i++)
        cprintf("─");

    cprintf("┘");

    gotoxy(4, 4);
    cputs(" ( )По стране");

    gotoxy(4, 6);
    cputs(" ( )По стоимости");

    gotoxy(24, 4);
    cputs("По возрастанию");

    gotoxy(24, 6);
    cputs("По убыванию");
}

void showDeleteDialog(void) {

    int i = 0, pos = 1;
    char key;
    TicketTL* t = NULL, * tmask = NULL;

    window(1, 2, 80, 25);

    //while(1){
    while (1) {
        //_setcursortype(_NOCURSOR);
        //clrscr();
        clrscr();
        textattr(WHITE);
        textbackground(BLUE);
        clrscr();
        //sel = 0;

        key = getch();

        gotoxy(1, pos);

        if (key == '1') pos++;
        else if (key == '2') pos--;

        if (key == 27) return;
    }


}