#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}




void GildedRose::updateQuality() 
{
    for (Item &item : items)
    {
        if (isBackStageFn(item.name))
        {
                item.quality++; 
        }
        if (isSulfurasFn(item.name) || isAgedBrieFn(item.name))
        {
            updatingQuality(item);
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
        setBounds(item);
    }
}

void GildedRose::setBounds(Item& item)
{
    item.quality = max(MIN_QUALITY, min(item.quality, MAX_QUALITY));
}

void GildedRose::handleExpired(Item& item)
{
    if (item.sellIn >= 0)
        return;
    if (isAgedBrieFn(item.name) || isBackStageFn(item.name))
    {
        item.quality++;
    }
    else if(isSulfurasFn(item.name))
    {
        item.quality = MIN_QUALITY;
    }
    else
    {
        item.quality--;
    }

}



