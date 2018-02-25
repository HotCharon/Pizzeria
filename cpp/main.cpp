#include "../headers/Includes.h"
#include "../headers/Pizzeria.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <ctime>


//int argc, char* argv[]
int main() {
	::testing::InitGoogleTest(&argc, argv);
	srand(time(NULL));
    return 0;
	return RUN_ALL_TESTS();
}