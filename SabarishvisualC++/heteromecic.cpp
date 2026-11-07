#include<iostream>
#include<cmath>
 using namespace std;
int main()
{
    int n,i;
    cout<<"Enter the number:";
    cin>>n;

    for(i=0;i<sqrt(n);i++)
    {
        if(n== i*(i+1))
        {
            cout<<"Heteromecic!";
        }
    }
}