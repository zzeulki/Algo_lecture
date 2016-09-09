//
//  main.cpp
//  09.08_02
//
//  Created by 강슬기 on 2016. 9. 8..
//  Copyright © 2016년 강슬기. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int root[100];
int arr[100];
int locate[100];

int count=0;


int find(int index)
{
    int r;
    int s;
    
    for(r=index;arr[r]>=0;r=arr[r]);
    while(index!=r)
    {
        s = arr[index];
        arr[index] = r;
        index = s;
    }
    return r;
}

void merge(int i, int j)
{
    int temp = arr[i] + arr[j];
    
    if(arr[i]>arr[j])
    {
        arr[i]=j;
        arr[j]=temp;
        
    }
    else
    {
        arr[j]=i;
        arr[i]=temp;
    }
    
    for(int k=1;k<=count;k++)
    {
        //다음 값이 j와 같고, root[i]가 다음 값을 가지고 있을 때
        if(root[k]==j && root[i]!=0)
            root[k]=root[i];
        //다음 값이 j와 같고, root[i]가 다음 값을 가지고 있지 않을 때
        else if(root[k]==j && root[i]==0)
        {
            root[k]=i;
        }
    }
    
    //i가 j에 붙을 때!
    if(root[i]!=0)
        root[j]=root[i];
    else if(root[i]==0)
        root[j]=i;
   
}

int main()
{
    int job,deadl,pro;
    int i;
    int p,q;
    
    
    scanf("%d",&count);
    
    for(i=1;i<=count;i++)
    {
        arr[i]=-1;
    }
    
    for(i=1;i<=count;i++)
    {
        scanf("%d %d %d",&job,&deadl,&pro);
        
        if(root[deadl]==0)  //제일 처음 빈 자리에 들어가는지 확인
        {
            locate[deadl]=job;
            
            if(deadl==1)    //처음 들어오는 데드라인이 1이였을 경우
            {
                p = find(count);    //마지막이 가리키고 있는 값 찾기
                
                merge(p,deadl);     //마지막이 가리키고 있는 다음 값과 첫 부분 병합하기!
               
            }
            else
            {
                p = deadl;  //현재 데드라인 위치
                
                q = find(p-1);  //현재 데드라인보다 앞 부분이 가리키고 있는 다음 값 찾기
                
                merge(q,p);       //현재 데드라인 앞 부분과 병합하기
            }
            
        }
        else    //이미 해당 데드라인 위치에 어떠한 값이 들어있을 때
        {
            
            locate[root[deadl]]=job;    //현재 데드라인이 들어갈 곳에 값 저장

            if(deadl==1)    //그 데드라인이 1이였을 때 (무조건 값이 마지막으로 넘어온 것과 마찬가지이다.)
            {
                
                if(root[count]!=0)      //마지막 위치의 다음 값이 존재할 때
                    p = root[count];    //마지막이 가리키고 있는 다음 값 반환
                else                    //마지막 위치의 다음 값이 없을 때
                    p = find(count);    //마지막 위치 값 반환
                if(root[p]!=0)
                    q = find(root[root[p]-1]);  //p의 다음 값보다 한 칸 앞에 있는 값의 다음 값 찾기(p의 루트가 다른 값 일 떄)
                else
                    q = find(p-1);      //p의 다음 값보다 한 칸 앞에 있는 값의 다음 값 찾기(p의 루트가 자기 자신일 때)
                
                merge(q,p);
                
            }
            else
            {
                p = root[deadl];    //다음 위치 찾기

                if(root[p]!=0)      //다음 위치에도 값이 있을 때
                    q = find(root[root[p]-1]);  //다음 위치 보다 한 칸 앞의 다음 위치를 찾는다
                else                //다음 위치 값이 없을 때는
                    q = find(p-1);  //다음 위치보다 바로 앞 칸의 위치를 찾는다.
                
                merge(q,p);
            }
        }
        
    }
    
    
    for(i=1;i<=count;i++)
    {
        printf("%d ",locate[i]);
    }
    
    return 0;
    
    
}
