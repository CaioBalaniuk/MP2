#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "rainhas.hpp"

TEST_CASE( "Entradas inv�lidas - tabuleiros inv�lidos", "[rainhas]" ) {
    REQUIRE( problema_8_rainhas("00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000") == -1 ); //entrada sem rainha
    REQUIRE( problema_8_rainhas("00000000,00000000,00000000,00000000,00000000,00000000,00000000,0000000") == -1 ); //entrada com uma casa a menos

}

