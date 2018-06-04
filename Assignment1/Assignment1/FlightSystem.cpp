/*
* FlightSystem.cpp
*
* Version information: v0.1
* Author: Adam Graham
* Date: 21/10/2017
* Description: A FlightSystem.cpp application to hold my methods
* Copyright notice
*/

#include <iostream>;
#include <string>;


#include "FlightSystem.h"



FlightSystem::FlightSystem() {

}


FlightSystem::FlightSystem(std::vector<Aircraft> aircraftList) 
	: aircraftList_{ aircraftList } {

}


void FlightSystem::AddAircraft(std::string flightNumber, std::string airline, std::string aircraftType, int groundSpeed, int altitude, std::string gridReference, int heading) {


	bool valid = true;


	for (int i = 0; i < aircraftList_.size(); i++) {

		if (aircraftList_[i].GetFlightNumber() == flightNumber) {
			valid = false;
		}
		
	}

	if (valid == true)
	{
		for (int i = 0; i < aircraftList_.size(); i++) {

			if (gridReference == aircraftList_.at(i).GetGridReference()) {
				

				int min = aircraftList_[i].GetAltitude() - 3000;
				int max = aircraftList_[i].GetAltitude() + 3000;

				if (altitude >= min && altitude <= max) {
					std::cout << "Warning - Aircraft collision possible between " << flightNumber << " and " << aircraftList_[i].GetFlightNumber();
				}
				
			}
		}

		Aircraft a1(flightNumber, airline, aircraftType, groundSpeed, altitude, gridReference, heading);
		aircraftList_.push_back(a1);

		std::cout << "\n\n\t You have added a new aircraft";

	}
	else
		std::cout << "Flight " + flightNumber + " already in the system";
	
	
}

std::vector<Aircraft> FlightSystem::ListAllAircraft() {

	std::vector<Aircraft> displayAircraft;


	for (int i = 0; i < aircraftList_.size(); i++) {

			displayAircraft.push_back(aircraftList_[i]);

	}

	return displayAircraft;
}


std::vector<Aircraft> FlightSystem::ListAllCruisingAircraft() {

	std::vector<Aircraft> displayCruisingAircraft;


	for (int i = 0; i < aircraftList_.size(); i++) {

		if (aircraftList_[i].GetAltitude() >= 30000) {

			displayCruisingAircraft.push_back(aircraftList_[i]);
			
		}
		
	}

	return displayCruisingAircraft;
}

void FlightSystem::RemoveAircraft(std::string flightNumber) {

	bool valid = false;

	for (int i = 0; i < aircraftList_.size(); i++) {

		if (aircraftList_[i].GetFlightNumber() == flightNumber) {

			std::cout << "\n Flight " << aircraftList_[i].GetFlightNumber() << " has been removed";
			aircraftList_.erase(aircraftList_.begin() + i);
			valid = true;
		}
		
		
	}

	if (valid == false) {
		std::cout << "Flight " + flightNumber + " is not in the system";
	}

}

void FlightSystem::ChangeHeading(std::string flightNumber, int heading) {

	bool valid = false;

	for (int i = 0; i < aircraftList_.size(); i++) {

		if (aircraftList_[i].GetFlightNumber() == flightNumber) {
			aircraftList_[i].SetHeading(heading);
			std::cout << "Flight " + flightNumber + " changed to " + std::to_string(heading);
			valid = true;
		}

	}

	if (valid != true) {
		std::cout << "Flight " + flightNumber + " is not in the system";
	}
}


int FlightSystem::GetHeading(std::string flightNumber) {

	bool valid = false;

	for (int i = 0; i < aircraftList_.size(); i++) {

		if (aircraftList_[i].GetFlightNumber() == flightNumber) {
			return aircraftList_[i].GetHeading();
			valid = true;
		}
		

	}

	if (valid != true) {
		std::cout << "\nFlight " + flightNumber + " is not in the system";
		return 0;
	}
}


void FlightSystem::ChangeAltitude(std::string flightNumber, int altitude) {

	bool valid = false;

	for (int i = 0; i < aircraftList_.size(); i++) {

		if (aircraftList_[i].GetFlightNumber() == flightNumber) {
			valid = true;
			for (int x = 0; x < aircraftList_.size();x++){

				if (aircraftList_[i].GetGridReference() == aircraftList_[x].GetGridReference() && aircraftList_[x].GetFlightNumber() != flightNumber) {
	

					int min = aircraftList_[x].GetAltitude() - 3000;
					int max = aircraftList_[x].GetAltitude() + 3000;

					if (altitude >= min && altitude <= max) {
						std::cout << "Warning - Aircraft collision possible between " << aircraftList_[i].GetFlightNumber() << " and " << aircraftList_[x].GetFlightNumber();
					}
					else {

						aircraftList_[i].SetAltitude(altitude);
						std::cout << "Altitude of flight " + flightNumber + " changed to " + std::to_string(altitude);						

					}
				}
				
			}


		}
	
	}

	if (valid != true) {
		std::cout << "Flight " + flightNumber + " is not in the system";
	}
}

int FlightSystem::GetAltitude(std::string flightNumber) {

	bool valid = false;

	for (int i = 0; i < aircraftList_.size(); i++) {

		if (aircraftList_[i].GetFlightNumber() == flightNumber) {

			return aircraftList_[i].GetAltitude();
			valid = true;
		}


	}

	if (valid != true) {
		std::cout << "Flight " + flightNumber + " is not in the system";
		return 0;
	}

}

int FlightSystem::NumAircraftSector() {

	int noAircrafts{0};

	for (int i = 0;i < aircraftList_.size();i++){
		noAircrafts++;
	}

	return noAircrafts;
}

