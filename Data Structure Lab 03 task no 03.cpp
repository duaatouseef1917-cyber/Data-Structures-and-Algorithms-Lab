#include<iostream>
using namespace std;
int main()
{
    int rows,columns;
    cout<<"Enter number of rows:";
    cin>>rows;
    cout<<"Enter number of columns:";
    cin>>columns;
     //Allocating memory for rows
    int**matrix=new int*[rows];
     //Allocating memory for columns in each row
    for(int i=0;i<rows;i++)
	{
        matrix[i]=new int[columns];
    }
     //Inputing th elements
    cout<<"\nEnter matrix elements:\n";
    for(int i=0;i<rows;i++) 
	{
        for(int j=0;j<columns;j++)
		{
            cin>>matrix[i][j];
        }
    }
     //Displaying matrix
    cout<<"\nMatrix:\n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
      //Free memory
    for(int i=0;i<rows;i++)
	{
        delete[]matrix[i];
    }
    delete[]matrix;
    matrix=nullptr;
    return 0;
}