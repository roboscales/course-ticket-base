#define INTERFACE

#include "core.h"

//dgdsd

//first go

void sort(void) {

    int countBox = 2, nowBox = -1, nowList = -1;
    radio_box* sortFor;
    element_list* sortHow;
}

void radioBoxRender(radio_box** boxes, size_t count) {

    int i = 0;
    


}

void render_main_panel(element_list** lists, size_t count) {
    int i = 0;
    window(1, 1, 80, 1);
    textattr(WHITE);
    textbackground(BLACK);
    clrscr();

    for (i = 0; i < count; i++) {
        gotoxy(lists[i]->sizes.x, lists[i]->sizes.y);
        if (lists[i]->hover) {
            textattr(BLACK);
            textbackground(WHITE);
            cprintf(" %s ", lists[i]->label);
        }
        else {
            textattr(WHITE);
            textbackground(BLACK);
            cprintf(" %s ", lists[i]->label);
        }
    }

}

void render_items(element_list* parent, item* items, size_t count) {
    int i = 0;
    int x = parent->sizes.x;
    int y = parent->sizes.y;
    int width = parent->sizes.width;


    window(x, y + 1, x + width, y + count + 1);
    textattr(WHITE);
    textbackground(BLACK);



    for (i = 0; i < count; i++) {

        if (items[i].hover) {

            textattr(BLACK);
            textbackground(GREEN);
            cprintf("│ %s │", items[i].label);
            cprintf("\r\n");
        }
        else {


            textattr(WHITE);
            textbackground(BLACK);

            cprintf("│ %s │", items[i].label);
            cprintf("\r\n");
        }
    }
}

void do_needle(int operation) {
    int num_list = operation / 10;
    int num_operation = operation % 10;

    switch (num_list) {
    case 0: {
        switch (num_operation) {
        case 0:
            seeDialog();
            break;

            /*case 1:
              closemo();
              return;*/
        }
        break;
    }
    case 1: {
        switch (num_operation) {
        case 0:
            createDialog();
            break;
        case 1:
            //editDialog();
            break;
        case 2:
            deleteDialog();
            break;
        }
        break;
    }
    case 2: {
        sortDialog();

        break;
    }
    }
}

