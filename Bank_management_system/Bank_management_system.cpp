#include<string>
#include <iostream>
#include"system_functions.h"
using namespace std;

int main()
{
	Bank B;// object has declared
	string ch;
	int choice;
	cout << "\n****---- BANK MANAGEMENT SYSTEM----****";
	cout << "\n=======================================\n";
	cout << "\nPress any key to start : ";
	cin >> ch;
	string Nic;

	do
	{
		cout << endl;
		cout << "\n **MENU LIST**";
		cout << "\n1.open Account\n2.Deposite\n3.withdrawal\n4.Update\n5.DeleteAccount\n6.balance inquary\n7.DisplayDetails\n8.exit ";
		cout << "\n \n ENTER YOUR CHOICE  : ";
		cin >> choice;
		switch (choice)// Switch case
		{
		case 1:
			B.open_Account();//createlist function is called
			break;

		case 2:			
			B.Diposite(Nic);
			break;
		
		case 3:		
			B.Withdrawal(Nic);
			break;
		
		case 4:
			cout << "\n UPDATE AN ACCOUNT\n" << endl;
			cout << "Enter the IC Numer : ";
			cin >> Nic;
			B.update(Nic);
			//B.Display_Details();
			break;
		
		case 5:
			cout << "\n DELETE AN ACCOUNT\n" << endl;
			cout << "Enter the IC Numer : ";
			cin >> Nic;
			B.Delete_Account(Nic);
			//B.Display_Details();
			break;
		
		case 6:
			B.Balance_inquary(Nic);
			break;

		case 7:
			B.Display_Details();
			break;
		case 8:
			break;
		default:
			cout << "Invalid Choice >>>> Try Again" << endl;
			
			
		}

	}
	while (choice!=8);
	return 0;	
}

