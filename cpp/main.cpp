#include "../headers/Includes.h"
#include "../headers/Pizzeria.h"
#include "../gtests.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <ctime>


//int argc, char* argv[]
int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	srand(time(NULL));

	RUN_ALL_TESTS();

	system("pause");

	return 0;
}