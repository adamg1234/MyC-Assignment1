/*
* Main.cpp
*
* Version information: v0.1
* Author: Adam Graham
* Date: 21/10/2017
* Description: A Main.cpp application to run my mySystem
* Copyright notice
*/



#include<iostream>
#include<conio.h>
#include<windows.h>
#include<ctype.h>
#include <fstream>
#include<stdlib.h>
#include <cstdlib>
#include <regex>

#include "FlightSystem.h";
#include "Aircraft.h";

using namespace std;


void PressKey();
void AddAircraft();
void DisplayAircraft();
void RemoveAircraft();
void ChangeHeading();
void GetHeading();
void ChangeAltitude();
void GetAltitude();
void NumAircraftSector();
void Menu();
FlightSystem mySystem;
	

int main() {



	mySystem.AddAircraft("BA744", "British Airlines", "Airplane", 437, 37000, "A7", 180);
	mySystem.AddAircraft("TA18", "Turkish Airlines", "Airplane", 591, 33000, "B7", 0);
	mySystem.AddAircraft("AW82", "Irish Airlines  ", "Airplane", 232, 30000, "C9", 90);
	mySystem.AddAircraft("QR32", "French Airlines ", "Airplane", 232, 20000, "C9", 75);

	Menu();

	return 0;
}




void PressKey() {

	cout << "\n\n Please press a key.....";
	_getch();
	system("cls");
	Menu();
}

void AddAircraft() {

	string flightNumber;
	string airline;
	string aircraftType;
	int groundSpeed;
	int altitude;
	string gridReference;
	int heading;

	regex gridRef("[A-J][1-9]");

	system("cls");
	cout << "-----------------Add Aircraft--------------";
	cout << "\n\n\tPlease enter a flight number: ";
	cin >> flightNumber;
	cin.ignore();
	cout << "\n\tPlease enter an airline: ";
	getline(cin, airline);
	cout << "\n\tPlease enter an aircraft type: ";
	cin >> aircraftType;
	cout << "\n\tPlease enter a ground speed: ";
	cin >> groundSpeed;
	cout << "\n\tPlease enter a altitude: ";
	cin >> altitude;
	cout << "\n\tPlease enter a grid reference: ";
	cin >> gridReference;
	cout << "\n\tPlease enter a heading: ";
	cin >> heading;

	if (groundSpeed > 0 && altitude > 0) {
		if (regex_match(gridReference, gridRef)) {
			mySystem.AddAircraft(flightNumber, airline, aircraftType, groundSpeed, altitude, gridReference, heading);
			PressKey();
		}
		else {
			cout << "\n Grid Reference must be 1 letter and 1 number";
			PressKey();
		}
	}
	else {
		cout << "Invalid input! Please re-enter";
		PressKey();
	}

}

void DisplayAircraft() {

	int choice;
	cout << "\n\n\t 1. Display all aircrafts ";
	cout << "\n\n\t 2. Display all aircrafts above 30000 feet";
	cout << "\n\n\t Your choice: ";
	cin >> choice;


	if (choice == 1) {

		system("cls");
		cout << "----------------------------------------Display All Aircraft------------------------------------";

		cout << "\nFlight#  \t\tAirline  \tAltitude  \tSpeed  \tGrid  \Heading \n\n";

		string flightNumber;
		string airline;
		string aircraftType;
		int groundSpeed;
		int altitude;
		string gridReference;
		int heading;

		for (int i = 0; i < mySystem.NumAircraftSector(); i++) {

			flightNumber = mySystem.ListAllAircraft().at(i).GetFlightNumber();
			airline = mySystem.ListAllAircraft().at(i).GetAirline();
			altitude = mySystem.ListAllAircraft().at(i).GetAltitude();
			groundSpeed = mySystem.ListAllAircraft().at(i).GetGroundSpeed();
			gridReference = mySystem.ListAllAircraft().at(i).GetGridReference();
			heading = mySystem.ListAllAircraft().at(i).GetHeading();

			cout << flightNumber;
			cout << "\t\t\t" << airline;
			cout << "\t" << std::to_string(altitude);
			cout << "\t\t" << std::to_string(groundSpeed);
			cout << "\t" << gridReference;
			cout << "\t" << std::to_string(heading) << endl;



		}

		PressKey();
	}
	if (choice == 2) {

		system("cls");
		cout << "----------------------------------------Display All Crusing Aircraft------------------------------------";

		cout << "\nFlight#  \t\tAirline  \tAltitude  \tSpeed  \tGrid  \Heading \n\n";

		string flightNumber;
		string airline;
		string aircraftType;
		int groundSpeed;
		int altitude;
		string gridReference;
		int heading;


		for (int i = 0; i < mySystem.ListAllCruisingAircraft().size(); i++) {

			flightNumber = mySystem.ListAllCruisingAircraft().at(i).GetFlightNumber();
			airline = mySystem.ListAllCruisingAircraft().at(i).GetAirline();
			altitude = mySystem.ListAllCruisingAircraft().at(i).GetAltitude();
			groundSpeed = mySystem.ListAllCruisingAircraft().at(i).GetGroundSpeed();
			gridReference = mySystem.ListAllCruisingAircraft().at(i).GetGridReference();
			heading = mySystem.ListAllCruisingAircraft().at(i).GetHeading();

			cout << flightNumber;
			cout << "\t\t" << airline;
			cout << "\t" << std::to_string(altitude);
			cout << "\t\t" << std::to_string(groundSpeed);
			cout << "\t" << gridReference;
			cout << "\t" << std::to_string(heading) << endl;



		}

		PressKey();
	}

}

