#include <iostream>
#include <fstream>
#include <exception>

#include "../Utils/Utils.h"

using namespace std;

void bubble_sort( int * v, int n ){
    bool swap;
    do{
        swap = false;
        for( int i = 0; i < n; i++ ){
            if( v[ i ] > v[ i+1 ] ){
                int aux = v[ i ];
                v[ i ] = v[ i+1 ];
                v[ i+1 ] = aux;
                swap = true;
            }
        }
    }while( swap );
}

int main( int argc, char * argv[] ){
    Instance inst = get_instance( argv[ 1 ] );

    bubble_sort( inst.numbers, inst.size );

    print_instance( inst );
    return 0;
}