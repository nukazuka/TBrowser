#include "Argument.hh"
using namespace std;

Argument::Argument(int argc, char* argv[] ){
  struct option Loptions[] = 
    {
      {"dir"    , required_argument, 0,  0  },
      {"option" , no_argument      , 0, 'o' },
      {"width"  , required_argument, 0,  1  },
      {"height" , required_argument, 0,  2  },
      {"file"   , required_argument, 0,  3  },
      {0, 0, 0, 0}
    };
  
  dir_ = ".";
  file_ = "";
  width_ = 1200.0;
  height_ = 800.0;

  int index = 0;
  int result = 0;

  while ( result != -1 )
    { 
      result = getopt_long( argc, argv, "o", Loptions, &index );

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

      switch ( result )
	{

	case 0:
	  {
	    dir_ = content;
	    break;
	  }
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
	case 3 : 
	  {

	    file_ = content;
	    break;
	  }
	}


    }

  if( dir_.substr( dir_.size()-1, 1 ) != "/" )
    dir_ = dir_ + "/";

}

void Argument::Option(){

  int width = 13;
  cout << "--OPTIONS-------------------------------" << endl;
  cout << "|" << setw(width) << "--option, -o" << " : View all options"    << endl;
  cout << "|" << setw(width) << "--file"       << " : Specify only 1 file" << endl;
  cout << "|" << setw(width) << "--dir"        << " : Specify directory"   << endl;
  cout << "|" << setw(width) << "--height"     << " : Height of window"    << endl;
  cout << "|" << setw(width) << "--width"      << " : Width of window"     << endl;
  cout << "----------------------------------------" << endl;

  exit(1);
}
