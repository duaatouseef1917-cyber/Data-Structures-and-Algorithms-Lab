#include<iostream>
#include<string>
using namespace std;
struct Product {
    string name;
    int code;
    float price;
};
int main(){
    int n;
    cout<<"Enter number of products:";
    cin>>n;
      //Dynamically allocating memory for n numbr products
    Product*products=new Product[n];
     //Input product details
    for(int i=0;i<n;i++){
        cout<<"\nProduct No "<<i+1<<endl;
        cout<<"Name:";
        cin>>products[i].name;
        cout<<"Code:";
        cin>>products[i].code;
        cout<<"Price:";
        cin>>products[i].price;
    }
     //Displaying of th products
    cout<<"\n----Product List----\n";
    for(int i=0;i<n;i++)
	{
        cout<<"\nProduct"<<i+1<<endl;
        cout<<"Name:"<<products[i].name<<endl;
        cout<<"Code:"<<products[i].code<<endl;
        cout<<"Price:"<<products[i].price<<endl;
    }
     //Free memory allocation
    delete[]products;
    products=nullptr;
    return 0;
}