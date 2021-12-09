#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}




void GildedRose::updateQuality() 
{
    for (Item &item : items)
    {
        if (isSulfurasFn(item.name) || isAgedBrieFn(item.name) || isBackStageFn(item.name))
        {
                item.quality++;
                if (isSulfurasFn(item.name) || isAgedBrieFn(item.name))
                {
                    if (item.sellIn < 6)
                    {
                        item.quality+=2;
                    }
                    if (item.sellIn < 11)
                    {
                        item.quality += 1;
                    }
                }
        }
        else 
        {
            item.quality--;
        }
        if (!isSulfurasFn(item.name))
        {
            item.sellIn--;
        }
        handleExpired(item);
        item.quality = max(MIN_QUALITY, min(item.quality, MAX_QUALITY));
    }
}

void GildedRose::handleExpired(Item& item)
{
    if (item.sellIn >= 0)
        return;
    if (isAgedBrieFn(item.name) || isBackStageFn(item.name))
    {
        item.quality = min(item.quality++, 50);
    }
    else if(isSulfurasFn(item.name))
    {
        item.quality = 0;
    }
    else
    {
        item.quality--;
    }

}



