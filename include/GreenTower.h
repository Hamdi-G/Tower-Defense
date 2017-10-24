#pragma once
#include <vector>
#include <iostream>
#include <math.h>
#include "Monster.h"
#include "GraphicPrimitives.h"
#include "Tower.h"

class GreenTower: public Tower
{
public:
	GreenTower(int posX = 0, int posY = 0, int level_ = 1);
	virtual void shoot(std::vector<Monster * > *monsters);
	virtual void draw(bool sample);
	virtual void upgradeLevel();
	virtual ~GreenTower();
};
