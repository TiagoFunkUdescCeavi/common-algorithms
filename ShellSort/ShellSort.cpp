#include "../Utils/Utils.h"

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
    Instance inst = get_instance( argv[ 1 ] );

    shell_sort( inst.numbers, inst.size );

    print_instance( inst );
    return 0;
}