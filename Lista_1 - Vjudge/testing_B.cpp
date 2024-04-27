#include <iostream>
#include <string> 

using namespace std;

long long int binary_search(long long int array[], long long int size, long long int search_value){
    long long int low = 0;
    long long high = size-1;

    long long int mid;

    while (low <= high){

        mid = (low+high)/2;

        if (search_value==array[mid]){
            return mid;
        }
        else if (search_value > array[mid]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    return -1;
}

int main(){
    long long int array[6] = {10, 20, 30, 40, 50, 60};
    long long int var = binary_search(array, 6, 25);
    cout << var << endl;

    return 0;
}