void interface(void) {
    int count = 4;
    int in_item = 0;
    int now_in_list = -1;
    int i = 0;
    int now_list = -1;
    char key;
    element_list** lists;
    item** items;
    int* count_items;

    clrscr();

    if (!tfirst)
        load();

    count_items = (int*)malloc(sizeof(int) * count);
    count_items[0] = 2;
    count_items[1] = 3;
    count_items[2] = 0;
    count_items[3] = 0;


    items = (item** )malloc(sizeof(item*) * count);
    for (i = 0; i < count; i++) {
        if (count_items[i] == 0)
            items[i] = NULL;
        else
            items[i] = (item*)malloc(sizeof(item) * count_items[i]);
    }



    lists = (element_list**)malloc(sizeof(element_list*) * count);
    for (i = 0; i < count; i++)
        lists[i] = (element_list*)malloc(sizeof(element_list));



    // first item
    lists[0]->label = "Просмотр";

    lists[0]->sizes.x = 1;
    lists[0]->sizes.y = 1;
    lists[0]->sizes.width = 12;
    lists[0]->sizes.height = 1;

    lists[0]->hover = 0;
    lists[0]->select_item = 0;
    lists[0]->items = items[0];

    // items
    lists[0]->items[0].label = "Просмотр";
    lists[0]->items[0].sizes.x = 1;
    lists[0]->items[0].sizes.y = 2;
    lists[0]->items[0].sizes.width = lists[0]->sizes.width;
    lists[0]->items[0].sizes.height = 1;
    lists[0]->items[0].hover = 0;

    lists[0]->items[1].label = "Выход";
    lists[0]->items[1].sizes.x = 1;
    lists[0]->items[1].sizes.y = 3;
    lists[0]->items[1].sizes.width = lists[0]->sizes.width;
    lists[0]->items[1].sizes.height = 1;
    lists[0]->items[1].hover = 0;
    //



    // second item
    lists[1]->label = "Редактирование";

    lists[1]->sizes.x = lists[0]->sizes.x + lists[0]->sizes.width;
    lists[1]->sizes.y = 1;
    lists[1]->sizes.width = 18;
    lists[1]->sizes.height = 1;

    lists[1]->hover = 0;
    lists[1]->select_item = 0;
    lists[1]->items = items[1];


    // items
    lists[1]->items[0].label = "Создание";
    lists[1]->items[0].sizes.x = lists[1]->sizes.x;
    lists[1]->items[0].sizes.y = 2;
    lists[1]->items[0].sizes.width = lists[1]->sizes.width;
    lists[1]->items[0].sizes.height = lists[1]->sizes.height;
    lists[1]->items[0].hover = 0;

    lists[1]->items[1].label = "Редактирование";
    lists[1]->items[1].sizes.x = lists[1]->sizes.x;
    lists[1]->items[1].sizes.y = 3;
    lists[1]->items[1].sizes.width = lists[1]->sizes.width;
    lists[1]->items[1].sizes.height = lists[1]->sizes.height;
    lists[1]->items[1].hover = 0;

    lists[1]->items[2].label = "Удаление";
    lists[1]->items[2].sizes.x = lists[1]->sizes.x;
    lists[1]->items[2].sizes.y = 4;
    lists[1]->items[2].sizes.width = lists[1]->sizes.width;
    lists[1]->items[2].sizes.height = lists[1]->sizes.height;
    lists[1]->items[2].hover = 0;
    //


    // third item
    lists[2]->label = "Сортировка";

    lists[2]->sizes.x = lists[1]->sizes.x + lists[1]->sizes.width;
    lists[2]->sizes.y = 1;
    lists[2]->sizes.width = 14;
    lists[2]->sizes.height = 1;

    lists[2]->hover = 0;
    lists[2]->select_item = 0;

    lists[2]->items = items[2];

    // fourth item
    lists[3]->label = "Помощь";

    lists[3]->sizes.x = lists[2]->sizes.x + lists[2]->sizes.width;
    lists[3]->sizes.y = 1;
    lists[3]->sizes.width = 9;
    lists[3]->sizes.height = 1;

    lists[3]->hover = 0;
    lists[3]->select_item = 0;
    lists[3]->items = items[3];

    if (now_list != -1)
        lists[now_list]->hover = 1;


    render_main_panel(lists, 4);



    key = getch();
    switch (app_state) {
    case APP_START: {

        // while (1) {

        //     switch (key) {

        //     case 121: {
        //         printf("ddddddddddddddddd");
        //         break;
        //     }

        //     }

        // }

        break;
    }

    case ACTIVE_TOOLBAR: {

        break;
    }

    case ACTIVE_ITEM_TOOLBAR: {

        break;
    }

    }




    key = getch();
    while (key != ESC) {
        switch (key) {
        case RIGHT: {

            if (++now_list == count || now_list == -1)
                now_list = 0;

            for (i = 0; i < count; i++)
                lists[i]->hover = 0;

            lists[now_list]->hover = 1;
            render_main_panel(lists, count);
            break;
        }

        case LEFT: {
            if (now_list == -1)
                now_list = 0;
            else if (--now_list < 0)
                now_list = count - 1;

            for (i = 0; i < count; i++)
                lists[i]->hover = 0;

            lists[now_list]->hover = 1;
            render_main_panel(lists, count);


            break;
        }
        case ENTER: {
            if (!in_item) {
                if (lists[now_list] != NULL) {
                    render_items(lists[now_list], lists[now_list]->items, count_items[now_list]);
                    in_item = 1;
                }
                else {
                    do_needle(now_list * 10);
                }
            }
            else
            {
                in_item = 0;

                lists[now_list]->hover = 0;
                render_main_panel(lists, 4);
                for (i = 0; i < count_items[now_list]; i++)
                    lists[now_list]->items[i].hover = 0;
                do_needle(now_list * 10 + now_in_list);
                now_list = -1;
            }
            break;
        }
        case UP: {
            if (in_item) {
                if (now_in_list == -1)
                    now_in_list = 0;
                else if (--now_in_list < 0)
                    now_in_list = count_items[now_list] - 1;

                for (i = 0; i < count_items[now_list]; i++)
                    lists[now_list]->items[i].hover = 0;
                lists[now_list]->items[now_in_list].hover = 1;

                render_items(lists[now_list], lists[now_list]->items, count_items[now_list]);
            }
            break;
        }
        case DOWN: {
            if (in_item) {
                if (now_in_list == -1)
                    now_in_list = 0;
                else if (++now_in_list == count_items[now_list])
                    now_in_list = 0;

                for (i = 0; i < count_items[now_list]; i++)
                    lists[now_list]->items[i].hover = 0;
                lists[now_list]->items[now_in_list].hover = 1;

                render_items(lists[now_list], lists[now_list]->items, count_items[now_list]);
            }
            break;
        }
        }
        key = getch();
    }










    /*
    char key;
    int sel = 0, pos[4] = {3, 15, 33, 47}, ent = OUT, selList = 0;
    char *men[] = {"Просмотр", "Редактирование", "Сортировка", "Выход"};
    char *see[] = {"Просмотр", "Выход"};
    char *edit[] = {"Создание", "Редактирование", "Удаление"};
    int posSeeY[2] = {2, 3}, posEditY[3] = {2, 3, 4};


    textattr(WHITE);
    textbackground(BLACK);
    clrscr();

    if(!tfirst)
    load();

    while(1){
    //clrscr();
    mainPanel(4, men[0], men[1], men[2], men[3]);

    //if(key == 68){
        //while(1){
            //clrscr();
            //mainPanel(4, men[0], men[1], men[2], men[3]);
            gotoxy(pos[sel], 1);

            textattr(BLACK);
            textbackground(LIGHTGRAY);
            cprintf(" %s ", men[sel]);

            key = getch();

            if(key == 0) key = getch();

            switch(key){
                case RIGHT:
                    //if(sel >= 0 && sel <= 3)
                    sel++;
                    break;
                case LEFT:
                    //if(sel >= 0 && sel <= 3)
                    sel--;
                    break;
                case '1':
                    seeDialog();
                    break;
            }

            if(key == ENTER) ent = IN;
            else ent = OUT;

            if(ent == IN){

                switch(sel){
                    case 0:
                           seeDialog();
                           listMenu(pos[sel], 2, 2, see[0], see[1]);
                           selList = 0;
                           while(1){

                           listMenu(3, 2, 2, see[0], see[1]);
                           key = getch();
                           if(key == 0) key = getch();

                           gotoxy(3, posSeeY[selList]);
                           textattr(BLACK);
                           textbackground(GREEN);
                           cprintf("%s", see[selList]);

                           switch(key){
                            case UP:
                                selList--;
                                break;
                            case DOWN:
                                selList++;
                                break;

                           }
                           if(selList > 1) selList = 0;
                           else if(selList < 0) selList = 1;


                           if(getch() == ESC){
                        selList = 0;
                        main();
                        break;
                        }
                        if(key == ENTER) break;
                           }

                    case 1:
                        listMenu(pos[sel], 2, 3, edit[0], edit[1], edit[2]);
                           sel = 0;
                           while(1){

                           listMenu(15, 2, 3, edit[0], edit[1], edit[2]);
                           key = getch();
                           if(key == 0) key = getch();

                           gotoxy(3, posEditY[sel]);
                           textattr(BLACK);
                           textbackground(GREEN);
                           cprintf("%s", edit[sel]);

                           switch(key){
                            case UP:
                                sel--;
                                break;
                            case DOWN:
                                sel++;
                                break;

                           }
                           if(sel > 2) sel = 0;
                           else if(sel < 0) sel = 1;

                           if(getch() == ESC){
                        sel = 0;
                        main();
                        break;
                        }
                        //if(getch() == ENTER) break;
                           }
                        break;
                    case 2:
                        sortDialog();
                        break;
                    case 3:
                        closemo();
                        return;
                }
                switch(key){
                    case RIGHT:
                    //if(sel >= 0 && sel <= 3)
                    sel++;
                    break;
                    case LEFT:
                    //if(sel >= 0 && sel <= 3)
                    sel--;
                    break;
                }
                switch(selList){
                    case 0:
                        seeDialog();
                        break;
                    case 1:
                        closemo();
                        return;
                           }
            }



            else if(ent == OUT) clrscr();

            if(sel > 3) sel = 0;
            else if(sel < 0) sel = 3;


            if(key == ESC) closemo();
        //}
    //}
    if(key == ESC) return;
       }
       */
}

