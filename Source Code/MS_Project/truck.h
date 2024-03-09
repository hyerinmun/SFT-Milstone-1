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
/// Validates location, weight, truck volume, box size from user input (passed as param)
/// </summary>
/// <param name="shipment">user input, info about shipment</param>
/// <returns>true (1) if valid</returns>
int isValidInput(const struct Shipment* shipment);

/// <summary>
/// gets truck route for given truck passed
/// </summary>
/// <param name="truck">truck on the route</param>
/// <param name="route">route to add to truck</param>
/// <returns>true (1) if route successfully found</returns>
int getTruckRoute(struct Truck* truck, const struct Route* route);

#endif // !TRUCK_H



