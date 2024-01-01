#pragma once
#include <iostream> 
#include <fstream>  
using namespace std;

int emp_entries = 0;

struct Employee {
	int employee_id;
	string employee_name;
	float hourly_wage;
	int weekly_hours_worked;
};

// arrays is passed by refrence no need to declare & sign
void AddEntry_employees(Employee employees[], const int& No_of_entries) {
	ofstream fout;
	fout.open("Employees.txt", ios::app);

	if (emp_entries < No_of_entries) {
		cout << "\nEnter employee ID (3-digit number): ";
		cin >> employees[emp_entries].employee_id;

		while (employees[emp_entries].employee_id < 100 || employees[emp_entries].employee_id > 999) {
			cout << "\nID must be a 3-digit number.\n";
			cout << "Enter employee ID (3-digit number): ";
			cin >> employees[emp_entries].employee_id;
		}

		for (int i = 0; i < emp_entries; ++i) {
			if (employees[i].employee_id == employees[emp_entries].employee_id) {
				cout << "This ID already exists. Please enter a different ID.\n";
				return;
			}
		}

		cout << "Enter Employee Name: ";
		cin >> employees[emp_entries].employee_name;

		cout << "Enter Hourly Wage: ";
		cin >> employees[emp_entries].hourly_wage;

		cout << "Enter Weekly Hours Worked: ";
		cin >> employees[emp_entries].weekly_hours_worked;



		fout << employees[emp_entries].employee_id << "\t";
		fout << employees[emp_entries].employee_name << "\t";
		fout << employees[emp_entries].hourly_wage << "\t";
		fout << employees[emp_entries].weekly_hours_worked << "\n";

		fout.close();
		emp_entries++;
	}
	else {
		cout << "Maximum entries reached!\n";
	}
}
void View_employees(const Employee employees[]) {
	cout << "Employee ID\t"<<"Employee Name\t"<<"Hourly Wage\t"<< "Weekly Hours Worked\n";
	for (int i = 0; i < emp_entries; ++i) {
		cout << employees[i].employee_id << "\t\t"
			<< employees[i].employee_name << "\t\t" 
			<< employees[i].hourly_wage << "\t\t"
			<< employees[i].weekly_hours_worked << endl;
	}
}
bool Search_employees(const Employee employees[], const int& Check_ID) {

	for (int i = 0; i < emp_entries; ++i) {
		if (employees[i].employee_id == Check_ID) {
			cout << "ID Found \n\n";
			cout << "Employee ID: \t" << employees[i].employee_id << endl;
			cout << "Employee Name: " << employees[i].employee_name << endl;
			cout << "Hourly Wage: \t" << employees[i].hourly_wage << endl;
			cout << "Weekly Hours Worked: " << employees[i].weekly_hours_worked << endl;
			return true;
		}
	}

	cout << "Incorrect ID!!!\nOR Employee with ID " << Check_ID << " is not present.\n";
	return false;
}
void Update_employees(Employee employees[]) {
	ofstream fout;
	fout.open("Employees.txt");

	int check_id;
	int Update_Choice;
	bool id_found = false;

	cout << "Enter the ID of the employee you want to change the attribute of: ";
	cin >> check_id;

	while (check_id < 100 || check_id > 999) {
		cout << "Enter a '3' digit number for an ID: ";
		cin >> check_id;
	}
	if (!Search_employees(employees, check_id)) {
		cout << "Employe with ID " << check_id << " not found.\n";
		return;
	}
	for (int i = 0; i < emp_entries; ++i) {
		if (employees[i].employee_id == check_id) {
			id_found = true;
			cout << "What do you wish to change?\n";
			cout << "1. Change Employee Name.\n";
			cout << "2. Change Hourly Wage.\n";
			cout << "3. Change Weekly Hours Worked.\n";
			cout << "Enter choice: ";
			cin >> Update_Choice;

			while (Update_Choice != 1 && Update_Choice != 2 && Update_Choice != 3) {
				cout << "Wrong input!\t Enter again: ";
				cin >> Update_Choice;
			}

			switch (Update_Choice) {
			case 1:
				cout << "Enter Employee Name: ";
				cin >> employees[i].employee_name;
				break;
			case 2:
				cout << "Enter Hourly Wage: ";
				cin >> employees[i].hourly_wage;
				break;
			case 3:
				cout << "Enter Weekly Hours Worked: ";
				cin >> employees[i].weekly_hours_worked;
				break;
			default:
				cout << "Something went wrong!!!";
				break;
			}
		}

		fout << employees[i].employee_id << "\t";
		fout << employees[i].employee_name << "\t";
		fout << employees[i].weekly_hours_worked << "\t";
		fout << employees[i].hourly_wage << "\n";
	}

	if (!id_found) {
		cout << "Employee with ID " << check_id << " is not found.\n";
	}
	fout.close();
}
void Delete_employees(Employee employees[]) {
	ofstream fout;
	fout.open("Employees.txt");

	int delete_id;
	bool id_found = false;

	cout << "Enter the ID of the employee you want to remove: ";
	cin >> delete_id;

	while (delete_id < 100 || delete_id > 999) {
		cout << "Enter a '3' digit number for an ID: ";
		cin >> delete_id;
	}

	for (int i = 0; i < emp_entries; ++i) {
		if (employees[i].employee_id == delete_id) {
			id_found = true;

			for (int j = i; j < emp_entries - 1; ++j) {
				employees[j] = employees[j + 1];
			}
			emp_entries--;
			break; 
		}
	}

	for (int i = 0; i < emp_entries; ++i) {
		fout << employees[i].employee_id << "\t";
		fout << employees[i].employee_name << "\t";
		fout << employees[i].weekly_hours_worked << "\t";
		fout << employees[i].hourly_wage << "\n";
	}

	if (id_found) {
		cout << "Employee with ID " << delete_id << " has been successfully deleted.\n";
	}
	else {
		cout << "Employee with ID " << delete_id << " is not found.\n";
	}
	fout.close();
}



