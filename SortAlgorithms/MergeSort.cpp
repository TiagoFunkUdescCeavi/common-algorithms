#include "../Utils.h"

void merge( int * A, int l, int m, int r ){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int * L = new int[ n1+1 ];
    int * R = new int[ n2+1 ];

    for( i = 0; i < n1; i++ ){
        L[ i ] = A[ l+i ];
    }
    for( j = 0; j < n2; j++ ){
        R[ j ] = A[ m+j+1 ];
    }

    i = 0;
    j = 0;
    k = l;
    while( i < n1 && j < n2 ){
        if( L[ i ] <= R[ j ] ){
            A[ k ] = L[ i ];
            i++;
        }else{
            A[ k ] = R[ j ];
            j++;
        }
        k++;
    }

    while( i < n1 ){
        A[ k ] = L[ i ];
        i++;
        k++;
    }

    while( j < n2 ){
        A[ k ] = R[ j ];
        j++;
        k++;
    }
}

void merge_sort( int * arr, int l, int r ){
    if( l < r ){
        int m = l+(r-l)/2;
        merge_sort( arr, l, m );
        merge_sort( arr, m+1, r );
        merge( arr, l, m, r );
    }
}

int main( int argc, char * argv[] ){
    Int_Vector int_vec = get_int_vector( argv[ 1 ] );

    merge_sort( int_vec.numbers, 0, int_vec.size-1 );

    print_int_vector( int_vec );
    return 0;
}