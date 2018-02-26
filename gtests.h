#include "headers/Pizzeria.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <ctime>


TEST (PizzeriaTest, GeneralTest) {
	Pizzeria piz;

	const long long countOfTests = 10000000;
	for (size_t i = 0; i < countOfTests; i++) {
		int countOfPizzas = rand() % 1000000;
		int countOfDrinks = rand() % 1000000;

		int typeOfSet = rand() % 3;

		Set* set;
        std::vector<Pizza*> pizzas;
        std::vector<Drink*> drinks;

		switch (typeOfSet) {
			case 0:
			{
				set = piz.MakeASetOrder(Pizzeria::ITALIAN_SET, countOfPizzas, countOfDrinks);

				pizzas = set->getPizzas();
				drinks = set->getDrinks();

				for (size_t i = 0; i < countOfPizzas; i++) {
					ASSERT_TRUE(pizzas[i]->getFilling() == Pizza::MEAT);
					ASSERT_TRUE(pizzas[i]->getSpice() == Pizza::KETCHUP);
					ASSERT_TRUE(pizzas[i]->getHotDegree() == Pizza::MID);
				}

				for (size_t i = 0; i < countOfDrinks; i++) {
					ASSERT_TRUE(typeid(typeof(drinks[i])) == typeid(Wine));
				}

				break;
			}

			case 1:
			{
				set = piz.MakeASetOrder(Pizzeria::RUSSIAN_SET, countOfPizzas, countOfDrinks);

				pizzas = set->getPizzas();
				drinks = set->getDrinks();

				for (size_t i = 0; i < countOfPizzas; i++) {
					ASSERT_TRUE(pizzas[i]->getFilling() == Pizza::MUSHROOMS);
					ASSERT_TRUE(pizzas[i]->getSpice() == Pizza::DILL);
					ASSERT_TRUE(pizzas[i]->getHotDegree() == Pizza::LOW);
				}

				for (size_t i = 0; i < countOfDrinks; i++) {
					ASSERT_TRUE(typeid(typeof(drinks[i])) == typeid(Kvass));
				}

				break;
			}

			case 2:
			{
				set = piz.MakeASetOrder(Pizzeria::MEXICAN_SET, countOfPizzas, countOfDrinks);

				pizzas = set->getPizzas();
				drinks = set->getDrinks();

				for (size_t i = 0; i < countOfPizzas; i++) {
					ASSERT_TRUE(pizzas[i]->getFilling() == Pizza::SALAMI);
					ASSERT_TRUE(pizzas[i]->getSpice() == Pizza::CHILI_SAUCE);
					ASSERT_TRUE(pizzas[i]->getHotDegree() == Pizza::HIGH);
				}

				for (size_t i = 0; i < countOfDrinks; i++) {
					ASSERT_TRUE(typeid(typeof(drinks[i])) == typeid(Mescal));
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
