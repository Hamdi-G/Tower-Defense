#pragma once
#include "Map.h"
#include "Monster.h"
#include "StrongMonster.h"
#include "FastMonster.h"
#include "ExplosiveMonster.h"
#include "Missile.h"
#include "Tower.h"
#include "BlueTower.h"
#include "GreenTower.h"
#include "RedTower.h"
#include "Engine.h"
#include <chrono>
#include <thread>
#include "Button.h"
#include "Consol.h"
#include "WaveManager.h"
#include <iostream>
#include <fstream>
#include <math.h>

class Game {


public:
  Game();
  void save();
  void load();
  void loadConfig();
  void restart();
  void addCoins(int coins_);
  void removeCoins(int coins_);
  int getCoins();
  int getLife();
  bool getStarted();
  WaveManager &getWM();
  Map &getMap();
  Consol &getConsol();
  std::vector<Tower *> &getTowers();
  std::vector<Monster *> &getMonsters();
  std::vector<Button *> &getButtons();
  bool setStarted();
  void decrLife();
  void drawComponent();
  void drawLogo();

private:
  bool started;
  bool over;
  int coins;
  int life;
  BlueTower* t1;
  GreenTower* t2;
  RedTower* t3;
  WaveManager waveManager;
  Map map;
  Consol consol;
  std::vector<Tower *> towers;
  std::vector<Monster *> monsters;
  std::vector<Button *> buttons;
  float x2,vx2;





};
