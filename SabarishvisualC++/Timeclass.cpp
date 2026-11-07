#include<iostream>
using namespace std;
class Time {
    private:
       int hours,minutes;
    public:
       Time(int h=0, int m=0):hours(h),minutes(m){}

       void display()
       {    cout<<"hrs:mins"<<hours<<":"<<minutes;     }
        
       Time &operator ++()
       {
           minutes++;
           if(minutes>=60)  { 
            minutes/=60;
            hours+=minutes;
        }
           return *this;

       }
       Time &operator --()
       {
          minutes--;
          if(minutes<=0)  {   hours-=1;minutes+=60; }
          return *this;
       }


};
int main()
{
    int h,m;
    cout<<"Enter the hours and minutes to increment and decrement---->:\n";
    cin>>h>>m;
    Time t1(h,m);
    Time  t2= ++t1;
    t2.display();
    cout<<"\n";
    Time t3=--t2;
    t3.display();

}