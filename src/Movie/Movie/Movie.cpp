#include "movie.h";

Movie::Movie() {}

Movie::Movie(string title, string director, vector <string> genre, vector <string> prot, int year) {
	this->title = title;
	this->director = director;
	this->year = year;
	for (int i = 0; i < genre.size(); i++) {
		this->genre.push_back(genre[i]);
	}
	for (int i = 0; i < prot.size(); i++) {
		this->prot.push_back(prot[i]);
	}
}
Movie::Movie(const Movie& obj_Movie) {
	this->title = obj_Movie.title;
	this->director = obj_Movie.director;
	this->year = obj_Movie.year;
	for (int i = 0; i < obj_Movie.genre.size(); i++) {
		this->genre.push_back(obj_Movie.genre[i]);
	}
	for (int i = 0; i < obj_Movie.prot.size(); i++) {
		this->prot.push_back(obj_Movie.prot[i]);
	}
}
Movie::~Movie() {
	cout << "Deleting Movie..." << endl;
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
vector <string> Movie::getProtagonists() {
	return prot;
}
void Movie::addProtagonist(string chara) {
	this->prot.push_back(chara);
}
vector <string> Movie::getGenre() {
	return genre;
}
void Movie::addGenre(string gen) {
	this->genre.push_back(gen);
}
string Movie::toString() {
	string str = "Title : " + this->getTitle() + " \n"
		+ "Director : " + this->getDirector() + "\n"
		+ "Year of publish : " + to_string(this->getYear()) + "\n";
	for (int i = 0; i < prot.size(); i++) {
		str += "Actor  " + to_string(i+1) + " : " + prot[i] + "\n";
	}
	for (int i = 0; i < genre.size(); i++) {
		str += "Gerne  " + to_string(i+1) + " : " + genre[i] + "\n";
	}
	return str;
}
