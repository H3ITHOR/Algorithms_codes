    #include <iostream>
    #include <string>

    using namespace std;

    void quicksort(long long int array[], long long int l, long long int r);
    void swap(long long int array[], long long int i, long long int j);
    long long int partition(long long int array[], long long int l, long long int r);
    long long int binary_search(long long int array[], long long int size, long long int search_value);

    int main(){

        long long int n; // array size
        long long int k; // diff between num

        cin >> n;
        cin >> k;

        long long int* array = new long long int[n];

        for (int i = 0; i < n; i++){
            cin >> array[i];
        }

        quicksort(array, 0, n - 1);

        long long int x = 0; // quantity of pairs

        for (int i = 0; i < n; i++){
            if (binary_search(array, n, array[i]-k) != -1){
                x++;
            }
        }

        cout << x << endl;

        return 0;
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
        swap(array, i, j);   
        }while(i < j);


        swap(array,i, j);
        swap(array, l, j);


        return j;
    }

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