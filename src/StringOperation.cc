#include "StringOperation.hh"

using namespace std;

string Subtraction( string s1, string s2 )
{

  istringstream is1(s1);
  istringstream is2(s2);

  int num1, num2;
  is1 >> num1;
  is2 >> num2;
  int result = num1 - num2;

  stringstream ssrtn;
  ssrtn << result;
  return ssrtn.str();
}

int String2Int( string st )
{

  istringstream iss(st);
  int num;
  iss >> num;

  return num;
}

string Replace( string word, string old_key, string new_key )
{

  string rtn = word;

  unsigned int pos = 0;
  unsigned int length = old_key.length();

  if( word == "" )
    return "";

  if( word.length() < length  )
      return word;

  for( unsigned int i=0; i<rtn.length(); i++, pos++ )
    {

      if( pos > rtn.length() )
	break;

      string target = rtn.substr( pos , length );

      if( target == old_key )
	{
	  rtn.replace( pos, length, new_key );
	  pos += new_key.size();

	}
    }

  cout << "===> "  << rtn << endl;
  return rtn;
}

