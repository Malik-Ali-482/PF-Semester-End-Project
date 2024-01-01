#pragma once
#include <iostream> 
#include <fstream>  

using namespace std;

int com_entries = 0;


struct Commission
{
	int candy_id;
	int employee_id;
	int boxes_sold;
	double Commission;
};
// arrays is passed by refrence no need to declare & sign
void AddEntry_Commission_Record(Commission Commissions[], const int& No_of_entries,
	Employee employees[], const int& emp_entries,
	Candy candies[], const int& can_entries) {
	ofstream fout;
	fout.open("Commission.txt", ios::app);

	if (com_entries < No_of_entries) {
		cout << "Enter Employee ID: ";
		cin >> Commissions[com_entries].employee_id;

		// Check if the entered employee ID exists
		bool employeeIDExists = false;
		for (int i = 0; i < emp_entries; ++i) {
			if (employees[i].employee_id == Commissions[com_entries].employee_id) {
				employeeIDExists = true;
				break;
			}
		}

		if (!employeeIDExists) {
			cout << "Employee ID specified does not exist in the records.\n";
			return;
		}

		// Similar checking for candy ID
		cout << "Enter Candy ID: ";
		cin >> Commissions[com_entries].candy_id;

		// Check if the entered candy ID exists
		bool candyIDExists = false;
		for (int i = 0; i < can_entries; ++i) {
			if (candies[i].id == Commissions[com_entries].candy_id) {
				candyIDExists = true;
				break;
			}
		}

		if (!candyIDExists) {
			cout << "Candy ID specified does not exist in the records.\n";
			return;
		}
		cout << "Enter Boxes Sold: ";
		cin >> Commissions[com_entries].boxes_sold;

		cout << "Enter Commission Earned By An Employe: ";
		cin >> Commissions[com_entries].Commission;



		fout << Commissions[com_entries].employee_id << "\t";
		fout << Commissions[com_entries].candy_id << "\t";
		fout << Commissions[com_entries].boxes_sold << "\t";
		fout << Commissions[com_entries].Commission << "\n";

		fout.close();
		com_entries++;
	}
	else {
		cout << "Maximum entries reached!\n";
	}
}
void View_Commission_Record(const Commission Commissions[]) {
	cout << "Employe ID\tCandy ID \tBoxes Sold\tCommission Made\n";
	for (int i = 0; i < com_entries; ++i) {
		cout << Commissions[i].employee_id << "\t\t"
			<< Commissions[i].candy_id << "\t\t" \
			<< Commissions[i].boxes_sold << "\t\t"
			<< Commissions[i].Commission << endl;
	}
}
bool Search_Commission_Record(const Commission Commissions[], const int& Check_ID) {

	for (int i = 0; i < com_entries; ++i) {
		if (Commissions[i].employee_id == Check_ID) {
			cout << "ID Found \n\n";
			cout << "Employee ID: " << Commissions[i].employee_id << endl;
			cout << "Candy ID: \t" << Commissions[i].candy_id << endl;
			cout << "Boxes Sold: \t" << Commissions[i].boxes_sold << endl;
			cout << "Commission Made: " << Commissions[i].Commission << endl;
			return true;
		}
	}

	cout << "Incorrect ID!!!\nOR Employee with ID " << Check_ID << " is not present.\n";
	return false;
}
void Update_Commission_Record(Commission Commissions[]) {
	ofstream fout;
	fout.open("Commision.txt");

	int check_id;
	int Update_Choice;
	bool id_found = false;

	cout << "Enter the ID of the employee you want to change the attribute of: ";
	cin >> check_id;

	while (check_id < 100 || check_id > 999) {
		cout << "Enter a '3' digit number for an ID: ";
		cin >> check_id;
	}
	if (!Search_Commission_Record(Commissions, check_id)) {
		cout << "Employe with ID " << check_id << " not found.\n";
		return;
	}
	for (int i = 0; i < com_entries; ++i) {
		if (Commissions[i].employee_id == check_id) {
			id_found = true;
			cout << "What do you wish to change?\n";
			cout << "1. Change Boxes Sold By An Employe.\n";
			cout << "2. Change Commission Made By An Employe.\n";
			
			cout << "Enter choice: ";
			cin >> Update_Choice;

			while (Update_Choice != 1 && Update_Choice != 2 ) {
				cout << "Wrong input!\t Enter again: ";
				cin >> Update_Choice;
			}

			switch (Update_Choice) {
			case 1:
				cout << "Enter Boxes sold by Employee: ";
				cin >> Commissions[i].boxes_sold;
				break;
			case 2:
				cout << "Enter Commission of Employee: ";
				cin >> Commissions[i].Commission;
				break;
			default:
				cout << "Something went wrong!!!";
				break;
			}
		}

		fout << Commissions[i].employee_id << "\t";
		fout << Commissions[i].candy_id << "\t";
		fout << Commissions[i].boxes_sold << "\t";
		fout << Commissions[i].Commission << "\n";
	}

	if (!id_found) {
		cout << "Employee with ID " << check_id << " is not found.\n";
	}
	fout.close();
}
void Delete_Commission_Record( Commission Commissions[]) {
	ofstream fout;
	fout.open("Commision.txt");

	int delete_id;
	bool id_found = false;

	cout << "Enter the ID of the employee you want to remove its record: ";
	cin >> delete_id;

	while (delete_id < 100 || delete_id > 999) {
		cout << "Enter a '3' digit number for an ID: ";
		cin >> delete_id;
	}

	for (int i = 0; i < com_entries; ++i) {
		if (Commissions[i].employee_id == delete_id) {
			id_found = true;

			for (int j = i; j < com_entries - 1; ++j) {
				Commissions[j] = Commissions[j + 1];
			}
			com_entries--;
			break;
		}
	}

	for (int i = 0; i < com_entries; ++i) {
		fout << Commissions[i].employee_id << "\t";
		fout << Commissions[i].candy_id << "\t";
		fout << Commissions[i].boxes_sold << "\t";
		fout << Commissions[i].Commission << "\n";
	}

	if (id_found) {
		cout << "Employee with ID " << delete_id << " has been successfully deleted.\n";
	}
	else {
		cout << "Employee with ID " << delete_id << " is not found.\n";
	}
	fout.close();
}

