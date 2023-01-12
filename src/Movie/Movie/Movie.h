#pragma once
#include <iostream>
#include <string>
#include<vector>
#include "graphics.h"
#include "config.h"

using namespace std;

class Movie {
public :
	vector <string> genre;
	// Construstors 
	Movie();
	Movie(string title, string director, vector <string> genre, vector <string> prot, string year, vector <string> shots, string poster, string summary);
	//Copy Const 
	Movie(const Movie& obj_Movie);
	// Deconstructor 
	~Movie();
	// Basic Get and Set methods
	string getYear();
	vector <string> getGenre();
	const string getTitle();
	//methods
	void nextShot();
	void previousShot();
	void draw();
	void draw1(float cx);// only the poster
	//Operators overload
	bool operator==(const Movie movie);
protected:
	string temp;
	string temp2;
	string title;
	string director;
	
	vector <string> prot;
	vector <string> shots;
	string poster;
	string year ;
	string summary;
	int images_index;
	//static int images_index;
	// Basic Get and Set methods 
	string getDirector();
	vector <string> getProtagonists();
	string getSummary();
	//methods
	void init();
};
