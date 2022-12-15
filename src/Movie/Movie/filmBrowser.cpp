#include "filmBrowser.h"
#include "graphics.h"
#include "config.h"
#include "movie.h"
#include "button.h"
#include "text_container.h"

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
	Movie aNewHope("A New Hope", "David Fincher", { "Drama" ,"Thriller" }, { "Edward Norton" ,"Brad Pitt" }, "1999");
	Movie empireStrikesBack("Empire Strikes Back", "David Fincher", { "Drama" ,"Thriller" }, { "Edward Norton" ,"Brad Pitt" }, "1999");
	Movie godFather("God Father", "David Fincher", { "Drama" ,"Thriller" }, { "Edward Norton" ,"Brad Pitt" }, "1999");
	Movie pulpFiction("Pulp Fiction", "David Fincher", { "Drama" ,"Thriller" }, { "Edward Norton" ,"Brad Pitt" }, "1999");
	Movie raidersOfTheLostArk("Raiders Of The Lost Ark", "David Fincher", { "Drama" ,"Thriller" }, { "Edward Norton" ,"Brad Pitt" }, "1999");
	Movie schindlerslist("Schindler's list", "David Fincher", { "Drama" ,"Thriller" }, { "Edward Norton" ,"Brad Pitt" }, "1999");
	Movie terminator("Terminator", "David Fincher", { "Drama" ,"Thriller" }, { "Edward Norton" ,"Brad Pitt" }, "1999");
	Movie templeOfDoom("Temple Of Doom", "David Fincher", { "Action" ,"Adventure" }, { "Kate Capshaw" ,"Harrison Ford" }, "1984");
	fightClub.draw(images[0]);
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