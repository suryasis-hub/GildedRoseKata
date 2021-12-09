#include <string>
#include <vector>
#include <set>

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
private:
    bool isItemNameNotInSet(set<string> nameSet, const Item& item);
public:
    vector<Item> & items;
    GildedRose(vector<Item> & items);
    
    void updateQuality();
    
};

