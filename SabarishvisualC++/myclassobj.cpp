// Define a class named Student.

// Add the following data members:

// name (string)

// rollNumber (int)

// marks (float)

// Add member functions to:

// Input student details.

// Display student details.
class Student
{
private:
          string name,rno;
          float marks;
public:
         void getstudentinfo()
         {
                cout<<"Enter the Name:";
                cin>>name;
                cout<<"Enter rno:";
                cin>>rno;
                cout<<"Enter marks: ";
                cin>>marks;
         }
         void displayinfo(void);
};
void Student ::displayinfo()
{
   cout<<name;
   cout<<rno;
   cout<<marks;
}
int  main(){
    Student s;
    s.getstudentinfo();
    s.displayinfo();
    return 0;
}


