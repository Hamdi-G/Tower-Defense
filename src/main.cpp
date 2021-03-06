/*
* Copyright (C) 2016 Guillaume Perez
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include "../include/Engine.h"
#include "../include/Game.h"
#include <chrono>
#include <thread>
#include "../include/MyGraphicEngine.h"
#include "../include/MyControlEngine.h"
#include "../include/MyGameEngine.h"

int main(int argc, char * argv[])
{
  Engine e(argc,argv);
  Game  game;
  GraphicEngine * ge = new MyGraphicEngine(&game,&game.getConsol(),&game.getMap(),&game.getTowers(),&game.getMonsters(),&game.getButtons());
  GameEngine * gme = new MyGameEngine(&game,&game.getConsol(),&game.getMap(),&game.getMonsters(),&game.getTowers(),&game.getButtons());
  ControlEngine * ce = new MyControlEngine(&game,&game.getConsol(),&game.getMap(),&game.getTowers(),&game.getMonsters(),&game.getButtons());
  e.setGraphicEngine(ge);
  e.setGameEngine(gme);
  e.setControlEngine(ce);
  e.start();
  game.getMap().~Map();
  return 0;
}
