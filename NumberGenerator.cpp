#include <iostream>
#include <cstdlib>
#include <fstream>
#include <exception>

using namespace std;

#define POS_SEED 1
#define POS_SIZE 2
#define POS_FILE 3

int main( int argc, char * argv[] ){
    int seed = stoi( argv[ POS_SEED ] );
    int size = stoi( argv[ POS_SIZE ] );
    char * file = argv[ POS_FILE ];

    srand( seed );

    int * numbers = new int[ size ];
    for( int i = 0; i < size; i++ ){
        numbers[ i ] = rand() % 1000;
    }

    fstream f( file, ios::out );
    if( !f ){
        throw runtime_error( "Error on open file to write."  );
    }
    f << size << " ";
    for( int i = 0; i < size; i++ ){
        f << numbers[ i ] << " ";
    }
    f.close();
    return 0;
}