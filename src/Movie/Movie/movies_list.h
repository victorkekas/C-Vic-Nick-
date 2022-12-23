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
	int movieIndex;
	bool filtersOn = false;

	int getMovieIndex();
	MoviesList();
	~MoviesList();
	void nextMovie();
	void previousMovie();
	void init();
	void draw();
	void setFilterAction();
	void resetFilters();
	void Filtered(vector <string> filteres);
	void drawFiltered();
};