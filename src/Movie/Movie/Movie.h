#pragma once
#include <iostream>
#include <string>
#include<vector>

using namespace std;

class Movie {
private :
	string title;
	string director;
	vector <string> genre;
	vector <string> prot;
	int year ;
public:
	// Construstors 
	Movie();																											
	Movie(string title, string director, vector <string> genre, vector <string> prot, int year);						
	//Copy Const 
	Movie(const Movie& obj_Movie);
	// Deconstructor 
	~Movie();
	// Basic Get and Set methods  
	int getYear();
	void setYear(int newY);
	string getTitle();
	void setTitle(string title);
	string getDirector();
	void setDirector(string dir);
	vector <string> getProtagonists();
	void addProtagonist(string chara);
	vector <string> getGenre();
	void addGenre(string gen);
	string toString();
};
