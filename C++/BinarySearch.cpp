//
//  main.cpp
//  BinarySearch
//
//  Created by Mai Tuyet Luu on 5/1/20.
//  Copyright © 2020 Mai Tuyet Luu. All rights reserved.
//
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;


int BinarySearch(int arr[], int left, int right, int x);

void show(int a[], int size);

int main()
{
    int n = 100;
    int a[n];
    
    //int a[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    //int size = sizeof(a)/sizeof(a[0]);
    
    srand((unsigned)time(0));
    
    cout << "Generating an array... " << endl;
    
    for(int i = 0; i < n; i++)
    {
        a[i] = (rand() % 100) + 1;
        //cout << arr1[i] << " ";
    }
    
    cout << "\nThe array is: ";
    show(a, n);
    
    sort(a, a+n);
    
    cout << "\nThe array after sorting: ";
    show(a, n);
    
    auto start = std::chrono::high_resolution_clock::now();
    
    BinarySearch(a, 0, n-1, 2);
    
    auto end = std::chrono::high_resolution_clock::now();
       
    auto t = std::chrono::duration_cast<std::chrono::nanoseconds> (end - start).count();
    
    cout << "Time for Binary search: " << t << endl;
    
    cout << endl;
    
    
}

void show(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int BinarySearch(int a[], int left, int right, int x)
{
    if (right >= left)
    {
        int mid = (left + right)/2;
        
        if(a[mid] == x)
        {
            cout << "\nThe value is found." << endl;
            return mid;
        }
        
        if(a[mid] > x)
        {
            return BinarySearch(a, left, mid - 1, x);
        }
        
        return BinarySearch(a, mid+1, right, x);
        
    }
    cout << "\nThe value is not found!" << endl;
    return -1;
}
