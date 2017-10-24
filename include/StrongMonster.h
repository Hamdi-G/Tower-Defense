#pragma once
#include "Monster.h"
#include <vector>
#include "GraphicPrimitives.h"
#include "Map.h"

class StrongMonster: public Monster
{
public:
  StrongMonster(Map * map);
  virtual void ReceiveDamage(float damage);
  virtual ~StrongMonster();

};
