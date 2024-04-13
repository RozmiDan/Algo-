#include <iostream>

using std::cin, std::cout, std::endl;

void merge_sort(int *arr, int const &size)
{
    if(size <= 1)
        return;
    else
    {
        //рекурсивно разбиваем наш массив до единичных числовых значений
        //с помощью арифметики указателей разделяем исходный массив на две части
        //в двух переменных будут хранится указатели на начало и середину массива
        int* leftArrStartEdge = arr;
        int middle = size/2;
        int leftArrSize = middle;
        int* rightArrStartEdge = arr + (middle);
        int rightArrSize = size - (middle);
        merge_sort(leftArrStartEdge, leftArrSize);
        merge_sort(rightArrStartEdge, rightArrSize);

        //сливаем получившиеся значения в буфер
        int bufferArr[size];
        int bufferCounter = 0;
        int leftArrCounter = 0;
        int rightArrCounter = 0;
        //сравниваем значения из двух частей массива
        //соответственно проходимся одновременно по двум отсортированным массивам
        //и сравниваем значения, бОльшее раньше попадает в буфер
        while((leftArrCounter != leftArrSize) && (rightArrCounter != size-leftArrSize))
        {
            if(leftArrStartEdge[leftArrCounter] < rightArrStartEdge[rightArrCounter])
            {
                bufferArr[bufferCounter] = leftArrStartEdge[leftArrCounter];
                bufferCounter++;
                leftArrCounter++;
            }
            else
            {
                bufferArr[bufferCounter] = rightArrStartEdge[rightArrCounter];
                bufferCounter++;
                rightArrCounter++;
            }
        }
        //если один из двух массивов закончился, а второй содержит значения
        //значит просто сливаем их в буфер
        while(leftArrCounter != leftArrSize)
        {
            bufferArr[bufferCounter] = leftArrStartEdge[leftArrCounter];
            bufferCounter++;
            leftArrCounter++;
        }

        while(rightArrCounter != size)
        {
            bufferArr[bufferCounter] = rightArrStartEdge[rightArrCounter];
            bufferCounter++;
            rightArrCounter++;
        }

        //копируем буфер в исходный массив
        for (int i = 0; i < size; i++) {
            arr[i] = bufferArr[i];
        }
    }
}

template <typename T>
void print_arr(T arr[], int size_arr)
{
    for(int i = 0; i < size_arr; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int size_of_arr;
    cin >> size_of_arr;
    int array_for_sort[size_of_arr];
    for (int i=0; i < size_of_arr; i++)
    {
        cin >> array_for_sort[i];
    }

    merge_sort(array_for_sort, size_of_arr);
    print_arr(array_for_sort, size_of_arr);
    return 0;
}
