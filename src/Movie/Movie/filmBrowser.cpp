#include "filmBrowser.h"
#include "graphics.h"
#include "config.h"
#include "movie.h"
#include "button.h"

void FilmBrowser::update()
{
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

	graphics::Brush br;
	br.fill_color[0] = 145.0f;
	br.fill_color[1] = 41.0f;
	br.fill_color[2] = 160.0f;
	br.fill_opacity = 0.8f;
	br.fill_secondary_color[0] = 145.0f;
	br.fill_secondary_color[1] = 64.0f;
	br.fill_secondary_color[2] = 160.0f;
	br.fill_secondary_opacity = 0.5f;
	br.gradient = true;
	//br.gradient_dir_u = 0.0f;
	//br.gradient_dir_v = 4.0f;
	br.outline_opacity = 0.0f;

	graphics::drawRect(CANVAS_WIDTH/2, CANVAS_HEIGTH/2, CANVAS_WIDTH, CANVAS_WIDTH, br);

	Movie movie1;
	movie1.draw(images[0]);
	Button b1;
	b1.draw();

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
