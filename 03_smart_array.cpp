#include <iostream>
using namespace std;

class smartArray
{
    int *data;
    int currSize;
    int size;

public:
    smartArray()
    {
        data = NULL;
        currSize = 0;
        size = 0;
    };

    smartArray(int n)
    {
        data = (int *)malloc(n * sizeof(int));
        // data = new int(n);
        currSize = n;
        size = n;
    }

    int &operator[](int idx)
    {
        return data[idx];
    }

    void push_back(int x)
    {
        if (currSize >= size)
        {
            int *newData = new int(2 * size);
            for (int i = 0; i < currSize; i++)
            {
                newData[i] = data[i];
            }

            free(data);
            data = newData;
            size = 2 * size;
        }
        data[currSize] = x;
        currSize++;
    }

    smartArray operator+(smartArray &arr)
    {
        smartArray newArr(this->currSize + arr.currSize);
        int i, j = 0;
        for (i = 0; i < this->currSize; i++)
        {
            newArr.data[i] = this->data[i];
        }
        while (j < arr.currSize)
        {
            newArr.data[i] = arr.data[j];
            i++;
            j++;
        }

        return newArr;
    }

    friend ostream &operator<<(ostream &out, smartArray &arr);

    void printArray() const
    {
        for (int i = 0; i < currSize; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

ostream &operator<<(ostream &out, smartArray &arr)
{
    for (int i = 0; i < arr.currSize; i++)
    {
        out << arr[i] << " ";
    }
    out << endl;
    return out;
}

int main()
{
    smartArray arr;
    // smartArray arr2;
    // smartArray arr3;

    // arr[0] = 1;
    // arr[1] = 2;
    // arr[2] = 3;
    // arr[3] = 4;
    // arr[4] = 5;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    cout << arr;
    // arr2.push_back(4);
    // arr2.push_back(5);

    // arr = arr + arr2;

    // arr.printArray();
}