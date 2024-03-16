#pragma once
#include<iostream>
#include<string>
using namespace std;
class Edge
{

	int Distance;
	string DestinationCity;
public:

	Edge(string name, int distance) {
		DestinationCity = name;
		Distance = distance;
	}
	void SetDistance(int value) {
		Distance = value;
	}
	int GetDistance() {
		return Distance;
	}
	void SetDestinationCity(string name) {
		DestinationCity = name;
	}
	string GetDestinationCity() {
		return DestinationCity;
	}
};

