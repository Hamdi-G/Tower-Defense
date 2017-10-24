#include "../include/Consol.h"

Consol::Consol(){}

void Consol::draw(){

  GraphicPrimitives::drawOutlinedRect2D(-1.0f,-1.0f,2.0f,0.1f,0.0,0.0,0.0);
  char *cstr = new char[str.length() + 1];
  strcpy(cstr, str.c_str());
  GraphicPrimitives::drawText2D(cstr,-0.97f,-0.97f,0.0,0.0,0.0);
}

void Consol::write(std::string str_){
  str = str_;
}

std::string &Consol::getString(){
  return str;
}
