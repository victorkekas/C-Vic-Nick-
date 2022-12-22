#include "movies_list.h"

MoviesList::MoviesList()
{
}

int MoviesList::getMovieIndex()
{
	return this->movieIndex;
}

MoviesList::~MoviesList()
{
	std::cout << "MoviesList" << endl;
}

void MoviesList::nextMovie()
{
	if (movieIndex == (movies.size() - 1)) {
		movieIndex = 0;
		return;
	}
	movieIndex += 1;
	return;
}

void MoviesList::previousMovie()
{
	if (movieIndex == 0) {
		movieIndex = (movies.size() - 1);
		return;
	}
	movieIndex -= 1;
	return;
}

void MoviesList::init()
{
	Movie fightClub("Fight Club", "David Fincher", { "Drama" ,"Thriller" }, { "Edward Norton" ,"Brad Pitt" }, "1999", {"shot-FightClubV1.png", "shot-FightClubV2.png"}, "FightClub.png");
	Movie aNewHope("A New Hope", "George Lucas", { "Action" ,"Adventure","Fantasy", "Sci-Fi" }, { "Mark Hamill" ,"Harrison Ford" }, "1977", {"shot-ANewHopeV1.png","shot-ANewHopeV2.png" ,"shot-ANewHopeV3.png" }, "ANewHope.png");
	Movie empireStrikesBack("Empire Strikes Back", "Irvin Kenshner", { "Action" ,"Adventure","Fantasy","Sci-fi" }, { "Mark Hamill" ,"Harrison Ford" }, "1980", {"shot-StarWarsV1.png","shot-StarWarsV2.png" ,"shot-StarWarsV3.png" ,"shot-StarWarsV4.png" ,"shot-StarWarsV5.png" ,"shot-StarWarsV6.png" }, "EmpireStrikesBack.png");
	Movie godFather("God Father", "Francis Ford Coppola ", { "Crime " ,"Drama" }, { "Marlon Brando" ,"Al Pacino" }, "1972", {"shot-GodfatherV1.png"}, "Godfather.png");
	Movie pulpFiction("Pulp Fiction", "Quentin Tarantino ", { "Drama" ,"Crime" }, { "John Travolta" ,"Uma Thurman", "Samuel L.Jackson", "Bruce Willis" }, "1994", { "shot-PulpFictionV1.png" ,"shot-PulpFictionV2.png" ,"shot-PulpFictionV3.png" }, "PulpFiction.png");
	Movie raidersOfTheLostArk("Raiders Of The Lost Ark", "Steven Spielberg", { "Action" ,"Adventure" }, { "Harrison Ford" ,"Karen Allen", "Paul Freeman" }, "1981", { "shot-RaidersOfTheLostArkV1.png" ,"shot-RaidersOfTheLostArkV2.png" ,"shot-RaidersOfTheLostArkV3.png" ,"shot-RaidersOfTheLostArkV4.png" }, "RaidersOfTheLostArk.png");
	Movie schindlerslist("Schindler's list", "Steven Spielberg", { "Drama" ,"Biography","History" }, { "Liam Neeson " ,"Ralph Fiennes", "Ben Kingsley" }, "1993", { "shot-SchindlerslistV1.png" ,"shot-SchindlerslistV2.png" ,"shot-SchindlerslistV3.png" }, "Schindlerslist.png");
	Movie terminator("Terminator", "James Cameron", { "Action" ,"Sci-Fi" }, { "Arnold Schwarzenegger" ,"Linda Hamilton", "Michael Biehn" }, "1984", { "shot-Terminator.png" }, "Terminator.png");
	Movie templeOfDoom("Temple Of Doom", "Steven Spielberg", { "Action" ,"Adventure" }, { "Kate Capshaw" ,"Harrison Ford" }, "1984", { "shot-TempleOfDoomV1.png" ,"shot-TempleOfDoomV2.png" ,"shot-TempleOfDoomV3.png" ,"shot-TempleOfDoomV4.png" ,"shot-TempleOfDoomV5.png" }, "TempleOfDoom.png");
	
	movies.push_back(fightClub);
	movies.push_back(aNewHope);
	movies.push_back(empireStrikesBack);
	movies.push_back(godFather);
	movies.push_back(pulpFiction);
	movies.push_back(raidersOfTheLostArk);
	movies.push_back(schindlerslist);
	movies.push_back(terminator);
	movies.push_back(templeOfDoom);

	movieIndex = 0;
}

void MoviesList::draw()
{
	movies[movieIndex].draw();
	if (movieIndex == (movies.size() - 1)) {
		movies[movieIndex - 1].draw1(2.7f);
		movies[0].draw1(9.001f);
	}
	else if (movieIndex == 0) {
		movies[movies.size() - 1].draw1(2.7f);
		movies[1].draw1(9.001f);
	}
	else {
		movies[movieIndex - 1].draw1(2.7f);
		movies[movieIndex + 1].draw1(9.001f);
	}
}
