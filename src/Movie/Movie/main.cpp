#include "movie.h"


int main() {

	Movie a ("Fight Club", "David Fincher ", { "Drama", "Action" }, { "Brad Pitt ", "Edward Norton " }, 2001);
	string ok= a.toString();
	cout << ok;
	return 0;

}
