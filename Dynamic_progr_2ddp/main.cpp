#include <iostream>

using namespace std;

int funk_qunt_finder(int column, int lines)
{
    int arr[lines+1][column+1];

    for (int i = 1; i < column+1; i++) {
        arr[1][i] = 1;
    }

    for (int i = 1; i < lines + 1; i++) {
        arr[i][1] = 1;
    }

    for (int i = 2; i < lines + 1; i++) {
        for (int j = 2; j < column + 1; j++) {
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }
    return arr[lines][column];
}

int main()
{
    int x,y;
    cin >> x >> y;
    cout << funk_qunt_finder(x,y) << endl;
    cout << "Hello World!" << endl;
    return 0;
}
