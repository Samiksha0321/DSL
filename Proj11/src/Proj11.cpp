//============================================================================
// Name        : Proj11.cpp
// Author      : 21153
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class search{
public:
	int n,data[50],sortdata[50],s;
	void data_input(){
		cout<<"Enter No. of Elements:"<<endl;
		cin>>n;
		cout<<"Enter Elements:"<<endl;
		for(int i=1;i<=n;i++){
			cin>>data[i];
		}
	}
	void linearSearch(int item){
		s=0;
		for(int i=1;i<=n;i++){
			if(data[i] == item){
				s=1;
				break;
			}
		}
		if(s==1)
			cout<<"Attended training program"<<endl;
		else
			cout<<"Didn't attend training program"<<endl;
	}
	void sentinelSearch(int a){
		int i=1;
		data[n] = a;
		while(data[i]!=a && i<n){
			i++;
		}
		if(i<n)
			cout<<a<<" attended Training Program"<<endl;
		else
			cout<<a<<" didn't attend Training Program"<<endl;
	}
	void binarySearch(int x){
		int y=1;
		int left, right, mid;
		left = 1;
		right = n;
		while(left<=right){
			mid = (left+right)/2;
			if(data[mid] == x){
				y=1;
				break;
			}
			else if(data[mid]>x)
				right = mid-1;
			else if(data[mid]<x)
				left=mid+1;
		}
		if(y==1)
			cout<<x<<" attended Training Program"<<endl;
		else
			cout<<x<<" didn't attend Training Program"<<endl;
	}
	int fibSearch(int x){
		int inf = 0, pos, k;
		static int kk= -1, nn = -1;
		static int fib[]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 98,
				1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811,
				514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817,
				39088169, 63245986, 102334155, 165580141};
		if (nn != n){
			k = 0;
			while (fib[k] < n)
				k++;
			kk = k;
			nn = n;
		}
		else
			k = kk;
		while (k > 0){
			pos = inf + fib[--k];
			if ((pos >= n) || (x < data[pos]))
				cout<<endl;
			else if (x > data[pos]){
				inf = pos + 1;
				k--;
			}
			else
				return pos;
		}
		return -1;
	}
	void sort(){
		int temp;
		for(int p=1;p<=n-1;p++){
			for(int j=1;j<=n-1;j++){
				if(data[j]>data[j+1]){
					temp=data[j];
					data[j]=data[j+1];
					data[j+1]=temp;
				}
			}
		}
	}
};


int main(){
	int s,r,pos;
	char y = 'y';
	search t;
	t.data_input();
	t.sort();
	while(y == 'y'){
	   cout<<"Select:\n\t1. Linear Search\n\t2. Sentinel Search\n\t3. Binary Search\n\t4. Fibonacci search";
	   cin>>s;
	   cout<<"Enter Roll no. to search:";
	   cin>>r;
	   switch(s){
	   	   case 1: cout<<"\tUsing Linear Search :\n";
	   	   	   	   t.linearSearch(r);
	   	   	   	   break;
	   	   case 2: cout<<"\tUsing Sentinel Search :\n";
	   	   	   	   t.sentinelSearch(r);
	   	   	   	   break;
	   	   case 3: cout<<"\tUsing Binary Search :\n";
	   	   	   	   t.binarySearch(r);
	   	   	   	   break;
	   	   case 4: cout<<"\tUsing Fibonacci search:\n";
	   	   	   	   pos=t.fibSearch(r);
	   	   	   	   if(pos>=0)
	   	   	   		   cout<<"attended training program at position "<<pos<<endl;
	   	   	   	   else
	   	   	   		   cout<<"didn't attended training program"<<endl;
	   	   	   	   break;
	   }
	   cout<<"do u want to continue(y/n)";
	   cin>>y;
	}
	return 0;
}
