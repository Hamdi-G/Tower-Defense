#pragma once
#include "GraphicPrimitives.h"
#include "Map.h"
#include <iostream>
#include <math.h>
#include <string>


class Monster
{
protected:
	std::string label;
	float life;
	float speed;
	int coins;
	float posX, posY;
	float r,g,b;
	int travledDistance;
	Map * map;
	Monster(Map * map_);

public:
	virtual void ReceiveDamage(float damage)=0;
	virtual void draw();
	virtual void move();
	virtual float getPosX();
	virtual float getPosY();
	virtual float getLife();
	virtual float getSpeed();
	virtual int getTravled();
	virtual int getCoins();
	virtual std::string getLabel();
	virtual void setPosX(float posX_);
	virtual void setPosY(float posY_);
	virtual void setLife(float life_);
	virtual void setSpeed(float speed_);
	virtual void setColor(float r_, float g_, float b_);
	virtual ~Monster();
};
