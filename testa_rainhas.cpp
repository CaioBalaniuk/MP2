#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "rainhas.hpp"

TEST_CASE( "Entradas inválidas - tabuleiros inválidos", "[rainhas]" ) {
    REQUIRE( problema_8_rainhas("teste_1.txt") == -1 ); //entrada sem rainha
    REQUIRE( problema_8_rainhas("teste_2.txt") == -1 ); //entrada com uma casa a menos
    REQUIRE( problema_8_rainhas("teste_3.txt") == -1 ); //entrada com menos de 8 rainhas
    REQUIRE( problema_8_rainhas("teste_5.txt") == -1 ); //entrada com mais de 8 rainhas
    REQUIRE( problema_8_rainhas("teste_6.txt") == -1 ); //entrada com 8 rainhas, mas 2 na mesma linha
    REQUIRE( problema_8_rainhas("teste_7.txt") == -1 ); //entrada com 8 rainhas, mas 3 na mesma linha
    REQUIRE( problema_8_rainhas("teste_8.txt") == -1 ); //entrada com uma casa a mais
    REQUIRE( problema_8_rainhas("teste_9.txt") == -1 ); //entrada com uma das linhas tendo 7 casas, e outra 9
}

TEST_CASE( "Entradas válida - mas não necessariamente correta", "[rainhas]" ) {
    REQUIRE( problema_8_rainhas("teste_4.txt") == 0 ); //entrada com todas as rainhas, uma por linha
}

TEST_CASE( "Entradas válidas - mas não é resposta pro problema das 8 rainhas.", "[rainhas]" ) {
    REQUIRE( problema_8_rainhas("teste_10.txt") == 0 ); //teste para duas rainhas na mesma coluna
    REQUIRE( problema_8_rainhas("teste_11.txt") == 0 ); //teste para duas rainhas na mesma coluna
    REQUIRE( problema_8_rainhas("teste_12.txt") == 0 ); //teste para duas rainhas na mesma coluna

}
