#pragma once
#include <iostream>
#include <fstream>
using namespace std;

int can_entries = 0;

struct Candy {
	int id;
	string name;
	int Boxes_per_Week;
	int Profit_per_Week;
};
// arrays is passed by refrence no need to declare & sign

void AddEntry_candy(Candy candies[], const int& No_of_entries){

	if (can_entries < No_of_entries) {

		ofstream fout;
		fout.open("Candies.txt", ios::app);

		cout << "\nEnter Candy details:\n";
		cout << "ID (6-digit number starting with 231): ";
		cin >> candies[can_entries].id;

		while (candies[can_entries].id < 231000 || candies[can_entries].id > 231999) {
			cout << "Enter a '6' digit number starting with 231 for an ID.\n";
			cout << "\nEnter product Id = \t";
			cin >> candies[can_entries].id;
		}

		for (int i = 0; i < can_entries; ++i) {
			if (candies[i].id == candies[can_entries].id) {
				cout << "This ID already exists. Please enter a different ID.\n";
				return;
			}
		}

		cout << "Name: ";
		cin >> candies[can_entries].name;

		cout << "Boxes sold per week: ";
		cin >> candies[can_entries].Boxes_per_Week;

		cout << "Profit per week: ";
		cin >> candies[can_entries].Profit_per_Week;

		fout << candies[can_entries].id << "\t";
		fout << candies[can_entries].name << "\t";
		fout << candies[can_entries].Boxes_per_Week << "\t";
		fout << candies[can_entries].Profit_per_Week << endl;

		can_entries++;
		fout.close();
	}
	else {
		cout << "Maximum candies reached!\n";
	}
}
void ViewCandies_candy(const Candy candies[]) {
	cout << "Candy candies:\n";
	cout << "ID\tName\t\tBoxes Sold\tProfit\n";
	for (int i = 0; i < can_entries; ++i) {
		cout << candies[i].id << "\t" << candies[i].name;
		if (candies[i].name.length() < 8) {
			cout << "\t\t";
		}
		else {
			cout << "\t";
		}
		cout << candies[i].Boxes_per_Week << "\t\t" << candies[i].Profit_per_Week << endl;
	}
}
bool Search_candy(const Candy candies[], const int& search_id) {

	for (int i = 0; i < can_entries; ++i) {
		if (candies[i].id == search_id) {
			cout << "ID found\n\n";
			cout << "Candy with ID " << search_id << " found:\n";
			cout << "ID: " << candies[i].id << "\nName: " << candies[i].name
				<< "\nBoxes Sold: " << candies[i].Boxes_per_Week
				<< "\nProfit: " << candies[i].Profit_per_Week << endl;
			return true;
		}
	}
	return false;
}
void Update_candy(Candy candies[]) {
	ofstream fout;
	fout.open("Candies.txt");

	int update_id;
	cout << "Enter ID to update: ";
	cin >> update_id;

	if (!Search_candy(candies, update_id)) {
		cout << "Candy with ID " << update_id << " not found.\n";
		return;
	}

	for (int i = 0; i < can_entries; ++i) {
		if (candies[i].id == update_id) {
			int choice;
			cout << "Candy found! What do you wish to update?\n";
			cout << "1. Name\n";
			cout << "2. Boxes sold per week\n";
			cout << "3. Profit per week\n";
			cout << "Enter choice: ";
			cin >> choice;

			switch (choice) {
			case 1:
				cout << "Enter new Name: ";
				cin >> candies[i].name;
				break;
			case 2:
				cout << "Enter new Boxes sold per week: ";
				cin >> candies[i].Boxes_per_Week;
				break;
			case 3:
				cout << "Enter new Profit per week: ";
				cin >> candies[i].Profit_per_Week;
				break;
			default:
				cout << "Invalid choice!\n";
				break;
			}

			cout << "Candy details updated for ID " << update_id << ".\n";
		}

		fout << candies[i].id << "\t" << candies[i].name;
		fout << candies[i].Boxes_per_Week << "\t" << candies[i].Profit_per_Week << endl;
	}

	fout.close();
}
void Delete_candy(Candy candies[]) {
	ofstream fout;
	fout.open("Candies.txt");
	int delete_id;
	cout << "Enter ID to delete: ";
	cin >> delete_id;

	bool found = false;
	for (int i = 0; i < can_entries; ++i) {
		if (candies[i].id == delete_id) {
			found = true;
			for (int j = i; j < can_entries - 1; ++j) {
				candies[j] = candies[j + 1];
			}
			can_entries--;
			cout << "Candy with ID " << delete_id << " deleted successfully.\n";
			break;
		}
	}
	for (int i = 0; i < can_entries; ++i) {
		fout << candies[i].id << "\t" << candies[i].name << "\t" << candies[i].Boxes_per_Week << "\t" << candies[i].Profit_per_Week << endl;
	}
	fout.close();

	if (!found) {
		cout << "Candy with ID " << delete_id << " not found.\n";
	}
}



