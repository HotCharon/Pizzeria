#pragma once

#include "Includes.h"
#include "Pizza.h"
#include "Drinks.h"

class Set {
public:
	void AddPizza(Pizza* p) {
		pizzas.push_back(p);
	}

	void AddDrink(Drink* d) {
		drinks.push_back(d);
	}

	std::vector<Pizza*> getPizzas() {
		return pizzas;
	}
	
	std::vector<Drink*> getDrinks() {
		return drinks;
	}

private:
	std::vector<Pizza*> pizzas;
	std::vector<Drink*> drinks;
};