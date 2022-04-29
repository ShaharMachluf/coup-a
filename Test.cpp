#include "doctest.h"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
using namespace coup;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Game"){
    Game game_1{};

	/* This player drew the "Duke" card, his name is Moshe
	and he is a player in game_1 */
	Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};

	vector<string> players = game_1.players();

    CHECK(players[0] == "Moshe");
    CHECK(players[1] == "Yossi");
    CHECK(players[2] == "Meirav");
    CHECK(players[3] == "Reut");
    CHECK(players[4] == "Gilad");

	CHECK(game_1.turn() == "Moshe");

	// throws no exceptions
	CHECK_NOTHROW(duke.income());
	CHECK_NOTHROW(assassin.income());
	CHECK_NOTHROW(ambassador.income());
	CHECK_NOTHROW(captain.income());
	CHECK_NOTHROW(contessa.income());

	// throws exception, it is duke's turn now
	CHECK_THROWS(assassin.income());

	duke.income();
	assassin.foreign_aid();

	// throws exception, the last operation duke performed
	// is income, which cannot be blocked by any role
	CHECK_THROWS(captain.block(duke));

	CHECK(duke.coins() == 2);
	CHECK(assassin.coins() == 3);

	// throws exception, the last operation duke performed
	// is foreign aid, which cannot be blocked by contessa
	CHECK_THROWS(contessa.block(assassin));

	duke.block(assassin);
	CHECK(assassin.coins() == 1);

	ambassador.transfer(duke, assassin); //transfers 1 coin from duke to assassin
	captain.foreign_aid();
	contessa.foreign_aid();

	duke.tax();
	assassin.income();
	ambassador.foreign_aid();
	captain.steal(contessa);
	contessa.foreign_aid();

	duke.tax();
	// no exception, assassin can coup with only 3 coins
	assassin.coup(duke);

	players = game_1.players();

    CHECK(players[0] == "Yossi");
    CHECK(players[1] == "Meirav");
    CHECK(players[2] == "Reut");
    CHECK(players[3] == "Gilad");

	contessa.block(assassin);

	players = game_1.players();
	
    CHECK(players[0] == "Moshe");
    CHECK(players[1] == "Yossi");
    CHECK(players[2] == "Meirav");
    CHECK(players[3] == "Reut");
    CHECK(players[4] == "Gilad");
}