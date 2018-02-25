#pragma once

#include "Includes.h"
#include "Pizza.h"
#include "Drinks.h"
#include "Recipes.h"

class SetChef { //it's abstract factory
public:
	virtual Pizza* CreatePizza() = 0;
	virtual Drink* CreateDrink() = 0;
};

class ItalianSetChef : public SetChef {
public:
	virtual Pizza* CreatePizza() {
		pizzaRecipe.CreatePizza();

		pizzaRecipe.BuildFilling();
		pizzaRecipe.BuildSpice();
		pizzaRecipe.BuildHotDegree();

		return pizzaRecipe.GetPizza().get();
	}

	virtual Drink* CreateDrink() {
		return new Wine;
	}

private:
	ItalianPizzaRecipe pizzaRecipe;
};

class RussianSetChef : public SetChef {
	virtual Pizza* CreatePizza() {
		pizzaRecipe.CreatePizza();

		pizzaRecipe.BuildFilling();
		pizzaRecipe.BuildSpice();
		pizzaRecipe.BuildHotDegree();

		return pizzaRecipe.GetPizza().get();
	}

	virtual Drink* CreateDrink() {
		return new Kvass;
	}

private:
	RussianPizzaRecipe pizzaRecipe;
};

class MexicanSetChef : public SetChef {
	virtual Pizza* CreatePizza() {
		pizzaRecipe.CreatePizza();

		pizzaRecipe.BuildFilling();
		pizzaRecipe.BuildSpice();
		pizzaRecipe.BuildHotDegree();

		return pizzaRecipe.GetPizza().get();
	}

	virtual Drink* CreateDrink() {
		return new Mescal;
	}

private:
	MexicanPizzaRecipe pizzaRecipe;
};