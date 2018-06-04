/*
* FlightSystem.h
*
* Version information: v0.1
* Author: Adam Graham
* Date: 21/10/2017
* Description: A FlightSystem.h application to hold my methods
* Copyright notice
*/

#pragma once

#include <iostream>;
#include <string>;
#include<vector>;

#include"Aircraft.h"

class FlightSystem
{

private:

	std::vector<Aircraft> aircraftList_;


public:
	FlightSystem();
	FlightSystem(std::vector<Aircraft> aircraftList_);

	void FlightSystem::AddAircraft(std::string flightNumber, std::string airline, std::string aircraftType, int groundSpeed, int altitude, std::string gridReference, int heading);
	std::vector<Aircraft> FlightSystem::ListAllAircraft();
	std::vector<Aircraft> FlightSystem::ListAllCruisingAircraft();
	void FlightSystem::RemoveAircraft(std::string flightNumber);
	void FlightSystem::ChangeHeading(std::string flightNumber, int heading);
	int FlightSystem::GetHeading(std::string flightNumber);
	void FlightSystem::ChangeAltitude(std::string flightNumber, int altitude);
	int FlightSystem::GetAltitude(std::string flightNumber);
	int FlightSystem::NumAircraftSector();


};

