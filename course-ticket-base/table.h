#pragma once
#include "core.h"

/** Основная функция отображения таблицы */
void showTable(void) {

    TicketTL* top = NULL, * bottom = NULL, * temp = NULL, * pageTop = NULL, * pageBottom = NULL;
    int listSize = 0, renderLoc = 0, * pages = NULL, pageCount = 0, onePageCoverage = 0, scroLen = 0, printCount = 0;
    char key;

    top = tfirst;
    for (bottom = top, scroLen = 0; bottom && scroLen < LEN; bottom = bottom->tnext, scroLen++);
    pageTop = tfirst;
    pageBottom = bottom;

    key = getch();

    while ((key = getch()) != ESC) {
        window(1, 2, 80, 25);
        textattr(WHITE);
        textbackground(BLUE);
        clrscr();

        //graphic part
        tableHead();

        for (bottom = top, scroLen = 0; bottom && scroLen < LEN; bottom = bottom->tnext, scroLen++);

        //that's it
        for (temp = top; temp != bottom; temp = temp->tnext) {
            tableElement(temp);
        }

        if (bottom)
            tableElement(bottom);

        tableBottom();

        // keys code

        //key = getch();

        if (key == 0) key = getch();

        switch (key) {
        case UP:
            if (top->tprev) {
                top = top->tprev;
            }
            break;
        case DOWN:
            if (bottom->tnext) {
                top = top->tnext;
            }
            break;
        case PGUP:
            if (top->tprev && top)
                for (scroLen = 1; top && scroLen < LEN; top = top->tprev, scroLen++);
            else
                top = tfirst;

            break;
        case PGDN:
            if (bottom->tnext && bottom)
                for (scroLen = 1; top && scroLen < LEN; top = top->tnext, scroLen++);

            break;
        case END:
            if (bottom) {
                bottom = getlast(tfirst);
                for (top = bottom, scroLen = 0; top && scroLen < LEN; top = top->tprev, scroLen++);
            }
            break;
        case HOME:
            top = tfirst;
            break;
        }

        if (key == ESC) break;
    }
}

/** Вспомогательная функция отображения таблицы */
void tableHead(void) {

    int i;
    char* country = "Страна", * transport = "Транспорт", * length = "Продолжительность", * cost = "Стоимость, руб";
    //window(1,2,80,25);
    textattr(WHITE);
    textbackground(BLACK);
    clrscr();

    for (i = 0; i < 79; i++) {

        switch (i) {
        case 0:
            cprintf("╔");
            break;
        case 78:
            cprintf("╗");
            break;
        case 18:
            cprintf("╦");
            break;
        case 40:
            cprintf("╦");
            break;
        case 60:
            cprintf("╦");
            break;
        default:
            cprintf("═");
            break;
        }
    }

    gotoxy(1, 2);
    cprintf("║");

    gotoxy(7, 2);
    cputs(country);

    gotoxy(19, 2);
    cprintf("║");

    gotoxy(26, 2);
    cputs(transport);

    gotoxy(41, 2);
    cprintf("║");

    gotoxy(43, 2);
    cputs(length);

    gotoxy(61, 2);
    cprintf("║");

    gotoxy(63, 2);
    cputs(cost);

    gotoxy(79, 2);
    cprintf("║");

    gotoxy(1, 3);
    for (i = 0; i < 79; i++) {

        switch (i) {
        case 0:
            cprintf("╠");
            break;
        case 78:
            cprintf("╣");
            break;
        case 18:
            cprintf("╬");
            break;
        case 40:
            cprintf("╬");
            break;
        case 60:
            cprintf("╬");
            break;
        default:
            cprintf("═");
            break;
        }
    }
    cprintf("\r\n");
}

/** Вспомогательная функция отображения таблицы */
void tableElement(TicketTL * t) {

    cprintf("%c%-17s%c%-21s%1c%*d:%02d%8c%12.2f%6c\r\n", 186, t->cou, 186, t->tr, 186, 9, (t->len / 60), (t->len % 60), 186, t->rub, 186);

}

/** Вспомогательная функция отображения таблицы */
void tableBottom(void) {

    int i = 0;

    for (i = 0; i < 79; i++) {

        switch (i) {
        case 0:
            cprintf("╚");
            break;
        case 78:
            cprintf("╝");
            break;
        case 18:
            cprintf("╩");
            break;
        case 40:
            cprintf("╩");
            break;
        case 60:
            cprintf("╩");
            break;
        default:
            cprintf("═");
            break;
        }
    }
}
