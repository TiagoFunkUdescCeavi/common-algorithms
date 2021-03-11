#include <fstream>
#include <exception>
#include <iostream>

using namespace std;

#define SIZE 10

struct Int_Vector{
    int size;
    int * numbers;
};

Int_Vector get_int_vector( char * file ){
    Int_Vector int_vec;
    ifstream f( file, ios::in );
    if( !f ){
		throw runtime_error( "Error on open file." );
	}
    
    f >> int_vec.size;
    int_vec.numbers = new int[ int_vec.size ];
    for( int i = 0; i < int_vec.size; i++ ){
        f >> int_vec.numbers[ i ];
    }
    return int_vec;
}

Int_Vector get_instance_ordened(){
    Int_Vector int_vec;
    int_vec.size = SIZE;
    int_vec.numbers = new int[ SIZE ];
    for( int i = 0; i < SIZE; i++ ){
        int_vec.numbers[ i ] = 2*i;
    }
    return int_vec;
}

void print_int_vector( Int_Vector int_vec ){
    for( int i = 0; i < int_vec.size; i++ ){
        cout << int_vec.numbers[ i ] << " ";
    }
    cout << endl;
}

void swap( int * v, int a, int b ){
    int aux = v[ a ];
    v[ a ] = v[ b ];
    v[ b ] = aux;
}