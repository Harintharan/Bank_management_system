#include <iostream>
#include<string>
using namespace std;

class Node
{
public:
	float val;
	float valu;
	float cash;
	string phnnum;
	string email;
	string F_name;
	string L_name;
	string Nic;
	Node* next;

	Node() {
		val = 0;
		valu = 0;
		cash = 0;
		phnnum = "07";
		email = "n";
		F_name = "n";
		L_name = "n";
		Nic = "0";
		next = NULL;
	}
};


class Bank
{
public:
	Node* head;

public:
	int length =0;

	Bank()
	{
		head = NULL;
	}

	void open_Account();//For Create a Account
	void Display_Details();//For Display the Account holder details
	void update(string);//For Update Account holder details
	void Delete_Account(string);//For Delete specific account by NIC
	void Diposite(string );//For Diposite cash
	void Withdrawal(string );//For Withdraw cash
	void Balance_inquary(string);//For Balance check
};


void Bank::open_Account()
{
	//Node* temp = NULL;
	//Node* A = NULL;
	Node* temp = new Node();
	int x, y;
	float amo;
	int ch1 = 1;
	string Fna, phn, Id;
	string Lna;
	string em;

	while (ch1 == 1)
	{
		x = rand() % 10;
		y = rand() % 10000;
		cout << endl;
		cout << "Enter the First Name : ";
		cin >> Fna;
		cout << "Enter the last Name : ";
		cin >> Lna;
		cout << "Enter the Phone number : ";
		cin >> phn;
		cout << "Enter the Email ID : ";
		cin >> em;
		cout << "Enter the NIC or Driving licence Number : ";
		cin >> Id;
		cout << "Enter the 1st Input cash (in Rupees) : ";
		cin >> amo;

		if (head == NULL)
		{
			//Node* temp = new Node();
			temp->F_name = Fna;
			temp->L_name = Lna;
			temp->cash = amo;
			temp->email = em;
			temp->Nic = Id;
			temp->val = x;
			temp->valu = y;
			temp ->phnnum = phn;
			temp->next = NULL;
			head=temp;
			length++;
		}

		else
		{
			//Node* temp = new Node();
			temp->F_name = Fna;
			temp->L_name = Lna;
			temp->cash = amo;
			temp->email = em;
			temp->Nic = Id;
			temp->val = x;
			temp->valu = y;
			temp->phnnum = phn;
			
			Node* current = head;

			while (current->next != NULL) {
				current = current->next;
			}
			current->next = temp;
			length++;	
		}
		cout << "Account number : 102-2001-" << head->val << "00" << temp->val << "-" << temp->valu << endl;
		cout << "\n~!!! CREATED ACCOUNT SUCCESSFULLY !!!";
		cout << "\n\n ENTER 0 TO RETURN CHOICE: ";
		cin >> ch1;
		cout << endl;
	}
}

void Bank::Display_Details()//To display Display Account holder Details
{
	if (head == NULL)
	{
		cout << "\nThere is no data found!!";
		return;
	}
		cout << "\nBank Acoount Management System\n";	
		cout << "---------------------------------\n";
		Node* current = head;
		while (current!= nullptr)
		{
			cout <<"\nAccount number : 102-2001-" << current->val << "00" << current->val << "-" << current->valu  << "\nLAST NAME: " << current->L_name << "\nFIRST NAME: " << current->F_name << "\nPHONE NUMBER: " << current->phnnum << "\nNIC NUMBER: " << current->Nic << "\nEMAIL: " << current->email << "\nAMOUNT: Rs. " << current->cash << "\n";
			cout << endl;
			cout << endl;
			current = current->next;
		}	
		cout << "* Total Account Holders : " << length;		
	
}

void Bank::Delete_Account(string nic_num)// Delete function
{
	Node* current = head;
	Node* temp = NULL;
	
	while (current != NULL && current->Nic != nic_num)// Search for the customer with the given account::nic number
	{
		temp = current;
		current = current->next;
	}

	if (current != NULL) 	// If the customer is found, delete their account
	{
		if (temp == NULL) 	// If the customer is at the head of the list
		{
			head = current->next;
		}
		else {
			temp->next = current->next;
		}
		delete current;
		length--;
		cout << "Account deleted successfully" << endl;
	}
	else {
		cout << "Account not found" << endl;
	}
}


void Bank::Diposite(string Nic )
{
	Node* current = head;
	float amt;
	bool found = false;
	if (head == NULL)
	{
		cout << "Account is not found" << endl;
	}
	else {
		string nid;
		cout << "Enter Customer NIC : ";
		cin >> nid;
		while (current != NULL)
		{
			if (current->Nic == nid)
			{
				found = true;
				break;
			}
			current = current->next;
		}
	}

	if (found)
	{
		float amt;
		cout << "Enter the Amount you want to deposite : ";
		cin >> amt;
		float total = current->cash + amt;
		current-> cash = total;
		cout << "After deposition your total amount in account is Rs." << total << endl;
	}
	else
		cout << "~~INVALID NIC~~" << endl;
}


void Bank :: Withdrawal(string Nic)
{
	Node* current = head;
	float amt;
	bool found = false;
	if (head == NULL)
	{
		cout << "Account is not found" << endl;
	}
	else {
		string nid;
		cout << "Enter Customer NIC : ";
		cin >> nid;
		while (current != NULL)
		{	
			if (current->Nic == nid)
			{
				found = true;
				break;
			}
			current = current->next;
		}
	}

	if (found)
	{
		cout << "Enter the Amount you want to Withdraw : ";
		cin >> amt;
		if (current->cash >= amt)
		{
			float total = current->cash - amt;
			current->cash = total;
			cout << "After Withdrawal your total amount in account is Rs." << total << endl;
		}
		else
		{
			cout << "Your Account Balance Not Enough" << endl;
		}
	}
	else
		cout << "\n~~INVALID NIC~~";
}


void Bank::update(string nic_num)
{
	Node* current = head;
	Node* prev = NULL;

	while (current != nullptr && current->Nic != nic_num)	// Search for the customer with the given account::nic number
	{
		prev = current;
		current = current->next;
	}

	float new_val;
	string new_phnnum;
	string new_email;
	string new_F_name;
	string new_L_name;
	string new_Nic;

	cout << "\nEnter name : ";
	cin >> new_F_name;
    cout << "Enter last name : ";
	cin >> new_L_name;
	cout << "Enter phone number : ";
	cin >> new_phnnum;
	cout << "Enter email id : ";
	cin >> new_email;
	cout << "Enter NIC : ";
	cin >> new_Nic;

	current->F_name =new_F_name;
	current->L_name = new_L_name;
	current->email = new_email;
	current->Nic = new_Nic;
	current->phnnum = new_phnnum;
}


void Bank::Balance_inquary( string NIC)
{
	Node* current = head;
	bool found = false;
	if (head == NULL)
	{
		cout << "Account is not found" << endl;
	}
	else {
		string nid;
		cout << "Enter Customer NIC : ";
		cin >> nid;
		while (current != NULL)
		{			
			if (current->Nic == nid)
			{
				found = true;
				break;
			}
			current = current->next;
		}
	}

	if (found)
	{	
		cout << "The cash in Account = Rs.";
		cout << current->cash;
		cout << endl;
	}
	else
		cout << "\n~~INVALID NIC~~";
}