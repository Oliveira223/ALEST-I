#include <iostream>

using namespace std;



int bubble(int *array, int tam){
    int tmp;
    
    for(int i = 0; i < tam; i++){
        cout << array[i] << " " << i << endl;

        if(array[i] > array[i+1]){
            tmp = array[i+1];
            array[i+1] = array[i];
            array[i] = tmp;
        }
    }

    return 0;
}



int main(){
    int a[] = {5, 4, 3, 2, 1};
    int tam = sizeof(a) / sizeof(a[0]);
    
    cout << "Array: [";
    for(int i = 0; i < tam; i++){
        cout << a[i] << ", ";
    }
    cout << "\b\b]" << endl;
    
    bubble(a, tam);    

    
    
    return 0;
}