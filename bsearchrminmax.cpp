// bsearchrminmax.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int bsearch(int [],int, int);
int bsearch(int [],int, int,int);
void findminmax(int[],int,int, int&, int&);

int _tmain(int argc, _TCHAR* argv[])
{
	int x[]={12,34,67,89,112,124,304};
	int nel=sizeof(x)/sizeof(int);
    cout<<bsearch(x,nel,89)<<endl;
	cout<<bsearch(x,0,nel-1,89)<<endl;
	int y[]={12,45,34,67,23,89,3,7};
	int ny=sizeof(y)/sizeof(int);
	int be,se;
	findminmax(y,0,ny-1,be,se);
	cout<<se<<" "<<be<<" "<<endl;
	return 0;
}
int bsearch(int x[],int n, int key){
int mid;
int low=0,high=n-1;
	while(low <= high){
		mid=(low+high)/2;
		if(key==x[mid])
			return mid;
		if(key>x[mid])
			low =mid+1;
		else
			high=mid-1;
	}
	return -1;// search failure
}
int bsearch(int x[], int lp, int rp, int key){
int mid;
	if ( lp > rp )
		return -1;
	mid=(lp+rp)/2;
	if(key==x[mid])
		return mid;
	if(key > x[mid])
		return bsearch(x,mid+1,rp,key);
	else
		return bsearch(x,lp,mid-1,key);
}
void findminmax(int x[], int lp, int rp,int& big, int &small){
	if(lp+1==rp){
		big=x[lp]>x[rp]? x[lp]:x[rp];
		small=x[lp]<x[rp]? x[lp]:x[rp];
	}
	else{
		int mid=(lp+rp)/2;
		int b1,b2,s1,s2;
		findminmax(x,lp,mid,b1,s1);
		findminmax(x,mid+1,rp,b2,s2);
		big= b1>b2?b1:b2;
		small= s1<s2?s1:s2;
	}

}
