#pragma once
#include <vector>
#include "Monster.h"
#include "GraphicPrimitives.h"
#include "Tower.h"
#include <iostream>
#include <math.h>

class RedTower: public Tower
{
private:
	Missile *missile2;
public:
	RedTower(int posX = 0, int posY = 0, int level_ = 1);
	virtual void shoot(std::vector<Monster * > *monsters);
	virtual void draw(bool sample);
	virtual void upgradeLevel();
	virtual ~RedTower();
};
