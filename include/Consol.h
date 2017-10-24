#pragma once
#include <string>
#include "GraphicPrimitives.h"

class Consol{
public:
  Consol();
  void draw();
  void write(std::string str_);
  std::string &getString();
private:
  std::string str;
};
