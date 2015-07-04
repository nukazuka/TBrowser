#ifndef Arguemnt_hh
#define Arguemnt_hh

#include <iostream>
#include <cstdlib>
#include <getopt.h>

using namespace std;
class Argument{
private:

  //  static struct option Loptions[7];
  static struct option Loptions[7];
  string dir_;
  double width_;
  double height_;

public:

  Argument(int argc, char* argv[] );
  ~Argument();
  string GetDirPath(){ return dir_;};
  double GetWindowWidth(){ return width_;};
  double GetWindowHeight(){ return height_;};
  void   MakeOptionList();
  void   Option();

};
#endif
