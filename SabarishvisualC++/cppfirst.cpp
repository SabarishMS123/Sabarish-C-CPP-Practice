
// IF else
// #include <iostream>
// using namespace std;
// int main() 
// {
//    int systolic, diastolic;
//    cout << "Enter systolic blood pressure: ";
//    cin >> systolic;
//    cout << "Enter diastolic blood pressure: ";
//    cin >> diastolic;

//    if (systolic > 120 || diastolic > 80) {
//        cout << "Warning: High blood pressure detected. Please consult a doctor." <<endl;
//    } else {
//        cout << "Blood pressure is within the normal range." << endl;
//    }

//    return 0;
// }


// Nested ifs
// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//    string type;
//    double damount, accnt = 0.0, expense = 0.0, eamount=0.0;

//    cout << "Enter transaction type (income/expense): ";
//    cin >> type;
   
   

//    if (type == "income") {
//        cout << "Enter Deposit amount: ";
//        cin >> damount;
//        if(damount<1000)
//        {
//        	cout<<"Less than 1000 the deposition is not allowed here";
// 		}
//    	cout << "Total Income: " << damount << endl;
//        cout << "Total Expense: " << eamount << endl;
//        cout << "Net Balance: " << (damount) << endl;
   	
//    }
   
//    else{
//    	if(type=="expense")
//    	{
//    		cout<<"Enter income amount:";
//    		cin>>damount;
//    		if(damount<1000)
//           {
//        	cout<<"Less than 1000 the income is not applicable to withdrawal here";
           
//            }
//            else{
			
//    		cout<<"Enter expense amount:";
//    		cin>>eamount;
//    		cout << "Total Income: " << damount << endl;
//            cout << "Total Expense: " << eamount << endl;
//            cout << "Net Balance: " << (damount - eamount) << endl;
   		
// 	       	}
// 	  }
// 		else{
// 			cout << "Invalid transaction type. Please enter 'income' or 'expense'." << endl;
// 		}
// 	}


   

//    return 0; 
// }
 

//else if ladder
//
// #include <iostream>
// #include <string>
// using namespace std;
// int main() {
//    int weather;
//    cout << "Enter the current weather (in celcius): ";
//    cin >> weather;

//    if (weather>= 30) {
//        cout << "It's a bright and beautiful day. Enjoy the sunshine!" << endl;
//    } else if (weather >= 19 && weather < 30) {
//        cout << "Don't forget to take an umbrella. Stay dry!" << endl;
//    } else if (weather <=0 && weather<=19 ) {
//        cout << "It's a winter wonderland out there. Stay warm!" << endl;
//    } else {
//        cout << "Invalid weather input. Please enter sunny, rainy, or snowy." << endl;
//    }

//    return 0;
// }


// while
// #include <iostream>
// using namespace std;

// int main() {
//    double balance = 1000.0;  
//    double amount;
//    int choice;

//    cout << "Welcome to the ATM Simulation!\n";
   
//    while (true) {  
//        cout << "\nCurrent Balance: $" << balance << "\n";
//        cout << "Enter amount to withdraw: $";
//        cin >> amount;

//        if (amount <= balance) {
//            balance -= amount;
//            cout << "Withdrawal successful! New Balance: $" << balance << "\n";
//        } else {
//            cout << "Insufficient balance. Try a smaller amount.\n";
//        }

//        cout << "Do you want to make another transaction? (y/n): ";
//        cin >> choice;

//        if (choice == 'n' || choice == 'N') {
//            cout << "Thank you for using the ATM! Goodbye.\n";
//            break;  
//        }
//    }
   
//    return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//    string correctPassword = "secure123";  // The correct password
//    string inputPassword;
//    int attempts = 0;
//    const int maxAttempts = 3;

//    do {
//    	cout<<"****WELCOME TO BANK OF BARODA (BOB)******\n";
//        cout << "Enter your password: ";
//        cin >> inputPassword;
//        attempts++;

//        if (inputPassword != correctPassword) {
//            cout << "Incorrect password. Please try again.\n";
//        }

