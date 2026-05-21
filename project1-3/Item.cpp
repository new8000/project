#include "Item.h"

void Item::PrintInfo() const
{
    cout << name
        << " (" << price << "G)"
        << endl;
}