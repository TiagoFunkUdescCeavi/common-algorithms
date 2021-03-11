#include "../Utils.h"

using namespace std;

void radix_sort( int * v, int n ){
    int i;
    int * b;
    int high = v[ 0 ];
    int exp = 1;
    const int BUCKET_SIZE = 10;

    b = new int[ n ];

    for( i = 0; i < n; i++ ){
        if( v[ i ] > high ){
            high = v[ i ];
        }
    }
    while( (high / exp) > 0){
        int bucket[ BUCKET_SIZE ] = { 0 };
        for( i = 0; i < n; i++ ){
            int index = (v[i]/exp) % 10;
            bucket[ index ]++;
        }
        for( i = 1; i < BUCKET_SIZE; i++ ){
            bucket[ i ] += bucket[ i-1 ];
        }
        for( i = n-1; i >= 0; i-- ){
            int index = (v[i]/exp) % 10;
            bucket[ index ] -= 1;
            b[ bucket[ index ] ] = v[ i ];
        }
        for( i = 0; i < n; i++ ){
            v[ i ] = b[ i ];
        }
        exp *= 10;
    }
}

int main( int argc, char * argv[] ){
    Int_Vector int_vec = get_int_vector( argv[ 1 ] );

    radix_sort( int_vec.numbers, int_vec.size );

    print_int_vector( int_vec );
    return 0;
}