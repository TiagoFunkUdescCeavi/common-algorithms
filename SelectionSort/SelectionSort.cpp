#include <iostream>
#include <fstream>
#include <exception>

#include "../Utils/Utils.h"

using namespace std;

int main( int argc, char * argv[] ){
    Instance inst = get_instance( argv[ 1 ] );

    for( int i = 0; i < inst.size-1; i++ ){
        int menor = inst.numbers[i];
        int indice = i;
        for( int j = i+1; j < inst.size; j++ ){
            if( menor > inst.numbers[j] ){
                menor = inst.numbers[j];
                indice = j;
            }
        }
        int aux = inst.numbers[i];
        inst.numbers[ i ] = inst.numbers[ indice ];
        inst.numbers[ indice ] = aux;
    }

    print_instance( inst );
    return 0;
}