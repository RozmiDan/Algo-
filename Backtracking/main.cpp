#include <iostream>
#include <string>

using namespace std;

static int top = 0;

void binary_generator(int a, bool arr[])
{
    if(a == 0)
    {
        for (int i = 0; i < top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else {
        arr[top++] = 0;
        binary_generator(a-1, arr);
        top--;

        arr[top++] = 1;
        binary_generator(a-1, arr);
        top--;
    }
}

void permutation(int number, uint16_t arr[], bool arr_used[])
{
    if(top == number) // если доходим до конца ветки выводим ответ
    {
        for(int i = 0; i < number; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    else
    {
        for (int numero = 0; numero < number; numero++) { // проходим по дереву для каждого числа
            if(!arr_used[numero]) // если число уже встречалось и находится в массиве, то отрезаем ветку
            {
                arr[top++] = numero; // добавляем число в последовательность
                arr_used[numero] = true; // удаляем его из списка доступных, для исключения повтора
                permutation(number, arr, arr_used);
                top--;
                arr_used[numero] = false; // обнуляем все использованные числа чтобы начать на новой ветке
            }
        }
    }
}

int main()
{
    int a;
    uint16_t arr_for_number[20]{0};
    bool arr_for_used_val[20]{false};
    cin >> a;
    //binary_generator(a, arr_for_number);
    permutation(a, arr_for_number, arr_for_used_val);
    cout << "Hello World!" << endl;
    return 0;
}