void create(void) {

    TicketTL* tnew = NULL, * t = NULL;
    float cost_en, cel, drob; //╨╝╨░╤Б╤Б╨╕╨▓ ╨┤╨╗╤П ╨▓╨▓╨╛╨┤╨░ ╨▓╨╡╤Й╨╡╤Б╤В╨▓╨╡╨╜╨╛╨│╨╛ ╤З╨╕╤Б╨╗╨░(╨▒╨░╨│ ╤Б╨╛ ╤Б╤В╤А╤Г╨║╤В╤Г╤А╨░╨╝╨╕)
    int hour = 0, min = 0, l = 0, h = 0, li = 0, isDot = 0;
    char dvoe, ent, ch[3], cm[3], cost[9] = { 0 };

    clrscr();

    tnew = (TicketTL*)malloc(sizeof(TicketTL));
    str_count++;

    printf("Создайте новую запись!\n");

    t = getlast(tfirst);

    fflush(stdin);
    puts("Страна:");

    l = -1;

    while (1) {

        ent = getch();

        if (l != 18) {
            if (ent == ' ' || ent >= 'А' && ent <= 'Я' || ent >= 'а' && ent <= 'п' || ent >= 'р' && ent <= 'я') {
                l++;
                if (l == 0) {
                    if (ent >= 'a' && ent <= 'z') ent -= 32;
                    else if (ent >= 'а' && ent <= 'п') ent -= 32;
                    else if (ent >= 'р' && ent <= 'я') ent -= 80;
                }
                tnew->cou[l] = ent;
                printf("%c", ent);
            }
        }

        if (ent == 13) {
            l++;
            tnew->cou[l] = '\0';
            break;
        }

        else if (ent == BACKSPACE && l >= 0) {
            printf("\b");
            printf(" ");
            printf("\b");
            l--;
        }

        if (ent == ESC) return;
    }

    printf("\n");

    fflush(stdin);
    puts("Вид транспорта:");
    choicetr(&tnew);
    puts(tnew->tr);

    fflush(stdin);
    printf("Время путешествия\n");

    l = 0;
    //    printf("  :  \r");
    while (1) {
        ent = getch();

        if (l != 5) {
            if (isdigit(ent) || ent == ':' && l <= 5) {
                if (l == 0) {
                    printf("%c", ent);
                    hour += (int)ent - 48;
                }
                if (l == 1) {
                    hour *= 10;
                    hour += (int)ent - 48;
                    printf("%c", ent);
                }

                if (l == 2) {
                    ent = ':';
                    printf("%c", ent);
                }

                if (l == 3) {
                    printf("%c", ent);
                    min += (int)ent - 48;
                }

                if (l == 4) {
                    min *= 10;
                    min += (int)ent - 48;
                    printf("%c", ent);
                }

                l++;
            }
        }


        if (ent == ESC) break;
        if (ent == ENTER && l == 5) break;
        else if (ent == BACKSPACE && l >= 0) {
            printf("\b");
            printf(" ");
            printf("\b");
            if (l == 4) min /= 10;
            if (l == 3) min /= 10;
            if (l == 1) hour /= 10;
            if (l == 0) hour /= 10;
            l--;
        }


    }
    tnew->len = (hour * 60) + min;

    fflush(stdin);
    printf("\n");
    printf("Стоимость:\n");
    l = 0;
    li = 0;
    isDot = 0;
    while (1) {

        ent = getch();

        if (isdigit(ent) && isDot == 0) {
            cost[l] = ent;
            printf("%c", ent);

            l++;
        }

        else if (ent == '.') {
            isDot = 1;
            h = l + 1;
            printf(".");
            cost[l] = ent;
        }

        else if (isdigit(ent) && isDot == 1 && h < l + 3) {
            cost[h] = ent;
            printf("%c", ent);
            h++;
        }

        if (ent == 13) {
            h++;
            cost[h] = '\0';
            break;
        }

        else if (ent == BACKSPACE && l >= 0) {
            printf("\b");
            printf(" ");
            printf("\b");
            if (isDot == 1) {
                h--;
                cost[h] = ' ';
            }
            else if (h == 0) {
                isDot = 0;
            }
            else if (isDot == 0) {
                l--;
                cost[l] = ' ';
            }
        }

        if (ent == ESC) return;

    }
    tnew->rub = atof(cost);
    fflush(stdin);

    printf("\n");

    if (tfirst) {
        addEnd(&tnew);
    }

    else {
        addBegin(&tnew);
    }

    printf("Press ESC to exit!");

    windofch = WINDON;

    while (1)
        if (getch() == ESC) break;
}

