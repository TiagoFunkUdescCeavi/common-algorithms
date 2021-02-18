#include <iostream>
#include <fstream>
#include <exception>
#include <math.h>

using namespace std;

int size = 0;

int * get_numbers( char * file ){
    ifstream f( file, ios::in );
    if( !f ){
		throw runtime_error( "Error on open file." );
	}
    
    f >> size;
    int * numbers = new int[ size ];
    for( int i = 0; i < size; i++ ){
        f >> numbers[ i ];
    }
    return numbers;
}

void print( int n, int * v ){
    for( int i = 0; i < n; i++ ){
        cout << v[ i ] << " ";
    }
    cout << endl;
}

void merge_sort( int * A, int low, int middle, int high ){
    // bool i_has_finished = false, j_has_finished = false;
    int i, j, k;
    int n1 = middle - low + 1;
    int n2 = high - middle;
    int * L = new int[ n1+1 ];
    int * R = new int[ n2+1 ];
    for( i = 0; i < n1; i++ ){
        L[ i ] = A[ low+i-1 ];
    }
    for( j = 0; j < n2; j++ ){
        R[ j ] = A[ middle+j ];
    }
    i = 0;
    j = 0;
    k = 0;
    for( k = low; k < high; k++ ){
        // if( i == n1 ) i_has_finished = true;
        // if( j == n2 ) j_has_finished = true;
        if( L[ i ] <= R[ j ] /* && !i_has_finished */ ){
            A[ k ] = L[ i ];
            i++;
        }else /* if( !j_has_finished ) */ {
            A[ k ] = R[ j ];
            j++;
        }
    }
}

void merge_sort( int * A, int p, int r ){
    if( p < r ){
        int q = floor( (p + r)/2 );
        merge_sort( A, p, q );
        merge_sort( A, q+1, r );
        merge_sort( A, p, q, r );
    }
}

int main( int argc, char * argv[] ){
    int * a = get_numbers( argv[ 1 ] );

    merge_sort( a, 0, size-1 );

    print( size, a );
    return 0;
}