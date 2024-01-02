#include <iostream> 
#include <fstream>   
#include"Candy.h"
#include"Employee.h"
#include"Commission.h"

using namespace std;

const int No_of_entries = 5;

Employee employees[No_of_entries];
Candy candies[No_of_entries];
Commission Commissions[No_of_entries];

void menu() {
	int sys_choice;
	cout << "\n1. Managing candies\n";
	cout << "2. Managing employees\n";
	cout << "3. Managing Commissions\n";
	cout << "4. To exit\n";

	cout << "Entity choice = \t";
	cin >> sys_choice;

	while (sys_choice != 1 && sys_choice != 2 && sys_choice != 3 && sys_choice != 4) {
		cout << "Wrong input!\n Enter again ('1' or '2' or '3' or '4') = \t";
		cin >> sys_choice;
	}

	while (true) {
		if (sys_choice == 4) {
			return;
		}
		int action;
		cout << "\nWhat do you wish to do ?\n";
		cout << "1. Enter data.\n";
		cout << "2. View data.\n";
		cout << "3. Search in the database.\n";
		cout << "4. Change an attribute.\n";
		cout << "5. Delete an entire entry.\n";
		cout << "6. Go back\n";
		cout << "\nFunction choice: \t";
		cin >> action;

		while (action != 1 && action != 2 && action != 3 && action != 4 && action != 5 && action != 6) {
			cout << "Wrong input!\n Enter again = \t";
			cin >> action;
		}

		if (sys_choice == 1) {
			switch (action) {
			case 1:
				if (can_entries < No_of_entries) {
					cout << "\nEntering data of a new Candy.\n";
					AddEntry_candy(candies, No_of_entries);
					break;
				}
				else {
					cout << "Maximum number of candies reached. Please restart the program to add a new entry.";
					break;
				}
			case 2:
				cout << "\nViewing data of all the previous candies.\n";
				ViewCandies_candy(candies);
				break;
			case 3:
				cout << "\nSearching for a Candy among the listed candies.\n";
				int id;
				cout << "Enter ID to search for: ";
				cin >> id;

				while (id < 231000 || id > 231999) {
					cout << "Enter a '6' digit number starting with 231 for an ID.\n";
					cout << "\nEnter product Id = \t";
					cin >> id;
				}
				if (!Search_candy(candies, id)) {
					cout << "ID not found";
				}
				break;
			case 4:
				cout << "\nChanging an attribute of a Candy.\n";
				Update_candy(candies);
				break;
			case 5:
				cout << "\nDeleting an entire entry.\n";
				Delete_candy(candies);
				break;
			case 6:
				menu();
				break;
			default:
				cout << "Something went wrong!!!";
				break;
			}
		}
		else if (sys_choice == 2) {
			switch (action) {
			case 1:
				if (emp_entries < No_of_entries) {
					cout << "\nEntering data of a new employee.\n";
					AddEntry_employees(employees, No_of_entries);
					break;
				}
				else {
					cout << "Maximum number of employees reached. Please restart the program to add a new entry.";
					break;
				}
			case 2:
				cout << "\nViewing data of all the employees.\n";
				View_employees(employees);
				break;
			case 3:
				cout << "\nSearching for an employee among the listed candies.\n";
				int id;
				cout << "Enter Employee ID to search for: ";
				cin >> id;

				while (id < 100 || id > 999) {
					cout << "Enter a '3' digit number for an ID.\n";
					cout << "\nEnter employee Id = \t";
					cin >> id;
				}
				if (!Search_employees(employees, id)) {
					cout << "ID not found";
				}
				break;
			case 4:
				cout << "\nChanging an attribute of an employee.\n";
				Update_employees(employees);
				break;
			case 5:
				cout << "\nDeleting an entire entry.\n";
				Delete_employees(employees);
				break;
			case 6:
				menu();
				break;
			default:
				cout << "Something went wrong!!!";
				break;
			}
		}
		else if (sys_choice == 3) {
			switch (action) {
			case 1:
				if (com_entries < No_of_entries) {
					cout << "\nEntering Data Of A New Comissin Record.\n";
					AddEntry_Commission_Record(Commissions, No_of_entries, employees, emp_entries, candies, can_entries);
					break;
				}
				else {
					cout << "Maximum number of employees reached. Please restart the program to add a new entry.";
					break;
				}
			case 2:
				cout << "\nViewing data of all the previous candies.\n";
				View_Commission_Record(Commissions);
				break;
			case 3:
				cout << "\nSearching for an employee among the listed candies.\n";
				int id;
				cout << "Enter Employee ID to search for: ";
				cin >> id;

				while (id < 100 || id > 999) {
					cout << "Enter a '3' digit number for an ID.\n";
					cout << "\nEnter Employee Id = \t";
					cin >> id;
				}
				if (!Search_Commission_Record(Commissions, id)) {
					cout << "ID not found";
				}
				break;
			case 4:
				cout << "\nChanging an attribute of an employee.\n";
				Update_Commission_Record(Commissions);
				break;
			case 5:
				cout << "\nDeleting an entire entry.\n";
				Delete_Commission_Record(Commissions);
				break;
			case 6:
				menu();
				break;
			default:
				cout << "Something went wrong!!!";
				break;
			}
		}
	}
}


int main() {
	cout << "   -------------------------------\n";
	cout << "   -CANDY SHOP Management SYSTEM-\n";
	cout << "   -------------------------------\n";

	ofstream fout;
	fout.open("Employees.txt", ios::app);
	if (!fout.is_open()) {
		cout << "Error opening Employees.txt for writing!" << endl;
		return 1;
	}
	fout.close();

	fout.open("Candies.txt", ios::app);
	fout.close();


	fout.open("Commission.txt", ios::app);
	fout.close();

	ifstream fin;

	fin.open("Candies.txt");

	while (fin >> candies[can_entries].id
		>> candies[can_entries].name
		>> candies[can_entries].Boxes_per_Week
		>> candies[can_entries].Profit_per_Week) {
		can_entries++;
	}
	fin.close();

	fin.open("Employees.txt");

	while (fin >> employees[emp_entries].employee_id
		>> employees[emp_entries].employee_name
		>> employees[emp_entries].hourly_wage
		>> employees[emp_entries].weekly_hours_worked)
	{
		emp_entries++;
	}
	fin.close();

	fin.open("Commission.txt");

	while (fin >> Commissions[com_entries].employee_id
		>> Commissions[com_entries].candy_id
		>> Commissions[com_entries].boxes_sold
		>> Commissions[com_entries].Commission)
	{
		com_entries++;
	}
	fin.close();

	menu();
	return 0;
}