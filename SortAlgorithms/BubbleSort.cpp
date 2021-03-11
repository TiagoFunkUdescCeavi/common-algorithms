#include "../Utils.h"

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
    Int_Vector int_vec = get_int_vector( argv[ 1 ] );

    bubble_sort( int_vec.numbers, int_vec.size );

    print_int_vector( int_vec );
    return 0;
}