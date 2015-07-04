#include "main.hh"

using namespace std;

int main(int argc, char* argv[])
{

  Argument* arg = new Argument( argc, argv );

  string dir_name = arg->GetDirPath();

  TApplication app( "app", &argc, argv );
  gROOT->SetStyle("Plain") ;
  gStyle->SetPalette(55, 0, 1 );

  TBrowser* a = new TBrowser("Browser", "Title", arg->GetWindowWidth() ,arg->GetWindowHeight() );
  gPad->SetGridx( true );
  gPad->SetGridy( true );
  gPad->SetTicks( 1, 1 );

      
  //  cout << dir_name << " is opened" << endl;
  vector < string > vfile;
  GetROOTFiles( dir_name, vfile );

  TFile* tf[vfile.size()];
  for( unsigned int i=0; i<vfile.size(); i++ )
    {

      tf[i] = new TFile( vfile[i].c_str() , "READ" );
    }

  app.Run();
  return 0;
}

void GetROOTFiles( string dir_name, vector < string >& vfile )
{

  DIR* dp = opendir( dir_name.c_str() );
  if (dp != NULL)
    {
      struct dirent* dent;
      do
	{
	  dent = readdir( dp );
	  if ( dent != NULL )
	    {
	      string name = dent->d_name;
	      //	      cout << setw(30) << name << "\t";
	      if( 
		 name.find( ".root" )  != string::npos 
		 && name.find( "DST" ) == string::npos
		  )
		{
		  vfile.push_back( dir_name + name );
		  //		  cout << "<-- ROOT file";
		}
	      //	      cout << endl;
	    }
	} 
      while(dent!=NULL);

      closedir(dp);
    }

  sort( vfile.begin() , vfile.end() );

}
