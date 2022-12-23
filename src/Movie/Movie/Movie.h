#pragma once
#include <iostream>
#include <string>
#include<vector>
#include "graphics.h"
#include "config.h"

using namespace std;

class Movie {
public :
	string title;
	string director;
	vector <string> genre;
	vector <string> prot;
	vector <string> shots;
	string poster;
	string year ;
	string summary;
	int images_index;
	//static int images_index;
	// Construstors 
	Movie();																											
	Movie(string title, string director, vector <string> genre, vector <string> prot, string year, vector <string> shots, string poster, string summary);
	//Copy Const 
	Movie(const Movie& obj_Movie);
	// Deconstructor 
	~Movie();
	// Basic Get and Set methods  
	string getYear();
	void setYear(string newY);
	string getTitle();
	void setTitle(string title);
	string getDirector();
	void setDirector(string dir);
	vector <string> getProtagonists();
	void addProtagonist(string chara);
	vector <string> getGenre();
	void addGenre(string gen);
	string getSummary();
	string toString();
	//methods
	void init();
	void draw();
	void draw1(float cx);// only the poster
	void nextShot();
	void previousShot();
};
