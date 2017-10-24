#include "../include/Square.h"

Square::Square() {}
Square::Square(int x_,int y_,bool path_):x(x_),y(y_),path(path_),empty(true){}
void Square::setPath(bool path_){
  path=path_;
  setColor(path);

}
void Square::setEmpty(bool empty_){
  empty=empty_;

}

bool Square::getPath(){
  return path;
}
bool Square::getEmpty(){
  return empty;
}

int Square::getX(){
  return x;
}
int Square::getY(){
  return y;
}
float Square::getColor(){
  if (path == true) {
    return 0.8f;
  } else {
    return 0.6f;
  }
}
void Square::setColor(bool path_)
{
  if (path == true) {
    r= 0.8f;
    b= 0.8f;
    g= 0.8f;
  } else {
    r= 0.6f;
    b= 0.6f;
    g= 0.6f;
  }
}

bool operator==(Square const& a, Square const& b)
{
    if (a.x == b.x && a.y == b.y)
        return true;
    else
        return false;
}

bool Square::existIn(std::vector<Square> &squares_){
  int k(0);
  for (int i = 0; i < squares_.size()-1; i++) {
    if (squares_[i] == *this) {
      k++;
    }
  }
  return k == 1;
}
