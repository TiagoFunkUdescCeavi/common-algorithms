#include "../Utils.h"

using namespace std;

void insertion_sort( int * v, int n ){
    for( int i = 1; i < n; i++ ){
        int key = v[ i ];
        int j = i-1;
        while( j >= 0 && v[ j ] > key ){
            v[ j+1 ] = v[ j ];
            j= j-1;
        }
        v[ j+1 ] = key;
    }
}

int main( int argc, char * argv[] ){
    Int_Vector int_vec = get_int_vector( argv[ 1 ] );

    insertion_sort( int_vec.numbers, int_vec.size );

    print_int_vector( int_vec );
    return 0;
}