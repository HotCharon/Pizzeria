#pragma once

#include "Includes.h"
#include "SetChefs.h"
#include "Set.h"

class Kitchen {
public:
	Set* CreateSet(SetChef& cc, int countOfPizzas, int countOfDrinks) {
		Set* set = new Set;
		
		for (size_t i = 0; i < countOfPizzas; i++)
			set->AddPizza(cc.CreatePizza());
		
		for (size_t i = 0; i < countOfDrinks; i++)
			set->AddDrink(cc.CreateDrink());

		return set;
	}
};