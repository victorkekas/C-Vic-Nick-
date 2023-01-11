#pragma once
#include "graphics.h"
#include "config.h"
#include "movie.h"


class MoviesList {
public:
	std::vector<Movie> movies;
	std::vector<Movie> filteredMovies;
	std::vector <std::string> filters;
	std::string textTitle;
	int movieIndex;
	bool filtersOn = false;
	int fromYear;
	int toYear;
	float spaces, prev_loc_start, prev_loc_end;

	int getMovieIndex();
	MoviesList();
	~MoviesList();
	void nextMovie();
	void previousMovie();
	void changeFromYear(int fromYear);
	void changeToYear(int toYear);
	int getOldestYear();
	int getNewestYear();
	void separator(float start, float end);
	void init();
	void draw();
	void draw(vector<Movie> Movies);
	void fillFilteredMovies(std::string title);
	void setFilter(std::string filter);
	void setFilterAction();
	void setFilterDrama();
	void setFilterAdventure();
	void setFilterFantasy();
	void setFilterHistory();
	void setFilterCrime();
	void setFilterSciFi();
	void resetFilters();
	void settextTitle(std::string title);
};