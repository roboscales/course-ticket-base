#include "core.h"

void deleteOneRecord(TicketTL** nowDelete) {

    if ((*nowDelete) == tfirst)
        deleteBegin(&tfirst);
    else if (!(*nowDelete)->tnext) 
        deleteLast(nowDelete);
    else 
        deleteMid(nowDelete);
}

void twoButtonDialog(int x1, int y1, int x2, int y2, char* message, char* first, char* second) {

    int i = 0;

    window(x1, y1, x2, y2);
    textattr(WHITE);
    textbackground(BLUE);

    clrscr();

    gotoxy(1, 1);
    cprintf("╔");

    for (i = 0; i < (x2 - x1) - 1; i++) {
        //gotoxy(i, 1);
        cprintf("═");
    }

    gotoxy((x2 - x1) + 1, 1);
    cprintf("╗");

    //gotoxy(1, 3);

    for (i = 2; i < (y2 - y1) + 1; i++) {
        gotoxy(1, i);
        cprintf("║");
        gotoxy((x2 - x1) + 1, i);
        cprintf("║");
    }

    gotoxy(1, (y2 - y1));
    cprintf("╚");

    for (i = 0; i < (x2 - x1) - 1; i++) cprintf("═");

    gotoxy((x2 - x1) + 1, (y2 - y1));
    cprintf("╝");


    gotoxy(4, 4);
    cputs(message);

    gotoxy(5, 8);
    cputs(first);

    gotoxy(19, 8);
    cputs(second);

}

void exitApp(void) {

    char key, sel;
    int pos = 5, l;

    //textattr(WHITE);
    //textbackground(BLACK);
    clrscr();

    if (windofch == WINDOFF) {
        if (tfirst) ListDestroy(&tfirst);
        return;
    }
    else if (windofch == WINDON) {
        while (1) {
            while (1) {
                _setcursortype(_NOCURSOR);
                twoButtonDialog(26, 6, 54, 15, "Сохранить изменения?", "Да", "Нет");
                sel = 0;

                gotoxy(pos, 8);
                if (pos == 5) {
                    textattr(BLACK);
                    textbackground(RED);
                    cprintf("Да");
                    sel = '1';
                }
                if (pos == 19) {
                    textattr(BLACK);
                    textbackground(RED);
                    cprintf("Нет");
                    sel = '2';
                }


                key = getch();

                if (key == 9 && pos == 5) {
                    pos = 19;
                }
                else if (key == 9 && pos == 19) {
                    pos = 5;
                }

                if (key == 27) return;
                if (key == 13) break;

            }
            switch (sel) {
            case '1':
                save();
                if (tfirst) ListDestroy(&tfirst);
                return;
            case '2':
                if (tfirst) ListDestroy(&tfirst);
                return;
            }
        }
    }
    else return;
}

