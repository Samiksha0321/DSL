//============================================================================
// Name        : Proj2.cpp
// Author      : 21153
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

class Matrix{
public:
    int arr[5][5];
    int row, column;

    //constructor
    Matrix(){
        row=0;
        column=0;
        arr[5][5]=;
    }

    void getSize(){
        cout<<"\nEnter no. of elements in row and column of matrix\t";
        cin>>row>>column;
    }
    void EnterMatrix(){
        cout<<"\nEnter the elements: "<<endl;
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++) 		cin>>arr[i][j];
        }
    }

    void upperTri() {														//upper Triangle
        int count=0;
        for(int i=0; i<row; i++){
            for(int j=0; j<i; j++){
                if(arr[i][j] != 0) count++;
            }
        }
        if(count!=0)	cout<<"\nMarix is not upper triangular."<<endl;
        else	cout<<"\nMarix is upper triangular."<<endl;
    }

    void sumDiagonal(){														//sum of diagonals
        int sum=0;
        for(int i=0; i<min(row, column); i++)		sum += arr[i][i];
        cout<<"\nSum of diagonals is: "<<sum<<endl;
    }

    void transpose(){
        cout<<"\nTranspose of the matrix is: "<<endl;							//transpose of matrix
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                cout<<arr[j][i]<<" ";
            }
            cout<<endl;
        }
    }

    void saddle(){															//saddle point
        int small, large=0;
        int count=0;
        for(int i=0; i<row; i++){
            int p=0;
            small=arr[i][0];
            for(int j=0; j<column; j++){
                if(small > arr[i][j]){
                    small = arr[i][j];
                    p=j;
                }
            }
            for(int j=0; j<row; j++){
                if(large < arr[j][p])	large = arr[j][p];
            }
            if(small == large){
                cout<<"\nSaddle point present which is "<<small<<endl;
                count ++;
            }
        }
        if(count == 0)	cout<<"\nSaddle point absent"<<endl;
    }
};

void addition(Matrix A, Matrix B){											//addition of 2 matrices
    cout<<"\nSum of the 2 matrices is: "<<endl;
    for(int i=0; i<max(A.row, B.row); i++){
        for(int j=0; j<max(A.column, B.column); j++)		cout<<A.arr[i][j] + B.arr[i][j]<<" ";
        cout<<endl;
    }
}

void subtract(Matrix A, Matrix B){											//subtraction of 2 matrices
    cout<<"\nSubtraction of the 2 matrices is:"<<endl;
    for(int i=0; i<min(A.row, B.row); i++){
        for(int j=0; j<min(A.column, B.column); j++) 		cout<<A.arr[i][j] - B.arr[i][j]<<" ";
        cout<<endl;
    }
}

void multiply(Matrix A, Matrix B){											//muliplication of 2 matrices
    int mul;
    if(A.row == B.column){
        cout<<"\nMultiplication of 2 matrices is: "<<endl;
        for(int i=0; i<A.row; i++){
            for(int j=0; j<B.column; j++){
                mul=0;
                for(int k=0; k<B.row; k++) 		mul += A.arr[i][k] * B.arr[k][j];
                cout<<mul<<" ";
            }
            cout<<endl;
        }
    }
    else cout<<"\nMultiplication of the 2 matrices is not possible!"<<endl;
}


int main() {																//main function
    Matrix A,B;

    A.getSize();
    A.EnterMatrix();
    A.upperTri();
    A.sumDiagonal();
    A.transpose();

    B.getSize();
    B.EnterMatrix();
    B.upperTri();
    B.sumDiagonal();
    B.transpose();

    addition(A, B);
    subtract(A, B);
    multiply(A, B);
    A.saddle();
    B.saddle();
    return 0;
}
