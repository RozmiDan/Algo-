#include <iostream>

using namespace std;

int fib_recur(int n)
{
    if(n <= 2)
        return 1;
    else
    {
        return fib_recur(n-1) + fib_recur(n-2);
    }
}

int fib_dynamic(int n)
{
    int* p_arr = new int[n+1]{};
    p_arr[1] = 1;
    p_arr[2] = 1;
    for (int i = 3; i < (n+1); i++)
    {
        p_arr[i] = p_arr[i-1] + p_arr[i-2];
    }
    int x = p_arr[n];
//    for (int i = 0;;) {

//    }
    delete [] p_arr;
    return x;
}

int main()
{
    int change_funk;
    cout << "1 or 2?" << endl;
    cin >> change_funk;
    int value;
    cout << "size?" << endl;
    cin >> value;
    int (*funk_d)(int);


    if(change_funk == 1)
    {
        funk_d = fib_recur;
    }
    else
    {
        funk_d = fib_dynamic;
    }

    cout << funk_d(value);

    cout << "Hello World!" << endl;
    return 0;
}
