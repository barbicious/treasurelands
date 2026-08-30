#pragma once

#define LIST(type) struct {\
    type *items;\
    usize length;\
    usize capacity;\
}

#define LIST_SIZE(list) (list.capacity * sizeof(*list.items))

#define LIST_INIT(list, cap)\
    do {\
        list.capacity = cap;\
        list.items = malloc(LIST_SIZE(list));\
    } while (0)

#define LIST_APPEND(list, item)\
do {\
    if (list.length >= list.capacity) {\
        list.capacity *= 2;\
        void *tmp = realloc(list.items, LIST_SIZE(list));\
        if (tmp == nullptr) {\
            LIST_FREE(list);\
        } else {\
            list.items = tmp;\
        }\
    }\
    list.items[++list.length] = item;\
} while(0);

#define LIST_FREE(list)\
    do {\
        free(list.items);\
    } while (0)
