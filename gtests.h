#include "headers/Pizzeria.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <ctime>


void GeneralTest() {
	Pizzeria piz;

	const long long countOfTests = 10000000;
	for (size_t i = 0; i < countOfTests; i++) {
		int countOfPizzas = rand() % 1000000;
		int countOfDrinks = rand() % 1000000;

		int typeOfSet = rand() % 3;

		Set* set;

		switch (typeOfSet) {
			case 0:
			{
				set = piz.MakeASetOrder(Pizzeria::ITALIAN_SET, countOfPizzas, countOfDrinks);

				std::vector<Pizza*> pizzas = set->getPizzas();
				std::vector<Drink*> drinks = set->getDrinks();

				for (size_t i = 0; i < countOfPizzas; i++) {
					ASSERT_TRUE(pizzas[i].getFilling() == Pizza::MEAT);
					ASSERT_TRUE(pizzas[i].getSpice() == Pizza::KETCHUP);
					ASSERT_TRUE(pizzas[i].getHotDegree() == Pizza::MID);
				}

				for (size_t i = 0; i < countOfDrinks; i++) {
					ASSERT_TRUE(typeid(drinks[i]) == Wine);
				}

				break;
			}

			case 1:
			{
				set = piz.MakeASetOrder(Pizzeria::RUSSIAN_SET, countOfPizzas, countOfDrinks);

				std::vector<Pizza*> pizzas = set->getPizzas();
				std::vector<Drink*> drinks = set->getDrinks();

				for (size_t i = 0; i < countOfPizzas; i++) {
					ASSERT_TRUE(pizzas[i].getFilling() == Pizza::MUSHROOMS);
					ASSERT_TRUE(pizzas[i].getSpice() == Pizza::DILL);
					ASSERT_TRUE(pizzas[i].getHotDegree() == Pizza::LOW);
				}

				for (size_t i = 0; i < countOfDrinks; i++) {
					ASSERT_TRUE(typeid(drinks[i]) == Kvass);
				}

				break;
			}

			case 2:
			{
				set = piz.MakeASetOrder(Pizzeria::MEXICAN_SET, countOfPizzas, countOfDrinks);

				std::vector<Pizza*> pizzas = set->getPizzas();
				std::vector<Drink*> drinks = set->getDrinks();

				for (size_t i = 0; i < countOfPizzas; i++) {
					ASSERT_TRUE(pizzas[i].getFilling() == Pizza::SALAMI);
					ASSERT_TRUE(pizzas[i].getSpice() == Pizza::ÑHILI_SAUCE);
					ASSERT_TRUE(pizzas[i].getHotDegree() == Pizza::HIGH);
				}

				for (size_t i = 0; i < countOfDrinks; i++) {
					ASSERT_TRUE(typeid(drinks[i]) == Mescal);
				}

				break;
			}

			default:
				break;
		}

		ASSERT_TRUE(pizzas.size() == countOfPizzas);
		ASSERT_TRUE(pizzas.size() == countOfDrinks);


	}
}