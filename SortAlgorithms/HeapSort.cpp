#include "../Utils.h"

using namespace std;

void heap_sort( int * v, int n ){
     int i = n/2, father, children, t;
     while( true ){
         if( i > 0 ){
             i--;
             t = v[ i ];
         } else {
             n--;
             if( n <= 0 ) return;
             t = v[ n ];
             v[ n ] = v[ 0 ];
         }
         father = i;
         children = i * 2 + 1;
         while( children < n ){
             if( (children+1 < n) && (v[ children+1 ] > v[ children ]) ){
                 children++;
             }
             if( v[ children ] > t ){
                 v[ father ] = v[ children ];
                 father = children;
                 children = father * 2 + 1;
             }else {
                 break;
             }
         }
         v[ father ] = t;
     }
 }

int main( int argc, char * argv[] ){
    Int_Vector int_vec = get_int_vector( argv[ 1 ] );

    heap_sort( int_vec.numbers, int_vec.size );

    print_int_vector( int_vec );
    return 0;
}