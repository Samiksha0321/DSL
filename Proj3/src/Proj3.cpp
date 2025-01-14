//============================================================================
// Name        : Proj3.cpp
// Author      : 21153
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

class Matrix{
public:
	int row, column, size, zeroCount;
	int arr[10][10];

	Matrix(){										//constructor
		row=0;
		column=0;
		size=0;
		zeroCount=0;
	}

	void getMatrix(){								// matrix input
		cout<<"\nEnter no of rows and columns:\t";
		cin>>row>>column;
		cout<<"\nEnter elements"<<endl;
		for(int i=0; i<row; i++){
			for(int j=0; j<column; j++)		cin>>arr[i][j];
		}
		size = row*column;
	}

	void putMatrix(){
		cout<<"\nEntered matrix is:"<<endl;
			for(int i=0; i<row; i++){
				for(int j=0; j<column; j++){
					cout<<arr[i][j]<<endl;
				}
		}
	}

	void checkSparse(){								//realization of sparse matrix
		for(int i=0; i<row; i++){
			for(int j=0; j<column; j++){
				if(arr[i][j] == 0)	zeroCount++;
			}
		}
		if(zeroCount > (size/2)){
			cout<<"\nIt is a sparse matrix which looks like: "<<endl;
			cout<<"Row Column Value"<<endl;
			for(int i=0; i<row; i++){
				for(int j=0; j<column; j++){
					if(arr[i][j] != 0)	cout<<i<<"\t"<<j<<"\t"<<arr[i][j]<<endl;
				}
			}
		}
		else
			cout<<"\nIt is not a sparse matrix."<<endl;
	}

	void fastTranspose(){																		//fast transpose
		cout << "The fast transpose of the given sparse matrix is:" << endl;
		cout<<"Row Column Value"<<endl;
		for(int i=0; i<column; i++){
			for(int j=0; j<row; j++){
				if(arr[j][i] != 0)	cout<<i<<"\t"<<j<<"\t"<<arr[j][i]<<endl;
			}
		}
	}
};

void addition(Matrix A, Matrix B){
	for(int i=0; i<max(A.row, B.row); i++){
		for(int j=0; j<max(A.column, B.column) ; j++){
			cout<<A.arr[i][j] + B.arr[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main() {
	cout<<"How many matrices in all?"<<endl;
	int n;
	cin>>n;
	Matrix A[n];
	for(int i=0; i<n; i++){
		A[i].getMatrix();
		A[i].putMatrix();
		A[i].checkSparse();
		A[i].fastTranspose();
	}

	cout<<"\nAddition of which 2 matrices do you want to perform?"<<endl;
	int a,b;
	cin>>a>>b;
	addition(A[a-1], A[b-1]);
	return 0;
}
