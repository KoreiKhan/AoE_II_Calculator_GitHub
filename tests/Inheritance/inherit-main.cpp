#include <string>
#include <iostream>
#include "Panda.h"
#include "Tiger.h"

using namespace std;

int main()
{
  string pandanames[] = { "Wao","Dao","Ninja" } ;
  string tigernames[] = { "Bob","Suzie","Henry" } ;

  string hungry_state;

  for ( int i = 0 ; i < 3 ; i++ )
    {
      Panda p(pandanames[i],i,true);	 // initialised
      p.eat(i+4);
      p.play(16);
      if (p.is_hungry())
	hungry_state = "hungry";
      else
	hungry_state = "not hungry";
      cout << "I am " << p.get_name() << endl << 
	"I am " << hungry_state << endl;
      cout << "I am noisy!" << endl;
      p.make_sound(5);

      Tiger t(tigernames[i],i);	 	// initialised
      t.play(7) ;
      if (t.is_hungry())
	hungry_state = "hungry";
      else
	hungry_state = "not hungry";
      cout << "I am " << t.get_name() << endl << 
	"I am " << hungry_state << endl;
      cout << "I'm going hunting" << endl;
      t.hunt() ;
      cout << "I am noisy!" << endl;
      t.make_sound(2) ;
    }
}
