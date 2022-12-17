#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Widget {

public :

	vector <int> position;	// Thesi pano ston kamva 
	bool can_move= false ;	// an mporei na paei dexia aristera 
	bool can_press= false ; // an mporei na patithei 
	bool can_type = false; // a mporei na grapsei 
	vector <int> widget_dim ; // Diastaseis Widget 
	
};

