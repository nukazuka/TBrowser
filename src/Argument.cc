#include "Argument.hh"
using namespace std;

Argument::Argument(int argc, char* argv[] ){
  struct option Loptions[] = 
    {
      {"dir"    , required_argument, 0, 'd'},
      {"option" , no_argument      , 0, 'o'},
      {"width"  , required_argument, 0, 1},
      {"height" , required_argument, 0, 2},
      {0, 0, 0, 0}
    };
  
  dir_ = ".";
  width_ = 1200.0;
  height_ = 800.0;

  int index = 0;
  int result = 0;

  while(result != -1)
    { 
      result = getopt_long( argc, argv, "dow", Loptions, &index );

      string content = "";

      if( optarg != NULL )
	content = optarg;

      if( content.find("~") != string::npos )
	{

	  string home_dir = getenv( "HOME" );
	  content = Replace( content , "~", home_dir );
	}

      if( result == 'o' )
	{
	  Option();
	}
      if( result == 'd' )
	{
	  dir_ = content;
	}

      switch ( result )
	{

	case 1 :
	  {
	    width_ = String2Int( content );
	    break;
	  }
	case 2 : 
	  {

	    height_ = String2Int( content );
	    break;
	  }
	}


    }

  if( dir_.substr( dir_.size()-1, 1 ) != "/" )
    dir_ = dir_ + "/";

}

void Argument::Option(){

  cout << "--OPTIONS--------------------------------------" << endl;
  cout << "  --dir, -d \t Specify directory" << endl;
  cout << "  --option -o\t View all options" << endl;
  cout << "  --height \t Height of window" << endl;
  cout << "  --width  \t Width of window" << endl;
  cout << "-----------------------------------------------" << endl;

  exit(1);
}
