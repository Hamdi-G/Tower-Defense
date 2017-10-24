#pragma once
#include <vector>
#include "Monster.h"
#include "Missile.h"
#include <math.h>
class Tower
{
protected:
	std::string label;
	float power;
	float ShootingDistance;
	int posX, posY;
	float r,g,b;
	int level;
	int price;
	bool box;
	Missile *missile;
	Tower(int posX_, int posY_);

public:
	virtual void shoot(std::vector<Monster * > *monsters) = 0;
  virtual void draw(bool sample = false);
	virtual int getPosX();
	virtual int getPosY();
	virtual float getPower();
	virtual int getLevel();
	virtual int getPrice();
	virtual bool getBox();
	virtual char getType();
	virtual void setPosX(int posX_);
	virtual void setPosY(int posY_);
	virtual void setPower(float power_);
	virtual void upgradeLevel();
	virtual void upgradePrice();
	virtual void setBox(bool box_);
	virtual void setColor(float r_, float g_, float b_);
	virtual ~Tower();
};
