//============================================================================
// Name        : Proj13.cpp
// Author      : 21153
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class sorting{
	int num, low, high;
	float per[50];
public:
	void get_percentage();
	int partition (float arr[], int low, int high);
	void quick_sort(float arr[], int low, int high);
	void display();
};

void sorting::get_percentage(){
	cout<<"Enter no of students: "<<endl;
	cin>>num;
	cout<<"Enter the percentage of students: "<<endl;
	for(int i=0; i<num; i++){
		cin>>per[i];
	}
	low = 0;
	high = num-1;
	quick_sort(per,0,num-1);
}

int sorting::partition (float arr[], int low, int high)
{
    float pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void sorting::quick_sort(float arr[], int low, int high){
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void sorting::display(){
	cout<<"Top 5 scores are: ";
	for(int i=num-1; i>=num-5; i--){
		cout<<per[i]<<" ";
	}
	cout<<endl;
}

int main() {
	sorting s;
	s.get_percentage();
	s.display();
	return 0;
}
