#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}


    
void GildedRose::updateQuality() 
{
    for (Item &item : items)
    {
        
        if (isItemNameNotInSet({ "Aged Brie","Backstage passes to a TAFKAL80ETC concert","Sulfuras, Hand of Ragnaros" }
            , item) && item.quality > 0)
        {
            item.quality--;
        }
        else
        {
            if (item.quality < 50)
            {
                item.quality++;
                if (isItemNameNotInSet({ "Backstage passes to a TAFKAL80ETC concert"}
                    , item) &&
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
        if (isItemNameNotInSet({ "Sulfuras, Hand of Ragnaros" }, item))
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
            else if (item.quality < 50)
            {                
                item.quality = item.quality++;   
            }
        }
    }
}

bool GildedRose::isItemNameNotInSet(set<string> nameSet, const Item& item)
{
    return (nameSet.find(item.name) == nameSet.end());
}

