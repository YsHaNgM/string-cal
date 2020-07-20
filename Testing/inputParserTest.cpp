#define CATCH_CONFIG_MAIN
#include "CatchMain.h"
#include "catch.hpp"

#include "shuntingYard.h"
#include <iostream>

TEST_CASE("test Add function", "[AddTest]")
{
    std::string line("223+2*3-5");
    std::string line1("+");
    std::string line2("");

    SECTION("test parser with comma-separated")
    {
        auto val = inputParser(line);
        auto rel = std::get_if<int>(&val);
        auto val1 = inputParser(line1);
        auto rel1 = std::get_if<char>(&val1);
        auto val2 = inputParser(line2);
        auto rel2 = std::get_if<int>(&val2);
        std::cout << *rel2 << std::endl;
        REQUIRE(*rel == 223);
        REQUIRE((*rel1) == '+');
        // REQUIRE();
    }
}