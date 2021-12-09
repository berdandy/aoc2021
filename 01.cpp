#define CATCH_CONFIG_MAIN
#include "includes/catch.hpp"

#include "01.h"

int Day1a() 
{
	int prev = 9999999;
	int increases = 0;
	for (int i=0; i<sizeof(data)/sizeof(data[0]); ++i) {
		if (prev < data[i]) {
			++increases;
		}
		prev = data[i];
	}
	return increases;
}

int Day1b()
{
	int prev3Sum = data[0]+data[1]+data[2];
	int increases = 0;
	for (int i=1; i<(sizeof(data)/sizeof(data[0]))-2; ++i) {
		int new3Sum = data[i] + data[i+1] + data[i+2];
		if (prev3Sum < new3Sum) {
			++increases;
		}
		prev3Sum = new3Sum;
	}
	return increases;
}

TEST_CASE("Day 1", "[day1]") {
	REQUIRE( Day1a() == 1466 );
	REQUIRE( Day1b() == 1491 );
};
