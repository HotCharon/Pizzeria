#pragma once

#include "Includes.h"
#include "Set.h"
#include "Kitchen.h"
#include "SetChefs.h"

class Pizzeria {
public:
	enum MenuItem{ITALIAN_SET, RUSSIAN_SET, MEXICAN_SET};

	Set* MakeASetOrder(MenuItem mi, int countOfPizzas, int countOfDrinks) {
		switch (mi) {
			case Pizzeria::ITALIAN_SET:
				kitchen.CreateSet(italianChef);
				break;
			case Pizzeria::RUSSIAN_SET:
				kitchen.CreateSet(russianChef);
				break;
			case Pizzeria::MEXICAN_SET:
				kitchen.CreateSet(mexicanChef);
				break;
			default:
				break;
		}
	}

private:
	Kitchen kitchen;
	
	SetChef italianChef;
	SetChef russianChef;
	SetChef mexicanChef;
};