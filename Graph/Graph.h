#pragma once
#include<iostream>
#include<vector>
#include"Vertex.h"
#include<queue>
#include<stack>
#include<fstream>
#include <unordered_map>
using namespace std;
class Graph
{
	vector<Vertex> Cities;
public:

	// Adding city to the graph
	void AddCity(Vertex NewVertex) {
		bool check = checkIfCityExist(NewVertex.GetCityName());
		if (check == true) {
			cout << "City Already Exist\n";
		}
		else {
			Cities.push_back(NewVertex);
			cout << "City Added\n";
		}

	}


	Vertex getCityByName(string name) {
		bool check = checkIfCityExist(name);
		if (check == true) {
			for (int i = 0; i < Cities.size(); i++) {
				if (Cities[i].GetCityName() == name) {
					return Cities[i];
				}
			}
		}
		else
			cout << "This City doesn't exist\n";
	}

	//Check if the City is already in the graph
	bool checkIfCityExist(string name) {
		for (int i = 0; i < Cities.size(); i++) {
			if (Cities[i].GetCityName() == name) {
				return true;
			}
		}
		return false;
	}

	//Check if the edge is already in the graph
	//name1--> name for the Source City
	//name2--> name for the Destination City
	bool checkIfEdgeExist(string name1, string name2) {
		Vertex v = getCityByName(name1);
		list<Edge>edgelist;
		edgelist = v.Edgeslist;
		bool flag = false;
		for (auto it = edgelist.begin(); it != edgelist.end(); it++) {
			if (it->GetDestinationCity() == name2) {
				flag = true;
				return flag;
				break;
			}
		}
		return flag;
	}


	// Traverse the graph(DFS)
	void DFS(string start) {
		bool check = checkIfCityExist(start);
		if (check) {
			stack<string>s;
			unordered_map<string, bool> visited;
			Vertex current = getCityByName(start);
			for (int i = 0; i < Cities.size(); i++) {
				visited[Cities[i].GetCityName()] = false;
			}
			s.push(start);
			visited[start] = true;
			while (!s.empty()) {
				cout << s.top() << "->";
				s.pop();
				for (auto it = current.Edgeslist.begin(); it != current.Edgeslist.end(); it++) {

					if (!visited[it->GetDestinationCity()]) {
						s.push(it->GetDestinationCity());
						visited[it->GetDestinationCity()] = true;
					}

				}
				if (!s.empty()) {
					current = getCityByName(s.top());
				}

			}
			cout << endl;
		}
		else
			cout << "This City doesn't exist" << endl;


	}

	// Traverse the graph(BFS)
	void BFS(string start) {
		bool check = checkIfCityExist(start);
		if (check) {
			queue<string> q;
			unordered_map<string, bool>visited;
			Vertex current = getCityByName(start);
			for (int i = 0; i < Cities.size(); i++) {
				visited[Cities[i].GetCityName()] = false;
			}
			q.push(current.GetCityName());
			visited[start] = true;

			while (!q.empty()) {
				for (auto it = current.Edgeslist.begin(); it != current.Edgeslist.end(); it++) {
					if (!visited[it->GetDestinationCity()]) {
						q.push(it->GetDestinationCity());
						visited[it->GetDestinationCity()] = true;
					}
				}
				cout << current.GetCityName() << "-->";

				q.pop();
				if (q.empty()) {
					break;
				}
				current = getCityByName(q.front());

			}
			cout << endl;
		}
		else
			cout << "This City doesn't exist" << endl;


	}

	// for Deleting city from the graph
	void DeleteCity(string name) {
		bool check = checkIfCityExist(name);
		if (check) {
			int cIndex = 0;
			for (int i = 0; i < Cities.size(); i++) {
				if (Cities[i].GetCityName() == name) {
					cIndex = i;
				}
			}
			for (int i = 0; i < Cities.size(); i++) {
				for (auto it = Cities[i].Edgeslist.begin(); it != Cities[i].Edgeslist.end(); it++) {
					if (it->GetDestinationCity() == name) {
						Cities[i].Edgeslist.erase(it);
						break;
					}
				}
			}
			Cities.erase(Cities.begin() + cIndex);
			cout << name << " Deleted Successfully" << endl;
		}
		else
			cout << "This city isn't available" << endl;
	}


	// for Adding edge between 2 cities in the graph
	void AddEdge(string name1, string name2, int w) {
		bool check1 = checkIfCityExist(name1);
		bool check2 = checkIfCityExist(name2);
		if (check1 == true && check2 == true) {
			bool check3 = checkIfEdgeExist(name1, name2);
			if (check3 == true) {
				cout << "This Road between " << name1 << " and " << name2 << " Already Exist\n";
			}
			else {
				for (int i = 0; i < Cities.size(); i++) {
					if (Cities[i].GetCityName() == name1) {
						Edge e(name2, w);
						Cities[i].Edgeslist.push_back(e);
					}
					else if (Cities[i].GetCityName() == name2) {
						Edge e(name1, w);
						Cities[i].Edgeslist.push_back(e);
					}
				}
				cout << "Edge between " << name1 << " and " << name2 << " added Successfully" << endl;
			}
		}
		else {
			cout << "Invalid City entered.\n";
		}


	}

