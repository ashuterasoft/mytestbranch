#include <iostream>
#include "mystring.h"

void foo( myString& s ); 
void bar( myString  s ); 

int main(){
  
  // construction and initialization

  myString a = "Hello ";
  myString b = a;
  myString c;

  cout << a << b << c << endl;

  cout << "------------------------------------------" << endl; 

  // value swap

  myString u = "123";
  myString v = "class";
  
  c = u;
  u = v;
  v = c;

  cout << u << v << c << endl;

  cout << "------------------------------------------" << endl; 

  // creating a few temporaries and testing +

  myString w = a + u;

  cout << w << endl; 

  cout << myString( "Beam me up" ) + myString( ", Scotty!") << endl;

  cout << "------------------------------------------" << endl; 

  // a miracle: although operator= is defined only for another myString,
  // the following line has the same effect as 
  //                                           a = myString( "Hi ");
  // Notice that a temporary is contsructed and then destroyed.
  // Lesson: C++ uses your constructor to construct objects as it sees fit.  

  a = "Hi ";

  cout << a << b << endl;

  cout << "------------------------------------------" << endl; 

  // Copy contructor is also used when passing parameters to functions
  // by value (but not by reference)

  myString x = "i am given to foo"; 
  myString y = "i am given to bar"; 

  foo( x );  

  cout << "And now x is: " << x << endl;

  bar( y );                 // notice the call to the copy constr.

  cout << "And now y is: " << y << endl; 

  cout << "------------------------------------------" << endl; 

  // check operator[]

  myString t = "hello old friend.";
  t[0] = 'H';
  t[6] = 'O';
  t[10] = 'F';

  cout << t << endl;

  cout << "------------------------------------------" << endl; 

  return 0;  // return 0 to signal normal completion to the OS
}
  
// both foo and bar attempt to clobber the string. See which one succeeds.

void foo( myString& s ){
  s = "FOO was here!";
}

void bar( myString s ){
  s = "BAR was here!";
}

//----------------------------------------------------------------------
//
//  Output of running  mystring-test  .
// 
//----------------------------------------------------------------------
/*

  myString( char * ) constr.
  myString copy const.
  myString default constr.
Hello Hello 
------------------------------------------
  myString( char * ) constr.
  myString( char * ) constr.
  myString::operator=
  myString::operator=
  myString::operator=
class123123
------------------------------------------
  myString default constr.
  myString copy const.
  myString destr.
Hello class
  myString( char * ) constr.
  myString( char * ) constr.
  myString default constr.
  myString copy const.
  myString destr.
Beam me up, Scotty!
  myString destr.
  myString destr.
  myString destr.
------------------------------------------
  myString( char * ) constr.
  myString::operator=
  myString destr.
Hi Hello 
------------------------------------------
  myString( char * ) constr.
  myString( char * ) constr.
  myString( char * ) constr.
  myString::operator=
  myString destr.
And now x is: FOO was here!
  myString copy const.
  myString( char * ) constr.
  myString::operator=
  myString destr.
  myString destr.
And now y is: i am given to bar
------------------------------------------
  myString( char * ) constr.
Hello Old Friend.
------------------------------------------
  myString destr.
  myString destr.
  myString destr.
  myString destr.
  myString destr.
  myString destr.
  myString destr.
  myString destr.
  myString destr.

*/
