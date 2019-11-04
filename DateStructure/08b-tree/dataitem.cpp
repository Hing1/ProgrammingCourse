#include "dataitem.h"

#include <iostream>

using std::cout;

DataItem::DataItem(long dd)
    :dData(dd) {}
void DataItem::displayItem() {
    cout << "/" << dData;
}
