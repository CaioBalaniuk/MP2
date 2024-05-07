#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "rainhas.hpp"

TEST_CASE( "Entradas inválidas - tabuleiros inválidos", "[rainhas]" ) {
    REQUIRE( problema_8_rainhas("00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000") == -1 ); //entrada sem rainha
    REQUIRE( problema_8_rainhas("00000000,00000000,00000000,00000000,00000000,00000000,00000000,0000000") == -1 ); //entrada com uma casa a menos
    REQUIRE( problema_8_rainhas("01000000,00000100,00100000,00001000,00000000,00010000,00001000,00100000") == -1 ); //entrada com menos de 8 rainhas
    REQUIRE( problema_8_rainhas("01000000,00000100,00100000,00001000,00010100,00010000,00001000,00100000") == -1 ); //entrada com mais de 8 rainhas

}

TEST_CASE( "Entradas válida - mas não necessariamente correta", "[rainhas]" ) {
    REQUIRE( problema_8_rainhas("01000000,00001000,00001000,10000000,00000001,00000100,00010000,00001000") == 1 ); //entrada com todas as rainhas, uma por linha
}
