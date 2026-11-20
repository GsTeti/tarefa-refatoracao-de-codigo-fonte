#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "GildedRose.h"

#define QUALIDADE_MAXIMA 50
#define QUALIDADE_MINIMA 0

static const char *QUEIJO_BRIE = "Aged Brie";
static const char *INGRESSO_SHOW = "Backstage passes to a TAFKAL80ETC concert";
static const char *SULFURAS = "Sulfuras, Hand of Ragnaros";
static const char *PREFIXO_CONJURADO = "Conjured";

Item* init_item(Item* item, const char *name, int sellIn, int quality)
{
    item->sellIn = sellIn;
    item->quality = quality;
    item->name = strdup(name);
    
    return item;
}

extern char* print_item(char* buffer, Item* item) 
{
    sprintf(buffer, "%s, %d, %d", item->name, item->sellIn, item->quality);
    return buffer;
}

static bool e_queijo_brie(const Item *item) {
    return strcmp(item->name, QUEIJO_BRIE) == 0;
}

static bool e_ingresso_show(const Item *item) {
    return strcmp(item->name, INGRESSO_SHOW) == 0;
}

static bool e_sulfuras(const Item *item) {
    return strcmp(item->name, SULFURAS) == 0;
}

static bool e_item_conjurado(const Item *item) {
    return strncmp(item->name, PREFIXO_CONJURADO, strlen(PREFIXO_CONJURADO)) == 0;
}

static void aumentar_qualidade(Item *item, int valor) {
    item->quality += valor;
    if (item->quality > QUALIDADE_MAXIMA) {
        item->quality = QUALIDADE_MAXIMA;
    }
}

static void diminuir_qualidade(Item *item, int valor) {
    item->quality -= valor;
    if (item->quality < QUALIDADE_MINIMA) {
        item->quality = QUALIDADE_MINIMA;
    }
}

static void atualizar_queijo_brie(Item *item) {
    item->sellIn--;
    int aumento = (item->sellIn < 0) ? 2 : 1;
    aumentar_qualidade(item, aumento);
}

static void atualizar_ingresso_show(Item *item) {
    if (item->sellIn <= 5) {
        aumentar_qualidade(item, 3);
    } else if (item->sellIn <= 10) {
        aumentar_qualidade(item, 2);
    } else {
        aumentar_qualidade(item, 1);
    }

    item->sellIn--;

    if (item->sellIn < 0) {
        item->quality = QUALIDADE_MINIMA;
    }
}

static void atualizar_item_conjurado(Item *item) {
    item->sellIn--;
    int perda = (item->sellIn < 0) ? 4 : 2;
    diminuir_qualidade(item, perda);
}

static void atualizar_item_comum(Item *item) {
    item->sellIn--;
    int perda = (item->sellIn < 0) ? 2 : 1;
    diminuir_qualidade(item, perda);
}

static void atualizar_um_item(Item *item) {
    if (e_sulfuras(item)) {
        return;
    }

    if (e_queijo_brie(item)) {
        atualizar_queijo_brie(item);
    } else if (e_ingresso_show(item)) {
        atualizar_ingresso_show(item);
    } else if (e_item_conjurado(item)) {
        atualizar_item_conjurado(item);
    } else {
        atualizar_item_comum(item);
    }
}

void update_quality(Item items[], int size) 
{
    for (int i = 0; i < size; i++) {
        atualizar_um_item(&items[i]);
    }
}