	// for Deleting edge between 2 cities from the graph
	void DeleteRoad(string name1, string name2) {
		bool check = checkIfEdgeExist(name1, name2);
		if (check) {
			for (int i = 0; i < Cities.size(); i++) {
				if (Cities[i].GetCityName() == name1) {
					for (auto it = Cities[i].Edgeslist.begin(); it != Cities[i].Edgeslist.end(); ++it) {
						if (it->GetDestinationCity() == name2) {
							Cities[i].Edgeslist.erase(it);
							break;
						}
					}
				}
				else if (Cities[i].GetCityName() == name2) {
					for (auto it = Cities[i].Edgeslist.begin(); it != Cities[i].Edgeslist.end(); ++it) {
						if (it->GetDestinationCity() == name1) {
							Cities[i].Edgeslist.erase(it);
							break;
						}
					}
				}
			}
			cout << "Road between " << name1 << " and " << name2 << " deleted successfully." << endl;
		}
		else {
			cout << "Road between " << name1 << " and " << name2 << " does not exist." << endl;
		}
	}



	// Print the shortest path between 2 Cities
	void dijkstra(string source, string dest) {
		if (!checkIfCityExist(source) || !checkIfCityExist(dest)) {
			cout << "This city doesn't exist\n";
			return;
		}
		unordered_map<string, bool> visited;
		unordered_map<string, int> dist;
		unordered_map<string, string> prev;
		stack<string> s;
		for (int i = 0; i < Cities.size(); i++) {
			visited[Cities[i].GetCityName()] = false;
			dist[Cities[i].GetCityName()] = INT_MAX;
		}
		dist[source] = 0;
		while (!visited[dest]) {
			string u;
			int min_dist = INT_MAX;
			for (auto d : dist) {
				if (!visited[d.first] && d.second < min_dist) {
					u = d.first;
					min_dist = d.second;
				}
			}
			if (min_dist == INT_MAX) break; // No path to destination
			visited[u] = true;
			for (auto e : getCityByName(u).Edgeslist) {
				string v = e.GetDestinationCity();
				int w = e.GetDistance();
				if (dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					prev[v] = u;
				}
			}
		}
		if (dist[dest] == INT_MAX) {
			cout << "There is no path from " << source << " to " << dest << endl;
			return;
		}
		cout << "The shortest distance: " << dist[dest] << " KM" << endl;
		string path = dest;
		s.push(path);
		while (s.top() != source) {
			path = prev[path];
			s.push(path);
		}
		cout << "The Path: ";
		while (!s.empty()) {
			cout << s.top() << "-->";
			s.pop();
		}
		cout << endl;
	}

	// print the whole graph
	void printGraph() {
		for (int i = 0; i < Cities.size(); i++) {
			Vertex City;
			City = Cities[i];
			cout << City.GetCityName() << " -->";
			City.printEdgeList();
		}
	}
	void saveToFileC(string filename) {
		ofstream file;
		file.open(filename);
		// Write cities to file
		cout << Cities.size();
		for (Vertex city : this->Cities) {
			file << city.GetCityName() << endl;
		}

		file.close();
		cout << "Graph data saved to file." << endl;

	}
	void saveToFileE(string filename) {
		ofstream file;
		file.open(filename);


		for (Vertex city : this->Cities) {
			file << city.GetCityName() << " " << city.Edgeslist.size();
			for (Edge edge : city.Edgeslist) {
				file << " " << edge.GetDestinationCity() << " " << edge.GetDistance();
			}
			file << endl;
		}

		file.close();
		cout << "Graph data saved to file." << endl;

	}
	void loadFromFileC(string fileName) {
		ifstream file;
		file.open(fileName);

		if (!file.is_open()) {
			cout << "Error: cannot open file " << fileName << endl;
			return;
		}

		Vertex city;
		string cityName;
		while (file >> cityName) {
			city.SetName(cityName);
			Cities.push_back(city);
		}
		file.close();
	}

	void loadFromFileE(string fileName) {
		ifstream file;
		file.open(fileName);
		if (!file.is_open()) {
			cout << "Error: cannot open file " << fileName << endl;
			return;
		}
		for (auto& it : Cities) {
			string city;
			int numOfEdges;
			file >> city >> numOfEdges;
			for (int i = 0; i < numOfEdges; i++) {
				string destinationName;
				int distance;
				file >> destinationName >> distance;
				Edge e(destinationName, distance);
				it.Edgeslist.push_back(e);
			}
		}
		file.close();
	}
	

};