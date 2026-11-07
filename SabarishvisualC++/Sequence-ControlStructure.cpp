//<----------------------Method 1----------------------------->


/*
#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int b = 10;
    cout << "Sum: " << (a + b) << endl;
    return 0;
}*/




//<----------------------Method 2----------------------------->
/*
#include <iostream>
using namespace std;

int add(int a, int b) {
    while (b != 0) {
        // Carry contains common set bits of a and b
        int carry = a & b;

        // Sum of bits of a and b where at least one of the bits is not set
        a = a ^ b;

        // Carry is shifted by one so that adding it to a gives the required sum
        b = carry << 1;
    }
    return a;
}

int main() {
    int a = 5;
    int b = 10;
    cout << "Sum: " << add(a, b) << endl;
    return 0;
}
*/






//<----------------------Method 3----------------------------->
/*
#include <iostream>
using namespace std;

int add(int a, int b) {
    for (int i = 0; i < b; i++) {
        a++;
    }
    return a;
}

int main() {
    int a = 5;
    int b = 10;
    cout << "Sum: " << add(a, b) << endl;
    return 0;
}
*/






//<----------------------Method 4----------------------------->
/*
#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int b = 10;
    cout << "Sum: " << (a -(-b)) << endl;
    return 0;
}
*/






//<----------------------Method 5----------------------------->
//#include <iostream>
//using namespace std;
//
//int add(int a, int b) {
//    if (b == 0)
//        return a;
//    return add(a + 1, b - 1);
//}
//
//int main() {
//    int a = 5;
//    int b = 10;
//    cout << "Sum: " << add(a, b) << endl;
//    return 0;
//}

