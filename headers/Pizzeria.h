#pragma once

#include "Includes.h"
#include "Set.h"
#include "Kitchen.h"
#include "SetChefs.h"

class Pizzeria {
public:
	enum MenuItem{ITALIAN_SET, RUSSIAN_SET, MEXICAN_SET};

	Set* MakeASetOrder(const MenuItem& mi, int countOfPizzas, int countOfDrinks) {
		switch (mi) {
			case Pizzeria::ITALIAN_SET:
				return kitchen.CreateSet(italianChef, countOfPizzas, countOfDrinks);
				break;

			case Pizzeria::RUSSIAN_SET:
				return kitchen.CreateSet(russianChef, countOfPizzas, countOfDrinks);
				break;

			case Pizzeria::MEXICAN_SET:
				return kitchen.CreateSet(mexicanChef, countOfPizzas, countOfDrinks);
				break;

			default:
				break;
		}
	}

private:
	Kitchen kitchen;
	
	ItalianSetChef italianChef;
	RussianSetChef russianChef;
	MexicanSetChef mexicanChef;
};