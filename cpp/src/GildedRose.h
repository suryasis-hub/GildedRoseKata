#include <string>
#include <vector>

using namespace std;

class Item
{
public:
    string name;
    int sellIn;
    int quality;
    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}
};

class GildedRose
{
 public:
    vector<Item> & items;
    GildedRose(vector<Item> & items);
    void handleExpired(Item& item);
    void updateQuality();
    const int MAX_QUALITY = 50;
    const int MIN_QUALITY = 0;

private:
    bool isSulfurasFn(const string name)
    {
        return name == "Sulfuras, Hand of Ragnaros";
    }

    bool isAgedBrieFn(const string name)
    {
        return name == "Aged Brie";
    }

    bool isBackStageFn(const string name)
    {
        return name == "Backstage passes to a TAFKAL80ETC concert";
    }
    void setBounds(Item& item);
    
};

void setBounds(Item& item);
