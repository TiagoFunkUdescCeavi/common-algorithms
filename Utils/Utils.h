#include <fstream>
#include <exception>
#include <iostream>

using namespace std;

#define SIZE 10

struct Instance{
    int size;
    int * numbers;
};

Instance get_instance( char * file ){
    Instance inst;
    ifstream f( file, ios::in );
    if( !f ){
		throw runtime_error( "Error on open file." );
	}
    
    f >> inst.size;
    inst.numbers = new int[ inst.size ];
    for( int i = 0; i < inst.size; i++ ){
        f >> inst.numbers[ i ];
    }
    return inst;
}

Instance get_instance_ordened(){
    Instance inst;
    inst.size = SIZE;
    inst.numbers = new int[ SIZE ];
    for( int i = 0; i < SIZE; i++ ){
        inst.numbers[ i ] = 2*i;
    }
    return inst;
}

void print_instance( Instance inst ){
    for( int i = 0; i < inst.size; i++ ){
        cout << inst.numbers[ i ] << " ";
    }
    cout << endl;
}