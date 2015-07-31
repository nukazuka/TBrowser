#ifndef MAIN_HH
#define MAIN_HH

#include "Argument.hh"
#include "Style.hh"

#include "TApplication.h"
#include "TBrowser.h"
#include "TPad.h"
#include "TROOT.h"
#include "TFile.h"
#include "TStyle.h"
#include "TRootBrowser.h"

#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main( int argc, char* argv[] );
string GetCurrentDirName();
void GetROOTFiles( string dir_name, vector < string >& vfile );


#endif
