/*
* Aircraft.cpp
*
* Version information: v0.1
* Author: Adam Graham
* Date: 21/10/2017
* Description: A Aircraft.cpp application to hold my attributes for the Aircrafts
* Copyright notice
*/

#include <iostream>;
#include <string>;

#include "Aircraft.h"



Aircraft::Aircraft() {

}


Aircraft::Aircraft(std::string flightNumber, std::string airline, std::string aircraftType, int groundSpeed, int altitude, std::string gridReference, int heading)
	:flightNumber_{ flightNumber }, airline_{ airline }, aircraftType_{ aircraftType }, groundSpeed_{ groundSpeed }, altitude_{ altitude }, gridReference_{ gridReference }, heading_{ heading } {


}


//Getters and Setters
void Aircraft::SetFlightNumber(std::string flightNumber) {

	flightNumber_ = flightNumber;
}

std::string Aircraft::GetFlightNumber() {

	return flightNumber_;
}


void Aircraft::SetAirline(std::string airline) {

	airline_ = airline;
}

std::string Aircraft::GetAirline() {

	return airline_;
}


void Aircraft::SetaircraftType(std::string aircraftType) {

	aircraftType_ = aircraftType;
}

std::string Aircraft::GetaircraftType() {

	return aircraftType_;
}


void Aircraft::SetGroundSpeed(int groundSpeed) {

	groundSpeed_ = groundSpeed;
}

int Aircraft::GetGroundSpeed() {

	return groundSpeed_;
}


void Aircraft::SetAltitude(int altitude) {

	altitude_ = altitude;
}

int Aircraft::GetAltitude() {

	return altitude_;
}


void Aircraft::SetGridReference(std::string gridReference) {

	gridReference_ = gridReference;
}

std::string Aircraft::GetGridReference() {

	return gridReference_;
}


void Aircraft::SetHeading(int heading) {

	heading_ = heading;
}

int Aircraft::GetHeading() {

	return heading_;
}
