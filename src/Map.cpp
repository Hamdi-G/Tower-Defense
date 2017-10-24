#include "../include/Map.h"


Map::Map(int number_, int  size_):size(size_),number(number_),squares(size, vector<Square>(size)){

	//size = loadSize();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			squares[i][j] = Square(i ,j);
		}
	}
	if (number_ != -1) {
		this->erase();

		//path par defaut
		int j(0);
		std::string str="../include/Maps/Map.txt";
		str.insert(19,std::to_string(number));
		ifstream fichier (str,  ios::in);
		string ligne;
		while (!fichier.eof())
		{
			getline(fichier,ligne);
			for(int i=0;i<ligne.length();i++)
			{
				if (ligne[i] == 'd'){
					squares[i][j].setPath(true);
					startPath = squares[i][j];
				}
				if (ligne[i] == 'f'){
					squares[i][j].setPath(true);
					endPath = squares[i][j];
				}
				if (ligne[i] == '1')
				squares[i][j].setPath(true);
			}
			j++;
		}
	}
	path();
}

void Map::draw() {
	if (number != -1) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				GraphicPrimitives::drawFillRect2D(((squares[i][j].getX()) * 0.1f * (12/(float)size) )-0.6f,((squares[i][j].getY()) * 0.1f * (12/(float)size) ) - 0.6f,0.097f * (12/(float)size) ,0.097f * (12/(float)size) ,(squares[i][j].getColor()),(squares[i][j].getColor()),(squares[i][j].getColor()));
			}
		}
		//castle
		if (endPath.getX() != -1) {
			GraphicPrimitives::drawFillTower2D((endPath.getX() * 0.1f * (12/(float)size) )-0.6f+0.04,(endPath.getY() * 0.1f * (12/(float)size) )-0.6f+0.05,1,0.824, 0.412, 0.118);
			GraphicPrimitives::drawFillTower2D((endPath.getX() * 0.1f * (12/(float)size) )-0.6f+0.04,(endPath.getY() * 0.1f * (12/(float)size) )-0.6f,1,0.824, 0.412, 0.118);
			GraphicPrimitives::drawFillTower2D((endPath.getX() * 0.1f * (12/(float)size) )-0.6f,(endPath.getY() * 0.1f * (12/(float)size) )-0.6f,1,0.824, 0.412, 0.118);
			GraphicPrimitives::drawFillTower2D((endPath.getX() * 0.1f * (12/(float)size) )-0.6f+0.08,(endPath.getY() * 0.1f * (12/(float)size) )-0.6f,1,0.824, 0.412, 0.118);
		}
	}
}
void Map::afficher(){
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (squares[j][i].getPath() == true) {
				std::cout << "true" ;
			} else {
				std::cout << "false";
			}
		}
		std::cout << std::endl;
	}
}

bool Map::getSquareStateByPostion(int xx,int yy){
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if((squares[i][j].getX() == xx) && (squares[i][j].getY() == yy)){
				return (squares[i][j].getPath());
			}
		}
	}
}

void Map::setMap(int number_){
	*this = Map(number_);
}

void Map::erase(){
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			squares[i][j].setPath(false);
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			squares[i][j].setEmpty(true);
		}
	}
	startPath = Square(-1,-1);
	endPath = Square(-1,-1);
}
void Map::save(){
	std::string const str="../include/Maps/Map5.txt";
	ofstream monFlux(str.c_str());

	if(monFlux)
	{
		for (int j = 0; j < size; j++) {
			for (int i = 0; i < size; i++) {
				if (squares[i][j] == startPath)
				monFlux << 'd';
				else if (squares[i][j] == endPath)
				monFlux << 'f';
				else if (squares[i][j].getPath())
				monFlux << '1';
				else
				monFlux << '0';
			}
			monFlux << "" << endl;
		}

	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
	}
	this->setMap(5);
}
Square Map::getStartPath(){
	return startPath;
}
Square Map::getEndPath(){
	return  endPath;
}

vector<vector<Square>> &Map::getSquares(){
	return squares;
}

void Map::setStartPath(Square startPath_){
	startPath = startPath_;
}
void Map::setEndPath(Square endPath_){
	endPath = endPath_;
}

int Map::getSize(){
	return size;
}

int Map::getnumber(){
	return number;
}

int Map::loadSize(){
	std::string str="../include/Maps/Map.txt";
	str.insert(19,std::to_string(number));
	ifstream fichier1 (str,  ios::in);
	string ligne;
	int i = 0;
	while (!fichier1.eof()){
		getline(fichier1,ligne);
		i++;
	}
	fichier1.close();
	return i-1;
}
bool Map::testFile(){

	std::string str="../include/Maps/Map.txt";
	str.insert(19,std::to_string(number));
	ifstream fichier2 (str,  ios::in);
	string ligne;
	int a,b;
	while (!fichier2.eof()){
		getline(fichier2,ligne);
		if (loadSize() == ligne.length()) {
			return false;
		}
		for (int i = 0; i < ligne.length(); i++) {
			if (ligne[i] == 'd') {
				a++;
			}else if (ligne[i] == 'f') {
				b++;
			}
		}
		if (a > 1 || b > 1 || a == 0 || b == 0) {
			return false;
		}
	}
	fichier2.close();
	return true;
}
void Map::path(){
	std::string const str="../include/Maps/shemin.txt";
	ofstream monFlux2(str.c_str());
	if(monFlux2)
	{
		for (int i = 1; i < size-1; i++) {
			for (int j = 1; j < size-1; j++) {
				if (squares[i][j].getPath()) {
					if (squares[i-1][j].getPath() && squares[i][j-1].getPath()) {
						monFlux2 << '(' << i << ',' << j << ')' << endl;
					}
					if (squares[i+1][j].getPath() && squares[i][j+1].getPath()) {
						monFlux2 << '(' << i << ',' << j << ')' << endl;
					}
					if (squares[i][j-1].getPath() && squares[i-1][j].getPath()) {
						monFlux2 << '(' << i << ',' << j << ')' << endl;
					}
					if (squares[i][j+1].getPath() && squares[i+1][j].getPath()) {
						monFlux2 << '(' << i << ',' << j << ')' << endl;
					}
				}
			}
		}
	}	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
	}
}

Map::~Map()
{
	squares.clear();
}
