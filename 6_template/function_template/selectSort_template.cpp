#include <iostream>
#include <fstream>
using namespace std;

template <typename T> //声明模板，T是一个通用数据类型
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
void selectSort(T nums[], int len)
{
    int max;
    for (int i = 0; i < len; i++)
    {
        max = i;
        for (int j = i + 1; j < len; j++)
        {
            if (nums[j] > nums[max])
                mySwap(nums[j], nums[max]);
        }
    }
}
template <typename T>
void printArray(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}
void test1()
{
    char charArray[] = "xujianpeng";
    int len = sizeof(charArray) / sizeof(charArray[0]) - 1;
    selectSort(charArray, len);
    printArray(charArray, len);
}
void test2()
{
    int nums[] = {9, 4, 2, 0, 5, 4, 5, 4, 7};
    int len = sizeof(nums) / sizeof(nums[0]);
    selectSort(nums, len);
    printArray(nums, len);
}
int main(int argc, const char *argv[])
{
    test1();
    test2();
    return 0;
}