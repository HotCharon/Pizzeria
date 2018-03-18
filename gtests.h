#include "headers/Pizzeria.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <ctime>


TEST (PizzeriaTest, GeneralTest) {
	Pizzeria piz;

	const long long countOfTests = 1000;
	for (size_t i = 0; i < countOfTests; i++) {
		int countOfPizzas = rand() % 1000;
		int countOfDrinks = rand() % 1000;

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
					ASSERT_TRUE(typeid(*drinks[i]) == typeid(Wine));
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
					ASSERT_TRUE(typeid(*drinks[i]) == typeid(Kvass));
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
					ASSERT_TRUE(typeid(*drinks[i]) == typeid(Mescal));
				}

				break;
			}

			default:
				break;
		}

		ASSERT_TRUE(pizzas.size() == countOfPizzas);
		ASSERT_TRUE(drinks.size() == countOfDrinks);
	}
}

TEST(PizzaTest, ItalianPizzaTest) {
	Pizzeria piz;
	const long long countOfTests = 100;

	for (int j = 0; j < countOfTests; ++j) {
		int countOfPizzas = 1000;

		Set* set;
		std::vector<Pizza*> pizzas;

		set = piz.MakeASetOrder(Pizzeria::ITALIAN_SET, countOfPizzas, 0);

		pizzas = set->getPizzas();

		for (size_t i = 0; i < countOfPizzas; i++) {
			ASSERT_TRUE(pizzas[i]->getFilling() == Pizza::MEAT);
			ASSERT_TRUE(pizzas[i]->getSpice() == Pizza::KETCHUP);
			ASSERT_TRUE(pizzas[i]->getHotDegree() == Pizza::MID);
		}
	}
}

TEST(PizzaTest, RussianPizzaTest) {
	Pizzeria piz;
	const long long countOfTests = 100;

	for (int j = 0; j < countOfTests; ++j) {
		int countOfPizzas = 1000;

		Set* set;
		std::vector<Pizza*> pizzas;

		set = piz.MakeASetOrder(Pizzeria::RUSSIAN_SET, countOfPizzas, 0);

		pizzas = set->getPizzas();

		for (size_t i = 0; i < countOfPizzas; i++) {
			ASSERT_TRUE(pizzas[i]->getFilling() == Pizza::MUSHROOMS);
			ASSERT_TRUE(pizzas[i]->getSpice() == Pizza::DILL);
			ASSERT_TRUE(pizzas[i]->getHotDegree() == Pizza::LOW);
		}
	}
}

TEST(PizzaTest, MexicanPizzaTest) {
	Pizzeria piz;
	const long long countOfTests = 100;

	std::vector<Pizza*> pizzas;
	for (int j = 0; j < countOfTests; ++j) {
		int countOfPizzas = 1000;

		Set* set;


		set = piz.MakeASetOrder(Pizzeria::MEXICAN_SET, countOfPizzas, 0);

		pizzas = set->getPizzas();

		for (size_t i = 0; i < countOfPizzas; i++) {
			ASSERT_TRUE(pizzas[i]->getFilling() == Pizza::SALAMI);
			ASSERT_TRUE(pizzas[i]->getSpice() == Pizza::CHILI_SAUCE);
			ASSERT_TRUE(pizzas[i]->getHotDegree() == Pizza::HIGH);
		}
	}
}

Set* MakeSet(const Pizzeria::MenuItem& setType, const int& countOfPizzas, const int& countOfDrinks){
	Pizzeria piz;
	Set* set;
	set = piz.MakeASetOrder(setType, 0, countOfDrinks);
	return set;
}

TEST(DrinkTest, ItalianDrinkTest) {
	const long long countOfTests = 100;

	std::vector<Drink*> drinks;
	for (int j = 0; j < countOfTests; ++j) {
		int countOfDrinks = 1000;
		drinks = MakeSet(Pizzeria::ITALIAN_SET, 0, countOfDrinks)->getDrinks();

		for (size_t i = 0; i < countOfDrinks; i++) {
			ASSERT_TRUE(typeid(*drinks[i]) == typeid(Wine));
		}
	}
}

TEST(DrinkTest, RussianDrinkTest) {
	Pizzeria piz;
	const long long countOfTests = 100;

	std::vector<Drink*> drinks;
	for (int j = 0; j < countOfTests; ++j) {
		int countOfDrinks = 1000;
		drinks = MakeSet(Pizzeria::RUSSIAN_SET, 0, countOfDrinks)->getDrinks();

		for (size_t i = 0; i < countOfDrinks; i++) {
			ASSERT_TRUE(typeid(*drinks[i]) == typeid(Kvass));
		}
	}
}

TEST(DrinkTest, MexicanDrinkTest) {
	Pizzeria piz;
	const long long countOfTests = 100;

	std::vector<Drink*> drinks;
	for (int j = 0; j < countOfTests; ++j) {
		int countOfDrinks = 1000;
		drinks = MakeSet(Pizzeria::MEXICAN_SET, 0, countOfDrinks)->getDrinks();

		for (size_t i = 0; i < countOfDrinks; i++) {
			ASSERT_TRUE(typeid(*drinks[i]) == typeid(Mescal));
		}
	}
}