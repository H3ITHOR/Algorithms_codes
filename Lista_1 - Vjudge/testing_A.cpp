#include <iostream>
#include <string>

using namespace std;

long long int array_sum(long long int array[], long long int lenght);
long long int find_smallest_biggest(long long int array[], long long int lenght, long long int coup_vl);
void quicksort(long long int array[], long long int l, long long int r);
void swap(long long int array[], long long int i, long long int j);
long long int partition(long long int array[], long long int l, long long int r);


int main(){

    long long int qt_choco; // number of choco bars in the shop
    cin >> qt_choco;
    long long int* pr_choco = new long long int[qt_choco]; // cost of the chocolate bars

    for (long long int i = 0; i < qt_choco; i++) {
        cin >> pr_choco[i];
    }

    long long int qt_coup; // quantity of coupons I have
    cin >> qt_coup;
    long long int* vl_coup = new long long int[qt_coup];

    for (long long int i = 0; i < qt_coup; i++) {
        cin >> vl_coup[i];
    }

            // sorting list
    quicksort(pr_choco, 0, qt_choco - 1);

        // finding the value to every coupon

    long long int total_sum = array_sum(pr_choco, qt_choco);

    for (long long int i = 0; i < qt_coup; i++){
        long long int variable = vl_coup[i];
        long long int sum = total_sum - find_smallest_biggest(pr_choco, qt_choco, variable);
        
        // output

        cout << sum << endl;
    }

    delete[] pr_choco;
    delete[] vl_coup;

    return 0;
}

long long int array_sum(long long int array[], long long int lenght){
    long long int sum = 0;
    for (long long int i = 0; i < lenght; i++){
        sum += array[i];
    }
    return sum;
}

long long int find_smallest_biggest(long long int array[], long long int lenght, long long int coup_vl){
    long long int i = lenght - coup_vl;

    return array[i];
}

void quicksort(long long int array[], long long int l, long long int r) {
    if (l < r){
        long long int s = partition(array, l, r);
        quicksort(array, l, s-1);
        quicksort(array, s+1, r);
    }
}


void swap(long long int array[], long long int i, long long int j){
    long long int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}


long long int partition(long long int array[], long long int l, long long int r){
    long long int p = array[l];
    long long int i = l;
    long long int j = r + 1;


    do{
       do{
            i++;
       }while(array[i] < p && i < r);
       do{
            j--;
       }while(array[j] > p);
       // fazer swap aqui
       swap(array, i, j);   
    }while(i < j);


    swap(array,i, j);
    swap(array, l, j);


    return j;
}
