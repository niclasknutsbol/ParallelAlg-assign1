#include <iostream>
#include <vector>
#include "mcbsp.hpp"
#include <cmath>

using namespace std;

void prime_sieve() {
   bsp_begin(1);   //Start BSP with 1 core only

   unsigned int bound;
   unsigned int n_print;
   cin >> bound;
   cin >> n_print;

   vector<bool> v(bound ,true);
   v.at(0) = v.at(1) = false;
   for( unsigned int p = 2; p <= sqrt( v.size() ); ++p )
   {
      for( unsigned int i = 2*p; i < v.size(); i = i + p )
      {
         v.at(i) = false;
      }
   }

   vector<unsigned> result(n_print);
   unsigned cnt = 0;
   unsigned int i = bound - 1;
   while( cnt != n_print) {
      if( (v.at(i) == true) ) {
         result.at(cnt++) = i;
      }
      --i;
   }

   for( int i = result.size() -1; i >= 0 ; --i ) {
      cout << result.at(i) << endl;
   }

   bsp_end();
}


int main( int argc, char *argv[])
{
   bsp_init(prime_sieve, argc, argv);
   prime_sieve();

   return 0;
}
