/*
Given the arrival and departure times of all trains that reach a railway station,
the task is to find the minimum number of platforms required for the railway 
station so that no train waits. 
We are given two arrays that represent the arrival and departure times of trains that stop.
Input: arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00},
       dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00} 
Output: 3 
Input: arr[] = {9:00, 9:40}, 
       dep[] = {9:10, 12:00} 
Output: 1 
*/

#include <iostream>
#include <algorithm>

int main()
{
    //int arr[] = { 900 , 940 , 950 , 1100 , 1500 , 1800 } ;
    //int dep[] = { 910, 1200 , 1120 , 1130 , 1900 , 2000 } ;

    //int arr[] = {900 , 940}; 
    //int dep[] = {910 , 1200} ;

    int arr[] = { 900 , 940 , 1000 , 1330 , 1530 } ;
    int dep[] = { 950 , 1010 , 1400 , 1420 , 1730 } ;

    int train_count = sizeof(arr)/sizeof(int) ;
    int min_plat = 0 , platforms = 0 ;

//Time Complexity: O(nlogn) , Space Complexity: O(1) 

    std :: sort (arr , arr + train_count );
    std :: sort ( dep , dep + train_count ) ;

    int i = 0 , j = 0 ;

    while ( i < train_count )
    {
        if( arr[i] <= dep[j])
        {
            platforms ++ ;
            min_plat = std :: max( platforms , min_plat );
            i++;
        }
        else
        {
            platforms -- ;
            j++ ;
        }
    }

    std :: cout << "Required Minimum Platforms: " << min_plat ; 
}