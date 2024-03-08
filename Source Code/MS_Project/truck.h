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

struct Truck {
	double weight;	//accumulated weight in kg
	double volume;	//current carried volume inside truck in cubic metres
	struct Route route;
};

struct Shipment {
	double weight;				//weight of shipment in kg
	double box_size;			//box size in cubic metres
	struct Point dest;	//destination of shipment, delivery point
};


int isValidInput(const struct Shipment* shipment);
//TODO: validate location, weight, truck volume, box size

#endif // !TRUCK_H



