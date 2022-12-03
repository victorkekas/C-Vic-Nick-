#pragma once
#include <iostream>
#include <string>

using namespace std;


class Movie {
private :
	string title;
	string director;
	string genre[3];
	string prot[3];
	int year ;
public:

	// Construstors 
	Movie();																											 // Default 
	Movie(string title,string director , string genre[3],string prot[3], int year);										//  

	//Copy Const 
	Movie(const Movie& obj_Movie);

	// Deconstructor 
	~Movie();
// ------------------------------------------------------------------------------------------------------------------------------------------------//
	// Basic Get and Set methods  

	int getYear();
	void setYear(int newY);

	string getTitle();
	void setTitle(string title);

	string getDirector();
	void setDirector(string dir);

	string getMainChar();
	void setMainChar(string chara);

	string getSecChar();
	void setSecChar(string chara);

	string getThirdChar();
	void setThirdChar(string chara);

	string getGenre1();
	void setGenre1(string gen);

	string getGenre2();
	void setGenre2(string gen);

	string getGenre3();
	void setGenre3(string gen);

	string toString();
};

