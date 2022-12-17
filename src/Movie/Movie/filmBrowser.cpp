#include "filmBrowser.h"
#include "graphics.h"
#include "config.h"
#include "movie.h"
#include "button.h"
#include "text_container.h"

void FilmBrowser::update()
{
	//sleep(4);
	/*
	Button* button_update = reinterpret_cast<Button*>(graphics::getUserData());
	if (button_update == nullptr) {
		graphics::setUserData(&button_update);
	}
	button_update->update();
	//
	
	if (!(graphics::getUserData() == nullptr)) {
		Button* button_update = reinterpret_cast<Button*>(graphics::getUserData());
		button_update->update();
	}
	else {
		std::cout << "test" << endl;
	}*/
	//std::cout<< "test" << endl;
}

void FilmBrowser::draw()
{
	std::vector<std::vector<std::string>> images;

	std::vector<std::string> FightClub;
	std::vector<std::string> ANewHope;
	std::vector<std::string> EmpireStrikesBack;
	std::vector<std::string> GodFather;
	std::vector<std::string> PulpFiction;
	std::vector<std::string> RaidersOfTheLostArk;
	std::vector<std::string> Schindlerslist;
	std::vector<std::string> Terminator;
	std::vector<std::string> TempleOfDoom;

	FightClub.push_back("FightClub.png");
	FightClub.push_back("shot-FightClubV1.png");
	FightClub.push_back("shot-FightClubV2.png");
	ANewHope.push_back("ANewHope.png");
	ANewHope.push_back("shot-ANewHopeV1.png");
	ANewHope.push_back("shot-ANewHopeV2.png");
	ANewHope.push_back("shot-ANewHopeV3.png");
	EmpireStrikesBack.push_back("EmpireStrikesBack.png");
	EmpireStrikesBack.push_back("shot-StarWarsV1.png");
	EmpireStrikesBack.push_back("shot-StarWarsV2.png");
	EmpireStrikesBack.push_back("shot-StarWarsV3.png");
	EmpireStrikesBack.push_back("shot-StarWarsV4.png");
	EmpireStrikesBack.push_back("shot-StarWarsV5.png");
	EmpireStrikesBack.push_back("shot-StarWarsV6.png");
	GodFather.push_back("Godfather.png");
	GodFather.push_back("shot-GodfatherV1.png");
	PulpFiction.push_back("PulpFiction.png");
	PulpFiction.push_back("shot-PulpFictionV1.png");
	PulpFiction.push_back("shot-PulpFictionV2.png");
	PulpFiction.push_back("shot-PulpFictionV3.png");
	RaidersOfTheLostArk.push_back("RaidersOfTheLostArk.png");
	RaidersOfTheLostArk.push_back("shot-RaidersOfTheLostArkV1.png");
	RaidersOfTheLostArk.push_back("shot-RaidersOfTheLostArkV2.png");
	RaidersOfTheLostArk.push_back("shot-RaidersOfTheLostArkV3.png");
	RaidersOfTheLostArk.push_back("shot-RaidersOfTheLostArkV4.png");
	Schindlerslist.push_back("Schindlerslist.png");
	Schindlerslist.push_back("shot-SchindlerslistV1.png");
	Schindlerslist.push_back("shot-SchindlerslistV2.png");
	Schindlerslist.push_back("shot-SchindlerslistV3.png");
	Terminator.push_back("Terminator.png");
	Terminator.push_back("shot-Terminator.png");
	TempleOfDoom.push_back("TempleOfDoom.png");
	TempleOfDoom.push_back("shot-TempleOfDoomV1.png");
	TempleOfDoom.push_back("shot-TempleOfDoomV2.png");
	TempleOfDoom.push_back("shot-TempleOfDoomV3.png");
	TempleOfDoom.push_back("shot-TempleOfDoomV4.png");
	TempleOfDoom.push_back("shot-TempleOfDoomV5.png");

	images.push_back(FightClub);
	images.push_back(ANewHope);
	images.push_back(EmpireStrikesBack);
	images.push_back(GodFather);
	images.push_back(PulpFiction);
	images.push_back(RaidersOfTheLostArk);
	images.push_back(Schindlerslist);
	images.push_back(Terminator);
	images.push_back(TempleOfDoom);

	std::vector<std::vector<std::string>> text;

	std::vector<std::string> TextFightClub;
	std::vector<std::string> TextANewHope;
	std::vector<std::string> TextEmpireStrikesBack;
	std::vector<std::string> TextGodFather;
	std::vector<std::string> TextPulpFiction;
	std::vector<std::string> TextRaidersOfTheLostArk;
	std::vector<std::string> TextSchindlerslist;
	std::vector<std::string> TextTerminator;
	std::vector<std::string> TextTempleOfDoom;

	TextFightClub.push_back("Title : Fight Club");
	TextFightClub.push_back("Director : David Fincher ");
	TextFightClub.push_back("Year of Publish : MCMXCI1X 1999%f" + to_string(1999));
	TextFightClub.push_back("Actor : Brad Pitt");
	TextFightClub.push_back("Actor : Edward Norton ");
	TextFightClub.push_back("Genre : Thriller ");
	TextFightClub.push_back("Genre : Drama ");
	TextANewHope.push_back("Title : A New Hope");
	TextANewHope.push_back("Director : George Lucas");
	TextANewHope.push_back("Year of Publish : 1977  ");
	TextANewHope.push_back("Actor : Mark Hamill ");
	TextANewHope.push_back("Actor : Harrison Ford  ");
	TextANewHope.push_back("Genre : Action ");
	TextANewHope.push_back("Genre : Sci-Fi ");
	TextEmpireStrikesBack.push_back("Title : Empire Strikes Back");
	TextEmpireStrikesBack.push_back("Director : Irvin Kershner ");
	TextEmpireStrikesBack.push_back("Year of Publish : 1980 ");
	TextEmpireStrikesBack.push_back("Actor : Mark Hamill ");
	TextEmpireStrikesBack.push_back("Actor : Harrison Ford");
	TextEmpireStrikesBack.push_back("Genre : Action  ");
	TextEmpireStrikesBack.push_back("Genre : Sci-Fi ");
	TextGodFather.push_back("Title : GodFather ");
	TextGodFather.push_back("Director : Francis Coppola ");
	TextGodFather.push_back("Year of Publish : 1972");
	TextGodFather.push_back("Actor : Al Pacino ");
	TextGodFather.push_back("Actor : Marlon Brando ");
	TextGodFather.push_back("Genre : Crime ");
	TextGodFather.push_back("Genre : Drama ");
	TextPulpFiction.push_back("Title : Pulp Fiction");
	TextPulpFiction.push_back("Director : Quentin Tarantino ");
	TextPulpFiction.push_back("Year of Publish : 1994");
	TextPulpFiction.push_back("Actor : John Travolta ");
	TextPulpFiction.push_back("Actor : Samuel L.Jackson ");
	TextPulpFiction.push_back("Genre : Crime ");
	TextPulpFiction.push_back("Genre : Drama ");
	TextRaidersOfTheLostArk.push_back("Title : Raiders of The Lost Ark");
	TextRaidersOfTheLostArk.push_back("Director : Steven Spielberg ");
	TextRaidersOfTheLostArk.push_back("Year of Publish : 1981 ");
	TextRaidersOfTheLostArk.push_back("Actor : Harrison Ford ");
	TextRaidersOfTheLostArk.push_back("Actor : Karen Allen ");
	TextRaidersOfTheLostArk.push_back("Genre : Action ");
	TextRaidersOfTheLostArk.push_back("Genre : Adventure ");
	TextSchindlerslist.push_back("Title : Schindlers List");
	TextSchindlerslist.push_back("Director : Steven Spielberg ");
	TextSchindlerslist.push_back("Year of Publish : 1993 ");
	TextSchindlerslist.push_back("Actor : Liam Neeson ");
	TextSchindlerslist.push_back("Actor : Ralph Fiennes ");
	TextSchindlerslist.push_back("Genre : Biography ");
	TextSchindlerslist.push_back("Genre : Drama ");
	TextTerminator.push_back("Title : Terminators");
	TextTerminator.push_back("Director : James Cameron ");
	TextTerminator.push_back("Year of Publish : 1984 ");
	TextTerminator.push_back("Actor : Arnold Schwarzenegger");
	TextTerminator.push_back("Actor : Linda Hamilton ");
	TextTerminator.push_back("Genre : Action ");
	TextTerminator.push_back("Genre : Sci-Fi ");
	TextTempleOfDoom.push_back("Title : Temple Of Doom");
	TextTempleOfDoom.push_back("Director : Steven Spielberg ");
	TextTempleOfDoom.push_back("Year of Publish : 1984 ");
	TextTempleOfDoom.push_back("Actor : Harrison Ford ");
	TextTempleOfDoom.push_back("Actor : Kate Capshaw ");
	TextTempleOfDoom.push_back("Genre : Action ");
	TextTempleOfDoom.push_back("Genre : Adventure ");

	text.push_back(TextFightClub);
	text.push_back(TextANewHope);
	text.push_back(TextEmpireStrikesBack);
	text.push_back(TextGodFather);
	text.push_back(TextPulpFiction);
	text.push_back(TextRaidersOfTheLostArk);
	text.push_back(TextSchindlerslist);
	text.push_back(TextTerminator);
	text.push_back(TextTempleOfDoom);

	graphics::Brush br;
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 0.5f;
	br.fill_color[2] = 0.0f;
	br.fill_opacity = 1.0f;
	br.fill_secondary_color[0] = 0.0f;
	br.fill_secondary_color[1] = 0.6f;
	br.fill_secondary_color[2] = 0.8f;
	br.fill_secondary_opacity = 1.0f;
	br.gradient = true;

	br.outline_opacity = 0.0f;

	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGTH / 2, CANVAS_WIDTH, CANVAS_WIDTH, br);

	Movie fightClub("Fight Club", "David Fincher", { "Drama" ,"Thriller" }, { "Edward Norton" ,"Brad Pitt" }, "1999");
	Movie aNewHope("A New Hope", "George Lucas", { "Action" ,"Adventure","Fantasy", "Sci-Fi" }, { "Mark Hamill" ,"Harrison Ford" }, "1977");
	Movie empireStrikesBack("Empire Strikes Back", "Irvin Kenshner", { "Action" ,"Adventure","Fantasy","Sci-fi" }, { "Mark Hamill" ,"Harrison Ford" }, "1980");
	Movie godFather("God Father", "Francis Ford Coppola ", { "Crime " ,"Drama" }, { "Marlon Brando" ,"Al Pacino" }, "1972");
	Movie pulpFiction("Pulp Fiction", "Quentin Tarantino ", { "Drama" ,"Crime" }, { "John Travolta" ,"Uma Thurman", "Samuel L.Jackson", "Bruce Willis" }, "1994");
	Movie raidersOfTheLostArk("Raiders Of The Lost Ark", "Steven Spielberg", { "Action" ,"Adventure" }, { "Harrison Ford" ,"Karen Allen", "Paul Freeman" }, "1981");
	Movie schindlerslist("Schindler's list", "Steven Spielberg", { "Drama" ,"Biography","History" }, { "Liam Neeson " ,"Ralph Fiennes", "Ben Kingsley" }, "1993");
	Movie terminator("Terminator", "James Cameron", { "Action" ,"Sci-Fi" }, { "Arnold Schwarzenegger" ,"Linda Hamilton", "Michael Biehn" }, "1984");
	Movie templeOfDoom("Temple Of Doom", "Steven Spielberg", { "Action" ,"Adventure" }, { "Kate Capshaw" ,"Harrison Ford" }, "1984");

	std::vector<Movie> movies;
	movies.push_back(fightClub);
	movies.push_back(aNewHope);
	movies.push_back(empireStrikesBack);
	movies.push_back(godFather);
	movies.push_back(pulpFiction);
	movies.push_back(raidersOfTheLostArk);
	movies.push_back(schindlerslist);
	movies.push_back(terminator);
	movies.push_back(templeOfDoom);


	movies[j].draw(images[j]);
	std::vector<std::vector<std::string>>* vec_ptr_images = &images;
	std::vector<Movie>* vec_ptr_movies = &movies;
	int* int_ptr_j = &j;
	static int* int_ptr_i = &(Movie::images_index); //des to static


	//button for movies (main image)
	graphics::Brush br_button_type_1;
	br_button_type_1.texture = std::string(ASSET_PATH) + "arrow.png";
	br_button_type_1.outline_color[0] = 1.0f;
	br_button_type_1.outline_color[1] = 0.0f;
	br_button_type_1.outline_color[2] = 0.0f;
	br_button_type_1.outline_width = 0.0f;
	br_button_type_1.outline_opacity = 0.0f;
	br_button_type_1.fill_color[0] = 0.0f;
	br_button_type_1.fill_color[1] = 0.0f;
	br_button_type_1.fill_color[2] = 0.0f;

	// left button for changing movie
	Button b1_left(CANVAS_WIDTH / 4.0f, CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 15.0f, CANVAS_HEIGTH / 10.3f, br_button_type_1, movies.size(), /*&images, &movies,*/ int_ptr_j, 'b');
	b1_left.draw(); 
	b1_left.addActionCallback(std::bind(&Button::ButtonAction_Index,&b1_left, std::placeholders::_1, std::placeholders::_2));
	//(b1_left).update(); 

	// right button for changing movie
	graphics::setOrientation(180);
	Button b1_right(3 * CANVAS_WIDTH / 4.0f, CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 15.0f, CANVAS_HEIGTH / 10.3f, br_button_type_1, movies.size(), /*&images, &movies,*/ int_ptr_j, 'f');
	b1_right.draw();
	b1_right.addActionCallback(std::bind(&Button::ButtonAction_Index, &b1_right, std::placeholders::_1, std::placeholders::_2));
	//(b1_right).update(); 
	graphics::setOrientation(0);

	//button for movies (secondary images)
	graphics::setScale(0.66f, 0.66f);
	br_button_type_1.outline_color[0] = 1.0f;
	br_button_type_1.outline_color[1] = 0.0f;
	br_button_type_1.outline_color[2] = 0.0f;
	br_button_type_1.outline_width = 0.0f;
	br_button_type_1.outline_opacity = 0.0f;
	br_button_type_1.fill_color[0] = 1.0f;
	br_button_type_1.fill_color[1] = 0.0f;
	br_button_type_1.fill_color[2] = 0.0f;
	 
	// left button for changing movie's images
	Button b2_left(3.2 * CANVAS_WIDTH / 4.0f - CANVAS_WIDTH / 7.0f, 3 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 15.0f, CANVAS_HEIGTH / 10.3f, br_button_type_1, images[j].size(), /*&images, &movies, */ int_ptr_i, 'b');
	b2_left.draw();
	b2_left.addActionCallback(std::bind(&Button::ButtonAction_Index_except0, &b2_left, std::placeholders::_1, std::placeholders::_2));
	//(b2_left).update();

	// right button for changing movie's images
	graphics::setOrientation(180);
	Button b2_right(3.2 * CANVAS_WIDTH / 4.0f + CANVAS_WIDTH / 7.0f, 3 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 15.0f, CANVAS_HEIGTH / 10.3f, br_button_type_1, images[j].size(), /*&images, &movies, */ int_ptr_i, 'f');
	b2_right.draw();
	b2_right.addActionCallback(std::bind(&Button::ButtonAction_Index_except0, &b2_right, std::placeholders::_1, std::placeholders::_2));
	//(b2_right).update();
	
	//reset br 
	graphics::setOrientation(0);
	graphics::setScale(1.0f, 1.0f);
}

void FilmBrowser::init()
{
}

FilmBrowser::FilmBrowser()
{

}

FilmBrowser::~FilmBrowser()
{

}