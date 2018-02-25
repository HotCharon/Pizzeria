#pragma once

#include "Includes.h"
#include "SetChefs.h"
#include "Set.h"

class Kitchen {
public:
	Set* CreateSet(SetChef& cc) {
		Set* set = new Set;

		set->AddPizza(cc.CreatePizza());
		set->AddDrink(cc.CreateDrink());

		return set;
	}
};