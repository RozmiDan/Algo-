#include <iostream>

using namespace std;

int calc_cost(int* arr_price, int size)
{
    int arr_cost[size];
    arr_cost[1] = arr_price[1];
    arr_cost[2] = arr_price[2] + arr_price[1];
    for (int i = 3; i < size; i++)
    {
        arr_cost[i] = min(arr_cost[i-1],arr_cost[i-2]) + arr_price[i];
    }
    cout << arr_cost[size-1] << " ";
}

int main()
{
    int value;
    cin >> value;
    int* parr = new int [++value];
    for (int i=1; i < (value); i++) {
        cin >> parr[i];
    }
    calc_cost(parr, value);
    delete [] parr;
    cout << "Hello World!" << endl;
    return 0;
}
