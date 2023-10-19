// Marcus Wu 7764624 
// This is the only file to submit.

#include "car.hpp"
#include <cstddef>
#include <cstring>
#include <iostream>
// #include .......
using namespace std;
Car::Car(){
	manufacturer=model=0;
	zeroToSixtyNs=0;
	headonDragCoeff=0;
	horsepower=0;
	backseatDoors=DoorKind::None;
	seatCount=0;
}
Car::~Car(){
	delete manufacturer;
	delete model;
}
Car::Car(char const* const manufacturerName, char const* const modelName, PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign){
	if(manufacturer==0) manufacturer=new char[100];
	if(model==0) model=new char[100];
	strcpy(manufacturer,manufacturerName);
	strcpy(model,modelName);
	headonDragCoeff=perf.headonDragCoeff;
	horsepower=perf.horsepower;
	zeroToSixtyNs=perf.zeroToSixtyNs;
	backseatDoors=backseatDoorDesign;
	seatCount=numSeats;
}
Car::Car(Car const& o){
	if(manufacturer==0) manufacturer=new char[100];
	if(model==0) model=new char[100];
	strcpy(manufacturer,o.manufacturer);
	strcpy(model,o.model);
	zeroToSixtyNs=o.zeroToSixtyNs;
	headonDragCoeff=o.headonDragCoeff;
	horsepower=o.horsepower;
	backseatDoors=o.backseatDoors;
	seatCount=o.seatCount;
}
Car& Car::operator=(Car const& o){
	if(manufacturer==0) manufacturer=new char[100];
	if(model==0) model=new char[100];
	strcpy(manufacturer,o.manufacturer);
	strcpy(model,o.model);
	zeroToSixtyNs=o.zeroToSixtyNs;
	headonDragCoeff=o.headonDragCoeff;
	horsepower=o.horsepower;
	backseatDoors=o.backseatDoors;
	seatCount=o.seatCount;
	return *this;
}
char const* Car::getManufacturer() const{
	return manufacturer;
}
char const* Car::getModel() const{
	return model;
}
uint8_t Car:: getSeatCount() const{
	return seatCount;
}
PerformanceStats Car::getStats() const{
	return PerformanceStats(horsepower,zeroToSixtyNs,headonDragCoeff);
}
DoorKind Car::getBackseatDoors() const{
	return backseatDoors;
}
void Car::manufacturerChange(char const* const newManufacturer){
	if(manufacturer==0) manufacturer=new char[100];
	strcpy(manufacturer,newManufacturer);
}
void Car::modelNameChange(char const* const newModelName){
	if(model==0) model=new char[100];
	strcpy(model,newModelName);
}
void Car::reevaluateStats(PerformanceStats newStats){
	zeroToSixtyNs=newStats.zeroToSixtyNs;
	headonDragCoeff=newStats.headonDragCoeff;
	horsepower=newStats.horsepower;
}
void Car::recountSeats(uint8_t newSeatCount){
	seatCount=newSeatCount;
}
void Car::reexamineDoors(DoorKind newDoorKind){
	backseatDoors=newDoorKind;
}
int main(){
	/*Car c;
	c.manufacturerChange("123");
	c.modelNameChange("1234");
	Car c2;
	c2=c;
	cout<<c.getModel()<<" "<<c2.getModel()<<"\n";*/
}
