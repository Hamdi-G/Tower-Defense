#include "../include/Game.h"


Game::Game():waveManager(){
  loadConfig();
  started = false;
  over = false;
  t1 = new BlueTower(0,15);
  t2 = new GreenTower(4,15);
  t3 = new RedTower(8,15);
  buttons.push_back(new Button(-0.3f,-0.6f,0.17f,0.1f,"New"));
  buttons.push_back(new Button(0.1f,-0.6f,0.18f,0.1f,"Load"));
  consol.write(".                                                      -Developed by Hamdi Gazzah-");
  x2=-0.5f;
  vx2=-0.02f;
}

void Game::restart(){
  for (int i = 0; i < buttons.size(); i++) {
    delete (buttons)[i];
    buttons.erase(buttons.begin()+i);
  }
  for (int i = 0; i < towers.size(); i++) {
    delete (towers)[i];
    towers.erase(towers.begin()+i);
  }
  for (int i = 0; i < monsters.size(); i++) {
    delete (monsters)[i];
    monsters.erase(monsters.begin()+i);
  }
  map.setMap(-1);
  *this = Game();
}

void Game::save(){
  std::string const str="../include/config/saved_game.txt";
  ofstream monFlux(str.c_str());

  if(monFlux)
  {
    monFlux << map.getnumber() << endl;
    monFlux << coins << endl;
    monFlux << life << endl;
    monFlux << waveManager.getWaveNumber() << endl;
    for (int i = 0; i < towers.size(); i++) {
      monFlux << towers[i]->getType() << '(';
      if (towers[i]->getPosX() < 10) {
        monFlux << '0' << towers[i]->getPosX() << ',';
      } else {
        monFlux << towers[i]->getPosX() / 10 <<  towers[i]->getPosX() % 10 << ',';
      }
      if (towers[i]->getPosY() < 10) {
        monFlux << '0' << towers[i]->getPosY() << ')';
      } else {
        monFlux << towers[i]->getPosY() / 10 <<  towers[i]->getPosY() % 10 << ')';
      }
      monFlux << "level " << towers[i]->getLevel() << endl;
    }
  }
  else
  {
    cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
  }

}

void Game::load(){
  std::string const str="../include/config/saved_game.txt";
  ifstream fichier (str,  ios::in); // ios::in pour la lecture, tu n'as pas besoin de binary map tu lis un fichier texte et pas un fichier binaire
  string ligne;
  getline(fichier,ligne);
  map.setMap(atoi(ligne.c_str()));

  getline(fichier,ligne);
  coins = atoi(ligne.c_str());

  getline(fichier,ligne);
  life = atoi(ligne.c_str());

  getline(fichier,ligne);
  waveManager.setWaveNumber(atoi(ligne.c_str()));
  while (!fichier.eof()) //eof est le flag de fin de fichier il se met a 1 quand tu as atteint la fin du fichier.
  {
    getline(fichier,ligne); // tu recupere une ligne de ton fichier sous la forme d'un string
    switch (ligne[0]) {
      case 'B':
      towers.push_back(new BlueTower(((ligne[2] - 48) * 10) + (ligne[3] - 48),((ligne[5] - 48) * 10) + (ligne[6] - 48),ligne[14] - 48));
      (map.getSquares())[((ligne[2] - 48) * 10) + (ligne[3] - 48)][((ligne[5] - 48) * 10) + (ligne[6] - 48)].setEmpty(false);
      break;
      case 'G':
      towers.push_back(new GreenTower(((ligne[2] - 48) * 10) + (ligne[3] - 48),((ligne[5] - 48) * 10) + (ligne[6] - 48),ligne[14] - 48));
      (map.getSquares())[((ligne[2] - 48) * 10) + (ligne[3] - 48)][((ligne[5] - 48) * 10) + (ligne[6] - 48)].setEmpty(false);
      break;
      case 'R':
      towers.push_back(new RedTower(((ligne[2] - 48) * 10) + (ligne[3] - 48),((ligne[5] - 48) * 10) + (ligne[6] - 48),ligne[14] - 48));
      (map.getSquares())[((ligne[2] - 48) * 10) + (ligne[3] - 48)][((ligne[5] - 48) * 10) + (ligne[6] - 48)].setEmpty(false);
      break;
    }
  }
}

