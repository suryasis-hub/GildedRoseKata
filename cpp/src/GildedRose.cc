#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}


    
void GildedRose::updateQuality() 
{
    for (Item &item : items)
    {
        if (item.name != "Aged Brie" && item.name != "Backstage passes to a TAFKAL80ETC concert"  \
            && item.name != "Sulfuras, Hand of Ragnaros" && item.quality > 0)
        {
            item.quality--;
        }
        else
        {
            if (item.quality < 50)
            {
                item.quality++;

                if (item.name == "Backstage passes to a TAFKAL80ETC concert" &&
                    item.sellIn < 11 && item.quality < 50)
                {
                    item.quality++;

                    if (item.sellIn < 6 && item.quality < 50)
                    {
                        item.quality++;   
                    }
                }
            }
        }

        if (item.name != "Sulfuras, Hand of Ragnaros")
        {
            item.sellIn--;
        }

        if (item.sellIn < 0)
        {
            if (item.name != "Aged Brie" && item.name != "Backstage passes to a TAFKAL80ETC concert" )
            {
                if (item.name != "Backstage passes to a TAFKAL80ETC concert" && item.name != "Sulfuras, Hand of Ragnaros" && item.quality > 0)
                {
                    item.quality--;
                }
                else
                {
                    item.quality = 0;
                }
            }
            else
            {
                if (item.quality < 50)
                {
                    item.quality = item.quality++;
                }
            }
        }
    }
}

