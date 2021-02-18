#include "../Utils/Utils.h"

using namespace std;

// int binary_search( int n, int * V, int value ){
//     int low = 0, middle, high = n-1;
//     while( low <= high ){
//         middle = (low+high) / 2;
//         if( value < V[middle] ){
//             high = middle - 1;
//         }else if( value > V[middle] ){
//             low = middle + 1;
//         }else {
//             return middle;
//         }
//     }
//     return -1;
// }

int binary_search( int * v, int low, int high, int value ){
    if( low > high ) return -1;
    int middle = (low+high)/2;
    if( value < v[ middle ] ){
        return binary_search( v, low, middle-1, value );
    }
    if( value > v[ middle ] ){
        return binary_search( v, middle+1, high, value );
    }
    return middle;
}

int main( int argc, char * argv[] ){
    int value = stoi( argv[ 1 ] );
    Instance inst = get_instance_ordened();

    cout << "Number: " << value << ", Position: " << binary_search( inst.numbers, 0, inst.size, value ) << endl;
    print_instance( inst );
    return 0;
}