void Game::loadConfig(){
  std::string const str="../include/config/configuration.txt";
  ifstream fichier (str,  ios::in); // ios::in pour la lecture, tu n'as pas besoin de binary map tu lis un fichier texte et pas un fichier binaire
  string ligne;
  int i,j;
  coins = 0;
  getline(fichier,ligne);
  getline(fichier,ligne);
  for (j = 0,i = ligne.length()-1 ; i > 13; i--, j++) {
    coins += (ligne[i] - 48) * ((int)pow(10,j));
  }
  life = 0;
  getline(fichier,ligne);
  for (j = 0,i = ligne.length()-1 ; i > 13; i--, j++) {
    life += (ligne[i] - 48) * ((int)pow(10,j));
  }
}

void Game::addCoins(int coins_){
  coins += coins_;
}

void Game::removeCoins(int coins_){
  coins -= coins_;
}

int Game::getCoins(){
  return coins;
}

int Game::getLife(){
  return life;
}

void Game::decrLife(){
  life--;
}

bool Game::getStarted(){
  return started;
}

bool Game::setStarted(){
  started = true;
}

WaveManager &Game::getWM(){
  return waveManager;
}

Map &Game::getMap(){
  return map;
}

Consol &Game::getConsol(){
  return consol;
}

std::vector<Tower *> &Game::getTowers(){
  return towers;
}

std::vector<Monster *> &Game::getMonsters(){
  return monsters;
}

std::vector<Button *> &Game::getButtons(){
  return buttons;
}

void Game::drawComponent(){
  if (!over) {
    //towers samples
    t1->draw(true);
    t2->draw(true);
    t3->draw(true);

    // coins
    std::string coins_s = std::to_string(coins);
    coins_s = "Coins : " + coins_s + "$";
    char *cstr = new char[coins_s.length() + 1];
    strcpy(cstr, coins_s.c_str());
    GraphicPrimitives::drawText2D(cstr,-0.9,-0.8,0.0,0.0,0.0);
    delete [] cstr;

    //life
    std::string life_s = std::to_string(life);
    life_s = "Life : " + life_s + "x";
    char *cstr2 = new char[life_s.length() + 1];
    strcpy(cstr2, life_s.c_str());
    GraphicPrimitives::drawText2D(cstr2,0.7,-0.8,0.0,0.0,0.0);
    delete [] cstr2;

    //wave
    std::string wave_s = std::to_string(waveManager.getWaveNumber());
    std::string mwave_s = std::to_string(waveManager.getMaxWave());
    wave_s = "Wave : " + wave_s + " / " + mwave_s;
    char *cstr3 = new char[wave_s.length() + 1];
    strcpy(cstr3, wave_s.c_str());
    GraphicPrimitives::drawText2D(cstr3,0.65,0.8,0.0,0.0,0.0);
    delete [] cstr3;
  }
}

void Game::drawLogo(){
  if (consol.getString()[0] == '.') {
    GraphicPrimitives::drawFillTower2D(-0.5,-0.2,10,0.502, 0.502, 0.502);
    GraphicPrimitives::drawLine2D(0.0f,0.3f,x2,-0.3f,1.0f,0.0f,1.0f);
    x2 += vx2;
    if (x2 > 0.9f || x2 < -0.9f) {
      vx2 = -vx2;
      x2 += vx2;
    }
    std::string wave_s = "Tower Defense v1.0";
    char *cstr3 = new char[wave_s.length() + 1];
    strcpy(cstr3, wave_s.c_str());
    GraphicPrimitives::drawText2D(cstr3,-0.25,-0.35,0.0,0.0,0.0,GLUT_BITMAP_TIMES_ROMAN_24);
    delete [] cstr3;
  }
}
