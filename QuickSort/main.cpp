#include <iostream>

using namespace std;

void quick_sort(int* left_bound, int* right_bound)
{
    int size_arr = right_bound - left_bound;
    //cheking size of arr
    if(right_bound - left_bound <= 1)
        return;
    //select rand element
    int rand_value = left_bound[rand() % size_arr];
    //cout << rand_value << endl;
    //sorting array into three parts
            //left values of array < rand_value
            //central values ==rand value
            //right values of array > rand value
    int* center_bound = left_bound;
    int counter = 0;
    for (int i = 0; i < size_arr; i++)
    {
        if(left_bound[i] < rand_value)
        {
            //swap(arr[i], *(center_bound + counter))
            int buf = left_bound[i];
            left_bound[i] = *(center_bound + counter);
            *(center_bound + counter) = buf;

            //swap(*(center_bound + counter), center_bound[0])
            buf = center_bound[0];
            center_bound[0] = *(center_bound + counter);
            *(center_bound + counter) = buf;

            center_bound++;
        }
        else if(left_bound[i] == rand_value)
        {
            //swap(left[i], *(center_bound + counter))
            int buf = left_bound[i];
            left_bound[i] = *(center_bound + counter);
            *(center_bound + counter) = buf;
            counter++;
        }

    }
    //recursion case
    quick_sort(left_bound, center_bound);
    quick_sort(center_bound + counter, right_bound);
}

int main()
{
    int size_arr = 0;
    cin >> size_arr;
    int* arr = new int [size_arr];
    for (int i = 0; i < size_arr; i++) {
        cin >> arr[i];
    }

    quick_sort(arr, arr+size_arr);

    for (int i = 0; i < size_arr; i++){
        cout << arr[i] << " ";}
    cout << endl;

    delete [] arr;
    return 0;
}
