#pragma once
#include "GraphicPrimitives.h"
#include "Map.h"
#include "Monster.h"
#include <iostream>


class Missile
{
public:
	Missile(float x1,float y1,float x2,float y2);
	/*void ReceiveDamage();
	void seDeplacer();
	void sexploser();*/
	void draw(float r, float g, float b);
	void move(float x ,float y);
	~Missile();
private:
	//int life;
	//int m_vitesse;
	float x1,y1,x2,y2;


};
