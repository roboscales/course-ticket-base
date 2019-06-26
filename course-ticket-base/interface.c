#define INTERFACE

#include "core.h"

#include "dialog.h"
#include "table.h"

#include "other.h"

//first go

#define list_element_fill(_index, _label, _x, _y, _width, _height, _hover, _select_item, _items_ptr) \
    lists[_index]->label = _label; \
    lists[_index]->sizes.x = _x; \
    lists[_index]->sizes.y = _y; \
    lists[_index]->sizes.width = _width; \
    lists[_index]->sizes.height = _height; \
    lists[_index]->hover = _hover; \
    lists[_index]->select_item = _select_item; \
    lists[_index]->items = _items_ptr; \

#define add_item_list(_index, _item_num, _label, _x, _y, _width, _height, _hover) \
    lists[_index]->items[_item_num].label = _label; \
    lists[_index]->items[_item_num].sizes.x = _x; \
    lists[_index]->items[_item_num].sizes.y = _y; \
    lists[_index]->items[_item_num].sizes.width = _width; \
    lists[_index]->items[_item_num].sizes.height = _height; \
    lists[_index]->items[_item_num].hover = _hover;



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
            showTable();
            break;

            /*case 1:
              exitApp();
              return;*/
        }
        break;
    }
    case 1: {
        switch (num_operation) {
        case 0:
            showCreateDialog();
            break;
        case 1:
            //editDialog();
            break;
        case 2:
            showDeleteDialog();
            break;
        }
        break;
    }
    case 2: {
        showSortDialog();

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
    int count_items[4];

    clrscr();

    if (!tfirst)
        load();

    
    count_items[0] = 3;
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
    list_element_fill(0, "Просмотр", 1, 1, 12, 1, 0, 0, items[0]);
    add_item_list(0, 0, "Просмотр", 1, 2, lists[0]->sizes.width, 1, 0);
    add_item_list(0, 1, "Поиск", 1, 3, lists[0]->sizes.width, 1, 0);
    add_item_list(0, 2, "Выход", 1, 4, lists[0]->sizes.width, 1, 0);
    

    // second item
    list_element_fill(1, "Редактирование", lists[0]->sizes.x + lists[0]->sizes.width, 1, 18, 1, 0, 0, items[1]);
    add_item_list(1, 0, "Создание", lists[1]->sizes.x, 2, lists[1]->sizes.width, 1, 0);
    add_item_list(1, 1, "Редактирование", lists[1]->sizes.x, 3, lists[1]->sizes.width, 1, 0);
    add_item_list(1, 2, "Удаление", lists[1]->sizes.x, 4, lists[1]->sizes.width, 1, 0);
   

    // third item
    list_element_fill(2, "Сортировка", lists[1]->sizes.x + lists[1]->sizes.width, 1, 14, 1, 0, 0, items[2]);

    // fourth item
    list_element_fill(3, "Помощь", lists[2]->sizes.x + lists[2]->sizes.width, 1, 9, 1, 0, 0, items[3]);



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
}

