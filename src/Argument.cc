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

      if( result == 'o' )
	{
	  Option();
	}
      if( result == 'd' )
	{
	  dir_ = optarg;
	}

      switch ( result )
	{

	case 1 :
	  {
	    width_ = atoi( optarg );
	    break;
	  }
	case 2 : 
	  {

	    height_ = atoi( optarg );
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
