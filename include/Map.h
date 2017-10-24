#pragma once
#include "GraphicPrimitives.h"
#include "Square.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Map {
private:
	int size;
	int number;
	Square startPath,endPath;
	vector<vector<Square>> squares;

public:
	Map(int number_ = -1, int size_ = 12);
	void draw();
	void afficher();
	bool getSquareStateByPostion(int xx,int yy);
	void setMap(int number_);
	Square getStartPath();
	Square getEndPath();
	int getSize();
	int getnumber();
	vector<vector<Square>> &getSquares();
	void setStartPath(Square startPath_);
	void setEndPath(Square endPath_);
	void erase();
	void save();
	int loadSize();
	bool testFile();
	void path();
	~Map();

};
