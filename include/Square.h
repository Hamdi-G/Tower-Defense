#pragma once
#include <vector>

class Square {

private:

	int x, y;
	bool path;
	bool empty;
	float r,g,b;

public:

	Square();
	Square(int x_,int y_,bool path_ = false);
	void setPath(bool path_);
	void setEmpty(bool empty_);
	bool getPath();
	bool getEmpty();
	int getX();
	int getY();
	float getColor();
	void setColor(bool path_);
	friend bool operator==(Square const& a, Square const& b);
	bool existIn(std::vector<Square> &squares_);
	bool existInn(std::vector<Square> &squares_);


};
