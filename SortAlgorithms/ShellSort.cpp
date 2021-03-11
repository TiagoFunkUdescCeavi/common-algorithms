#include "../Utils.h"

using namespace std;

void shell_sort( int * v, int n ){
    int i, j, value;
    int h = 1;
    while( h < n ){
        h = 3*h+1;
    }
    while( h > 0 ){
        for( i = h; i < n; i++ ){
            value = v[ i ];
            j = i;
            while( j > h-1 && value <= v[ j-h ] ){
                v[ j ] = v[ j-h ];
                j = j-h;
            }
            v[ j ] = value;
        }
        h = h/3;
    }
}

int main( int argc, char * argv[] ){
    Int_Vector int_vec = get_int_vector( argv[ 1 ] );

    shell_sort( int_vec.numbers, int_vec.size );

    print_int_vector( int_vec );
    return 0;
}