#include "../Utils.h"

using namespace std;

void gnome_sort( int * v, int s ){
    int i = 1;
    while( i < s ){
        if( i == 0 || v[ i-1 ] <= v[ i ] ){
            i++;
        }else{
            int a = v[ i-1 ];
            v[ i-1 ] = v[ i ];
            v[ i ] = a;
            i--;
        }
    }
}

int main( int argc, char * argv[] ){
    Int_Vector int_vec = get_int_vector( argv[ 1 ] );

    gnome_sort( int_vec.numbers, int_vec.size );

    print_int_vector( int_vec );
    return 0;
}