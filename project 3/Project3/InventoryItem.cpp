
#include "InventoryItem.h"

bool InventoryItem::removeUnits(int h) {

	if (units < h) {
		return false;
	}
	else
	{
		units -= h;
		return true;
		
	}

}