//        if (attempts >= maxAttempts && inputPassword != correctPassword) {
//            cout << "Maximum attempts reached. Access denied.\n";
//            return 0;
//        }
//    } while (inputPassword != correctPassword);

//    cout << "Password accepted. Access granted.\n";

//    return 0;
// }

// #include<iostream>
// using namespace std;

// int main() {
//    int i, j, k = 0, heart_rate;
//    cout << "\n*****For how many days you wanna report?:*******\n";
//    cin >> j;
//    for(i = 1; i <= j; i++) {
//        cout << "\nEnter Heart Rate of Day " << i << ": ";
//        cin >> heart_rate;
//        if(heart_rate > 72) {
//            cout << "Dangerous! Just be careful\n";
//            k += heart_rate;
//        } else {
//            cout << "NORMAL!\n";
//        }
//    }
//    if(j > 0 && (k / j) > 72) {
//        cout << "\nReport: BAD";
//    } else {
//        cout << "\nReport: HEALTHY HEART!";
//    }

//    return 0;
// }





// #include <iostream>
// #include <string>
// using namespace std;

// int bookCount = 0;

// int main() {
//     int choice;
    
//     do {
//         cout << "Library Management System\n";
//         cout << "1. Add Book\n";
//         cout << "2. Issue Book\n";
//         cout << "3. Return Book\n";
//         cout << "4. View Books\n";
//         cout << "5. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;
//         int id;
//         string title;
//         char issued = 'N'; // Declare issued here to avoid multiple declarations

//         switch (choice) {
//             case 1:
//                 cout << "Enter Book ID: ";
//                 cin >> id;
//                 cin.ignore(); // Clear the newline character from the input buffer
//                 cout << "Enter Book Title: ";
//                 getline(cin, title); // Use getline to allow spaces in the title
//                 cout << "Book added successfully! (ID: " << id << ", Title: " << title << ", Issued: " << issued << ")\n";
//                 bookCount++;
//                 break;
//             case 2:
//                 cout << "Enter Book ID to issue: ";
//                 cin >> id;
//                 cin.ignore(); // Clear the newline character from the input buffer
//                 cout << "Enter Book Title to issue: ";
//                 getline(cin, title); // Use getline to allow spaces in the title
//                 cout << "Book issued successfully! (ID: " << id << ", Title: " << title << ", Issued: Y)\n";
//                 break;
//             case 3:
//                 cout << "Enter Book ID to return: ";
//                 cin >> id;
//                 cin.ignore(); // Clear the newline character from the input buffer
//                 cout << "Enter Book Title to return: ";
//                 getline(cin, title); // Use getline to allow spaces in the title
//                 cout << "Book returned successfully! (ID: " << id << ", Title: " << title << ", Issued: N)\n";
//                 break;
//             case 4:
//                 cout << "Views are currently closed.\n";
//                 break;
//             case 5:
//                 cout << "Exiting the system...\n";
//                 break;
//             default:
//                 cout << "Invalid choice. Please try again.\n";
//                 break;
//         }
//     } while (choice != 5);

//     return 0;
// }






// #include <iostream>
// using namespace std; 
// int main() {
//     double balance = 1000.0;  
//     double amount;
//     char choice; 
//     cout << "Welcome to the ATM Simulation!\n";
//     while (true) {  
//         cout << "\nCurrent Balance: $" << balance << "\n";
//         cout << "Enter amount to withdraw: $";
//         cin >> amount;
//         if (amount <= balance) {
//             balance -= amount;
//             cout << "Withdrawal successful! New Balance: $" << balance << "\n";
//         } else {
//             cout << "Insufficient balance. Try a smaller amount.\n";
//         }

//         cout << "Do you want to make another transaction? (y/n): ";
//         cin >> choice;

//         if (choice == 'n' || choice == 'N') {
//             cout << "Thank you for using the ATM! Goodbye.\n";
//             break;  
//         }
//     }
//     return 0;
// }
