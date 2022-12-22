#pragma once
#include "graphics.h"
#include "config.h"
#include "movie.h"
//#include "button.h"
//#include "text_container.h"

class MoviesList {
public:
	std::vector<Movie> movies;
	int movieIndex;

	MoviesList();
	~MoviesList();
	void nextMovie();
	void previousMovie();
	void init();
	void draw();
};