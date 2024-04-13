#include <iostream>

using namespace std;

void counting_sort(int arr[], int N, int M)
{
    int tmp_arr[M];
    for (int i = 0; i < M; i++) {
        tmp_arr[i] = 0;
    }

    for(int i = 0; i < N; i++){
        tmp_arr[arr[i]]++;
    }

    int counter = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < tmp_arr[i]; j++) {
            arr[counter] = i;
            counter++;
        }
    }
}

int main()
{
    const int N = 15;
    const int M=8;
    int arr[N] = {3, 4, 1, 5, 6, 4, 2, 7, 6, 4, 3, 2, 1, 5, 4};

    counting_sort(arr, N, M);

    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
