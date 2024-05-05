#include <stdlib.h>
#include <stdio.h>

typedef struct Item {
    char *_value;
    size_t index;
    struct Item *next;
} Item;

typedef struct Map {
   struct Item *start;
   size_t count;
}Map;

int push(Map *map, char *value) {
    Item* _item = (Item*) malloc(sizeof(Item));
    _item->_value = value;
    Item *last = map->start;
    for (size_t i = 0; i < map->count; i++) {
        last = last->next;
    }
    map->count ++;
    last->next = _item;
    return 0;
}

int filter(char *filter) {
    
}

Map* map() {
    Map* map = (Map*) malloc(sizeof(Map));
    Item* start = (Item*) malloc(sizeof(Item));
    start->index = 0;
    start->next = NULL;
    start->_value = NULL;
    map->count = 0;
    map->start = start;
}



int main() {
    Map *mamad = map();
    push(mamad,"kian");
    push(mamad,"erfan");
    push(mamad,"mobin");
    push(mamad,"nima");
    Item *item = mamad->start;
    for (size_t i = 0; i < mamad->count;i++) {
        item = item->next;
        printf("%s\n",item->_value);
    }
    // printf("%s\n",mamad->start->next->_value);
    return 0;
}