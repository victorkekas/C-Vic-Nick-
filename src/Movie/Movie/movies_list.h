#pragma once
#include "graphics.h"
#include "config.h"
#include "movie.h"
//#include "button.h"
//#include "text_container.h"

class MoviesList {
public:
	std::vector<Movie> movies;
	std::vector<Movie> filteredMovies;
	std::vector <std::string> filters;
	int movieIndex;
	bool filtersOn = false;

	int getMovieIndex();
	MoviesList();
	~MoviesList();
	void nextMovie();
	void previousMovie();
	void init();
	void draw();
	void draw(vector<Movie> Movies);
	void fillFilteredMovies();
	void tidyUpFilteredMovies();
	void setFilterAction();
	void resetFilters();
};