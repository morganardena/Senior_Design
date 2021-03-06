// ClassesExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class Cake
{
public:
	int numSlices =0;
	int numCandles=0;
	string cakeFlavor="";

	void makeCake(int numberOfCandles, int numberOfSlices, string flavorOfCake)
	{
		numCandles = numberOfCandles;
		numSlices = numberOfSlices;
		cakeFlavor = flavorOfCake;
		mixBatter();
		cout << "Cake is ready for the oven.";
	}

	void eatCake()
	{
		if (numSlices == 0) {
			cout << "There is no cake to eat.";
		}
		else {
			cout << "Here is a slice of" << cakeFlavor << " cake" << endl;
			numSlices -= 1;
		}
	}
private:
	void mixBatter()
	{
		cout << "Batter was mixed.";
	}
};


class Oven
{
public:
	//Data members (Properties)
	int maxTemp;
	int minTemp;
	string brand;
	string typeOfOven;

	//Data functions (Behaviors)
	int getTemp()
	{
		return currentTemp;
	}
	void setTemp(int temp)
	{
		currentTemp = temp;
	}
	int getTimer()
	{
		return timer;
	}
	void setTimer(int time)
	{
		timer = time;
	}

	void bake(Cake cake)
	{
		cout << "Baked a " << cake.cakeFlavor << " for " << timer << " minutes at " << currentTemp << " degrees Fahrenheit." << endl;
	}

	//Default Constructor
	Oven()
	{
		cout << "Default constructor called." << endl;
		maxTemp = 500;
		minTemp = 100;
		brand = "Name Brand";
		typeOfOven = "Electric";
		ptr = new int;
		*ptr = 0;
	}

	//Parametized Constructor
	Oven(int maxTemp, int minTemp, string brand, string typeOfOven)
	{
		cout << "Parametize constructor called." << endl;
		this->maxTemp = maxTemp;
		this->minTemp = minTemp;
		this->brand = brand;
		this->typeOfOven = typeOfOven;
		ptr = new int;
		*ptr = 0;
	}

	//Copy Constructor
	Oven(const Oven &obj)
	{
		cout << "Copy constructor called." << endl;
		ptr = new int;
		*ptr = *obj.ptr;
		maxTemp = obj.maxTemp;
		minTemp = obj.minTemp;
		brand = obj.brand;
		typeOfOven = obj.typeOfOven;
	}

private:
	//Data members (Properties)
	int currentTemp = 0;
	int timer;
	int *ptr;
};


int main()
{
	Cake myCake;
	string cakeFlavor = "Chocolate";
	myCake.eatCake();

	int numSlices = 3, numCandles = 2;
	myCake.makeCake(numCandles, numSlices, cakeFlavor);


	int timer;
	int currentTemp;

	Oven myOven;
	//view oven properties
	cout << "Max temperature: " << myOven.maxTemp << endl;
	cout << "Min temperature: " << myOven.minTemp << endl;
	currentTemp = myOven.getTemp();
	cout << "Current temperature: " << currentTemp << endl;
	timer = myOven.getTimer();
	cout << "Timer: " << timer << endl;
	cout << "Brand: " << myOven.brand << endl;
	cout << "Type of oven: " << myOven.typeOfOven << endl;

	//bake a cake
	currentTemp = 350;
	timer = 30;
	myOven.setTemp(currentTemp);
	myOven.setTimer(timer);
	myOven.bake(myCake);

	//Create a new oven specifying properties (parameters)
	int maxTemp = 400, minTemp = 200;
	string brand ="Fancy Oven", typeOfOven = "Gas";
	Oven myNewOven(maxTemp, minTemp, brand, typeOfOven);

	//view oven properties
	cout << "Max temperature: " << myNewOven.maxTemp << endl;
	cout << "Min temperature: " << myNewOven.minTemp << endl;
	currentTemp = myNewOven.getTemp();
	cout << "Current temperature: " << currentTemp << endl;
	timer = myNewOven.getTimer();
	cout << "Timer: " << timer << endl;
	cout << "Brand: " << myNewOven.brand << endl;
	cout << "Type of oven: " << myNewOven.typeOfOven << endl;

	//bake a cake
	currentTemp = 250;
	timer = 50;
	myNewOven.setTemp(currentTemp);
	myNewOven.setTimer(timer);
	myNewOven.bake(myCake);

	//Copy constructor , create copy of old oven
	Oven copyOven = myOven;

	//view oven properties
	cout << "Max temperature: " << copyOven.maxTemp << endl;
	cout << "Min temperature: " << copyOven.minTemp << endl;
	currentTemp = copyOven.getTemp();
	cout << "Current temperature: " << currentTemp << endl;
	timer = copyOven.getTimer();
	cout << "Timer: " << timer << endl;
	cout << "Brand: " << copyOven.brand << endl;
	cout << "Type of oven: " << copyOven.typeOfOven << endl;

	//bake a cake
	currentTemp = 400;
	timer = 10;
	copyOven.setTemp(currentTemp);
	copyOven.setTimer(timer);
	copyOven.bake(myCake);
}

