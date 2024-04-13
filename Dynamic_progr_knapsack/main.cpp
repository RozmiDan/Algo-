#include <iostream>

using std::pair, std::cout, std::endl, std::cin;

int backpackFunk(int itemsNums, pair<int,int>*arrInfoNums, int packCapacity)
{
    //sozdanie dvumernogo massiva
    packCapacity += 1;
    int** arrOfSumCost = new int*[itemsNums];
    for (int i = 0; i < itemsNums; i++) {
        arrOfSumCost[i] = new int[packCapacity]{0};
    }


    //algoritm prohoda i vichisleniya optimalnoy zagruzhinosti
    for(int i = 1; i < itemsNums; i++)
    {
        for (int j = 1; j < packCapacity; j++)
        {
            //poka massa elementa menshe tekuchey gruzopodemnosti - copiruem proshliy stolb
            if(arrInfoNums[i].first > j)
            {
                arrOfSumCost[i][j] = arrOfSumCost[i-1][j];
            }
            else
            {
                //sravnivaem znachenie stoimosti esli dobavlyaem tekushiy element i esli net
                arrOfSumCost[i][j] = std::max(arrOfSumCost[i-1][j], arrOfSumCost[i-1][j-arrInfoNums[i].first] + arrInfoNums[i].second);
            }
        }
    }


    for(int i = 0; i < itemsNums; i++)
    {
        for (int j = 0; j < packCapacity; j++)
        {
            cout << arrOfSumCost[i][j];
        }
        cout << endl;
    }

    int result = arrOfSumCost[itemsNums-1][packCapacity-1];

    //delete massivs
    for (int i = 0; i < itemsNums; i++)
    {
        delete [] arrOfSumCost[i];
    }
    delete [] arrOfSumCost;

    return result;
}

int main()
{
    int numOfItems, capacityOfBackpack;
    cout << "vvedite kolichestvo elementov i vmestimost rykzaka";
    cin >> numOfItems >> capacityOfBackpack;
    pair<int,int>* arr = new pair<int,int> [++numOfItems];


    for (int i = 1; i < numOfItems; i++)
    {
        cout << "vvedite massu & cennost elementa" << i << endl;
        cin >> arr[i].first >> arr[i].second;
    }

    cout << backpackFunk(numOfItems, arr, capacityOfBackpack) << endl;

    delete [] arr;

    return 0;
}
