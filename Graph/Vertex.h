#pragma once
#include<iostream>
#include"Edge.h"
#include<string>
#include<list>
#include<fstream>
using namespace std;
class Vertex
{
	string City_name;
public:
	list<Edge> Edgeslist;
	Vertex() {
		City_name = "";
	}
	Vertex(string name) {
		City_name = name;
	}
	void SetName(string name) {
		City_name = name;
	}
	string GetCityName() {
		return City_name;
	}
	void printEdgeList() {
		cout << "[";
		for (auto it= Edgeslist.begin();it != Edgeslist.end();it++) {
			cout << it->GetDestinationCity() << "(" << it->GetDistance() << " KM) -->";
		}
		cout << "]";
		cout << endl;
	}
};

