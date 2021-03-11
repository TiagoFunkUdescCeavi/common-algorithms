#include "../Utils.h"

using namespace std;

void quick_sort( int * v, int b, int n ){
    int i, j, pivo, aux;
    i = b;
    j = n-1;
    pivo = v[ (b+n)/2 ];
    while( i <= j ){
        while( v[ i ] < pivo && i < n ) i++;
        while( v[ j ] > pivo && j > b ) j--;
        if( i <= j ){
            swap( v, i, j );
            i++;
            j--;
        }
    }
    if( j > b ) quick_sort( v, b, j+1 );
    if( i < n ) quick_sort( v, i, n );
}

int main( int argc, char * argv[] ){
    Int_Vector int_vec = get_int_vector( argv[ 1 ] );

    quick_sort( int_vec.numbers, 0, int_vec.size );

    print_int_vector( int_vec );
    return 0;
}