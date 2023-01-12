#pragma once
#include "graphics.h"
#include "config.h"
#include "movie.h"


class MoviesList {
public:
	std::vector<Movie> movies;
	std::vector<Movie> filteredMovies;
	bool filtersOn = false;
	MoviesList();
	~MoviesList();
	void init();
	void draw();
	int getMovieIndex();
	int getOldestYear();
	int getNewestYear();
	void nextMovie();
	void previousMovie();
	void settextTitle(std::string title);
	void changeFromYear(int fromYear);
	void changeToYear(int toYear);
	void fillFilteredMovies(std::string title);
	void setFilter(std::string filter);
	void resetFilters();
private:
	std::vector <std::string> filters;
	std::string textTitle;
	int movieIndex;
	int fromYear;
	int toYear;
	float spaces, prev_loc_start, prev_loc_end;
	void draw(vector<Movie> Movies);
};