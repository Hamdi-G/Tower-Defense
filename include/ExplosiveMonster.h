#pragma once
#include "Monster.h"
#include <vector>
#include "GraphicPrimitives.h"
#include "Map.h"

class ExplosiveMonster: public Monster
{
public:
  ExplosiveMonster(Map * map);
  virtual void ReceiveDamage(float damage);
  virtual void draw();
  virtual ~ExplosiveMonster();

};
