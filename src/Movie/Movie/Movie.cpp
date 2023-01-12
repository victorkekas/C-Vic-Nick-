#include "movie.h";

//int Movie::images_index = 1;

Movie::Movie() {}

Movie::Movie(string title, string director, vector <string> genre, vector <string> prot, string year, vector <string> shots, string poster, string summary) {
	this->images_index = 0;
	this->title = title;
	this->director = director;
	this->year = year;
	this->poster = poster;
	this->summary = summary;
	for (int i = 0; i < genre.size(); i++) {
		this->genre.push_back(genre[i]);
	}
	for (int i = 0; i < prot.size(); i++) {
		this->prot.push_back(prot[i]);
	}
	for (int i = 0; i < shots.size(); i++) {
		this->shots.push_back(shots[i]);
	}
}

Movie::Movie(const Movie& obj_Movie) {
	this->images_index = obj_Movie.images_index;
	this->title = obj_Movie.title;
	this->director = obj_Movie.director;
	this->year = obj_Movie.year;
	this->poster = obj_Movie.poster;
	this->summary = obj_Movie.summary;
	for (int i = 0; i < obj_Movie.genre.size(); i++) {
		this->genre.push_back(obj_Movie.genre[i]);
	}
	for (int i = 0; i < obj_Movie.prot.size(); i++) {
		this->prot.push_back(obj_Movie.prot[i]);
	}
	for (int i = 0; i < obj_Movie.shots.size(); i++) {
		this->shots.push_back(obj_Movie.shots[i]);
	}
}

Movie::~Movie() {
}

string Movie::getYear() {
	return year;
}


const string Movie::getTitle() {
	return title;
}

string Movie::getDirector() {
	return director;
}

vector <string> Movie::getProtagonists() {
	return prot;
}

vector <string> Movie::getGenre() {
	return this->genre;
}

string Movie::getSummary()
{
	return this->summary;
}

void Movie::init()
{
}

void Movie::draw()
{
	//draw main image 
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + poster;
	br.outline_color[0] = 0.0f;
	br.outline_color[1] = 0.0f;
	br.outline_color[2] = 0.0f;
	br.outline_width = 2.0f;
	graphics::drawRect(2.2f * CANVAS_WIDTH / 6.0f, CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 5.0f, CANVAS_HEIGTH / 2.3f, br); // main image

	//draw shots 
	graphics::Brush br2;
	br2.texture = std::string(ASSET_PATH) + shots[images_index];
	br2.outline_color[0] = 0.0f;
	br2.outline_color[1] = 0.0f;
	br2.outline_color[2] = 0.0f;
	br2.outline_width = 2.0f;
	graphics::drawRect(3.2 * CANVAS_WIDTH / 4.0f, 3 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 4.0f, 1.1 * CANVAS_HEIGTH / 4.0f, br2); // secondary images

	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;
	br.outline_color[0] = 0.0f;
	br.outline_color[1] = 0.0f;
	br.outline_color[2] = 0.0f;

	//set font style 
	graphics::setFont(std::string(ASSET_PATH) + "LiberationSans-Bold.ttf");

	//draw movie iformation  
	std::string str;
	float j = 20;
	int i = 0;
	//print title 
	str = "Title : " + getTitle();
	graphics::drawText(CANVAS_WIDTH / 16, j * CANVAS_HEIGTH / 34, 22.0f, str, br);
	str = "";
	j += 1.5f;
	//print director 
	str = "Director : " + getDirector();
	graphics::drawText(CANVAS_WIDTH / 16, j * CANVAS_HEIGTH / 34, 16.0f, str, br);
	str = "";
	j += 1.2f;
	//print year of publishation 
	str = "Year of Publish : " + getYear();
	graphics::drawText(CANVAS_WIDTH / 16, j * CANVAS_HEIGTH / 34, 16.0f, str, br);
	str = "";
	j += 1.2f;
	//print actors 
	str += "Actors : ";
	for (i; i < prot.size(); i++) {
		str += prot[i];
		if (i + 1 == prot.size())  break;
		str += ", ";
	}
	graphics::drawText(CANVAS_WIDTH / 16, j * CANVAS_HEIGTH / 34, 16.0f, str, br);
	str = "";
	j += 1.2f;
	//print Genres   
	str += "Genres : ";
	i = 0;
	for (i; i < genre.size(); i++) {
		str += genre[i];
		if (i + 1 == genre.size())  break;
		str += ", ";
	}
	graphics::drawText(CANVAS_WIDTH / 16, j * CANVAS_HEIGTH / 34, 16.0f, str, br);
	str = "";
	j += 1.6f;

	str = "Summary : ";
	graphics::drawText(CANVAS_WIDTH / 16, j * CANVAS_HEIGTH / 34, 16.0f, str, br);
	j += 1.2f;
	str = " ";

	str = getSummary();
	std::string tempstring;
	std::string temp2string="";
	bool notSecondelseIf=false;
	for (int i = 0; i <= str.length(); i++) {
		if (str[i]!= ' ') {
			tempstring += str[i];
		}
		else if (temp2string.length() + tempstring.length() + 1 <= 70) {
			temp2string += tempstring + " ";
			tempstring = "";
			notSecondelseIf = true;
		}
		else if (temp2string.length() + tempstring.length() <= 70 && !notSecondelseIf) {
			temp2string += tempstring;
			tempstring = "";
		}
		else {
			graphics::drawText(CANVAS_WIDTH / 16, j * CANVAS_HEIGTH / 34, 16.0f, temp2string, br);
			temp2string = "";
			temp2string += tempstring +" ";
			tempstring = "";
			j += 1.2f;
		}
		if (i == str.length()) {
			temp2string += tempstring + " ";
			graphics::drawText(CANVAS_WIDTH / 16, j * CANVAS_HEIGTH / 34, 16.0f, temp2string, br);
		}
	}
}

void Movie::draw1(float cx)
{
	//draw poster only 
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + poster;
	br.outline_color[0] = 0.0f;
	br.outline_color[1] = 0.0f;
	br.outline_color[2] = 0.0f;
	br.outline_width = 2.0f;
	graphics::drawRect(cx*CANVAS_WIDTH / 16.0f, CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 7.0f, CANVAS_HEIGTH / 3.3f, br); // main image
}

void Movie::nextShot()
{
	//change shot
	if (images_index == (shots.size() - 1)) {
		images_index = 0;
		return;
	}
	images_index += 1;
	return;
}

void Movie::previousShot()
{
	//change shot
	if (images_index == 0) {
		images_index = (shots.size() - 1);
		return;
	}
	images_index -= 1;
	return;
}

bool Movie::operator==(Movie movie)
{
	if (this->title._Equal(movie.getTitle())) {
		return true;
	}
	else {
		return false;
	}
}