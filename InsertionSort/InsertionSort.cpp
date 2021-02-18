#include <iostream>
#include <fstream>
#include <exception>

#include "../Utils/Utils.h"

using namespace std;

int main( int argc, char * argv[] ){
    Instance inst = get_instance( argv[ 1 ] );

    for( int i = 1; i < inst.size; i++ ){
        int key = inst.numbers[ i ];
        int j = i-1;
        while( j >= 0 && inst.numbers[ j ] > key ){
            inst.numbers[ j+1 ] = inst.numbers[ j ];
            j= j-1;
        }
        inst.numbers[ j+1 ] = key;
    }

    print_instance( inst );
    return 0;
}