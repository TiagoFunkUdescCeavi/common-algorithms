#include "../Utils.h"

using namespace std;

void selection_sort( int * v, int n ){
    for( int i = 0; i < n-1; i++ ){
        int menor = v[i];
        int indice = i;
        for( int j = i+1; j < n; j++ ){
            if( menor > v[j] ){
                menor = v[j];
                indice = j;
            }
        }
        int aux = v[i];
        v[ i ] = v[ indice ];
        v[ indice ] = aux;
    }
}

int main( int argc, char * argv[] ){
    Int_Vector int_vec = get_int_vector( argv[ 1 ] );

    selection_sort( int_vec.numbers, int_vec.size );

    print_int_vector( int_vec );
    return 0;
}