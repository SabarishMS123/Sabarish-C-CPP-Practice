#include<iostream>
#include<string>
using namespace std;
class Toy{
    public:
      string  name;
      string color;
      void toydetails();
};

void Toy::toydetails(){
    cout<<"TOY NAME:"<<name<<endl;
    cout<<"TOY COLOR:"<<color<<endl;
}
int main(){
    Toy t;
    t.name="car";
    t.color="black";
    t.toydetails();
    return 0;
}