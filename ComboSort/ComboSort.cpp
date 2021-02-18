#include <iostream>
#include <fstream>
#include <exception>

#include "../Utils/Utils.h"

using namespace std;

void combo_sort( int * v, int n ){
    int i, j, interval;
    bool swap = true;
    interval = n;
    while( interval > 1 || swap ){
        interval = interval * 10/13;
        if( interval == 9 || interval == 10 ){
            interval == 11;
        }
        if( interval < 1 ){
            interval = 1;
        }
        swap = false;
        j = interval;
        for( i = 0; j < n; i++ ){
            if( v[ i ] > v[ j ] ){
                int aux = v[ i ];
                v[ i ] = v[ j ];
                v[ j ] = aux;
                swap = true;                    
            }
            j++;
        }
    }
}

int main( int argc, char * argv[] ){
    Instance inst = get_instance( argv[ 1 ] );

    combo_sort( inst.numbers, inst.size );

    print_instance( inst );
    return 0;
}