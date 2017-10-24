#pragma once
#include "Monster.h"
#include <vector>
#include "GraphicPrimitives.h"
#include "Map.h"

class FastMonster: public Monster
{
public:
  FastMonster(Map * map);
  virtual void ReceiveDamage(float damage);
  virtual void draw();
  virtual ~FastMonster();

};
