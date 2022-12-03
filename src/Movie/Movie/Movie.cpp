#include "Movie.h";

Movie::Movie() {}

Movie::Movie(string title, string director, string genre[3], string prot[3], int year) {
	this->title = title;
	this->director = director;
	this->genre[0] = genre[0];
	this->genre[1] = genre[1];
	this->genre[2] = genre[2];
	this->prot[0] = prot[0];
	this->prot[1] = prot[1];
	this->prot[2] = prot[2];
	this->year = year;
}

Movie::Movie(const Movie& obj_Movie) {
	this->title = obj_Movie.title;
	this->director = obj_Movie.director;
	this->genre[0] = obj_Movie.genre[0];
	this->genre[1] = obj_Movie.genre[1];
	this->genre[2] = obj_Movie.genre[2];
	this->prot[0] = obj_Movie.prot[0];
	this->prot[1] = obj_Movie.prot[1];
	this->prot[2] = obj_Movie.prot[2];
	this->year = obj_Movie.year;
}


Movie::~Movie() {
	cout << "Deleting Movie..." << endl;
	delete this;
	cout << "Deleted :) " << endl;
}

int Movie::getYear() {
	return year ;
}
void Movie::setYear(int newY) {
	this->year = newY;
}

string Movie::getTitle() {
	return title;
}
void Movie::setTitle(string title) {
	this->title = title;
}

string Movie::getDirector() {
	return director;
}
void Movie::setDirector(string dir) {
	this->director = dir;
}

string Movie::getMainChar() {
	return prot[0];
}
void Movie::setMainChar(string chara) {
	this->prot[0] = chara;
}

string Movie::getSecChar() {
	return prot[1];
}
void Movie::setSecChar(string chara) {
	this->prot[1] = chara;
}

string Movie::getThirdChar() {
	return prot[2];
}
void Movie::setThirdChar(string chara) {
	this->prot[2] = chara;
}

string Movie::getGenre1() {
	return genre[0];
}
string Movie::getGenre2() {
	return genre[1];
}
string Movie::getGenre3() {
	return genre[2];
}
void Movie::setGenre1(string gen) {
	this->genre[0] = gen;
}
void Movie::setGenre2(string gen) {
	this->genre[1] = gen;
}
void Movie::setGenre3(string gen) {
	this->genre[2] = gen;
}
string Movie::toString() {

	return ("Title " + this->getTitle() + "\n"
		+ "Director " + this->getDirector() + "\n"
		+ "Genre " + this->getGenre1() + " " + this->getGenre2() + " " + this->getGenre3() + "\n"
		+ "Protagonists " + this->getMainChar() + " " + this->getSecChar() + " " + this->getThirdChar() + "\n"
		+ "Year published " + to_string(this->getYear()));
	
}
