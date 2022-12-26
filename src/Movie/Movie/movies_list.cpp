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
	else if (movieIndex == 0 && filtersOn) {
		movieIndex = (filteredMovies.size() - 1);
		return;
	}
	movieIndex -= 1;
	return;
}

void MoviesList::init()
{
	Movie fightClub("Fight Club", "David Fincher", { "Drama" }, { "Brad Pitt", "Edward Norton", "Helena Bonham Carter" }, "1999", { "shot-FightClubV1.png", "shot-FightClubV2.png" }, "FightClub.png", "An insomniac office worker and a devil-may-care soap maker form an underground fight club that evolves into much more.");
	Movie aNewHope("A New Hope", "George Lucas", { "Action" ,"Adventure","Fantasy" }, {"Mark Hamill" ,"Harrison Ford", "Carrie Fisher"}, "1977", {"shot-ANewHopeV1.png","shot-ANewHopeV2.png" ,"shot-ANewHopeV3.png"}, "ANewHope.png", "Luke Skywalker joins forces with a Jedi Knight, a cocky pilot, a Wookiee and two droids to save the galaxy from the Empire's world-destroying battle station, while also attempting to rescue Princess Leia from the mysterious Darth Vader.");
	Movie empireStrikesBack("Empire Strikes Back", "Irvin Kenshner", { "Action" ,"Adventure","Fantasy" }, { "Mark Hamill" ,"Harrison Ford", "Carrie Fisher " }, "1980", { "shot-StarWarsV1.png","shot-StarWarsV2.png" ,"shot-StarWarsV3.png" ,"shot-StarWarsV4.png" ,"shot-StarWarsV5.png" ,"shot-StarWarsV6.png" }, "EmpireStrikesBack.png", "After the Rebels are brutally overpowered by the Empire on the ice planet Hoth, Luke Skywalker begins Jedi training with Yoda, while his friends are pursued across the galaxy by Darth Vader and bounty hunter Boba Fett.");
	Movie godFather("God Father", "Francis Ford Coppola ", { "History " ,"Drama" }, { "Marlon Brando" ,"Al Pacino", "James Caan" }, "1972", { "shot-GodfatherV1.png" }, "Godfather.png", "The aging patriarch of an organized crime dynasty in postwar New York City transfers control of his clandestine empire to his reluctant youngest son.");
	Movie pulpFiction("Pulp Fiction", "Quentin Tarantino ", { "Drama" ,"Crime" }, { "John Travolta" ,"Uma Thurman", "Samuel L.Jackson" }, "1994", { "shot-PulpFictionV1.png" ,"shot-PulpFictionV2.png" ,"shot-PulpFictionV3.png" }, "PulpFiction.png", "The lives of two mob hitmen, a boxer, a gangster and his wife, and a pair of diner bandits intertwine in four tales of violence and redemption.");
	Movie raidersOfTheLostArk("Raiders Of The Lost Ark", "Steven Spielberg", { "Action" ,"Adventure" }, { "Harrison Ford" ,"Karen Allen", "Paul Freeman" }, "1981", { "shot-RaidersOfTheLostArkV1.png" ,"shot-RaidersOfTheLostArkV2.png" ,"shot-RaidersOfTheLostArkV3.png" ,"shot-RaidersOfTheLostArkV4.png" }, "RaidersOfTheLostArk.png", "Archaeology professor Indiana Jones ventures to seize a biblical artefact known as the Ark of the Covenant. While doing so, he puts up a fight against Renee and a troop of Nazis.");
	Movie schindlerslist("Schindler's list", "Steven Spielberg", { "Drama" ,"History" }, { "Liam Neeson " ,"Ralph Fiennes", "Ben Kingsley" }, "1993", { "shot-SchindlerslistV1.png" ,"shot-SchindlerslistV2.png" ,"shot-SchindlerslistV3.png" }, "Schindlerslist.png", "In German-occupied Poland during World War II, industrialist Oskar Schindler gradually becomes concerned for his Jewish workforce after witnessing their persecution by the Nazis.");
	Movie terminator("Terminator", "James Cameron", { "Action" ,"Sci-Fi" }, { "Arnold Schwarzenegger" ,"Linda Hamilton", "Michael Biehn" }, "1984", { "shot-Terminator.png" }, "Terminator.png", "A human soldier is sent from 2029 to 1984 to stop an almost indestructible cyborg killing machine, sent from the same year, which has been programmed to execute a young woman whose unborn son is the key to humanity's future salvation.");
	Movie templeOfDoom("Temple Of Doom", "Steven Spielberg", { "Action" ,"Adventure" }, { "Kate Capshaw" ,"Harrison Ford","Ke Huy Quan" }, "1984", { "shot-TempleOfDoomV1.png" ,"shot-TempleOfDoomV2.png" ,"shot-TempleOfDoomV3.png" ,"shot-TempleOfDoomV4.png" ,"shot-TempleOfDoomV5.png" }, "TempleOfDoom.png", "A skirmish in Shanghai puts archaeologist Indiana Jones, his partner Short Round and singer Willie Scott crossing paths with an Indian village desperate to reclaim a rock stolen by a secret cult beneath the catacombs of an ancient palace.");

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

void MoviesList::fillFilteredMovies()
{
	for (auto& gen: filters) { //for every filter in filters 
		for (auto& mov : movies) { //for every movie in the "main" vector 
			for (auto& movgen: mov.getGenre()) { //for every genre in each movie 
				if (movgen==gen) { // if one of the genre of the movie is the same as the one we are looking for 
					if (filteredMovies.size()==0) {
						filteredMovies.push_back(mov);
					}
					else {
						for (auto& secm : filteredMovies) { //for every movie in "secondary" vector
							if (secm==mov) { //if the movie is already in the "secondary" vector dont add it
								std::cout << "if " << endl;
								std::cout<< mov.getTitle() <<endl;
							}
							else { //otherwise add it to the "secondary" vector
								std::cout << "else " << endl;
								std::cout << mov.getTitle() << endl;
								filteredMovies.push_back(mov);
							}
						}
					}
				}
			}
		}
	}
	//tidyUpFilteredMovies();
}

void MoviesList::tidyUpFilteredMovies()
{
	std::vector<Movie> toBeRemovedMovies;

	for (auto& mov : filteredMovies) {
		bool isOn = false;
		for (auto& mgen : mov.getGenre()) {
			if (std::find(filters.begin(), filters.end(), mgen) != filters.end()) {
				isOn = true;
			}
		}
		if (!isOn) { toBeRemovedMovies.push_back(mov); }
	}
	for (auto& mov : toBeRemovedMovies) {
		filteredMovies.erase(std::remove(filteredMovies.begin(), filteredMovies.end(), mov), filteredMovies.end());
		//we must override operator == to do something (probably comare to Movies) - I did it ?
	}
}

void MoviesList::setFilterAction()
{
	if (!filtersOn) {
		filters.push_back("Action");
		filtersOn = true;
		movieIndex = 0;
	}
	else if (filtersOn) {
		if (std::find(filters.begin(), filters.end(), "Action") != filters.end()) {
			filters.erase(std::remove(filters.begin(), filters.end(), "Action"), filters.end());
			if (filters.size() == 0) { filtersOn = false; }
		}
		else {
			filters.push_back("Action");
		}
	}
	fillFilteredMovies();
}

void MoviesList::setFilterDrama()
{
	if (!filtersOn) {
		filters.push_back("Drama");
		filtersOn = true;
		movieIndex = 0;
	}
	else if (filtersOn) {
		if (std::find(filters.begin(), filters.end(), "Drama") != filters.end()) {
			filters.erase(std::remove(filters.begin(), filters.end(), "Drama"), filters.end());
			if (filters.size() == 0) { filtersOn = false; }
		}
		else {
			filters.push_back("Drama");
		}
	}
	fillFilteredMovies();
}

void MoviesList::setFilterAdventure()
{
	if (!filtersOn) {
		filters.push_back("Adventure");
		filtersOn = true;
		movieIndex = 0;
	}
	else if (filtersOn) {
		if (std::find(filters.begin(), filters.end(), "Adventure") != filters.end()) {
			filters.erase(std::remove(filters.begin(), filters.end(), "Adventure"), filters.end());
			if (filters.size() == 0) { filtersOn = false; }
		}
		else {
			filters.push_back("Adventure");
		}
	}
	fillFilteredMovies();
}

void MoviesList::setFilterFantasy()
{
	if (!filtersOn) {
		filters.push_back("Fantasy");
		filtersOn = true;
		movieIndex = 0;
	}
	else if (filtersOn) {
		if (std::find(filters.begin(), filters.end(), "Fantasy") != filters.end()) {
			filters.erase(std::remove(filters.begin(), filters.end(), "Fantasy"), filters.end());
			if (filters.size() == 0) { filtersOn = false; }
		}
		else {
			filters.push_back("Fantasy");
		}
	}
	fillFilteredMovies();
}

void MoviesList::setFilterHistory()
{
	if (!filtersOn) {
		filters.push_back("History");
		filtersOn = true;
		movieIndex = 0;
	}
	else if (filtersOn) {
		if (std::find(filters.begin(), filters.end(), "History") != filters.end()) {
			filters.erase(std::remove(filters.begin(), filters.end(), "History"), filters.end());
			if (filters.size() == 0) { filtersOn = false; }
		}
		else {
			filters.push_back("History");
		}
	}
	fillFilteredMovies();
}

void MoviesList::setFilterCrime()
{
	if (!filtersOn) {
		filters.push_back("Crime");
		filtersOn = true;
		movieIndex = 0;
	}
	else if (filtersOn) {
		if (std::find(filters.begin(), filters.end(), "Crime") != filters.end()) {
			filters.erase(std::remove(filters.begin(), filters.end(), "Crime"), filters.end());
			if (filters.size() == 0) { filtersOn = false; }
		}
		else {
			filters.push_back("Crime");
		}
	}
	fillFilteredMovies();
}

void MoviesList::setFilterSciFi()
{
	if (!filtersOn) {
		filters.push_back("Sci-Fi");
		filtersOn = true;
		movieIndex = 0;
	}
	else if (filtersOn) {
		if (std::find(filters.begin(), filters.end(), "Sci-Fi") != filters.end()) {
			filters.erase(std::remove(filters.begin(), filters.end(), "Sci-Fi"), filters.end());
			if (filters.size() == 0) { filtersOn = false; }
		}
		else {
			filters.push_back("Sci-Fi");
		}
	}
	fillFilteredMovies();
}

void MoviesList::resetFilters()
{
	filters.clear();
	filtersOn = false;
	movieIndex = 0;
	fillFilteredMovies();
}

void MoviesList::draw(vector<Movie> Movies)
{
	Movies[movieIndex].draw();
	if ((Movies.size()) == 1) {
		return;
	}
	else if ((Movies.size()) == 2) {
		if (movieIndex == 0) {
			Movies[1].draw1(9.001f);
		}
		else {
			Movies[0].draw1(2.7f);
		}
	}
	else {
		if (movieIndex == 0) {
			Movies[(Movies.size()) - 1].draw1(2.7f);
			Movies[1].draw1(9.001f);
		}
		else if (movieIndex == ((Movies.size()) - 1)) {
			Movies[movieIndex - 1].draw1(2.7f);
			Movies[0].draw1(9.001f);
		}
		else {
			Movies[movieIndex - 1].draw1(2.7f);
			Movies[movieIndex + 1].draw1(9.001f);
		}
	}
}

void MoviesList::draw()
{

	if (filtersOn) {
		draw(filteredMovies);
	}
	else if (!filtersOn) {
		draw(movies);
	}
}
