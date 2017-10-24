#include "../include/WaveManager.h"

WaveManager::WaveManager(){
  monsterNo = 0;
  nbmonsters = 0;
  wave = 0;
  maxWave = 0;
  std::string str="../include/config/wave_list.txt";
  ifstream fichier (str,  ios::in);
  string ligne;
  while (!fichier.eof())
  {
    getline(fichier,ligne);
    maxWave++;
  }
  fichier.close();
}

Monster* WaveManager::getNextMonster(Map * map_){
  std::string str="../include/config/wave_list.txt";
  ifstream fichier (str,  ios::in);
  string ligne;
  for (int i = 0; i < wave; i++)
  getline(fichier,ligne);
  nbmonsters = ligne.length() / 2 + 1;
  if (monsterNo  < ligne.length()) {
    if (ligne[monsterNo] == 'S'){
      monsterNo = monsterNo + 2;
      fichier.close();
      return new StrongMonster(map_);
    }
    else if (ligne[monsterNo] == 'F'){
      monsterNo = monsterNo + 2;
      fichier.close();
      return new FastMonster(map_);
    }
    else if (ligne[monsterNo] == 'E'){
      monsterNo = monsterNo + 2;
      fichier.close();
      return new ExplosiveMonster(map_);
    }
  }
}

bool WaveManager::getnbMonsters(){
  return nbmonsters > (int)((monsterNo+1)/2);
}

int WaveManager::getWaveNumber(){
  return wave;
}
void WaveManager::incrWave(){
  wave++;
  monsterNo = 0;
  nbmonsters = 0;
}
int WaveManager::getMaxWave(){
  return maxWave-1;
}

void WaveManager::setWaveNumber(int number_){
  wave = number_;
}
