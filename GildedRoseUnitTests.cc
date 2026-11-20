#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>
#include <stdlib.h>

extern "C" {
#include "GildedRose.h"
}

TEST_GROUP(TestGildedRoseGroup)
{
    Item item;

    void teardown() {
        free(item.name);
    }
};

TEST(TestGildedRoseGroup, ItemComumPerdeUmDeQualidadeAntesDeVencer)
{
    init_item(&item, "+5 Dexterity Vest", 10, 20);
    update_quality(&item, 1);
    LONGS_EQUAL(9, item.sellIn);
    LONGS_EQUAL(19, item.quality);
}

TEST(TestGildedRoseGroup, ItemComumPerdeDoisDeQualidadeDepoisDeVencer)
{
    init_item(&item, "+5 Dexterity Vest", 0, 20);
    update_quality(&item, 1);
    LONGS_EQUAL(-1, item.sellIn);
    LONGS_EQUAL(18, item.quality);
}

TEST(TestGildedRoseGroup, QualidadeNuncaFicaNegativa)
{
    init_item(&item, "Elixir of the Mongoose", 5, 0);
    update_quality(&item, 1);
    LONGS_EQUAL(4, item.sellIn);
    LONGS_EQUAL(0, item.quality);
}

TEST(TestGildedRoseGroup, QueijoBrieAumentaQualidadeEmUm)
{
    init_item(&item, "Aged Brie", 2, 0);
    update_quality(&item, 1);
    LONGS_EQUAL(1, item.sellIn);
    LONGS_EQUAL(1, item.quality);
}

TEST(TestGildedRoseGroup, QueijoBrieAumentaQualidadeEmDoisDepoisDeVencer)
{
    init_item(&item, "Aged Brie", 0, 10);
    update_quality(&item, 1);
    LONGS_EQUAL(-1, item.sellIn);
    LONGS_EQUAL(12, item.quality);
}

TEST(TestGildedRoseGroup, QualidadeNuncaPassaDeCinquenta)
{
    init_item(&item, "Aged Brie", 2, 50);
    update_quality(&item, 1);
    LONGS_EQUAL(50, item.quality);
}

TEST(TestGildedRoseGroup, SulfurasNuncaMuda)
{
    init_item(&item, "Sulfuras, Hand of Ragnaros", 0, 80);
    update_quality(&item, 1);
    LONGS_EQUAL(0, item.sellIn);
    LONGS_EQUAL(80, item.quality);
}

TEST(TestGildedRoseGroup, IngressoShowSobeUmQuandoFaltamMaisDeDezDias)
{
    init_item(&item, "Backstage passes to a TAFKAL80ETC concert", 15, 20);
    update_quality(&item, 1);
    LONGS_EQUAL(14, item.sellIn);
    LONGS_EQUAL(21, item.quality);
}

TEST(TestGildedRoseGroup, IngressoShowSobeDoisQuandoFaltamDezDiasOuMenos)
{
    init_item(&item, "Backstage passes to a TAFKAL80ETC concert", 10, 20);
    update_quality(&item, 1);
    LONGS_EQUAL(9, item.sellIn);
    LONGS_EQUAL(22, item.quality);
}

TEST(TestGildedRoseGroup, IngressoShowSobeTresQuandoFaltamCincoDiasOuMenos)
{
    init_item(&item, "Backstage passes to a TAFKAL80ETC concert", 5, 20);
    update_quality(&item, 1);
    LONGS_EQUAL(4, item.sellIn);
    LONGS_EQUAL(23, item.quality);
}

TEST(TestGildedRoseGroup, IngressoShowZeraQualidadeDepoisDoShow)
{
    init_item(&item, "Backstage passes to a TAFKAL80ETC concert", 0, 20);
    update_quality(&item, 1);
    LONGS_EQUAL(-1, item.sellIn);
    LONGS_EQUAL(0, item.quality);
}

TEST(TestGildedRoseGroup, ItemConjuradoPerdeDoisDeQualidadeAntesDeVencer)
{
    init_item(&item, "Conjured Mana Cake", 3, 6);
    update_quality(&item, 1);
    LONGS_EQUAL(2, item.sellIn);
    LONGS_EQUAL(4, item.quality);
}

TEST(TestGildedRoseGroup, ItemConjuradoPerdeQuatroDeQualidadeDepoisDeVencer)
{
    init_item(&item, "Conjured Mana Cake", 0, 6);
    update_quality(&item, 1);
    LONGS_EQUAL(-1, item.sellIn);
    LONGS_EQUAL(2, item.quality);
}

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}