void choicetr(TicketTL * *pt) {

    char key;

    while (1) {

        printf("Выберите вид транспорта:\n1 - Автомобиль\n2 - Самолет\n3 - Круизный лайнер\n4 - Автобус\n5 - Пешком\n");

        key = getch();

        switch (key) {
        case '1':
            strcpy((*pt)->tr, "Автомобиль");
            return;
        case '2':
            strcpy((*pt)->tr, "Самолет");
            return;
        case '3':
            strcpy((*pt)->tr, "Круизный лайнер");
            return;
        case '4':
            strcpy((*pt)->tr, "Автобус");
            return;
        case '5':
            strcpy((*pt)->tr, "Пешком");
            return;
        }
    }
}

/*void sort(void){
    char key;

    clrscr();

    puts("Выберите тип сортировки");
    puts("1 - По стране(А-Я)");
    puts("2 - По стране(Я-А)");
    puts("3 - По стоимости(по возрастанию)");
    puts("4 - По стоимости(по убыванию)");

    key=getch();

    switch(key){
        case '1':
            if(tfirst && tfirst->tnext){
             bsortssb(&tfirst);
             windofch = WINDON;
             puts("Отсортировано. ESC - для продолжения");
                //while(1)
                if(getch()==ESC) break;
             }
            else if((tfirst && !tfirst->tnext) || !tfirst){
            puts("Нет элементов для сортировки! ESC - для продолжения");
                windofch = WINDOFF;
                //while(1)
                if(getch()==ESC) break;
            }
         case '2':
            if(tfirst && tfirst->tnext){
             bsortsbs(&tfirst);
             windofch = WINDON;
             puts("Отсортировано! ESC - для продолжения");
                //while(1)
                if(getch()==ESC) break;
             }
            else if((tfirst && !tfirst->tnext) || !tfirst){
            puts("Нет элементов для сортировки! ESC - для продолжения");
                windofch = WINDOFF;
                if(getch()==ESC) break;
            }
         case '3':
            if(tfirst && tfirst->tnext){
             bsortrsb(&tfirst);
             windofch = WINDON;
             puts("Отсортировано! ESC - для продолжения");
                //while(1)
                if(getch()==ESC) break;
             }
            else if((tfirst && !tfirst->tnext) || !tfirst){
            puts("Нет элементов для сортировки! ESC - для продолжения");
                windofch = WINDOFF;
                //while(1)
                if(getch()==ESC) break;
            }
         case '4':
            if(tfirst && tfirst->tnext){
             bsortrbs(&tfirst);
             windofch = WINDON;
             puts("Отсортировано! ESC - для продолжения");
                //while(1)
                if(getch()==ESC) break;
             }
            else if((tfirst && !tfirst->tnext) || !tfirst){
            puts("Нет элементов для сортировки! ESC - для продолжения");
                windofch = WINDOFF;
                //while(1)
                if(getch()==ESC) break;
            }
    }
} */

