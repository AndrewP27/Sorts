// Sorts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <random>
#include <ctime>
#include <iostream>
#include <time.h>

int* generateNums(int size);
void selectionSort(int* vec, int size);
void insertionSort(int* vec, int size);
void swap(int* a, int* b);
void printVec(int* vec, int size);

int main()
{
    clock_t t1, t2, t3;

    int size = 20000;
    srand(20);
    int* vec = generateNums(size);
    srand(20);
    int* vec2 = generateNums(size);
    t1 = clock();
    insertionSort(vec, size);
    t2 = clock();
    selectionSort(vec2, size);
    t3 = clock();
    float diff = ((float)t2 - (float)t1) / CLOCKS_PER_SEC;
    float diff2 = ((float)t3 - (float)t2) / CLOCKS_PER_SEC;

    std::cout << "Running time: " << diff << std::endl;
    std::cout << "Running time: " << diff2 << std::endl;

    return 0;

}

int* generateNums(int size) 
{
    int* returnVal = new int[size];
    for (int i = 0; i < size; i++)
    {
        returnVal[i] = rand() % (size * 100);
    }
    return returnVal;
}

void selectionSort(int* vec, int size)
{
    int min;
    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i+1; j < size; j++)
        {
            if (vec[min] > vec[j])
            {
                min = j;
            }
        }
        swap(vec + i, vec + min);
    }
}

void insertionSort(int* vec, int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (vec[j] < vec[j - 1])
            {
                swap(vec + j, vec + j - 1);
            }
            else
                break;
        }
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printVec(int* vec, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << vec[i] << ", " << std::endl;
    }
    std::cout << std::endl;
}