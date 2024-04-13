#include <iostream>

using namespace std;

void radix_sort(int arr[], const int& N, const int& M)
{
    int arr_null[N];
    int arr_unit[N];
    int size_null = 0;
    int size_unit = 0;
    int radix = 0;

    for (int i = 0; i < N; i++)
        arr_null[i]=0;
    for (int i = 0; i < N; i++)
        arr_unit[i]=0;

    while(radix < M) // проходим по массиву M раз, где М - количество бит в наибольшем числе массива
    {
        for (int i = 0; i < N; i++)
        {
            if(arr[i] & (1 << radix)) // побитовая маска для вычленения нужных битов числа
            {
                arr_unit[size_unit++] = arr[i];
            }
            else
            {
                arr_null[size_null++] = arr[i];
            }
        }

        // копирование информации из вспомогательных массивов в основной
        for (int i = 0; i < size_null; i++)
        {
            arr[i] = arr_null[i];
        }

        for (int i = 0; i < size_unit; i++)
        {
            arr[i + size_null] = arr_unit[i];
        }

        size_null = 0;
        size_unit = 0;
        radix++;
    }
}



int main()
{
    const int M = 4;
    const int N = 12;
    int arr[N]{6,11,9,6,3,8,15,4,2,3,0,1};
    radix_sort(arr, N, M);
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
