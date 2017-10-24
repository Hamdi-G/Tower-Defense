#pragma once
#include "Map.h"
#include <iostream>
#include <fstream>
#include "Monster.h"
#include "StrongMonster.h"
#include "FastMonster.h"
#include "ExplosiveMonster.h"

class WaveManager {
private:
  int monsterNo;
  int nbmonsters;
  int wave;
  int maxWave;

public:
    WaveManager();
    Monster* getNextMonster(Map * map_);
    bool getnbMonsters();
    int getWaveNumber();
    void incrWave();
    int getMaxWave();
    void setWaveNumber(int number_);

};
