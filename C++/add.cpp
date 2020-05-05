//
//  main.cpp
//  Array_Project
//
//  Created by Mai Tuyet Luu on 4/28/20.
//  Copyright © 2020 Mai Tuyet Luu. All rights reserved.
//
#include <cstdlib>
#include <chrono>
#include <iostream>
using namespace std;

const int N = 800;

void execution_time(int arr1[], int arr2[], int n);
void add_array(int arr1[], int arr2[]);
void returnMiddleValue(int arr[], int n);

int main()
{
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Adding 1D arrays
    int n = 20000;
    
    int arr1[n];
    int arr2[n];
    
    int arr3[N][N];
    int arr4[N][N];
    
    srand((unsigned)time(0));
    
    cout << "Generating first 1D array... " << endl;
    
    for(int i = 0; i < n; i++)
    {
        arr1[i] = (rand() % 100) + 1;
        //cout << arr1[i] << " ";
    }
    
    
    
    cout << "Generating second 1D array... " << endl;
    
    for(int i = 0; i < n; i++)
    {
        arr2[i] = (rand() % 100) + 1;
        //cout << arr2[i] << " ";
    }
    
    
    execution_time(arr1, arr2, n);
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //Adding 2D arrays
    
    cout <<"Generating first 2D array... " <<endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            arr3[i][j] = (rand() % 100) + 1;
            //cout << arr3[i][j] << " ";
        }
        //cout << endl;
    }
   
    
    cout <<"Generating second 2D array..." <<endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            arr4[i][j] = (rand() % 100) + 1;
            //cout << arr4[i][j] << " ";
        }
        //cout << endl;
    }
    //cout << endl;
    
    auto start1 = std::chrono::high_resolution_clock::now();
    
    int sum[N][N];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            sum[i][j] = arr3[i][j] + arr4[i][j];
        }
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    
    auto t1 = std::chrono::duration_cast<std::chrono::nanoseconds> (end1 - start1).count();
    
    cout << "Time for adding two 2D arrays size "<< N <<" x "<< N <<" :" << t1 << endl;
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    auto start2 = std::chrono::high_resolution_clock::now();
    
    //BinarySearch(arr, 0, n-1, 13);
    returnMiddleValue(arr1, n);

    auto end2 = std::chrono::high_resolution_clock::now();
    
    auto t2 = std::chrono::duration_cast<std::chrono::nanoseconds> (end2 - start2).count();
    
    cout << "Time for returning middle value in this array: " << t2 << endl;
     
    
    return 0;
}

void add_array(int arr1[], int arr2[], int n)
{
    int sum[n];
    for(int i = 0; i < n; i++)
    {
        sum[i] = arr1[i] + arr2[i];
    }
}


void execution_time(int arr1[], int arr2[], int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    
    add_array(arr1, arr2, n);
    
    auto end = std::chrono::high_resolution_clock::now();
    
    auto t = std::chrono::duration_cast<std::chrono::nanoseconds> (end - start).count();
    
    cout << "Time for adding two 1D arrays: " << t << endl;
    
}

void returnMiddleValue(int arr[], int n)
{
    double result;
    int mid = n / 2;
    
    if(mid % 2 == 0)
    {
        result = (mid + (mid+1))/2;
    }
    if(mid % 2 != 0)
    {
        result = mid;
    }
}