void del(TicketTL** nowDelete) {

    if ((*nowDelete) == tfirst) {
        deleteBegin(&tfirst);
    }

    else if (!(*nowDelete)->tnext) {
        deleteLast(nowDelete);

    }

    else {
        deleteMid(nowDelete);
    }
    //windofch = WINDON;
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

void closemo(void) {

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

void diagnos(void) {
    TicketTL* t = NULL;

    clrscr();

    puts("State of List:");

    for (t = tfirst; t; t = t->tnext) {
        printf("Current:%p\nPrev:%p  Next:%p\n", t, t->tprev, t->tnext);
        printf("\n");
    }

    while (1) {
        if (getch() == 27) break;
    }
}

void deleteDialog(void) {

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

void mainPanel(size_t num, char* first, ...) {

    va_list args;
    char* str = { '\0' };
    int men = 0, pos = 3, sel = 0;

    window(1, 1, 80, 1);
    textattr(WHITE);
    textbackground(BLACK);
    //clrscr();

    va_start(args, num);

    str = va_arg(args, char*);


    clrscr();
    //cputs(first);
    //men = strlen(first);

    while (num--) {
        gotoxy(men + 4, 1);
        cputs(str);
        men += strlen(str) + 4;
        //str[strlen(str)] = '\0';
        str = va_arg(args, char*);
    }

    //gotoxy(men, 1);

    if (str == NULL) {
        str--;
        *str = '\0';
    }

    va_end(args);
}

void listMenu(int x1, int y1, size_t num, char* first, ...) {

    va_list args;
    int* size, i = 0, xbig = 0;
    size_t n = num, s = num;
    char* str = { '\0' }, * big = { '\0' };

    va_start(args, num);

    str = va_arg(args, char*);

    while (n--) {
        if (strlen(str) > strlen(big))
            big = str;
        str = va_arg(args, char*);
    }

    va_end(args);

    xbig = strlen(big);

    window(x1 - 1, y1, x1 + xbig + 4, y1 + num + 1);

    textattr(BLACK);
    textbackground(LIGHTGRAY);

    va_start(args, num);

    n = num;

    str = NULL;

    str = va_arg(args, char*);

    //cputs(first);
    clrscr();

    //n = num;

    gotoxy(2, 1);
    cprintf("┌");

    for (i = 0; i < (xbig + 2); i++)
        cprintf("─");

    cprintf("┐");

    i = 2;

    while (n--) {
        gotoxy(3, i);
        cputs(str);
        i++;
        str = va_arg(args, char*);
    }

    for (i = 2; i < s + 2; i++) {
        gotoxy(2, i);
        cprintf("│");
        gotoxy(xbig + 5, i);
        cprintf("│");
    }

    gotoxy(2, num + 2);
    cprintf("└");

    for (i = 0; i < (xbig + 2); i++)
        cprintf("─");

    cprintf("┘");

    va_end(args);
}

void seeDialog(void) {

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
        headConsole();

        for (bottom = top, scroLen = 0; bottom && scroLen < LEN; bottom = bottom->tnext, scroLen++);

        //that's it
        for (temp = top; temp != bottom; temp = temp->tnext) {
            tableConsole(temp);
        }

        if (bottom)
            tableConsole(bottom);

        endConsole();

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

void headConsole(void) {

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

void tableConsole(TicketTL * t) {

    cprintf("%c%-17s%c%-21s%1c%*d:%02d%8c%12.2f%6c\r\n", 186, t->cou, 186, t->tr, 186, 9, (t->len / 60), (t->len % 60), 186, t->rub, 186);

}

void endConsole(void) {

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

void createDialog(void) {

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

void sortDialog(void) {

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

//got a present for ya

void infoSystem() {
}