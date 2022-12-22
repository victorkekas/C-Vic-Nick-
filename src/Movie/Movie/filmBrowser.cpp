#include "filmBrowser.h"
#include "graphics.h"
#include "config.h"
#include "movie.h"
#include "button.h"
#include "text_container.h"

std::vector<std::vector<std::string>> images;
std::vector<Movie> movies;
Button* b1_left;
Button* b1_right;
Button* b2_left;
Button* b2_right;
/*std::vector<Button*> buttons;
buttons.push_back(&b2_test);
buttons.push_back(&b1_left);
buttons.push_back(&b1_right);
buttons.push_back(&b2_left);
buttons.push_back(&b2_right);
*/

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
	if (b1_left) {
		b1_left->update();
	}
	if (b1_right) {
		b1_right->update();
	}
	if (b2_left) {
		b2_left->update();
	}
	if (b2_right) {
		b2_right->update();
	}
}

void FilmBrowser::init()
{
	//declaration of movies and description
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


	std::vector<std::string> TextFightClub;
	std::vector<std::string> TextANewHope;
	std::vector<std::string> TextEmpireStrikesBack;
	std::vector<std::string> TextGodFather;
	std::vector<std::string> TextPulpFiction;
	std::vector<std::string> TextRaidersOfTheLostArk;
	std::vector<std::string> TextSchindlerslist;
	std::vector<std::string> TextTerminator;
	std::vector<std::string> TextTempleOfDoom;

	Movie fightClub("Fight Club", "David Fincher", { "Drama" ,"Thriller" }, { "Edward Norton" ,"Brad Pitt" }, "1999");
	Movie aNewHope("A New Hope", "George Lucas", { "Action" ,"Adventure","Fantasy", "Sci-Fi" }, { "Mark Hamill" ,"Harrison Ford" }, "1977");
	Movie empireStrikesBack("Empire Strikes Back", "Irvin Kenshner", { "Action" ,"Adventure","Fantasy","Sci-fi" }, { "Mark Hamill" ,"Harrison Ford" }, "1980");
	Movie godFather("God Father", "Francis Ford Coppola ", { "Crime " ,"Drama" }, { "Marlon Brando" ,"Al Pacino" }, "1972");
	Movie pulpFiction("Pulp Fiction", "Quentin Tarantino ", { "Drama" ,"Crime" }, { "John Travolta" ,"Uma Thurman", "Samuel L.Jackson", "Bruce Willis" }, "1994");
	Movie raidersOfTheLostArk("Raiders Of The Lost Ark", "Steven Spielberg", { "Action" ,"Adventure" }, { "Harrison Ford" ,"Karen Allen", "Paul Freeman" }, "1981");
	Movie schindlerslist("Schindler's list", "Steven Spielberg", { "Drama" ,"Biography","History" }, { "Liam Neeson " ,"Ralph Fiennes", "Ben Kingsley" }, "1993");
	Movie terminator("Terminator", "James Cameron", { "Action" ,"Sci-Fi" }, { "Arnold Schwarzenegger" ,"Linda Hamilton", "Michael Biehn" }, "1984");
	Movie templeOfDoom("Temple Of Doom", "Steven Spielberg", { "Action" ,"Adventure" }, { "Kate Capshaw" ,"Harrison Ford" }, "1984");


	movies.push_back(fightClub);
	movies.push_back(aNewHope);
	movies.push_back(empireStrikesBack);
	movies.push_back(godFather);
	movies.push_back(pulpFiction);
	movies.push_back(raidersOfTheLostArk);
	movies.push_back(schindlerslist);
	movies.push_back(terminator);
	movies.push_back(templeOfDoom);


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

	// left button for changing movie !!!!!DELETE THE BUTTONS LATER PLEASE 
	b1_left = new Button(CANVAS_WIDTH / 4.0f, CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 15.0f, CANVAS_HEIGTH / 10.3f, br_button_type_1, movies.size(), /*&images, &movies,*/ &j, 'b');
	b1_left->addActionCallback(std::bind(&Button::ButtonAction_Index, b1_left)); //

	// right button for changing movie !!!!!DELETE THE BUTTONS LATER PLEASE
	b1_right = new Button(3 * CANVAS_WIDTH / 4.0f, CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 15.0f, CANVAS_HEIGTH / 10.3f, br_button_type_1, movies.size(), /*&images, &movies,*/ &j, 'f');
	b1_right->addActionCallback(std::bind(&Button::ButtonAction_Index, b1_right));


	//button for movies (secondary images)
	
	br_button_type_1.outline_color[0] = 1.0f;
	br_button_type_1.outline_color[1] = 0.0f;
	br_button_type_1.outline_color[2] = 0.0f;
	br_button_type_1.outline_width = 0.0f;
	br_button_type_1.outline_opacity = 0.0f;
	br_button_type_1.fill_color[0] = 1.0f;
	br_button_type_1.fill_color[1] = 0.0f;
	br_button_type_1.fill_color[2] = 0.0f;

	// left button for changing movie's images
	b2_left = new Button(3.2 * CANVAS_WIDTH / 4.0f - CANVAS_WIDTH / 7.0f, 3 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 15.0f, CANVAS_HEIGTH / 10.3f, br_button_type_1, images[j].size(), /*&images, &movies, */ &(Movie::images_index), 'b');
	b2_left->addActionCallback(std::bind(&Button::ButtonAction_Index_except0, b2_left));

	// right button for changing movie's images
	graphics::setOrientation(180);
	b2_right = new Button(3.2 * CANVAS_WIDTH / 4.0f + CANVAS_WIDTH / 7.0f, 3 * CANVAS_HEIGTH / 4.0f, CANVAS_WIDTH / 15.0f, CANVAS_HEIGTH / 10.3f, br_button_type_1, images[j].size(), /*&images, &movies, */ &(Movie::images_index), 'f');
	b2_right->addActionCallback(std::bind(&Button::ButtonAction_Index_except0, b2_right));

	//reset br 
	graphics::setOrientation(0);
}

void FilmBrowser::draw()
{
	//background
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
	//end background 

	movies[j].draw(images[j]);

	// left button for changing movie
	b1_left->draw();

	// left button for changing movie's images
	graphics::setScale(0.66f, 0.66f);
	b2_left->draw();
	graphics::setScale(1.0f, 1.0f);

	//
	graphics::setOrientation(180);
	// right button for changing movie
	b1_right->draw();

	// right button for changing movie's images
	graphics::setScale(0.66f, 0.66f);
	b2_right->draw();
	graphics::setScale(1.0f, 1.0f);

	//reset br 
	graphics::setOrientation(0);
}



FilmBrowser::FilmBrowser()
{

}

FilmBrowser::~FilmBrowser()
{
	std::cout << "FilmBrowser" << endl;
	delete b1_left;
	delete b1_right;
	delete b2_left;
	delete b2_right;
}