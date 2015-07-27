#include "main.hh"

using namespace std;

int main(int argc, char* argv[])
{

  // argument handler
  Argument* arg = new Argument( argc, argv );

  // path to a terget directory
  string dir_name = arg->GetDirPath();

  TApplication app( "app", &argc, argv );
  gROOT->SetStyle("Plain") ;
  gStyle->SetPalette(kBird);

  TBrowser* a = new TBrowser("Browser", "TBrowser", arg->GetWindowWidth() ,arg->GetWindowHeight() );
  gPad->SetGridx( true );
  gPad->SetGridy( true );
  gPad->SetTicks( 1, 1 );

  // names of ROOT file in the target directory
  vector < string > vfile;

  if( arg->GetFilePath() == "" )
    GetROOTFiles( dir_name, vfile );
  else
    vfile.push_back( arg->GetFilePath() );

  // open ROOT files 
  TFile* tf[vfile.size()];
  for( unsigned int i=0; i<vfile.size(); i++ )
    {

      tf[i] = new TFile( vfile[i].c_str() , "READ" );
      //      a->Add(tf[i]);
    }

  TRootBrowser* imp = (TRootBrowser*)a->GetBrowserImp();
  //  imp->Connect( imp, "Refresh()", "TApplication", &app, "Terminate()" );
  imp->Connect( imp, "CloseWindow()", "TApplication", &app, "Terminate()" );

  app.Run();
  return 0;
}

void GetROOTFiles( string dir_name, vector < string >& vfile )
{

  DIR* dp = opendir( dir_name.c_str() );
  if( dp != NULL)
    {

      struct dirent* dent;

      do
	{

	  dent = readdir( dp );

	  if( dent != NULL )
	    {

	      string name = dent->d_name;
	      if( name.find( ".root" )  != string::npos && name.find( "DST" ) == string::npos && name != ".root_hist" )
		vfile.push_back( dir_name + name );
	    }
	} 
      while(dent!=NULL);

      closedir(dp);
    }

  sort( vfile.begin() , vfile.end() );
}
