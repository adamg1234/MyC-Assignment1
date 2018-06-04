/*
* Aircraft.cpp
*
* Version information: v0.1
* Author: Adam Graham
* Date: 21/10/2017
* Description: A Aircraft.h application to hold my attributes for the Aircrafts
* Copyright notice
*/

#pragma once

#include <string>;

class Aircraft {

private:

	std::string flightNumber_;
	std::string airline_;
	std::string aircraftType_;
	int groundSpeed_;
	int altitude_;
	std::string gridReference_;
	int heading_;




public:
	Aircraft();

	Aircraft(std::string flightNumber_, std::string airline_, std::string aircraftType_, int groundSpeed_, int altitude_, std::string gridReference_, int heading_);

	void Aircraft::SetFlightNumber(std::string flightNumber);
	std::string Aircraft::GetFlightNumber();

	void Aircraft::SetAirline(std::string airline);
	std::string Aircraft::GetAirline();

	void Aircraft::SetaircraftType(std::string aircraftType);
	std::string Aircraft::GetaircraftType();

	void Aircraft::SetGroundSpeed(int groundSpeed);
	int Aircraft::GetGroundSpeed();

	void Aircraft::SetAltitude(int altitude);
	int Aircraft::GetAltitude();

	void Aircraft::SetGridReference(std::string gridReference);
	std::string Aircraft::GetGridReference();

	void Aircraft::SetHeading(int heading);
	int Aircraft::GetHeading();


};


