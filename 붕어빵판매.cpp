//
//  main.cpp
//  bongabbang
//
//  Created by 강슬기 on 2016. 9. 16..
//  Copyright © 2016년 강슬기. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

void found(int k, int count, int arr[])
{
    if(arr[k]+arr[count-k]>arr[count])
    {
       // cout << arr[count] << ">>  " << endl;
        arr[count] = arr[k] + arr[count-k];
        //cout << arr[count] << endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int count;
    int *arr;
    
    cin >> count;
    
    arr = new int[count];
    
    for(int i = 1 ; i<= count ; i++)
        cin >> arr[i];
    
    
    //n2이 되지 않으면 계산하지 못함
    for(int j = 1 ; j <= count ;j++)
    {
        for(int p = 1 ; p <j; p++)
        {
            if(p!=j)
            found(p,j,arr);
            
        }
        
    }
    
    
    
    cout << arr[count] << endl;
    
    return 0;
}