void RemoveAircraft() {

	string flightNum;
	system("cls");
	cout << "\n Please enter the flight you wish to remove: ";
	cin >> flightNum;

	mySystem.RemoveAircraft(flightNum);
	PressKey();

}

void ChangeHeading() {

	string changeFlight;
	int newHeading;
	system("cls");
	cout << "\n Please enter the flight you wish to change: ";
	cin >> changeFlight;

	cout << "\n Please enter the new heading for the flight: ";
	cin >> newHeading;

	mySystem.ChangeHeading(changeFlight, newHeading);
	PressKey();
}

void GetHeading() {

	string flightNum;
	system("cls");
	cout << "\n Please enter the flight you wish to view heading: ";
	cin >> flightNum;

	if (mySystem.GetHeading(flightNum) == 0) {

		cout << "\n Heading: Invalid ";
		PressKey();
	}
	else {
		cout << "\n Heading: " << mySystem.GetHeading(flightNum);
		PressKey();
	}
}

void ChangeAltitude() {

	string changeFlight;
	int newAltitude;
	system("cls");
	cout << "\n Please enter the flight you wish to change: ";
	cin >> changeFlight;

	cout << "\n Please enter the new altitude for the flight: ";
	cin >> newAltitude;

	mySystem.ChangeAltitude(changeFlight, newAltitude);
	PressKey();

}

void GetAltitude() {

	string flightNum;
	system("cls");
	cout << "\n Please enter the flight you wish to view altitude: ";
	cin >> flightNum;
	if (mySystem.GetAltitude(flightNum) == 0){

		cout << "\n Altitude: Invalid ";
		PressKey();
	}
	else {
		cout << "\n Altitude: " << mySystem.GetAltitude(flightNum);
		PressKey();
	}
}

void NumAircraftSector() {

	cout << "\n\tThe number of aircrafts in the sector: " << mySystem.NumAircraftSector();
	PressKey();
	system("cls");

}

void Menu() {

	system("cls");
	int num;

	do {

		cout << "\n\n\t 1. Add a Aircraft ";
		cout << "\n\n\t 2. List All Aircrafts";
		cout << "\n\n\t 3. Remove Aircraft";
		cout << "\n\n\t 4. Change Heading of an aircraft";
		cout << "\n\n\t 5. Get Heading of an aircraft";
		cout << "\n\n\t 6. Change the altitude of a specified aircraft";
		cout << "\n\n\t 7. Get the altitude of a specified aircraft";
		cout << "\n\n\t 8. Get the number of live aircraft in the system";
		cout << "\n\n\t 9. Exit";
		cout << "\n\n\t Your choice: ";
		cin >> num;


		if (num > 9 || num < 1)
			cout << "\nInvalid entry please re-enter";
		
		switch (num)
		{
		case 1:
			AddAircraft();
		case 2:
			DisplayAircraft();
		case 3:
			RemoveAircraft();
		case 4:
			ChangeHeading();
		case 5:
			GetHeading();
		case 6:
			ChangeAltitude();
		case 7:
			GetAltitude();
		case 8:
			NumAircraftSector();
		case 9:
			break;
		default:
			break;
		}



	} while (num != 9);

}

