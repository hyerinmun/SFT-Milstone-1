#pragma once
#include "mapping.h"
#ifndef TRUCK_H
#define TRUCK_H

#define MAX_WEIGHT 1200	//max carrying weight
#define MAX_VOL 50		//max carrying volume of each truck
#define NUM_OF_TRUCKS 3	//there are only 3 trucks

#define SIZE_SM 0.5		//size of small box
#define SIZE_MED 1		//size of medium box
#define SIZE_LG 5		//size of large box

#define MIN_ALPHA_COL 'A'	//minimum letter value for destination point
#define MAX_ALPHA_COL 'Y'	//max letter value for destination point
#define MIN_NUM_ROW 1		//min number value for destination point
#define MAX_NUM_ROW 25		//max number value for destination point

struct Truck {
	double weight;		//accumulated weight in kg
	double volume;		//current carried volume inside truck in cubic metres
	struct Route route;
};

struct Shipment {
	double weight;			//weight of shipment in kg
	double box_size;		//box size in cubic metres
	struct Point dest;		//destination of shipment, delivery point
	};

/// <summary>
/// Prompts user to enter information about a shipment. Validates location, weight, truck volume, box size from user input (passed as param)
/// </summary>
/// <param name="shipment">user input, info about shipment</param>
/// <returns>true (1) if valid, else returns -1 for invalid</returns>
int getInput(const struct Shipment* shipment);

/// <summary>
/// gets truck route for given truck passed
/// </summary>
/// <param name="truck">truck on the route</param>
/// <param name="route">route to add to truck</param>
/// <returns>true (1) if route successfully found</returns>
int getTruckRoute(const struct Truck* truck, const struct Route* route);

/// <summary>
/// This function assesses the validity of a given box size that will be loaded on the truck. 
/// The input parameter 'boxSize' represents the size of the box to be examined.
/// Within the function, three constant values('1/2 (SIZE_SM)' '1 (SIZE_MED)' and '5 (SIZE_LG)') are defined to establish the acceptable box sizes.
/// </summary>
/// <param name="boxSize">box size that will be loaded on the truck</param>
/// <returns>true (1) if valid which means they are one of size among three constant values</returns>
int isValidSize(const double* boxSize);

/// <summary>
/// This function evaluates whether adding a box to a truck exceeds its volume capacity.
/// The trucks are also capable of carrying 50 cubic meters (MAX_VOL) of boxes.
/// </summary>
/// <param name="truck"> truck on the route</param>
/// <param name="volume">volume of shipment that will be loaded on the truck</param>
/// <returns>true (1) if valid which means the volume is more than 0 and less than equal to 50, else returns -1 for invalid</returns>
int isValidVolume(const struct Truck* truck, const double* volume);

/// <summary>
/// This function assesses whether a truck becomes overloaded after incorporating a shipment.
/// All our trucks are the same size and can hold up to 1200 kg (MAX_WEIGHT) of cargo
/// If the current weight capacity of the truck is less than or equal to 1200, 
/// it adds the weight of the shipment to the truck's capacity. 
/// After the addition check if the updated capacity remains less than or equal to 1200. 
/// </summary>
/// <param name="weight">weight to compare to min/max range of truck's carrying capacity</param>
/// <returns>true (1) if valid which means the weight is more than 0 and less than equal to 1200, else returns -1 for invalid</returns>
int isValidWeight(const double* weight);

/// <summary>
/// Checks if the truck passed as argument has enough carrying capacity left to hold the given weight.
/// </summary>
/// <param name="truck2Check">truck to check capacity of</param>
/// <param name="shipment">shipment whose weight is to be added</param>
/// <returns> returns true (1) if truck DOES have space in it, else returns -1 if it's full</returns>
int isTruckLoadable(const struct Truck* truck2Check, const struct Shipment* shipment);

/// <summary>
/// This function checks if the passed path argument does not intersect with building
/// </summary>
/// <param name="route"> valid truck route</param>
/// <param name="map"> map structure </param>
/// <returns>true (1) if valid, else returns -1 for invalid</returns>
int isvalidLocation(const struct Route* route, const struct Map* map);

/// <summary>
/// Finds the truck whose route is nearest to the the bldg point.
/// </summary>
/// <param name="truck">truck whose route is being checked in relation to bldg point</param>
/// <param name="bldg">point to get closest route to, destination</param>
/// <returns>true (1) if truck passed is the closest to the bldg, else return -1 when it's not</returns>
int findClosestTruck(const struct Truck* truck, const struct Point* bldg);

#endif // !TRUCK_H



