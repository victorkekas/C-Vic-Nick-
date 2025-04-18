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
}

void MoviesList::nextMovie()
{
	//get the next movie and if on the last movie of the vector, "loop" to the first
	if (movieIndex == (movies.size() - 1) || movieIndex == (filteredMovies.size() - 1)) {
		movieIndex = 0;
		return;
	}
	movieIndex += 1;
	return;
}

void MoviesList::previousMovie()
{
	//get the previous movie and if on the first movie of the vector, "loop" to the last one 
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

void MoviesList::changeFromYear(int fromYear)
{
	this->fromYear = fromYear;
}

void MoviesList::changeToYear(int toYear)
{
	this->toYear = toYear;
	
}

int MoviesList::getOldestYear()
{
	//return the year of the oldest movie 
	int year;
	year = std::stoi(movies[0].getYear());
	for (int i = 0; i < movies.size(); i++) {
		if (std::stoi(movies[i].getYear()) < year) {
			year = std::stoi(movies[i].getYear());
		}
	}
	return year;

}

int MoviesList::getNewestYear()
{
	//return the year of the newest movie 
	int year;
	year = std::stoi(movies[0].getYear());
	for (int i = 0; i < movies.size(); i++) {
		if (std::stoi(movies[i].getYear()) > year) {
			year = std::stoi(movies[i].getYear());
		}
	}
	return year;
}

void MoviesList::init()
{
	//create wanted movies 
	Movie fightClub("Fight Club", "David Fincher", { "Drama" }, { "Brad Pitt", "Edward Norton", "Helena Bonham Carter" }, "1999", { "shot-FightClubV1.png", "shot-FightClubV2.png" }, "FightClub.png", "An insomniac office worker and a devil-may-care soap maker form an underground fight club that evolves into much more.");
	Movie aNewHope("A New Hope", "George Lucas", { "Action" ,"Adventure","Fantasy" }, {"Mark Hamill" ,"Harrison Ford", "Carrie Fisher"}, "1977", {"shot-ANewHopeV1.png","shot-ANewHopeV2.png" ,"shot-ANewHopeV3.png"}, "ANewHope.png", "Luke Skywalker joins forces with a Jedi Knight, a cocky pilot, a Wookiee and two droids to save the galaxy from the Empire's world-destroying battle station, while also attempting to rescue Princess Leia from the mysterious Darth Vader.");
	Movie empireStrikesBack("Empire Strikes Back", "Irvin Kenshner", { "Action" ,"Adventure","Fantasy" }, { "Mark Hamill" ,"Harrison Ford", "Carrie Fisher " }, "1980", { "shot-StarWarsV1.png","shot-StarWarsV2.png" ,"shot-StarWarsV3.png" ,"shot-StarWarsV4.png" ,"shot-StarWarsV5.png" ,"shot-StarWarsV6.png" }, "EmpireStrikesBack.png", "After the Rebels are brutally overpowered by the Empire on the ice planet Hoth, Luke Skywalker begins Jedi training with Yoda, while his friends are pursued across the galaxy by Darth Vader and bounty hunter Boba Fett.");
	Movie godFather("God Father", "Francis Ford Coppola ", { "History" ,"Drama","Crime"}, {"Marlon Brando" ,"Al Pacino", "James Caan"}, "1972", {"shot-GodfatherV1.png"}, "Godfather.png", "The aging patriarch of an organized crime dynasty in postwar New York City transfers control of his clandestine empire to his reluctant youngest son.");
	Movie pulpFiction("Pulp Fiction", "Quentin Tarantino ", { "Drama" ,"Crime" }, { "John Travolta" ,"Uma Thurman", "Samuel L.Jackson" }, "1994", { "shot-PulpFictionV1.png" ,"shot-PulpFictionV2.png" ,"shot-PulpFictionV3.png" }, "PulpFiction.png", "The lives of two mob hitmen, a boxer, a gangster and his wife, and a pair of diner bandits intertwine in four tales of violence and redemption.");
	Movie raidersOfTheLostArk("Raiders Of The Lost Ark", "Steven Spielberg", { "Action" ,"Adventure" }, { "Harrison Ford" ,"Karen Allen", "Paul Freeman" }, "1981", { "shot-RaidersOfTheLostArkV1.png" ,"shot-RaidersOfTheLostArkV2.png" ,"shot-RaidersOfTheLostArkV3.png" ,"shot-RaidersOfTheLostArkV4.png" }, "RaidersOfTheLostArk.png", "Archaeology professor Indiana Jones ventures to seize a biblical artefact known as the Ark of the Covenant. While doing so, he puts up a fight against Renee and a troop of Nazis.");
	Movie schindlerslist("Schindler's list", "Steven Spielberg", { "Drama" ,"History" }, { "Liam Neeson " ,"Ralph Fiennes", "Ben Kingsley" }, "1993", { "shot-SchindlerslistV1.png" ,"shot-SchindlerslistV2.png" ,"shot-SchindlerslistV3.png" }, "Schindlerslist.png", "In German-occupied Poland during World War II, industrialist Oskar Schindler gradually becomes concerned for his Jewish workforce after witnessing their persecution by the Nazis.");
	Movie terminator("Terminator", "James Cameron", { "Action" ,"Sci-Fi" }, { "Arnold Schwarzenegger" ,"Linda Hamilton", "Michael Biehn" }, "1984", { "shot-Terminator.png" }, "Terminator.png", "A human soldier is sent from 2029 to 1984 to stop an almost indestructible cyborg killing machine, sent from the same year, which has been programmed to execute a young woman whose unborn son is the key to humanity's future salvation.");
	Movie templeOfDoom("Temple Of Doom", "Steven Spielberg", { "Action" ,"Adventure" }, { "Kate Capshaw" ,"Harrison Ford","Ke Huy Quan" }, "1984", { "shot-TempleOfDoomV1.png" ,"shot-TempleOfDoomV2.png" ,"shot-TempleOfDoomV3.png" ,"shot-TempleOfDoomV4.png" ,"shot-TempleOfDoomV5.png" }, "TempleOfDoom.png", "A skirmish in Shanghai puts archaeologist Indiana Jones, his partner Short Round and singer Willie Scott crossing paths with an Indian village desperate to reclaim a rock stolen by a secret cult beneath the catacombs of an ancient palace.");
//push them in main vector 
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

	fromYear = getOldestYear();
	toYear = getNewestYear();
}

void MoviesList::fillFilteredMovies(std::string title)
{
	filteredMovies.clear();
	std::vector<Movie> toBeRemovedMovies;
	bool isOnFilteredMovies = false;

	//push_back in the vector filteredMovies, the movies which correspond to at least one filter 
	for (auto& gen : filters) {
		for (int i = 0; i < movies.size(); i++) {
			isOnFilteredMovies = false;
			for (int j = 0; j < movies[i].genre.size(); j++) {
				if (movies[i].genre[j]==gen) {
					if (filteredMovies.size()==0) {
						filteredMovies.push_back(movies[i]);
					}
					for (int h = 0; h < filteredMovies.size();h++) {
						if (movies[i].getTitle()._Equal(filteredMovies[h].getTitle())) {
							isOnFilteredMovies = true;
						}
					}
					if (!isOnFilteredMovies) {
						filteredMovies.push_back(movies[i]);
					}
				}
			}
		}
	}

	//Remove from filteredMovies the movies that do not correspond to all the filters 
	isOnFilteredMovies = false;
	for (auto gen : filters) {
		for (int i = 0; i < filteredMovies.size(); i++) {
			isOnFilteredMovies = false;
			for (int j = 0; j < filteredMovies[i].getGenre().size(); j++) {
				if (filteredMovies[i].genre[j] == gen) {
					isOnFilteredMovies = true;
				}
			}
			if (!isOnFilteredMovies) {
				toBeRemovedMovies.push_back(filteredMovies[i]);
			}
		}
	}
	for (auto& mov : toBeRemovedMovies) {
		filteredMovies.erase(std::remove(filteredMovies.begin(), filteredMovies.end(), mov), filteredMovies.end());
	}
	
	//Remove from the vectro filteredMovies the movies that are not included within the approprate years 
	toBeRemovedMovies.clear();
	if (!filtersOn) {
		for (int i = 0; i < movies.size(); i++) {
			if (std::stoi(movies[i].getYear()) <= toYear && std::stoi(movies[i].getYear()) >= fromYear) {
				filteredMovies.push_back(movies[i]);
				filtersOn = true;
			}
		}
	}
	else {
		if (filters.size() != 0) {
			for (int i = 0; i < filteredMovies.size(); i++) {
				if (std::stoi(filteredMovies[i].getYear()) < fromYear || std::stoi(filteredMovies[i].getYear()) > toYear) {
					toBeRemovedMovies.push_back(filteredMovies[i]);
				}
			}
			for (auto& mov : toBeRemovedMovies) {
				filteredMovies.erase(std::remove(filteredMovies.begin(), filteredMovies.end(), mov), filteredMovies.end());
			}
		}
		else {
			filteredMovies.clear();
			for (int i = 0; i < movies.size(); i++) {
				if (std::stoi(movies[i].getYear()) <= toYear && std::stoi(movies[i].getYear()) >= fromYear) {
					filteredMovies.push_back(movies[i]);
					filtersOn = true;
				}
			}
		}

	}
	
	//filter based on the Title _ With a little bug _ Wokrs one letter prior 
	toBeRemovedMovies.clear();
	if (!textTitle._Equal("")) {
		if (!filtersOn) {
			for (int i = 0; i < movies.size(); i++) {
				isOnFilteredMovies = false;
				if ((movies[i].getTitle()).find(textTitle) != std::string::npos) {
					if (filteredMovies.size() == 0) {
						filteredMovies.push_back(movies[i]);
						filtersOn = true;
					}
					for (int h = 0; h < filteredMovies.size(); h++) {
						if (movies[i].getTitle()._Equal(filteredMovies[h].getTitle())) {
							isOnFilteredMovies = true;
						}
					}
					if (!isOnFilteredMovies) {
						filteredMovies.push_back(movies[i]);
					}
				}
			}
		}
		else if (filtersOn) {
			for (int i = 0; i < filteredMovies.size(); i++) {
				if (!((filteredMovies[i].getTitle()).find(textTitle) != std::string::npos)) {
					toBeRemovedMovies.push_back(filteredMovies[i]);
				}
			}
			for (auto& mov : toBeRemovedMovies) {
				filteredMovies.erase(std::remove(filteredMovies.begin(), filteredMovies.end(), mov), filteredMovies.end());
			}
		}	
	}
	
	movieIndex = 0;
}

void MoviesList::setFilter(std::string filter)
{
	//push_back filter in vector filters, and if aldready exists remove it
	movieIndex = 0;
	if (!filtersOn) {
		filters.push_back(filter);
		filtersOn = true;
	}
	else if (filtersOn) {
		if (std::find(filters.begin(), filters.end(), filter) != filters.end()) {
			filters.erase(std::remove(filters.begin(), filters.end(), filter), filters.end());
			if (filters.size() == 0 && fromYear == getOldestYear() && toYear == getNewestYear())
			{
				filtersOn = false;
			}
		}
		else {
			filters.push_back(filter);
		}
	}
	//tidy up the vector fillFilteredMovies
	fillFilteredMovies("");
}

void MoviesList::resetFilters()
{
	//set appropiate values to their initial state 
	filters.clear();
	fromYear = getOldestYear();
	toYear = getNewestYear();
	filtersOn = false;
	movieIndex = 0;
	fillFilteredMovies("");
}

void MoviesList::settextTitle(std::string title)
{
	this->textTitle = title;
}

void MoviesList::draw(vector<Movie> Movies)
{
	//draw at most three movies of a vector 
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
	//draw vector movies or vector filteredMovies
	if (filtersOn) {//if filters do not match any movie, draw proper message
		if (filteredMovies.size()==0) {
			graphics::Brush br;
			graphics::drawText(1.5f*CANVAS_WIDTH / 5.0f, CANVAS_HEIGTH / 4.0f,20,"No movie found...",br);
		}
		else {
			draw(filteredMovies);
		}
		
	}
	else if (!filtersOn) {
		draw(movies);
	}
}