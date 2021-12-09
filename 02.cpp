#define CATCH_CONFIG_MAIN
#include "includes/catch.hpp"

#include "02.h"

#include <iostream>
#include <regex>
#include <string>
#include <vector>

// ok, I got really fucking tired of parsing in aoc2020, so in anticipation of all that shit. here. regex. may god have mercy on my soul
std::vector<std::string> tokenize(const std::string str, const std::regex re)
{
	std::sregex_token_iterator it{ str.begin(), str.end(), re, -1 };
	std::vector<std::string> tokenized{ it, {} };

	// rip out empty strings
	tokenized.erase(std::remove_if(
		tokenized.begin(),
		tokenized.end(),
		[](std::string const& s) { return s.size() == 0; }),
		tokenized.end()
	);

	return tokenized;
}

int Day2a() 
{
	int hpos = 0;
	int depth = 0;
	
	const std::regex re(R"([ ]+)");
	for (const std::string& str : data)
	{
		const std::vector<std::string> t = tokenize(str, re);
		if (t[0] == "forward") 
		{
			hpos += atoi(t[1].c_str());
		}
		else if (t[0] == "up") 
		{
			depth -= atoi(t[1].c_str());
		}
		else if (t[0] == "down") 
		{
			depth += atoi(t[1].c_str());
		}
	}
	return hpos * depth;
}

int Day2b()
{
	int hpos = 0;
	int depth = 0;
	int aim = 0;
	
	const std::regex re(R"([ ]+)");
	for (const std::string& str : data)
	{
		const std::vector<std::string> t = tokenize(str, re);
		if (t[0] == "forward") 
		{
			hpos += atoi(t[1].c_str());
			depth += aim * atoi(t[1].c_str());
		}
		else if (t[0] == "up") 
		{
			aim -= atoi(t[1].c_str());
		}
		else if (t[0] == "down") 
		{
			aim += atoi(t[1].c_str());
		}
	}
	return hpos * depth;
}

TEST_CASE("Day 2", "[day2]") {
	REQUIRE( Day2a() == 1692075 );
	REQUIRE( Day2b() == 1749524700 );
};

// vim: noai:ts=4:sw=4
