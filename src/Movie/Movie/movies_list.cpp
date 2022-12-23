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
	if (movieIndex == (movies.size() - 1) || movieIndex == (filteredMovies.size() - 1)) {
		movieIndex = 0;
		return;
	}
	movieIndex += 1;
	return;
}

void MoviesList::previousMovie()
{
	if (movieIndex == 0 && !filtersOn) {
		movieIndex = (movies.size() - 1);
		return;
	}
	else if(movieIndex == 0 && filtersOn) {
		movieIndex = (filteredMovies.size() - 1);
		return;
	}
	movieIndex -= 1;
	return;
}

void MoviesList::init()
{
	Movie fightClub("Fight Club", "David Fincher", { "Drama" }, { "Brad Pitt", "Edward Norton", "Helena Bonham Carter"}, "1999", {"shot-FightClubV1.png", "shot-FightClubV2.png"}, "FightClub.png", "An insomniac office worker and a devil-may-care soap maker form an underground fight club that evolves into much more.");
	Movie aNewHope("A New Hope", "George Lucas", { "Action" ,"Adventure","Fantasy" }, { "Mark Hamill" ,"Harrison Ford", "Carrie Fisher"}, "1977", {"shot-ANewHopeV1.png","shot-ANewHopeV2.png" ,"shot-ANewHopeV3.png"}, "ANewHope.png", "Luke Skywalker joins forces with a Jedi Knight, a cocky pilot, a Wookiee and two droids to save the galaxy from the Empire's world-destroying battle station, while also attempting to rescue Princess Leia from the mysterious Darth Vader.");
	Movie empireStrikesBack("Empire Strikes Back", "Irvin Kenshner", { "Action" ,"Adventure","Fantasy" }, { "Mark Hamill" ,"Harrison Ford", "Carrie Fisher "}, "1980", {"shot-StarWarsV1.png","shot-StarWarsV2.png" ,"shot-StarWarsV3.png" ,"shot-StarWarsV4.png" ,"shot-StarWarsV5.png" ,"shot-StarWarsV6.png"}, "EmpireStrikesBack.png", "After the Rebels are brutally overpowered by the Empire on the ice planet Hoth, Luke Skywalker begins Jedi training with Yoda, while his friends are pursued across the galaxy by Darth Vader and bounty hunter Boba Fett.");
	Movie godFather("God Father", "Francis Ford Coppola ", { "History " ,"Drama" }, { "Marlon Brando" ,"Al Pacino", "James Caan" }, "1972", {"shot-GodfatherV1.png"}, "Godfather.png", "The aging patriarch of an organized crime dynasty in postwar New York City transfers control of his clandestine empire to his reluctant youngest son.");
	Movie pulpFiction("Pulp Fiction", "Quentin Tarantino ", { "Drama" ,"Crime" }, { "John Travolta" ,"Uma Thurman", "Samuel L.Jackson" }, "1994", { "shot-PulpFictionV1.png" ,"shot-PulpFictionV2.png" ,"shot-PulpFictionV3.png" }, "PulpFiction.png", "The lives of two mob hitmen, a boxer, a gangster and his wife, and a pair of diner bandits intertwine in four tales of violence and redemption.");
	Movie raidersOfTheLostArk("Raiders Of The Lost Ark", "Steven Spielberg", { "Action" ,"Adventure" }, { "Harrison Ford" ,"Karen Allen", "Paul Freeman" }, "1981", { "shot-RaidersOfTheLostArkV1.png" ,"shot-RaidersOfTheLostArkV2.png" ,"shot-RaidersOfTheLostArkV3.png" ,"shot-RaidersOfTheLostArkV4.png" }, "RaidersOfTheLostArk.png", "Archaeology professor Indiana Jones ventures to seize a biblical artefact known as the Ark of the Covenant. While doing so, he puts up a fight against Renee and a troop of Nazis.");
	Movie schindlerslist("Schindler's list", "Steven Spielberg", { "Drama" ,"History" }, { "Liam Neeson " ,"Ralph Fiennes", "Ben Kingsley" }, "1993", { "shot-SchindlerslistV1.png" ,"shot-SchindlerslistV2.png" ,"shot-SchindlerslistV3.png" }, "Schindlerslist.png", "In German-occupied Poland during World War II, industrialist Oskar Schindler gradually becomes concerned for his Jewish workforce after witnessing their persecution by the Nazis.");
	Movie terminator("Terminator", "James Cameron", { "Action" ,"Sci-Fi" }, { "Arnold Schwarzenegger" ,"Linda Hamilton", "Michael Biehn" }, "1984", { "shot-Terminator.png" }, "Terminator.png","A human soldier is sent from 2029 to 1984 to stop an almost indestructible cyborg killing machine, sent from the same year, which has been programmed to execute a young woman whose unborn son is the key to humanity's future salvation.");
	Movie templeOfDoom("Temple Of Doom", "Steven Spielberg", { "Action" ,"Adventure" }, { "Kate Capshaw" ,"Harrison Ford","Ke Huy Quan"}, "1984", {"shot-TempleOfDoomV1.png" ,"shot-TempleOfDoomV2.png" ,"shot-TempleOfDoomV3.png" ,"shot-TempleOfDoomV4.png" ,"shot-TempleOfDoomV5.png"}, "TempleOfDoom.png", "A skirmish in Shanghai puts archaeologist Indiana Jones, his partner Short Round and singer Willie Scott crossing paths with an Indian village desperate to reclaim a rock stolen by a secret cult beneath the catacombs of an ancient palace.");
	
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

void MoviesList::Filtered(vector <string> filteres)
{
	for (auto gen : filteres) {
		for (auto mov : movies) {
			if (std::find((mov.getGenre()).begin(), (mov.getGenre()).end(), gen) != (mov.getGenre()).end()) {
				filteredMovies.push_back(mov);
			}
		}
	}
	filtersOn = true;
	movieIndex = 0;
}

void MoviesList::setFilterAction()
{
	MoviesList::Filtered({ "Action" });
}

void MoviesList::resetFilters()
{
	filtersOn = false;
	filteredMovies.clear();
}

void MoviesList::drawFiltered()
{
	filteredMovies[movieIndex].draw();
	if (filteredMovies.size() == 2)
	{
		if (movieIndex == (filteredMovies.size() - 1)) {
			filteredMovies[0].draw1(9.001f);
		}
		else if (movieIndex == 0) {
			filteredMovies[1].draw1(9.001f);
		}
	}
	else if (filteredMovies.size() == 1) {
		return;
	}
	else {
		filteredMovies[movieIndex - 1].draw1(2.7f);
		filteredMovies[movieIndex + 1].draw1(9.001f);
	}
}
